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

#ifndef L298N_H
#define L298N_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define MAX_PWM 255
#define LEFT 0
#define RIGHT 1

class L298N
{
private:
  // ports of L298N
  unsigned int ena;
  unsigned int enb;
  unsigned int in1;
  unsigned int in2;
  unsigned int in3;
  unsigned int in4;
  // Initialize ports of L298N
  void initMotorController();
public:
  L298N(unsigned int ena, unsigned int enb, unsigned in1,
    unsigned in2, unsigned in3, unsigned in4)
    : ena(ena),
      enb(enb),
      in1(in1),
      in2(in2),
      in3(in3),
      in4(in4)
      {
        initMotorController();
      }
    // Set speed of a single motor
    void setMotorSpeed(int i, int spd);
    // Set speed of two motors
    void setMotorSpeeds(int leftSpeed, int rightSpeed);
    // Stop a single motor
    void stopMotor(int i);
    // Stop two motors
    void stopMotors();
};

#endif
