#include <WiFi.h>
#include <HTTPClient.h>
#include <LiquidCrystal_I2C.h>
#include <ArduinoJson.h>

#define TDS_PIN 34
#define TEMP_PIN 32

LiquidCrystal_I2C lcd(0x27, 16, 2);

float voltage = 0;
float tdsValue = 0;
float temperatureValue = 0;
float ph = 7.0;

String ssid = "YOUR_WIFI";
String password = "YOUR_PASSWORD";

void setup()
{
  Serial.begin(115200);

  pinMode(TDS_PIN, INPUT);
  pinMode(TEMP_PIN, INPUT);

  lcd.init();
  lcd.backlight();

  WiFi.begin(ssid.c_str(), password.c_str());

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("WiFi Connected");
}

void loop()
{

  int analogValue = analogRead(TDS_PIN);
  int tempAnalog = analogRead(TEMP_PIN);

  voltage = analogValue * (3.3 / 4095.0);

  temperatureValue = tempAnalog / 88.0;

  tdsValue = (133.42 * voltage * voltage * voltage
              - 255.86 * voltage * voltage
              + 857.39 * voltage) * 0.5;

  Serial.print("TDS: ");
  Serial.println(tdsValue);

  lcd.setCursor(0, 0);
  lcd.print("TDS:");
  lcd.print(tdsValue);

  lcd.setCursor(0, 1);
  lcd.print("Temp:");
  lcd.print(temperatureValue);

  sendToCloud();

  delay(5000);
}

void sendToCloud()
{

  if (WiFi.status() == WL_CONNECTED)
  {

    HTTPClient http;

    http.begin("http://iotbegineer.com/api/sensors");
    http.addHeader("Content-Type", "application/json");

    DynamicJsonDocument doc(200);

    doc["tds"] = tdsValue;
    doc["temperature"] = temperatureValue;
    doc["ph"] = ph;

    String json;
    serializeJson(doc, json);

    int httpResponseCode = http.POST(json);

    Serial.println(httpResponseCode);

    http.end();
  }
}
