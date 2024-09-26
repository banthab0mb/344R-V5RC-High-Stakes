/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Henry Rudowski                                            */
/*    Created:      6/5/2024, 8:09:26 AM                                      */
/*    Description:  344R High Stakes Code                                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "auton.h"
#include "sylib/sylib.hpp"
#include "robot-config.h"
#include "pre-auton.h"
#include "opcontrol.h"

using namespace vex;

/*
TODO:
Auton Selctor?
Driver control file
Test driving
Create auton
Get LEDS and set them up
*/


// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Function                          */
/*---------------------------------------------------------------------------*/

void pre_auton(void)
{
  sylib::initialize(); // initialize the library

  // Pre Auton file is called:

  preAuton();

}

/*---------------------------------------------------------------------------*/
/*                              Autonomous Task                              */
/*---------------------------------------------------------------------------*/

void autonomous(void)
{
  auton();
}

/*---------------------------------------------------------------------------*/
/*                              User Control Task                            */
/*---------------------------------------------------------------------------*/

void usercontrol(void)
{
  sylib::delay(2000); // Wait for 2 seconds before starting the drivetrain motors
  // usercontrol function is called:
  opControl();
}

//
// Competition functions and callbacks.
//
int main()
{
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true)
  {
    wait(100, msec);
  }
}
