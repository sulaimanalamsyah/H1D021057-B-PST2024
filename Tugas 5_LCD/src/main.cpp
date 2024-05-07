#include <Arduino.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);
int SDA_pin = D1;
int SCL_pin = D2;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(SDA_pin,SCL_pin);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello, world!");
  lcd.setCursor(0,1);
  lcd.print("I am arduino!");
}

void loop() {
  // put your main code here, to run repeatedly:

}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}