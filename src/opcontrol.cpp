#include "vex.h"
#include "auton.h"
#include "sylib/sylib.hpp"
#include "robot-config.h"

using namespace vex;

void opControl(){

  Brain.Screen.drawImageFromFile("brainbanner.png", 0, 0);

  // User control code here, inside the loop
  while (1)
  { 
        // x₁ = Left Motor X = [Controller] [3] position + [Controller] [1] position
        // x₂ = Right Motor X = [Controller] [3] position - [Controller] [1] position
        // Sets each motor's velocity (in rpm) to 0.0001x³ (shown as 0.0001 * x * x * x)
        FrontLeftMotor.setVelocity((0.0001 * (((Controller1.Axis3.position() + Controller1.Axis1.position()) * (Controller1.Axis3.position() + Controller1.Axis1.position())) * (Controller1.Axis3.position() + Controller1.Axis1.position()))), percent);
        BackLeftMotor.setVelocity((0.0001 * (((Controller1.Axis3.position() + Controller1.Axis1.position()) * (Controller1.Axis3.position() + Controller1.Axis1.position())) * (Controller1.Axis3.position() + Controller1.Axis1.position()))), percent);
        FrontRightMotor.setVelocity((0.0001 * (((Controller1.Axis3.position() - Controller1.Axis1.position()) * (Controller1.Axis3.position() - Controller1.Axis1.position())) * (Controller1.Axis3.position() - Controller1.Axis1.position()))), percent);
        BackRightMotor.setVelocity((0.0001 * (((Controller1.Axis3.position() - Controller1.Axis1.position()) * (Controller1.Axis3.position() - Controller1.Axis1.position())) * (Controller1.Axis3.position() - Controller1.Axis1.position()))), percent);
        MiddleLeftMotor.setVelocity((0.0001 * (((Controller1.Axis3.position() - Controller1.Axis1.position()) * (Controller1.Axis3.position() - Controller1.Axis1.position())) * (Controller1.Axis3.position() + Controller1.Axis1.position()))), percent);
        MiddleRightMotor.setVelocity((0.0001 * (((Controller1.Axis3.position() - Controller1.Axis1.position()) * (Controller1.Axis3.position() - Controller1.Axis1.position())) * (Controller1.Axis3.position() - Controller1.Axis1.position()))), percent);
        // Spins motor according to the velocity set
        FrontLeftMotor.spin(forward);
        BackLeftMotor.spin(forward);
        MiddleLeftMotor.spin(forward);
        FrontRightMotor.spin(forward);
        BackRightMotor.spin(forward);
        MiddleRightMotor.spin(forward);

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}