#include "vex.h"
#include "auton.h"
#include "sylib/sylib.hpp"
#include "robot-config.h"

using namespace vex;

void opControl(){
    
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

  // User control code here, inside the loop
  while (1)
  { 
        // x₁ = Left Motor X = [Controller] [3] position + [Controller] [1] position
        // x₂ = Right Motor X = [Controller] [3] position - [Controller] [1] position
        // Sets each motor's velocity (in rpm) to 0.0001x³ (shown as 0.0001 * x * x * x)
        FrontLeftMotor.set_velocity_custom_controller((0.0001 * (((Controller1.Axis3.position() + Controller1.Axis1.position()) * (Controller1.Axis3.position() + Controller1.Axis1.position())) * (Controller1.Axis3.position() + Controller1.Axis1.position()))) /*, percent*/ );
        BackLeftMotor.set_velocity_custom_controller((0.0001 * (((Controller1.Axis3.position() + Controller1.Axis1.position()) * (Controller1.Axis3.position() + Controller1.Axis1.position())) * (Controller1.Axis3.position() + Controller1.Axis1.position()))) /*, percent */);
        FrontRightMotor.set_velocity_custom_controller((0.0001 * (((Controller1.Axis3.position() - Controller1.Axis1.position()) * (Controller1.Axis3.position() - Controller1.Axis1.position())) * (Controller1.Axis3.position() - Controller1.Axis1.position()))) /*, percent */);
        BackRightMotor.set_velocity_custom_controller((0.0001 * (((Controller1.Axis3.position() - Controller1.Axis1.position()) * (Controller1.Axis3.position() - Controller1.Axis1.position())) * (Controller1.Axis3.position() - Controller1.Axis1.position()))) /*, percent */);
        MiddleLeftMotor.set_velocity_custom_controller((0.0001 * (((Controller1.Axis3.position() + Controller1.Axis1.position()) * (Controller1.Axis3.position() + Controller1.Axis1.position())) * (Controller1.Axis3.position() + Controller1.Axis1.position()))) /*, percent */);
        MiddleRightMotor.set_velocity_custom_controller((0.0001 * (((Controller1.Axis3.position() - Controller1.Axis1.position()) * (Controller1.Axis3.position() - Controller1.Axis1.position())) * (Controller1.Axis3.position() - Controller1.Axis1.position()))) /*, percent */);

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}