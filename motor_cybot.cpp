#include <Arduino.h>
#include "motor_cybot.h"
#define l_b 2
#define l_f 3
#define r_b 4
#define r_f 5

RobotMovil::RobotMovil()
{
  pinMode(r_f, OUTPUT);
  pinMode(r_b, OUTPUT);
  pinMode(l_f, OUTPUT);
  pinMode(l_b, OUTPUT);
}

void RobotMovil::forward(int l, int r, int t)
{
  digitalWrite(l_b, LOW);
  digitalWrite(r_b, LOW);
  analogWrite(l_f, l);
  analogWrite(r_f, r);
  delay(t);
}

void RobotMovil::reverse(int l, int r, int t)
{
  digitalWrite(l_f, LOW);
  digitalWrite(r_f, LOW);
  analogWrite(l_b, l);
  analogWrite(r_b, r);
  delay(t);
}

void RobotMovil::rotate(int p, int t)
{
  digitalWrite(l_f, LOW);
  digitalWrite(l_b, LOW);
  digitalWrite(r_f, LOW);
  digitalWrite(r_b, LOW);
  if (t>0)
   {
    analogWrite(l_b, p);
    analogWrite(r_f, p);
   }
  else
   {
    analogWrite(l_f, p);
    analogWrite(r_b, p);    
   } 
  delay(abs(t));
}
