#include "vex.h"
#include "auton.h"
#include "sylib/sylib.hpp"
#include "motor.hpp"
#include "robot-config.h"
#include "sylib/motor.hpp"

using namespace vex;

// // Driver's controller initalization
controller Controller1 = controller(primary);

// // Motor controller for the drivetrain
sylib::SpeedControllerInfo drivetrain_motor_controller(
    [](double rpm)
    { return 5; }, // kV function
    1,             // kP
    1,             // kI
    1,             // kD
    1,             // kH
    true,         // anti-windup enabled
    0,             // anti-windup range
    false,         // p controller bounds threshold enabled
    0,             // p controller bounds cutoff enabled
    1,             // kP2 for when over threshold
    0              // range to target to apply max voltage
);

sylib::Motor FrontLeftMotor(1, 600, true, drivetrain_motor_controller);
// auto BackLeftMotor = sylib::Motor(2, 600, true, drivetrain_motor_controller);
// auto MiddleLeftMotor = sylib::Motor(3, 600, false, drivetrain_motor_controller);
// auto FrontRightMotor = sylib::Motor(4, 600, false, drivetrain_motor_controller);
// auto BackRightMotor = sylib::Motor(5, 600, false, drivetrain_motor_controller);
// auto MiddleRightMotor =  sylib::Motor(6, 600, true, drivetrain_motor_controller);