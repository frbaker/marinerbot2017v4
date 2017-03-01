// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include <ctime>
#include "AutonomousCommand.h"
#include "FireBalls.h"
#include"Autonomous/Auton1.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

AutonomousCommand::AutonomousCommand(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain.get());

}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void AutonomousCommand::Initialize() {


	setAutonStep(1); // initialize on step 1
	setUsedEncDist(0.0); //our traveled distance starts at zero
	SetTimeout(15); //set a 15 second timeout

	double startTime = Timer::GetFPGATimestamp();
	//std::time_t pstartTime = std::time(0); //use for practice periods only
	SmartDashboard::PutNumber("Auton StartTime", startTime);
}

// Called repeatedly when this Command is scheduled to run
void AutonomousCommand::Execute() {
	//double gearSideRange = RobotMap::gearSideUltra->GetRangeMM(); // reads the range on the ultrasonic sensor
	//double nonGearSideRange = RobotMap::nonGearSideUltra->GetRangeMM(); // reads the range on the ultrasonic sensor

	int autonNumber = SmartDashboard::GetNumber("autonNumber",1);

	switch(autonNumber){
	case 1:
		//position 1:Blue
		auton1();
		break;
	case 2:
		//position 2:Blue
		auton2();
		break;
	case 3:
		//position 3:Blue
		auton3();
		break;
	case 4:
		//position 1:Red
		auton4();
		break;
	case 5:
		//position 2:Red
		auton5();
		break;
	case 6:
		//position 3:Red
		break;
	default:
		auton1();
		break;
}

}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousCommand::IsFinished() {
    return IsTimedOut();
	//return false;
}

// Called once after isFinished returns true
void AutonomousCommand::End() {
	Robot::driveTrain->autoDrive(0.0, 0.0, 0.0, 0.0); //full stop
	RobotMap::ballVibrator->Set(0.0); //stop
	Robot::shooter->shooterMotor->Set(0.0); //stop
	RobotMap::ballFeederBallFeederSpike->Set(0.0); //stop
	RobotMap::ballSubFeeder->Set(0.0); //stop




}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousCommand::Interrupted() {

}
/*void AutonomousCommand::auton1(){s
	Robot::shooter->justShootMe();

}
*/



void AutonomousCommand::setAutonStep(int nextStep){
	autonStep = nextStep;
}
int AutonomousCommand::getAutonStep(){
	return autonStep;
}
void AutonomousCommand::setUsedEncDist(float totalDist){
	usedEncDist = totalDist;
}
float AutonomousCommand::getUsedEncDist(){
	return usedEncDist;
}





void AutonomousCommand::auton1(){
	/*
	 * 1. Drive Forward 60% speed for 9 inches
	 */
	if (getAutonStep() == 1){
		if(Robot::driveTrain->ReturnEncoderDistance()-getUsedEncDist() < 9){
			Robot::driveTrain->autoDrive(0.0, 0.6, 0.0, RobotMap::drivegyro->GetAngle());
		}
		else {
			Robot::driveTrain->autoDrive(0.0, 0.0, 0.0, 0.0); //full stop
			setAutonStep(getAutonStep() + 1);  //go to next step
			SmartDashboard::PutNumber("Routine1 End1 EncDist", getUsedEncDist()); //show us the average encoder distance values
			setUsedEncDist(Robot::driveTrain->ReturnEncoderDistance()); //record used Encoder Distance at end of step 1
		}
	}

	/*
	 * 2. Turn left till we reach -90 degrees
	 */
	if (getAutonStep() == 2){
		if(RobotMap::drivegyro->GetAngle() > -90){
			Robot::driveTrain->autoDrive(0.0, 0.0, -0.3, 0.0);
		}
		else{
			Robot::driveTrain->autoDrive(0.0, 0.0, 0.0, 0.0); //full stop
			setAutonStep(getAutonStep() + 1); //go to next step
			SmartDashboard::PutNumber("Routine1 End2 EncDist", Robot::driveTrain->ReturnEncoderDistance());
			SmartDashboard::PutNumber("Routine1 End2 Angle", RobotMap::drivegyro->GetAngle());
			setUsedEncDist(Robot::driveTrain->ReturnEncoderDistance()); //record used Encoder Distance at end of step 2
		}
	}

	/*
	 * 3. Drive Forward 60% speed for 216 inches
	 */
	if (getAutonStep() == 3){
		if(Robot::driveTrain->ReturnEncoderDistance()-getUsedEncDist() < 216){
			//get our current encDistance - should add a sanity check to keep from looping forever if we don't get a sensor reading
			Robot::driveTrain->autoDrive(0.0, 0.6, 0.0, RobotMap::drivegyro->GetAngle());
		}
		else{
			Robot::driveTrain->autoDrive(0.0, 0.0, 0.0, 0.0); //full stop
			setAutonStep(getAutonStep() + 1); //go to next step
			SmartDashboard::PutNumber("Routine1 End3 EncDist", Robot::driveTrain->ReturnEncoderDistance());
			setUsedEncDist(Robot::driveTrain->ReturnEncoderDistance()); //record used Encoder Distance at end of step 3
		}
	}

	/*
	 * 4. Turn left another -36 degrees till we reach -126
	 */
	if (getAutonStep() == 4){
		if(RobotMap::drivegyro->GetAngle() > -126){
			Robot::driveTrain->autoDrive(0.0, 0.0, -0.3, 0.0);
		}
		else{
			Robot::driveTrain->autoDrive(0.0, 0.0, 0.0, 0.0); //full stop
			setAutonStep(getAutonStep() + 1); //go to next step
			SmartDashboard::PutNumber("Routine1 End4 EncDist", Robot::driveTrain->ReturnEncoderDistance());
			SmartDashboard::PutNumber("Routine1 End4 Angle", RobotMap::drivegyro->GetAngle());
			setUsedEncDist(Robot::driveTrain->ReturnEncoderDistance()); //record used Encoder Distance at end of step 2
		}
	}
	/*
	 * 5. Start the shooter, subshooter, ball vibrator, and x-mas tree
	 */
	if (getAutonStep() == 5){
		if(RobotMap::drivegyro->GetAngle() > -126){
			RobotMap::ballVibrator->Set(0.25);
			Robot::shooter->shooterMotor->Set(0.7);
			RobotMap::ballFeederBallFeederSpike->Set(0.5);
			RobotMap::ballSubFeeder->Set(0.75);
		}
		else{
			RobotMap::ballVibrator->Set(0.0); //stop
			Robot::shooter->shooterMotor->Set(0.0); //stop
			RobotMap::ballFeederBallFeederSpike->Set(0.0); //stop
			RobotMap::ballSubFeeder->Set(0.0); //stop
			setAutonStep(getAutonStep() + 1); //go to next step
			SmartDashboard::PutNumber("Routine1 End4 EncDist", Robot::driveTrain->ReturnEncoderDistance());
			SmartDashboard::PutNumber("Routine1 End4 Angle", RobotMap::drivegyro->GetAngle());
			setUsedEncDist(Robot::driveTrain->ReturnEncoderDistance()); //record used Encoder Distance at end of step 2
		}
	}
}

void AutonomousCommand::auton2(){
	/*
	 * 1. Drive Forward 60% speed for 9 inches
	 */
	if (getAutonStep() == 1){
		if(Robot::driveTrain->ReturnEncoderDistance()-getUsedEncDist() < 9){
			Robot::driveTrain->autoDrive(0.0, 0.6, 0.0, RobotMap::drivegyro->GetAngle());
		}
		else {
			setAutonStep(getAutonStep() + 1);  //go to next step
			SmartDashboard::PutNumber("Routine1 End1 EncDist", getUsedEncDist()); //show us the average encoder distance values
			setUsedEncDist(Robot::driveTrain->ReturnEncoderDistance()); //record used Encoder Distance at end of step 1
		}
	}

	/*
	 * 2. Turn left till we reach -90 degrees
	 */
	if (getAutonStep() == 2){
		if(RobotMap::drivegyro->GetAngle() > -90){
			Robot::driveTrain->autoDrive(0.0, 0.0, -0.3, 0.0);
		}
		else{
			setAutonStep(getAutonStep() + 1); //go to next step
			SmartDashboard::PutNumber("Routine1 End2 EncDist", Robot::driveTrain->ReturnEncoderDistance());
			SmartDashboard::PutNumber("Routine1 End2 Angle", RobotMap::drivegyro->GetAngle());
			setUsedEncDist(Robot::driveTrain->ReturnEncoderDistance()); //record used Encoder Distance at end of step 2
		}
	}

	/*
	 * 3. Drive Forward 60% speed for 216 inches
	 */
	if (getAutonStep() == 3){
		if(Robot::driveTrain->ReturnEncoderDistance()-getUsedEncDist() < 216){
			//get our current encDistance - should add a sanity check to keep from looping forever if we don't get a sensor reading
			Robot::driveTrain->autoDrive(0.0, 0.6, 0.0, RobotMap::drivegyro->GetAngle());
		}
		else{
			setAutonStep(getAutonStep() + 1); //go to next step
			SmartDashboard::PutNumber("Routine1 End3 EncDist", Robot::driveTrain->ReturnEncoderDistance());
			setUsedEncDist(Robot::driveTrain->ReturnEncoderDistance()); //record used Encoder Distance at end of step 3
		}
	}

	/*
	 * 4. Turn left another -36 degrees till we reach -126
	 *
	 */
	if (getAutonStep() == 4){
		if(RobotMap::drivegyro->GetAngle() > -126){
			Robot::driveTrain->autoDrive(0.0, 0.0, -0.3, 0.0);
		}
		else{
			setAutonStep(getAutonStep() + 1); //go to next step
			SmartDashboard::PutNumber("Routine1 End4 EncDist", Robot::driveTrain->ReturnEncoderDistance());
			SmartDashboard::PutNumber("Routine1 End4 Angle", RobotMap::drivegyro->GetAngle());
			setUsedEncDist(Robot::driveTrain->ReturnEncoderDistance()); //record used Encoder Distance at end of step 2
		}
	}
}
void AutonomousCommand::auton3(){
	/*
	 * 1. Drive Forward 60% speed for 9 inches
	 */
	if (getAutonStep() == 1){
		if(Robot::driveTrain->ReturnEncoderDistance()-getUsedEncDist() < 9){
			Robot::driveTrain->autoDrive(0.0, 0.6, 0.0, RobotMap::drivegyro->GetAngle());
		}
		else {
			setAutonStep(getAutonStep() + 1);  //go to next step
			SmartDashboard::PutNumber("Routine1 End1 EncDist", getUsedEncDist()); //show us the average encoder distance values
			setUsedEncDist(Robot::driveTrain->ReturnEncoderDistance()); //record used Encoder Distance at end of step 1
		}
	}

	/*
	 * 2. Turn left till we reach -90 degrees
	 */
	if (getAutonStep() == 2){
		if(RobotMap::drivegyro->GetAngle() > -90){
			Robot::driveTrain->autoDrive(0.0, 0.0, -0.3, 0.0);
		}
		else{
			setAutonStep(getAutonStep() + 1); //go to next step
			SmartDashboard::PutNumber("Routine1 End2 EncDist", Robot::driveTrain->ReturnEncoderDistance());
			SmartDashboard::PutNumber("Routine1 End2 Angle", RobotMap::drivegyro->GetAngle());
			setUsedEncDist(Robot::driveTrain->ReturnEncoderDistance()); //record used Encoder Distance at end of step 2
		}
	}

	/*
	 * 3. Drive Forward 60% speed for 216 inches
	 */
	if (getAutonStep() == 3){
		if(Robot::driveTrain->ReturnEncoderDistance()-getUsedEncDist() < 216){
			//get our current encDistance - should add a sanity check to keep from looping forever if we don't get a sensor reading
			Robot::driveTrain->autoDrive(0.0, 0.6, 0.0, RobotMap::drivegyro->GetAngle());
		}
		else{
			setAutonStep(getAutonStep() + 1); //go to next step
			SmartDashboard::PutNumber("Routine1 End3 EncDist", Robot::driveTrain->ReturnEncoderDistance());
			setUsedEncDist(Robot::driveTrain->ReturnEncoderDistance()); //record used Encoder Distance at end of step 3
		}
	}

	/*
	 * 4. Turn left another -36 degrees till we reach -126
	 *
	 */
	if (getAutonStep() == 4){
		if(RobotMap::drivegyro->GetAngle() > -126){
			Robot::driveTrain->autoDrive(0.0, 0.0, -0.3, 0.0);
		}
		else{
			setAutonStep(getAutonStep() + 1); //go to next step
			SmartDashboard::PutNumber("Routine1 End4 EncDist", Robot::driveTrain->ReturnEncoderDistance());
			SmartDashboard::PutNumber("Routine1 End4 Angle", RobotMap::drivegyro->GetAngle());
			setUsedEncDist(Robot::driveTrain->ReturnEncoderDistance()); //record used Encoder Distance at end of step 2
		}
}
}
void AutonomousCommand::auton4(){
	/*
	 * 1. Drive Forward 60% speed for 9 inches
	 */
	if (getAutonStep() == 1){
		if(Robot::driveTrain->ReturnEncoderDistance()-getUsedEncDist() < 9){
			Robot::driveTrain->autoDrive(0.0, 0.6, 0.0, RobotMap::drivegyro->GetAngle());
		}
		else {
			setAutonStep(getAutonStep() + 1);  //go to next step
			SmartDashboard::PutNumber("Routine1 End1 EncDist", getUsedEncDist()); //show us the average encoder distance values
			setUsedEncDist(Robot::driveTrain->ReturnEncoderDistance()); //record used Encoder Distance at end of step 1
		}
	}

	/*
	 * 2. Turn left till we reach -90 degrees
	 */
	if (getAutonStep() == 2){
		if(RobotMap::drivegyro->GetAngle() > -90){
			Robot::driveTrain->autoDrive(0.0, 0.0, -0.3, 0.0);
		}
		else{
			setAutonStep(getAutonStep() + 1); //go to next step
			SmartDashboard::PutNumber("Routine1 End2 EncDist", Robot::driveTrain->ReturnEncoderDistance());
			SmartDashboard::PutNumber("Routine1 End2 Angle", RobotMap::drivegyro->GetAngle());
			setUsedEncDist(Robot::driveTrain->ReturnEncoderDistance()); //record used Encoder Distance at end of step 2
		}
	}

	/*
	 * 3. Drive Forward 60% speed for 216 inches
	 */
	if (getAutonStep() == 3){
		if(Robot::driveTrain->ReturnEncoderDistance()-getUsedEncDist() < 216){
			//get our current encDistance - should add a sanity check to keep from looping forever if we don't get a sensor reading
			Robot::driveTrain->autoDrive(0.0, 0.6, 0.0, RobotMap::drivegyro->GetAngle());
		}
		else{
			setAutonStep(getAutonStep() + 1); //go to next step
			SmartDashboard::PutNumber("Routine1 End3 EncDist", Robot::driveTrain->ReturnEncoderDistance());
			setUsedEncDist(Robot::driveTrain->ReturnEncoderDistance()); //record used Encoder Distance at end of step 3
		}
	}

	/*
	 * 4. Turn left another -36 degrees till we reach -126
	 *
	 */
	if (getAutonStep() == 4){
		if(RobotMap::drivegyro->GetAngle() > -126){
			Robot::driveTrain->autoDrive(0.0, 0.0, -0.3, 0.0);
		}
		else{
			setAutonStep(getAutonStep() + 1); //go to next step
			SmartDashboard::PutNumber("Routine1 End4 EncDist", Robot::driveTrain->ReturnEncoderDistance());
			SmartDashboard::PutNumber("Routine1 End4 Angle", RobotMap::drivegyro->GetAngle());
			setUsedEncDist(Robot::driveTrain->ReturnEncoderDistance()); //record used Encoder Distance at end of step 2
		}
}
}
void AutonomousCommand::auton5(){
	/*
	 * 1. Drive Forward 60% speed for 9 inches
	 */
	if (getAutonStep() == 1){
		if(Robot::driveTrain->ReturnEncoderDistance()-getUsedEncDist() < 9){
			Robot::driveTrain->autoDrive(0.0, 0.6, 0.0, RobotMap::drivegyro->GetAngle());
		}
		else {
			setAutonStep(getAutonStep() + 1);  //go to next step
			SmartDashboard::PutNumber("Routine1 End1 EncDist", getUsedEncDist()); //show us the average encoder distance values
			setUsedEncDist(Robot::driveTrain->ReturnEncoderDistance()); //record used Encoder Distance at end of step 1
		}
	}

	/*
	 * 2. Turn left till we reach -90 degrees
	 */
	if (getAutonStep() == 2){
		if(RobotMap::drivegyro->GetAngle() > -90){
			Robot::driveTrain->autoDrive(0.0, 0.0, -0.3, 0.0);
		}
		else{
			setAutonStep(getAutonStep() + 1); //go to next step
			SmartDashboard::PutNumber("Routine1 End2 EncDist", Robot::driveTrain->ReturnEncoderDistance());
			SmartDashboard::PutNumber("Routine1 End2 Angle", RobotMap::drivegyro->GetAngle());
			setUsedEncDist(Robot::driveTrain->ReturnEncoderDistance()); //record used Encoder Distance at end of step 2
		}
	}

	/*
	 * 3. Drive Forward 60% speed for 216 inches
	 */
	if (getAutonStep() == 3){
		if(Robot::driveTrain->ReturnEncoderDistance()-getUsedEncDist() < 216){
			//get our current encDistance - should add a sanity check to keep from looping forever if we don't get a sensor reading
			Robot::driveTrain->autoDrive(0.0, 0.6, 0.0, RobotMap::drivegyro->GetAngle());
		}
		else{
			setAutonStep(getAutonStep() + 1); //go to next step
			SmartDashboard::PutNumber("Routine1 End3 EncDist", Robot::driveTrain->ReturnEncoderDistance());
			setUsedEncDist(Robot::driveTrain->ReturnEncoderDistance()); //record used Encoder Distance at end of step 3
		}
	}

	/*
	 * 4. Turn left another -36 degrees till we reach -126
	 *
	 */
	if (getAutonStep() == 4){
		if(RobotMap::drivegyro->GetAngle() > -126){
			Robot::driveTrain->autoDrive(0.0, 0.0, -0.3, 0.0);
		}
		else{
			setAutonStep(getAutonStep() + 1); //go to next step
			SmartDashboard::PutNumber("Routine1 End4 EncDist", Robot::driveTrain->ReturnEncoderDistance());
			SmartDashboard::PutNumber("Routine1 End4 Angle", RobotMap::drivegyro->GetAngle());
			setUsedEncDist(Robot::driveTrain->ReturnEncoderDistance()); //record used Encoder Distance at end of step 2
		}
}
}
void AutonomousCommand::auton6(){
	/*
	 * 1. Drive Forward 60% speed for 9 inches
	 */
	if (getAutonStep() == 1){
		if(Robot::driveTrain->ReturnEncoderDistance()-getUsedEncDist() < 9){
			Robot::driveTrain->autoDrive(0.0, 0.6, 0.0, RobotMap::drivegyro->GetAngle());
		}
		else {
			setAutonStep(getAutonStep() + 1);  //go to next step
			SmartDashboard::PutNumber("Routine1 End1 EncDist", getUsedEncDist()); //show us the average encoder distance values
			setUsedEncDist(Robot::driveTrain->ReturnEncoderDistance()); //record used Encoder Distance at end of step 1
		}
	}

	/*
	 * 2. Turn left till we reach -90 degrees
	 */
	if (getAutonStep() == 2){
		if(RobotMap::drivegyro->GetAngle() > -90){
			Robot::driveTrain->autoDrive(0.0, 0.0, -0.3, 0.0);
		}
		else{
			setAutonStep(getAutonStep() + 1); //go to next step
			SmartDashboard::PutNumber("Routine1 End2 EncDist", Robot::driveTrain->ReturnEncoderDistance());
			SmartDashboard::PutNumber("Routine1 End2 Angle", RobotMap::drivegyro->GetAngle());
			setUsedEncDist(Robot::driveTrain->ReturnEncoderDistance()); //record used Encoder Distance at end of step 2
		}
	}

	/*
	 * 3. Drive Forward 60% speed for 216 inches
	 */
	if (getAutonStep() == 3){
		if(Robot::driveTrain->ReturnEncoderDistance()-getUsedEncDist() < 216){
			//get our current encDistance - should add a sanity check to keep from looping forever if we don't get a sensor reading
			Robot::driveTrain->autoDrive(0.0, 0.6, 0.0, RobotMap::drivegyro->GetAngle());
		}
		else{
			setAutonStep(getAutonStep() + 1); //go to next step
			SmartDashboard::PutNumber("Routine1 End3 EncDist", Robot::driveTrain->ReturnEncoderDistance());
			setUsedEncDist(Robot::driveTrain->ReturnEncoderDistance()); //record used Encoder Distance at end of step 3
		}
	}

	/*
	 * 4. Turn left another -36 degrees till we reach -126
	 *
	 */
	if (getAutonStep() == 4){
		if(RobotMap::drivegyro->GetAngle() > -126){
			Robot::driveTrain->autoDrive(0.0, 0.0, -0.3, 0.0);
		}
		else{
			setAutonStep(getAutonStep() + 1); //go to next step
			SmartDashboard::PutNumber("Routine1 End4 EncDist", Robot::driveTrain->ReturnEncoderDistance());
			SmartDashboard::PutNumber("Routine1 End4 Angle", RobotMap::drivegyro->GetAngle());
			setUsedEncDist(Robot::driveTrain->ReturnEncoderDistance()); //record used Encoder Distance at end of step 2
		}
}
}


/*float AutonomousCommand::encoderValue(float lf_encoder, float lr_encoder, float rf_encoder, float rr_encoder, float encDistance ){

	lf_encoder = RobotMap::driveTrainLf->GetEncPosition()*25.12;
	lr_encoder = RobotMap::driveTrainLf->GetEncPosition()*25.12;

	rf_encoder = RobotMap::driveTrainLf->GetEncPosition()*25.12;
	rr_encoder = RobotMap::driveTrainLf->GetEncPosition()*25.12;


	encDistance = (lf_encoder + lr_encoder + rr_encoder + rf_encoder) / 2; //averages the values from all encoders
	return encDistance;


}
*/
