#include "L298N.h"

// motor 1
#define ENA 5
#define IN1 7
#define IN2 8
// motor 2
#define ENB 6
#define IN3 9
#define IN4 10

L298N l298n_controller(ENA, ENB, IN1, IN2, IN3, IN4);

void setup()
{
  Serial.begin(57600);
}

void loop()
{
  // left wheel go forward for 5 seconds
  l298n_controller.setMotorSpeed(LEFT, 50);
  delay(5000);
  // stop left wheel for 5 seconds
  l298n_controller.stopMotor(LEFT);
  delay(5000);
  // right wheel go backward for 5 seconds
  l298n_controller.setMotorSpeed(RIGHT, -50);
  delay(5000);
  // stop right wheel for 5 seconds
  l298n_controller.stopMotor(RIGHT);
  delay(5000);
  // both wheels go forward for 5 seconds
  l298n_controller.setMotorSpeeds(50, 50);
  delay(5000);
  // stop both wheels for 5 seconds
  l298n_controller.stopMotors();
  delay(5000);
}
