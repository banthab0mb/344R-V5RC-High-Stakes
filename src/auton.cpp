#include "vex.h"
#include "auton.h"
#include "sylib/sylib.hpp"
#include "robot-config.h"
#include "pre-auton.h"

using namespace vex;

void auton()
{
  if(autonToRun == 0)
    {
      Brain.Screen.clearScreen();
      Brain.Screen.drawImageFromFile("brainbanner.png", 0, 0);

      // Set the motors to spin at 150 RPM for 5 seconds
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

    if(autonToRun == 1)
    {
      Brain.Screen.clearScreen();
      Brain.Screen.drawImageFromFile("brainbanner.png", 0, 0);

    }

    if(autonToRun == 2)
    {
      Brain.Screen.print("3");
    }

    if(autonToRun == 3)
    {
      Brain.Screen.print("4");
    }

}
