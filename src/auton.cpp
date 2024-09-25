#include "vex.h"
#include "auton.h"
#include "sylib/sylib.hpp"

using namespace vex;


void auton()
{
// Set the motors to spin at 150 RPM for 5 seconds using the 
// custom speed controller
  FrontLeftMotor.set_velocity_custom_controller(150); 
  BackLeftMotor.set_velocity_custom_controller(150);
  MiddleLeftMotor.set_velocity_custom_controller(150);
  FrontRightMotor.set_velocity_custom_controller(150);
  BackRightMotor.set_velocity_custom_controller(150);
  MiddleRightMotor.set_velocity_custom_controller(150);
  sylib::delay(5000);
  FrontLeftMotor.stop();
  BackLeftMotor.stop();
  MiddleLeftMotor.stop();
  FrontRightMotor.stop();
  BackRightMotor.stop();
  MiddleRightMotor.stop();
}
