#ifndef ROBOT_CONFIG_H
#define ROBOT_CONFIG_H

#include "vex.h"
#include "sylib/motor.hpp"

using namespace vex;

extern controller Controller1;

extern brain Brain;

extern motor FrontLeftMotor;
extern motor FrontRightMotor;
extern motor BackLeftMotor;
extern motor BackRightMotor;
extern motor MiddleLeftMotor;
extern motor MiddleRightMotor;

extern digital_out clamp;

#endif