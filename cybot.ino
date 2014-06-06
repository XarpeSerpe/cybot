/* Control de cybot con Arduino Mega

Uso de pines
2 izquierda atras
3 izquierda adelante
4 derecha atras
5 derecha adelante

A12 ojo izq
A13 ojo der
cybot.forward(120,120,3000);
cybot.reverse(120,120,3000);
cybot.rotate(120,3000);
cybot.rotate(120,-3000);
*/
#include "motor_cybot.h"

RobotMovil cybot;

const int ir_eye_right = A14;
const int ir_eye_left = A15;
const int eye_R = A12;
const int eye_L = A13;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
 
  if (digitalRead(12) == LOW)
  {
    followLight();
  }
  else
  {
    followLine();
  }
}

void followLine()
{
 // int gas = noise();
  if (analogRead(ir_eye_right) > analogRead(ir_eye_left))
    {
      cybot.forward(100,0,1);
    }
 else if(analogRead(ir_eye_right) < analogRead(ir_eye_left))
    {
      cybot.forward(0,100,1);
    }
 else
    {
      cybot.forward(100,100,1);
    }
}

void followLight()
{
  //int gas = noise();  
  if (analogRead(eye_R) > analogRead(eye_L)) {cybot.forward(255,0,1);}
  else if(analogRead(eye_R) < analogRead(eye_L)) {cybot.forward(0,255,1);}
  else {cybot.forward(255,255,1);}
}

int noise() 
{
   const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
   unsigned int sample;
   unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level
 
   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;
 
   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(A11);
      if (sample < 1024)  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // save just the min levels
         }
      }
   }
   peakToPeak = map(signalMax - signalMin,0,1024,0,127);  // max - min = peak-peak amplitude
 /*  double volts = (peakToPeak * 3.3) / 1024;  // convert to volts
   Serial.print(peakToPeak);
   Serial.print(" ");
   Serial.println(volts);*/
   return peakToPeak;
}
