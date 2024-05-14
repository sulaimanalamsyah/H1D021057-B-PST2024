#include <Arduino.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

Servo myservo;
LiquidCrystal_I2C lcd(0x27, 16, 2);
int trigPin = D0;
int echoPin = D1;
int redLED = D2;
int greenLED = D3;
int SDA_pin = D5;
int SCL_pin = D6;

long duration;
int distance;

void setup() 
{
  myservo.attach(D4);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  Wire.begin(SDA_pin, SCL_pin);
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
}

void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (0.034 * duration)/2;
  lcd.setCursor(0,0);
  lcd.print("Jarak: ");
  lcd.print(distance);
  lcd.print(" cm");

  if (distance <= 10) 
  {
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);

    myservo.write(90);
    delay(15);
  } 
  else 
  {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);

    myservo.write(0);
    delay(15);
  }

  delay(1000);
}