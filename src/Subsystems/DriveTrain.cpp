// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "CANTalon.h"


#include "DriveTrain.h"
#include "../RobotMap.h"
#include "Commands/DriveWithJoy.h"
#include <AHRS.h>
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    //lf = RobotMap::driveTrainLf;

	lf = RobotMap::driveTrainLf;
    rf = RobotMap::driveTrainRf;
    lr = RobotMap::driveTrainLr;
    rr = RobotMap::driveTrainRr;
    mecanum = RobotMap::driveTrainMecanum;



    //dg = RobotMap::drivegyro;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

    table = NetworkTable::GetTable("piData");


    /*
     *
     * In the periodic for autonomous and periodic we'll do something like this to read the network tables
     *
     * while(true){
     * 	std::vector<double> arr = table-GetNumberArray("area", llvm::ArrayRef<double>());
     * 	for (unsigned int i = 0; i < arr.size(); i++){
     * 		std::cout << arr[i] << " ";
     * 	}
     * }
     */

   lf->SetFeedbackDevice(CANTalon::CtreMagEncoder_Absolute);
   lr->SetFeedbackDevice(CANTalon::CtreMagEncoder_Absolute);
   lr->SetSensorDirection(true);
   rf->SetFeedbackDevice(CANTalon::CtreMagEncoder_Absolute);
   rr->SetFeedbackDevice(CANTalon::CtreMagEncoder_Absolute);
   rr->SetSensorDirection(true);

    //gg = RobotMap::driveGyro;
//*********** Eclipse is stupid and is not recognizing these lf and rr things,
/*
    lf->SetFeedbackDevice(CANTalon::CtreMagEncoder_Absolute);
    //lf->SetSensorDirection(true);

    lr->SetFeedbackDevice(CANTalon::CtreMagEncoder_Absolute);
    lr->SetSensorDirection(true);

    rf->SetFeedbackDevice(CANTalon::CtreMagEncoder_Absolute);

    rr->SetFeedbackDevice(CANTalon::CtreMagEncoder_Absolute);
    rr->SetSensorDirection(true);
*/



/* Note, This does not work for PWM.
    lf->SetFeedbackDevice(TalonSRX::CtreMagEncoder_Absolute);
    //lf->SetSensorDirection(true);

    lr->SetFeedbackDevice(TalonSRX::CtreMagEncoder_Absolute);
    lr->SetSensorDirection(true);

    rf->SetFeedbackDevice(TalonSRX::CtreMagEncoder_Absolute);

    rr->SetFeedbackDevice(TalonSRX::CtreMagEncoder_Absolute);
    rr->SetSensorDirection(true);
*/



}

void DriveTrain::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

        SetDefaultCommand(new DriveWithJoy());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.




/*****Newly Added - Untested*******/
float DriveTrain::driveToAngle(double targetAngle){
	double turnAngle = angleToTurn(RobotMap::drivegyro->GetYaw(),targetAngle);

	int encClicksRev = 256; //need to know the encoder count per rev
	double myX = 0.0; //initialize as 0.0 so they are set if there is no joystick input
	double myY = 0.0;
	double myZ = 0.0;

	myX = Robot::oi->getJoystick1()->GetRawAxis(0);
	myY = Robot::oi->getJoystick1()->GetRawAxis(1);
	myZ = Robot::oi->getJoystick1()->GetRawAxis(2);


	if(turnAngle<4){
		//using this as a hack of PID control, until pid can be implemented


		DriveTrain::mecanum->MecanumDrive_Cartesian(turnAngle, myY, myZ, RobotMap::drivegyro->GetYaw());
		//DriveTrain::mecanum->MecanumDrive_Cartesian((double)myX, (double)myY, (double)myZ, calculatePID(targetAngle,-1*sqrt(RobotMap::drivegyro->GetYaw()),0.3,.06,0));
		//DriveTrain::mecanum->MecanumDrive_Cartesian(0.0, 0.0, 0.0,Drivetrain::calculatePID(targetAngle,-1*sqrt(RobotMap::drivegyro->GetYaw()),0.3,.06,0));
	}
	return RobotMap::drivegyro->GetAngle();
}
double DriveTrain::angleToTurn(double currentAngle, double targetAngle){
	double provisionalAngle = targetAngle-currentAngle;
	if(provisionalAngle>-180 && provisionalAngle<=180){
		return provisionalAngle;
	}
	else if(provisionalAngle>180){
		return provisionalAngle-360;
	}
	else if(provisionalAngle<=-180){
		return provisionalAngle+360;
	}

	//should never get here
	return provisionalAngle;
}
double DriveTrain::calculatePID(double setpoint, double current, double Kp, double Ki, double Kd){
	float f;
	double previousIVal, previous;
	double encoderAngle = (-285.5-current)*(3.1415/2)/(-182.75);
	f = .4*cos(encoderAngle);
	double dVal = 0;
	Ki = 0.0000;
	double iVal = previousIVal + (double)setpoint-(double)current;
	if(previous != 0){
			dVal = ((double)current-(double)previous)*Kd;
	}
	previousIVal = iVal;
	previous = current;
	return (Kp*(setpoint-current) + f)+(iVal*Ki)+-dVal;
}


float DriveTrain::ReturnEncoderDistance(int lf_encoder, int lr_encoder, int rf_encoder, int rr_encoder, float encDistance){
//This method returns the encoder distances

lf_encoder = lf->GetEncPosition()*25.12;
lr_encoder = lr->GetEncPosition()*25.12;

rf_encoder = rf->GetEncPosition()*25.12;
rr_encoder = rr->GetEncPosition()*25.12;


encDistance = (lf_encoder + lr_encoder + rr_encoder + rf_encoder) / 2; //averages the values from all encoders

SmartDashboard::PutNumber("Encoder Distance", encDistance);
SmartDashboard::PutNumber("lf Encoder", lf_encoder);
SmartDashboard::PutNumber("lr Encoder", lr_encoder);
SmartDashboard::PutNumber("rf Encoder", rf_encoder);
SmartDashboard::PutNumber("rr Encoder", rr_encoder);
return encDistance;

}

void DriveTrain::ResetEncoderDistance(){
	lf->SetPosition(0);
	lr->SetPosition(0);
	rf->SetPosition(0);
	rr->SetPosition(0);

}

float DriveTrain::ReturnGyroAngle(float gyroPosition){

gyroPosition = RobotMap::drivegyro->GetAngle();

return gyroPosition;
}



void DriveTrain::ResetGyroAngle(){

	RobotMap::drivegyro->Reset();
}

/*******Existing *****/
//void DriveTrain::takeJoystickInputs(double x, double y, double z, double angle){
	//DriveTrain::mecanum->MecanumDrive_Cartesian(Robot::oi->joystick1->GetX(),Robot::oi->joystick1->GetY(), Robot::oi->joystick1->GetZ());

//}
void DriveTrain::takeJoystickInputs(double x, double y, double z, double angle){
	DriveTrain::mecanum->MecanumDrive_Cartesian(Db(x), Db(y), Db(z));
}

void DriveTrain::stop(){
	DriveTrain::mecanum->MecanumDrive_Cartesian(0.0, 0.0, 0.0, 0.0);
}


double DriveTrain::Db(double axisVal){
	//if (axisVal < -0.10){
		//if(axisVal <= -0.95){
			//return axisVal;
		//}
	return axisVal;

	//}
	//else if (axisVal > 0.10){
		//if(axisVal >= 0.95){
			//return 0.95;
		//}
		//return axisVal;
	//}

	//return 0;

}
void DriveTrain::takeAutoInputs(double y1, double y2){
	DriveTrain::mecanum->TankDrive( y1, y2);

}


