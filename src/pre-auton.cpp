#include "vex.h"
#include "auton.h"
#include "sylib/sylib.hpp"
#include "robot-config.h"

using namespace vex;

void preAuton(){
  // All activities that occur before the start of the autonomous phase should be placed here.

  // Brain screen logo
  Brain.Screen.drawImageFromFile("brainbanner.png", 0, 0);

  // Create an addrled object
  auto underGlow = sylib::Addrled(22, 1, 64);

  // Set the LED strip to a gradient in HSV color space
  // that displays a full range of hues
  underGlow.gradient(0xFF0000, 0xFF0005, 0, 0, false, true);

  // Cycle the colors at speed 10
  underGlow.cycle(*underGlow, 10);

}