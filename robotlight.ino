#include <RobotMovil.h>
RobotMovil robot;

int eye_R = A3;
int eye_L = A5;
int light_R;
int light_L;

void setup()
{
Serial.begin(9600);
}

void loop()
{
  delay(30);
  light_R = analogRead(eye_R);
  Serial.print(light_R);
  Serial.println(" right");

  delay(30);
  light_L = analogRead(eye_L); 
  Serial.print(light_L);
  
  Serial.println(" left");

  int dist=min(light_L,light_R);
 
  if (light_L>light_R) {robot.forward(100,25,1);}
  else if(light_L<light_R) {robot.forward(25,100,1);}
  else {robot.forward(100,100,1);}
  
}
