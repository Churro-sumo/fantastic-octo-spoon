#include <xmotion.h>
#include "fish.h"
static int argument1 = 16;
static int argument2 = 63;
void setup()
{
  pinMode(9, OUTPUT);
  pinMode(10, INPUT);
  pinMode(A1,INPUT);//DREAPTA
  pinMode(A2,INPUT);//DIAGONALADREAPTA
  pinMode(4,INPUT);//MIJOC
  pinMode(1,INPUT);//STANGADIAGONALA
  pinMode(0,INPUT);//STANGA

  while(digitalRead(10) == false)
  {
    digitalWrite(9,1); 
  }

  digitalWrite(9,0);
}

void loop()
{
  while(digitalRead(10) == false)
  {
    digitalWrite(9,0);
    xmotion.StopMotors(1);  // 100ms Stop Both Motors
    digitalWrite(9,1);

    if (analogRead(A5) < 400) {
      fish();
    } else if (analogRead(A4) < 400) {
      fish();
    } else {
      xmotion.Forward(30,1); // %100 Speed, both motor forward 100mS.
      switch (digitalRead(4)) {
        case true:  // your hand is on the sensor
          xmotion.Forward(argument2,3); // %100 Speed, both motor forward 100mS
          break;
        case false:  // your hand is close to the sensor
          break;
      }
      switch (digitalRead(A1)) {
        case true:  // your hand is on the sensor
          xmotion.ArcTurn(argument1,argument2,3); // %100 Speed, both motor forward 100mS
          break;
        case false:  // your hand is close to the sensor
          break;
      }
      switch (digitalRead(0)) {
        case true:  // your hand is on the sensor
          xmotion.ArcTurn(argument2,argument1,3); // %100 Speed, both motor forward 100mS
          break;
        case false:  // your hand is close to the sensor
          break;
      }
  }
  }
  if(digitalRead(10) == false)
  {
    digitalWrite(9,0);
    xmotion.StopMotors(1);  // 100ms Stop Both Motors
  }
}