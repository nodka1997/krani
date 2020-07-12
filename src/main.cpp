#include <Arduino.h>

const int motorCCW = 5;
const int motorCW = 4;
const int valveClose = 14;
const int valveOpen = 12;
const int btnValveOpen = 13;
const int btnValveClose = 15;

void resetState();

void setup()
{

  Serial.begin(9600);
  pinMode(motorCCW, OUTPUT);
  pinMode(motorCW, OUTPUT);
  pinMode(valveClose, INPUT);
  pinMode(valveOpen, INPUT);
  pinMode(btnValveOpen, INPUT);
  pinMode(btnValveClose, INPUT);

  Serial.println("above resetState()");
  resetState();
  Serial.println("below resetState()");
}

void loop()
{

}

void resetState()
{
  Serial.println(digitalRead(valveClose));
  while (digitalRead(valveClose) == 1)
  {
    Serial.println("looping");
    digitalWrite(btnValveClose, 1);
  }

  digitalWrite(btnValveClose, 0);
}