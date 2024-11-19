#include <xmotion.h>
#include "fish.h"

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

    digitalWrite(9,1);

    if (analogRead(A5) < 400) {
      fish();
    } else if (analogRead(A4) < 400) {
      fish();
    } else {
      xmotion.Forward(30,1); // %100 Speed, both motor forward 100mS.
      switch (digitalRead(4)) {
        case true:  // your hand is on the sensor
          xmotion.Forward(63,3); // %100 Speed, both motor forward 100mS
          break;
        case false:  // your hand is close to the sensor
          break;
      }
      switch (digitalRead(A1)) {
        case true:  // your hand is on the sensor
          xmotion.ArcTurn(16,63,3); // %100 Speed, both motor forward 100mS
          break;
        case false:  // your hand is close to the sensor
          break;
      }
      switch (digitalRead(0)) {
        case true:  // your hand is on the sensor
          xmotion.ArcTurn(63,16,3); // %100 Speed, both motor forward 100mS
          break;
        case false:  // your hand is close to the sensor
          break;
      }

  while(digitalRead(10) == false)
  {
    digitalWrite(9,0);
    xmotion.StopMotors(1);  // 100ms Stop Both Motors
  }
  }
  while(digitalRead(10) == false)
  {
    digitalWrite(9,0);
    xmotion.StopMotors(1);  // 100ms Stop Both Motors
  }
}
