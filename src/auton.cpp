#include "vex.h"
#include "auton.h"
#include "sylib/sylib.hpp"
#include "robot-config.h"

using namespace vex;


void auton()
{
// Set the motors to spin at 150 RPM for 5 seconds using the 
// custom speed controller
  FrontLeftMotor.setVelocity(150, rpm); 
  BackLeftMotor.setVelocity(150, rpm);
  MiddleLeftMotor.setVelocity(150, rpm);
  FrontRightMotor.setVelocity(150, rpm);
  BackRightMotor.setVelocity(150, rpm);
  MiddleRightMotor.setVelocity(150, rpm);
  sylib::delay(5000);
  FrontLeftMotor.stop();
  BackLeftMotor.stop();
  MiddleLeftMotor.stop();
  FrontRightMotor.stop();
  BackRightMotor.stop();
  MiddleRightMotor.stop();
}
