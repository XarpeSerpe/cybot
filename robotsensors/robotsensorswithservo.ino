/* Sigue luz sin colisionar*/
#include <RobotMovil.h>
#include <Servo.h>
#include <NewPing.h>
#include <math.h>

RobotMovil robot;
Servo cuello;
/*NewPing sonar_L(10,10,50);
NewPing sonar_R(11,11,50);*/
NewPing sonar(5,A0,50);

float dist;
int eye_R = A3;
int eye_L = A5;
int light_R;
int light_L;
int angle;

void setup()
{
Serial.begin(9600);//debug
cuello.attach(3);
cuello.write(0);
delay(300);
}

void loop()
{
  for(int i = 0; i < 12; i++)
  {
    angle = i * 15;
    
    dist = sonar.ping_cm();
    delay(150);
    if(dist == 0) {dist=50;}
    if(dist>15) {robot.forward(150,150,1);/*follow_light();*/}
    else {
          if (angle < 90) {robot.rotate(-1);}
          else {robot.rotate(1);}
        }
    cuello.write(angle);
    delay(300); //ajustar el valor
  }
  for(int i = 12; i > 0; i--)
  {
    angle = i * 15;
    
    dist = sonar.ping_cm();
    delay(150);
    if(dist == 0){dist=50;}
    if(dist>15) {robot.forward(150,150,1);/*follow_light();*/}
    else {
          if (angle < 90) {robot.rotate(-1);}
          else {robot.rotate(1);}
        }
    cuello.write(angle);
    delay(300); //ajustar el valor
  }
}

void follow_light()
  {
    delay(30);
    light_R = analogRead(eye_R);
    delay(30);
    light_L = analogRead(eye_L);
    if (light_L>light_R) {robot.forward(100,25,2);}
    else if(light_L<light_R) {robot.forward(25,100,2);}
    else {robot.forward(100,100,2);}
  }
