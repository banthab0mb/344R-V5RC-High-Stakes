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

// auton selector variable
int autonToRun = 0;

/*
TODO:
Auton Selctor - DONE
Driver control file - DONE
Test driving - DONE
Create auton(s)
Get LEDS and set them up
*/


// A global instance of competition
competition Competition;


// Pre-Autonomous Function

void pre_auton(void)
{
  sylib::initialize(); // initialize the library

  // Pre Auton file is called:

  preAuton();

}

// Autonomous Task

void autonomous(void)
{
  auton();
}

// User Control Task


void userControl(void)
{
  // usercontrol function is called:
  opControl();
}

//
// Competition functions and callbacks.
//
int main()
{
  competition Competition;

  Competition.autonomous(autonomous);
  Competition.drivercontrol(userControl);

  while(true)
  {
    if(!Competition.isEnabled())
    {
      Brain.Screen.clearScreen(white);
      for(int i = 0; i < 4; i++)
      {
        autonButtons[i].render();
        if(autonButtons[i].isClicked())
        {
          autonButtons[autonToRun].buttonColor = white;
          autonButtons[i].buttonColor = green;
          autonToRun = i;
        }
      }
    }

    Brain.Screen.render();
    vex::task::sleep(7);
  }
}
