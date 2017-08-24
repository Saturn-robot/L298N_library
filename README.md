[![Project Status: Active – The project has reached a stable, usable state and is being actively developed.](http://www.repostatus.org/badges/latest/active.svg)](http://www.repostatus.org/#active)

# Overview

This driver is to drive L298N to control motors. You can using it to adjust speeds, change directioon and so on. This driver has been tested on Arduino Mega 2560. You can file a bug in issue of this repository.

# Installation

On the repository page, look for the “Download ZIP” button and save it in somewhere.

You can install this library via the Library Manager interface. For example, as for Arduino 1:1.0.5+dfsg2-2, you can install it from directory in **Sketch** menu > Import library... > Add library... in form of zip file or folder.

If you want to add a library manually, you need to uncompress it and put in the proper directory. Arduino libraries are managed in three different places: inside the IDE installation folder, inside the core folder and in the libraries folder inside your sketchbook. The location of your sketchbook defaults to “..\<you>\DOCUMENTS\Arduino” on Windows machines. The path is clearly shown in the Preferences panel. If you want to see where the sketchbook defaults open Preferences under File.

# Usage

## Create a L298N controller

You need to offer 6 parameters to create a L298N controller and they are ENA, ENB, IN1, IN2, IN3, IN4 i.e. 6 pins of L298N board.

```
L298N l298n_controller(ENA, ENB, IN1, IN2, IN3, IN4);
```

## Adjust speed

You can method `setMotorSpeed` to set speed of a motor and you should offer two parameters - one is to specify which motor(LEFT or RIGHT) and the other is value of speed.

```
// left wheel go forward for 5 seconds
l298n_controller.setMotorSpeed(LEFT, 50);
```

You can also set speeds of two motors simultaneously using `setMotorSpeeds` and it has only one parameter - the value of speed.

```
// both wheels go forward for 5 seconds
l298n_controller.setMotorSpeeds(50, 50);
```

## Stop motors

You can use method `stopMotor` and `stopMotors` to stop one motor and two motors.

```
// stop right wheel for 5 seconds
l298n_controller.stopMotor(RIGHT);
delay(5000);

// stop both wheels for 5 seconds
l298n_controller.stopMotors();
delay(5000);
```

This library is very easy to use. You can learn it from codes in example folder.

# License

This library is licensed under the GNU General Public License, v3. A copy of this license is included in the file [LICENSE](LICENSE).
