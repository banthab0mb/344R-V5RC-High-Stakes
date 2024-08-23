/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Henry Rudowski                                            */
/*    Created:      6/5/2024, 8:09:26 AM                                      */
/*    Description:  344R High Stakes Code                                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "sylib/sylib.hpp"

using namespace vex;

// Driver's controller initalization
controller Controller1 = controller(primary);

// Motor controller for the drivetrain
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

auto FrontLeftMotor = sylib::Motor(1, 600, true, drivetrain_motor_controller);
auto BackLeftMotor = sylib::Motor(2, 600, true, drivetrain_motor_controller);
auto MiddleLeftMotor = sylib::Motor(3, 600, false, drivetrain_motor_controller);
auto FrontRightMotor = sylib::Motor(4, 600, false, drivetrain_motor_controller);
auto BackRightMotor = sylib::Motor(5, 600, false, drivetrain_motor_controller);
auto MiddleRightMotor = sylib::Motor(6, 600, true, drivetrain_motor_controller);


// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Function                          */
/*---------------------------------------------------------------------------*/

void pre_auton(void)
{
  sylib::initialize(); // initialize the library

  // Create an addrled object
  auto addrled = sylib::Addrled(1, 1, 64);

  // Set the LED strip to a gradient in HSV color space
  // that displays a full range of hues
  addrled.gradient(0xFF0000, 0xFF0005, 0, 0, false, true);

  // Cycle the colors at speed 10
  addrled.cycle(*addrled, 10);

  // PRE AUTON CODE HERE:
}

/*---------------------------------------------------------------------------*/
/*                              Autonomous Task                              */
/*---------------------------------------------------------------------------*/

void autonomous(void)
{
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                              User Control Task                            */
/*---------------------------------------------------------------------------*/

void usercontrol(void)
{
  sylib::delay(2000); // Wait for 2 seconds before starting the drivetrain motors

  // Set the motors to spin at 150 RPM for 5 seconds using the 
  // custom speed controller
  FrontLeftMotor.set_velocity_custom_controller(150); 
  BackLeftMotor.set_velocity_custom_controller(150);
  MiddleLeftMotor.set_velocity_custom_controller(150);
  FrontRightMotor.set_velocity_custom_controller(150);
  BackRightMotor.set_velocity_custom_controller(150);
  MiddleRightMotor.set_velocity_custom_controller(150);
  sylib::delay(5000);
  FrontLeftMotor.stop();
  BackLeftMotor.stop();
  MiddleLeftMotor.stop();
  FrontRightMotor.stop();
  BackRightMotor.stop();
  MiddleRightMotor.stop();

  // User control code here, inside the loop
  while (1)
  { 
        // x₁ = Left Motor X = [Controller] [3] position + [Controller] [1] position
        // x₂ = Right Motor X = [Controller] [3] position - [Controller] [1] position
        // Sets each motor's velocity (in rpm) to 0.0001x³ (shown as 0.0001 * x * x * x)
        FrontLeftMotor.set_velocity_custom_controller((0.0001 * (((Controller1.Axis3.position() + Controller1.Axis1.position()) * (Controller1.Axis3.position() + Controller1.Axis1.position())) * (Controller1.Axis3.position() + Controller1.Axis1.position()))) /*, percent*/ );
        BackLeftMotor.set_velocity_custom_controller((0.0001 * (((Controller1.Axis3.position() + Controller1.Axis1.position()) * (Controller1.Axis3.position() + Controller1.Axis1.position())) * (Controller1.Axis3.position() + Controller1.Axis1.position()))) /*, percent */);
        FrontRightMotor.set_velocity_custom_controller((0.0001 * (((Controller1.Axis3.position() - Controller1.Axis1.position()) * (Controller1.Axis3.position() - Controller1.Axis1.position())) * (Controller1.Axis3.position() - Controller1.Axis1.position()))) /*, percent */);
        BackRightMotor.set_velocity_custom_controller((0.0001 * (((Controller1.Axis3.position() - Controller1.Axis1.position()) * (Controller1.Axis3.position() - Controller1.Axis1.position())) * (Controller1.Axis3.position() - Controller1.Axis1.position()))) /*, percent */);
   
  
   
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
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
