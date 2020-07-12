#include <Arduino.h>

const int motorCCW = 5;
const int motorCW = 4;
const int valveClose = 14;
const int valveOpen = 12;
const int btnValveOpen = 13;
const int btnValveClose = 16;
void controlValve(int valveState);
unsigned long measureOpenTime();
unsigned long measureCloseTime();

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

  Serial.println(measureOpenTime());
  Serial.println(measureCloseTime());
}

void loop()
{
}

void controlValve(int valveState) // 0 - daketilia 1- giaa
{
  if (valveState == 0)
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
  controlValve(0);
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
  controlValve(1);
  unsigned long startTime = millis();
  digitalWrite(motorCW, 1);
  while (digitalRead(valveOpen) == 1)
  {
    yield();
  }
  digitalWrite(motorCW, 0);
  return millis() - startTime;
}