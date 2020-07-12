#include <Arduino.h>

const int motorCCW = 5;
const int motorCW = 4;
const int valveClose = 14;
const int valveOpen = 12;
const int btnValveOpen = 13;
const int btnValveClose = 16;

unsigned long openTime = 0;
unsigned long closeTime = 0;
float currentStatePercent = 0;

void openValveToPercentage(float toPercent)
{
  if (currentStatePercent > toPercent)
  {
    // daketva
    digitalWrite(motorCW, 1);
    delay(closeTime * (currentStatePercent - toPercent));
    digitalWrite(motorCW, 0);
  }
  else
  {
    // gageba
    digitalWrite(motorCCW, 1);
    delay(openTime * (toPercent - currentStatePercent));
    digitalWrite(motorCCW, 0);
  }
  currentStatePercent = toPercent;
}

void resetValveToOpenOrClose(bool valveState) // 0 - daketilia 1- giaa
{
  if (valveState)
  {
    //close
    while (digitalRead(valveOpen) == 1)
    {
      digitalWrite(motorCW, 1);
      yield();
    }
    digitalWrite(motorCW, 0);
  }
  else
  {
    //open
    while (digitalRead(valveClose) == 1)
    {
      digitalWrite(motorCCW, 1);
      yield();
    }
    digitalWrite(motorCCW, 0);
  }
}

unsigned long measureOpenTime()
{
  resetValveToOpenOrClose(true);
  unsigned long startTime = millis();
  digitalWrite(motorCCW, 1);
  while (digitalRead(valveClose) == 1)
  {
    yield();
  }
  digitalWrite(motorCCW, 0);
  return millis() - startTime;
}

unsigned long measureCloseTime()
{
  resetValveToOpenOrClose(false);
  unsigned long startTime = millis();
  digitalWrite(motorCW, 1);
  while (digitalRead(valveOpen) == 1)
  {
    yield();
  }
  digitalWrite(motorCW, 0);
  return millis() - startTime;
}

void setup()
{

  Serial.begin(9600);
  Serial.println();
  pinMode(motorCCW, OUTPUT);
  pinMode(motorCW, OUTPUT);
  pinMode(valveClose, INPUT);
  pinMode(valveOpen, INPUT);
  pinMode(btnValveOpen, INPUT);
  pinMode(btnValveClose, INPUT);

  openTime = measureOpenTime();
  closeTime = measureCloseTime();
  currentStatePercent = 0;

  openValveToPercentage(0.5);
  delay(3000);
  openValveToPercentage(0.7);
  delay(3000);
  openValveToPercentage(0.2);
}

void loop()
{
}