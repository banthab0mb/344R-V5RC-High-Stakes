#include "vex.h"
#include "auton.h"
#include "sylib/sylib.hpp"
#include "robot-config.h"
#include "sylib/motor.hpp"

using namespace vex;

brain Brain;


// // Driver's controller initalization
controller Controller1 = controller(primary);

motor FrontLeftMotor(PORT1, gearSetting::ratio6_1, true);
motor BackLeftMotor(PORT2, gearSetting::ratio6_1, true);
motor MiddleLeftMotor(PORT3, gearSetting::ratio6_1, true);
motor FrontRightMotor(PORT4, gearSetting::ratio6_1, false);
motor BackRightMotor(PORT5, gearSetting::ratio6_1, false);
motor MiddleRightMotor(PORT6, gearSetting::ratio6_1, false);

motor intake(PORT7, gearSetting::ratio36_1, false);
motor conveyor(PORT8, gearSetting::ratio36_1, true);

digital_out clamp = digital_out(Brain.ThreeWirePort.B);

