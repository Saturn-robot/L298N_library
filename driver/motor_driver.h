/*
Name:		motor_driver.h
Created:	7/22/2016 8:56:52 PM
Author:	Chaoyang Liu
*/

#define LEFT           0
#define RIGHT          1
//#define MAX_PWM        255
// motor one
#define ENA 5
#define IN1 7
#define IN2 8
// motor two
#define ENB 6
#define IN3 9
#define IN4 10

void initMotorController();
void setMotorSpeed(int i, int spd);
void stopMotor(int i);
void setMotorSpeeds(int leftSpeed, int rightSpeed);
void stopMotors();
