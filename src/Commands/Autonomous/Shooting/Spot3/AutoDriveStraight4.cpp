// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include <Commands/Autonomous/Shooting/Spot3/AutoDriveStraight4.h>

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

AutoDriveStraight4::AutoDriveStraight4(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void AutoDriveStraight4::Initialize() {
	NoDriveIt();
}

// Called repeatedly when this Command is scheduled to run
void AutoDriveStraight4::Execute() {
	DriveIt();
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveStraight4::IsFinished() {
return false;
/*	float encDist = (Robot::driveTrain->lf->GetEncPosition()*25.12 + Robot::driveTrain->lr->GetEncPosition()*25.12 + Robot::driveTrain->rf->GetEncPosition()*25.12 + Robot::driveTrain->rr->GetEncPosition()*25.12) / 4;
	if(encDist >9){
		return true;
	}
	else{
	return false;
	}
	*/
}

// Called once after isFinished returns true
void AutoDriveStraight4::End() {
	NoDriveIt();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveStraight4::Interrupted() {

}
void AutoDriveStraight4::DriveIt(){
	Robot::driveTrain->takeJoystickInputs(0.0, 0.55, 0.0, 0.0);
	//RobotMap::ballFeederBallFeederSpike->Set(Relay::Value::kForward*0.7);
}
void AutoDriveStraight4::NoDriveIt(){

	Robot::driveTrain->takeJoystickInputs(0.0, 0.0, 0.0, 0.0);
}
