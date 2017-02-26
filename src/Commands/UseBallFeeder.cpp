// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "UseBallFeeder.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

UseBallFeeder::UseBallFeeder(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::ballFeeder.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void UseBallFeeder::Initialize() {
	DoNotFeedIt();
	//RobotMap::ballFeederBallFeederSpike->Set(Relay::kOff);
}

// Called repeatedly when this Command is scheduled to run
void UseBallFeeder::Execute() {
	FeedIt();
	//RobotMap::ballFeederBallFeederSpike->Set(Relay::kForward);
}

// Make this return true when this Command no longer needs to run execute()
bool UseBallFeeder::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void UseBallFeeder::End() {
	DoNotFeedIt();
	//RobotMap::ballFeederBallFeederSpike->Set(Relay::kOff);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UseBallFeeder::Interrupted() {
	DoNotFeedIt();
	//RobotMap::ballFeederBallFeederSpike->Set(Relay::kOff);
}

void UseBallFeeder::FeedIt(){
	RobotMap::ballFeederBallFeederSpike->Set(0.5);
	RobotMap::ballSubFeeder->Set(0.75);
	//RobotMap::ballFeederBallFeederSpike->Set(Relay::Value::kForward*0.7);
}
void UseBallFeeder::DoNotFeedIt(){
	RobotMap::ballFeederBallFeederSpike->Set(0);
	RobotMap::ballSubFeeder->Set(0);
}








