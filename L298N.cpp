/*
 * L298N library, using to drive L298N to control motors
 * Copyright (C) 2017  Liu Chaoyang
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/
 
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
      analogWrite(ena, -spd);
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
      analogWrite(enb, -spd);
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
