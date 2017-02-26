// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"
#include <AHRS.h>
#include <CameraServer.h>
#include <CANTalon.h>

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<DriveTrain> Robot::driveTrain;
std::shared_ptr<BallFeeder> Robot::ballFeeder;
std::shared_ptr<Conveyer> Robot::conveyer;
std::shared_ptr<GearMover> Robot::gearMover;
std::shared_ptr<Shooter> Robot::shooter;
std::shared_ptr<Climber> Robot::climber;
std::shared_ptr<ShooterAdjuster> Robot::shooterAdjuster;
std::shared_ptr<Leds> Robot::leds;
std::shared_ptr<RopeGather> Robot::ropeGather;
std::unique_ptr<OI> Robot::oi;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

void Robot::RobotInit() {
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    driveTrain.reset(new DriveTrain());
    ballFeeder.reset(new BallFeeder());
    conveyer.reset(new Conveyer());
    gearMover.reset(new GearMover());
    shooter.reset(new Shooter());
    climber.reset(new Climber());
    shooterAdjuster.reset(new ShooterAdjuster());
    leds.reset(new Leds());
    ropeGather.reset(new RopeGather());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());

	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand.reset(new AutonomousCommand());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS



	//CameraServer::GetInstance()->StartAutomaticCapture(2);



	//Below is some sort of voodo magic for network tables that doesn't work. At least I think it does not work. It is untested.
	/*while(true){
		std::cout<<"ZEDdata:";
		std::vector<double>arr = RobotMap::steven->GetNumberArray("Depths", llvm::ArrayRef<double>());
		for (unsigned int i=0; i < arr.size(); i++ ){
				std::cout << arr[i] <<" ";
		}
				std::cout<< std::endl;
				Wait(1);
	}
	*/



  }

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){
	SmartDashboard::PutNumber("autonNumber",1);
	RobotMap::drivegyro->ZeroYaw();
	SmartDashboard::PutNumber("autonSpe", 1);
	SmartDashboard::PutNumber("autonDir",1);
	SmartDashboard::PutNumber("autonSec",1);




}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Start();


	RobotMap::driveTrainLf->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Brake);


}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();
	//RobotMap::driveGyro->Reset();
	RobotMap::drivegyro->Reset();
Robot::driveTrain->lf->SetFeedbackDevice(CANTalon::CtreMagEncoder_Absolute);


}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();

		double shooterVolts = RobotMap::shooterAdjusterShooterPot->GetAverageVoltage();

		SmartDashboard::PutNumber("Shooter Pot", shooterVolts);

		double gearVoltage = RobotMap::gearSideUltra->GetAverageVoltage();
		double gearDistance = gearVoltage/0.00931; //should return distance in inches (if 4.77 v is applied)
		double driveAngle = RobotMap::drivegyro->GetAngle();
		//double gearDistance = gearVoltage/0.00644; //should return distance in inches (if 3.3 v is applied)
		SmartDashboard::PutNumber("Gear Range", gearDistance);
		//double msAngle = RobotMap::driveGyro->GetYaw();

		//SmartDashboard::PutNumber("Drive Yaw",  RobotMap::drivegyro->GetYaw());
		//SmartDashboard::PutNumber("Drive Yaw",  RobotMap::drivegyro->GetYaw());
		SmartDashboard::PutNumber("Drive Angle", driveAngle);
		//SmartDashboard::PutNumber("Drive X",  RobotMap::driveGyro->GetRawGyroX());
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);
