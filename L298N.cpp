#include "L298N.h"

void L298N::initMotorController()
{
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void L298N::setMotorSpeed(int i, int spd)
{
  if (spd > MAX_PWM)
  {
    spd = MAX_PWM;
  }
  if (spd < -MAX_PWM)
  {
    spd = -MAX_PWM;
  }
  if (i == LEFT)
  {// left wheel
    if (spd >= 0)
    {
      // Go forward
      digitalWrite(in2, HIGH);
      digitalWrite(in1, LOW);
      analogWrite(ena, spd);
    }
    else
    {
      // Go backward
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(ena, spd);
    }
  }
  else
  {// right wheel
    if (spd >= 0)
    {
      // Go forward
      digitalWrite(in4, HIGH);
      digitalWrite(in3, LOW);
      analogWrite(enb, spd);
    }
    else
    {
      // Go backward
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enb, spd);
    }
  }
}

void L298N::setMotorSpeeds(int leftSpeed, int rightSpeed)
{
  setMotorSpeed(LEFT, leftSpeed);
  setMotorSpeed(RIGHT, rightSpeed);
}

void L298N::stopMotor(int i)
{
  setMotorSpeed(i, 0);
}

void L298N::stopMotors()
{
  setMotorSpeeds(0, 0);
}
