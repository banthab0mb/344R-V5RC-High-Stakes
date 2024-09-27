#ifndef ROBOT_CONFIG_H
#define ROBOT_CONFIG_H

#include "vex.h"
#include "sylib/motor.hpp"

using namespace vex;

extern controller Controller1;

extern brain Brain;

extern sylib::Motor FrontLeftMotor;
extern sylib::Motor FrontRightMotor;
extern sylib::Motor BackLeftMotor;
extern sylib::Motor BackRightMotor;
extern sylib::Motor MiddleLeftMotor;
extern sylib::Motor MiddleRightMotor;

#endif