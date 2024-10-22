#include "vex.h"
#include "auton.h"
#include "sylib/sylib.hpp"
#include "robot-config.h"
#include "pre-auton.h"

using namespace vex;

// Auton drive functions
void driveForward(double Distance /* distance in inches divided by wheel circ (8.6394)*/ ) {
  FrontLeftMotor.spinFor(forward, Distance/8.6394, turns, false);
  BackLeftMotor.spinFor(forward, Distance/8.6394, turns, false);
  MiddleLeftMotor.spinFor(forward, Distance/8.6394, turns, false);
  FrontRightMotor.spinFor(forward, Distance/8.6394, turns, false);
  BackRightMotor.spinFor(forward, Distance/8.6394, turns, false);
  MiddleRightMotor.spinFor(forward, Distance/8.6394, turns);

  // waits to return until all motors are stopped moving
  while(FrontLeftMotor.isSpinning() || BackLeftMotor.isSpinning() || MiddleLeftMotor.isSpinning() || 
          FrontRightMotor.isSpinning() || BackRightMotor.isSpinning() || MiddleRightMotor.isSpinning()) {
        wait(10, msec);
    }
}

void driveReverse(double Distance /* distance in inches divided by wheel circ (8.6394)*/ ) {
  FrontLeftMotor.spinFor(reverse, Distance/8.6394, turns, false);
  BackLeftMotor.spinFor(reverse, Distance/8.6394, turns, false);
  MiddleLeftMotor.spinFor(reverse, Distance/8.6394, turns, false);
  FrontRightMotor.spinFor(reverse, Distance/8.6394, turns, false);
  BackRightMotor.spinFor(reverse, Distance/8.6394, turns, false);
  MiddleRightMotor.spinFor(reverse, Distance/8.6394, turns);

  // waits to return until all motors are stopped moving
  while(FrontLeftMotor.isSpinning() || BackLeftMotor.isSpinning() || MiddleLeftMotor.isSpinning() || 
          FrontRightMotor.isSpinning() || BackRightMotor.isSpinning() || MiddleRightMotor.isSpinning()) {
        wait(10, msec);
    }
}

void turnLeft(double Degrees) {
    // Calculate the distance each wheel needs to travel to turn left by the specified number of degrees
    double wheelCircumference = 8.6394; // Wheel circumference in inches
    double distance = (wheelCircumference * Degrees) / 360; // Calculate the distance traveled by each wheel

    // Spin motors for left turn
    FrontLeftMotor.spinFor(reverse, distance, turns, false);
    BackLeftMotor.spinFor(reverse, distance, turns, false);
    MiddleLeftMotor.spinFor(reverse, distance, turns, false);
    FrontRightMotor.spinFor(forward, distance, turns, false);
    BackRightMotor.spinFor(forward, distance, turns, false);
    MiddleRightMotor.spinFor(forward, distance, turns, true);
}

void turnRight(double Degrees) {
    // Calculate the distance each wheel needs to travel to turn right by the specified number of degrees
    double wheelCircumference = 8.6394; // Wheel circumference in inches
    double distance = (wheelCircumference * Degrees) / 360; // Calculate the distance traveled by each wheel

    // Spin motors for right turn
    FrontLeftMotor.spinFor(forward, distance, turns, false);
    BackLeftMotor.spinFor(forward, distance, turns, false);
    MiddleLeftMotor.spinFor(forward, distance, turns, false);
    FrontRightMotor.spinFor(reverse, distance, turns, false);
    BackRightMotor.spinFor(reverse, distance, turns, false);
    MiddleRightMotor.spinFor(reverse, distance, turns, true);
}

void speed(double inputRPM) {
  FrontLeftMotor.setVelocity(inputRPM, rpm);
  BackLeftMotor.setVelocity(inputRPM, rpm);
  MiddleLeftMotor.setVelocity(inputRPM, rpm);
  FrontRightMotor.setVelocity(inputRPM, rpm);
  BackRightMotor.setVelocity(inputRPM, rpm);
  MiddleRightMotor.setVelocity(inputRPM, rpm);
}

// Auton code

void auton()
{
  if(autonToRun == 0) // Red mogo
    {
      Brain.Screen.clearScreen();
      Brain.Screen.drawImageFromFile("brainbanner.png", 0, 0);
      
    speed(500);
    driveForward(18);
    

    }

    if(autonToRun == 1) // Red wall
    {
      Brain.Screen.clearScreen();
      Brain.Screen.drawImageFromFile("brainbanner.png", 0, 0);

    }

    if(autonToRun == 2) // Blue mogo
    {
      Brain.Screen.print("3");
    }

    if(autonToRun == 3) // Blue wall
    {
      Brain.Screen.print("4");
    }

}
