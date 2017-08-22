#define MAX_PWM 255
#define LEFT 0
#define RIGHT 1

class L298N
{
private:
  unsigned int ena;
  unsigned int enb;
  unsigned int in1;
  unsigned int in2;
  unsigned int in3;
  unsigned int in4;
  // Initialize pins of L298N
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
    void setMotorSpeed(int i, int spd);
    void setMotorSpeeds(int leftSpeed, int rightSpeed);
    void stopMotor(int i);
    void stopMotors();
};
