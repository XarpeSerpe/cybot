#include <RobotMovil.h>
RobotMovil robot;

void setup()
{
  robot.forward(120,120,1000);
  robot.rotate(500);
  robot.reverse(120,120,1000);
  robot.rotate(-500);
}

void loop()
{
  for(int i = 0; i < 100;i++)
  {
  robot.forward(i,100,i);
  }
  for(int i = 100; i > 0; i--)
  {
  robot.forward(100,i,i);
  }
}
