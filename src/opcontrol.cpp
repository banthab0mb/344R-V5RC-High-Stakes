#include "vex.h"
#include "auton.h"
#include "sylib/sylib.hpp"
#include "robot-config.h"

using namespace vex;

// Mogo clamp code
bool l1PressState;
  void l1Press() {
  l1PressState = !l1PressState;
  if (l1PressState) {
    clamp.set(true);
  } else {
    clamp.set(false);
  }

}

void intakeControl() {
  if (Controller1.ButtonR1.pressing()) {
  intake.spin(forward, 100, percent);
  }
}

void conveyorControl() {
  if (Controller1.ButtonR2.pressing()) {
  conveyor.spin(forward, 100, percent);
  }
}

void opControl(){

  Brain.Screen.drawImageFromFile("brainbanner.png", 0, 0);

  // Mogo clamp controller toggle
  Controller1.ButtonL1.pressed(l1Press);

  // Intake and conveyor control
  intakeControl();
  conveyorControl();

  // Driving code inside while loop
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