#include <Arduino.h>

const int motorCCW = 5;
const int motorCW = 4;
const int valveClose = 12;
const int valveOpen = 14;
const int btnValveOpen = 13;
const int btnValveClose = 15;

void setup()
{
  Serial.begin(9600);
  pinMode(motorCCW, OUTPUT);
  pinMode(motorCW, OUTPUT);
  pinMode(valveClose, INPUT);
  pinMode(valveOpen, INPUT);
  pinMode(btnValveOpen, INPUT);
  pinMode(btnValveClose, INPUT);
  sdfsdfs
}

void loop()
{

  if (digitalRead(btnValveOpen) == LOW)
  {
    digitalWrite(motorCCW, HIGH);
  }
  else
  {
    digitalWrite(motorCCW, LOW);
  }

  if (digitalRead(btnValveClose) == LOW)
  {
    digitalWrite(motorCW, HIGH);
  }
  else
  {
    digitalWrite(motorCW, LOW);
  }

  if (digitalRead(valveOpen) == digitalRead(btnValveOpen))
  {
    digitalWrite(motorCCW, LOW);
  }

  if (digitalRead(valveClose) == digitalRead(btnValveClose))
  {
    digitalWrite(motorCW, LOW);
  }

}
