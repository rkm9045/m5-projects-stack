#include <M5StickC.h>
#include <M5_ENV.h>

SHT3X sht30;
QMP6988 qmp6988;
SGP30 sgp30;

void setup() {
  M5.begin();
  M5.Lcd.setRotation(3);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(2);

  Wire.begin();
  if (!sht30.begin(0x44)) {
    M5.Lcd.println("SHT30 Error");
  }
  if (!qmp6988.init()) {
    M5.Lcd.println("QMP6988 Error");
  }
  if (!sgp30.begin()) {
    M5.Lcd.println("SGP30 Error");
  }
}

void loop() {
  float temp = sht30.getTemperature();
  float hum = sht30.getHumidity();
  float pres = qmp6988.calcPressure();
  uint16_t co2 = sgp30.getCO2();
  uint16_t tvoc = sgp30.getTVOC();

  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.printf("Temp: %.2f C\n", temp);
  M5.Lcd.printf("Humidity: %.2f %%\n", hum);
  M5.Lcd.printf("Pressure: %.2f hPa\n", pres / 100.0);
  M5.Lcd.printf("CO2: %d ppm\n", co2);
  M5.Lcd.printf("TVOC: %d ppb\n", tvoc);

  delay(2000);
}
