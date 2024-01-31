#include <Arduino.h>

// put function declarations here:
int SensorValue;
int SensorLow = 1023;
int SensorHigh = 0;

const int ledPin = 13;

void setup()
{
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  while (millis() < 5000)
  {
    SensorValue = analogRead(A0);
    if (SensorValue > SensorHigh)
    {
      SensorHigh = SensorValue;
    }
    if (SensorValue < SensorLow)
    {
      SensorLow = SensorValue;
    }
  }
  digitalWrite(ledPin, LOW);
}

void loop()
{
  // put your main code here, to run repeatedly:
  SensorValue = analogRead(A0);
  int pitch =  map(SensorValue, SensorLow, SensorHigh, 50, 4000);
  tone(8, pitch, 20);
  delay(10);
}

// put function definitions here:
int myFunction(int x, int y)
{
  return x + y;
}