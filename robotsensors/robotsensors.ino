/* Sigue luz sin colisionar*/
#include <RobotMovil.h>
RobotMovil robot;

#include <NewPing.h>
/*NewPing sonar_L(10,10,50);
NewPing sonar_R(11,11,50);*/
NewPing sonar(5,A0,50);
float dist;
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
  dist = sonar.ping_cm();
  if(dist == 0.00){dist=50.0;}
  
  //debug
  /*Serial.print(dist);
  Serial.println(" cm");*/

  if(dist>15)
  {
    delay(30);
    light_R = analogRead(eye_R);
  
  //debug
  /*Serial.print(" ");
  Serial.print(light_R);
  Serial.print(" right");*/

    delay(30);
    light_L = analogRead(eye_L);
 
  //debug
  /*Serial.print(" "); 
  Serial.print(light_L);
  Serial.println(" left");*/
  
  if (light_L>light_R) {robot.forward(100,25,1);}
  else if(light_L<light_R) {robot.forward(25,100,1);}
  else {robot.forward(100,100,1);}
  }
  else {robot.rotate(1);}
  
}
