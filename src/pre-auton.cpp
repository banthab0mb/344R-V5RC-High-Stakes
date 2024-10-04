#include "vex.h"
#include "auton.h"
#include "sylib/sylib.hpp"
#include "robot-config.h"
#include "pre-auton.h"

using namespace vex;


// configures buttons
Button autonButtons[] = {
  Button(10, 10, 150, 50, "Right Rush", green, black),
  Button(170, 10, 150, 50, "Right Main", white, black),
  Button(10, 70, 150, 50, "Left Win Pt", white, black),
  Button(170, 70, 150, 50, "Left Normal", white, black)
};


void preAuton(){
  // All activities that occur before the start of the autonomous phase should be placed here.

  // Create an addrled object
  auto underGlow = sylib::Addrled(22, 1, 64);

  // Set the LED strip to a gradient in HSV color space
  // that displays a full range of hues
  underGlow.gradient(0xFF0000, 0xFF0005, 0, 0, false, true);

  // Cycle the colors at speed 10
  underGlow.cycle(*underGlow, 10);

}