// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "UseGearMover.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

UseGearMover::UseGearMover(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::gearMover.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	SetTimeout(1);

}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void UseGearMover::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void UseGearMover::Execute() {
	PushItOff();
	//RobotMap::gearMoverGearSparkMotor->Set(-0.35);
}

// Make this return true when this Command no longer needs to run execute()
bool UseGearMover::IsFinished() {
    return IsTimedOut();
    //If the 1 second set in the SetTmeout(1) above is done, this will return true
    //and program execution will go to the End() method.
	//return false;
}

// Called once after isFinished returns true
void UseGearMover::End() {
	DoNothing();
	//RobotMap::gearMoverGearSparkMotor->Set(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UseGearMover::Interrupted() {
	DoNothing();
	//RobotMap::gearMoverGearSparkMotor->Set(0);
}
void UseGearMover::PushItOff(){
	RobotMap::gearMoverGearSparkMotor->Set(-0.35);
}
void UseGearMover::DoNothing(){
	RobotMap::gearMoverGearSparkMotor->Set(0);
}
