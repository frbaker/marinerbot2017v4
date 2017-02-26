// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "CANTalon.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include <WPILib.h>
#include <AHRS.h>
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION


// Below is to be used if its on CAN bus

//std::shared_ptr<CANTalon> RobotMap::driveTrainLf;
std::shared_ptr<CANTalon> RobotMap::driveTrainRf;
std::shared_ptr<CANTalon> RobotMap::driveTrainLr;
std::shared_ptr<CANTalon> RobotMap::driveTrainRr;
std::shared_ptr<CANTalon> RobotMap::driveTrainLf;

// Below is to be used if its on a PWM
/*
std::shared_ptr<TalonSRX> RobotMap::driveTrainLf;
std::shared_ptr<TalonSRX> RobotMap::driveTrainRf;
std::shared_ptr<TalonSRX> RobotMap::driveTrainLr;
std::shared_ptr<TalonSRX> RobotMap::driveTrainRr;
*/


std::shared_ptr<RobotDrive> RobotMap::driveTrainMecanum;
std::shared_ptr<SpeedController> RobotMap::ballFeederBallFeederSpike;
std::shared_ptr<SpeedController> RobotMap::conveyerSpeedController1;
std::shared_ptr<SpeedController> RobotMap::gearMoverGearSparkMotor;
std::shared_ptr<Encoder> RobotMap::shooterShooterEncoder;
std::shared_ptr<CANTalon> RobotMap::shooterShooterMotor;
std::shared_ptr<CANTalon> RobotMap::climberClimberMotor;
std::shared_ptr<SpeedController> RobotMap::shooterAdjusterShooterAdjust;
std::shared_ptr<AnalogInput> RobotMap::shooterAdjusterShooterPot;
std::shared_ptr<Relay> RobotMap::ledsLedSpike;
std::shared_ptr<Relay> RobotMap::ropeGatherRopeGatherRelay;
std::shared_ptr<AnalogInput> RobotMap::gearSideUltra;
std::shared_ptr<AnalogInput> RobotMap::nonGearSideUltra;

std::shared_ptr<SpeedController> RobotMap::ballSubFeeder;
std::shared_ptr<SpeedController> RobotMap::ballVibrator;
std::shared_ptr<AHRS> RobotMap::drivegyro;

//std::shared_ptr<AnalogGyro> RobotMap::agyro;

std::shared_ptr<NetworkTable> RobotMap::steven;



void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS







	LiveWindow *lw = LiveWindow::GetInstance();



    gearSideUltra.reset(new AnalogInput(1)); // assigns ultra to be an ultrasonic sensor which uses DigitalOutput 1 for the echo pulse and DigitalInput 1 for the trigger pulse
    nonGearSideUltra.reset(new AnalogInput(2)); // assigns ultra to be an ultrasonic sensor which uses DigitalOutput 1 for the echo pulse and DigitalInput 1 for the trigger pulse
    //ahrs.reset(new AHRS(SPI::Port::kMXP));


    //driveAgyro.reset(new AHRS(I2C::kMXP));
    drivegyro.reset(new AHRS(SerialPort::Port::kUSB1));
    //lw->AddSensor("Atest", "testA", drivegyro);
    //drivegyro.reset(new AHRS(SerialPort::Port::kOnboard));


// Below is the CAN id's if drive is on CAN bus


    driveTrainLf.reset(new CANTalon(7));
    lw->AddActuator("DriveTrain", "Lf", driveTrainLf);
    
    driveTrainRf.reset(new CANTalon(5));
    lw->AddActuator("DriveTrain", "Rf", driveTrainRf);
    
    driveTrainLr.reset(new CANTalon(0));
    lw->AddActuator("DriveTrain", "Lr", driveTrainLr);
    
    driveTrainRr.reset(new CANTalon(4));
    lw->AddActuator("DriveTrain", "Rr", driveTrainRr);



// Below is the PWM id's if robot is on PWM interface

 /*   driveTrainLf.reset(new TalonSRX(4));
    lw->AddActuator("DriveTrain", "Lf", driveTrainLf);

    driveTrainRf.reset(new TalonSRX(5));
    lw->AddActuator("DriveTrain", "Rf", driveTrainRf);

    driveTrainLr.reset(new TalonSRX(6));
    lw->AddActuator("DriveTrain", "Lr", driveTrainLr);

    driveTrainRr.reset(new TalonSRX(7));
    lw->AddActuator("DriveTrain", "Rr", driveTrainRr);
    */


//*********************************************************
    


    driveTrainMecanum.reset(new RobotDrive(driveTrainLf, driveTrainLr,
              driveTrainRf, driveTrainRr));
    
    driveTrainMecanum->SetSafetyEnabled(false);

	 driveTrainMecanum->SetExpiration(0.1);
    driveTrainMecanum->SetSensitivity(0.5);
     driveTrainMecanum->SetMaxOutput(1.0);


// ***************Motor Inversions for PWM ****************

  /*  driveTrainMecanum->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
    driveTrainMecanum->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
    driveTrainMecanum->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
    //driveTrainMecanum->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
*/

//*****************Motor Inversions for CAN *****************


      driveTrainMecanum->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
      driveTrainMecanum->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
      driveTrainMecanum->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
       driveTrainMecanum->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);



    ballFeederBallFeederSpike.reset(new Talon(2));
   // lw->AddActuator("BallFeeder", "BallFeederSpike", ballFeederBallFeederSpike);
    
    ballSubFeeder.reset(new Talon(5)); //Not wired yet

    //To do - test to make sure connection is on 3
    ballVibrator.reset(new Talon(3));

    conveyerSpeedController1.reset(new Spark(0));
    lw->AddActuator("Conveyer", "Speed Controller 1", std::static_pointer_cast<Spark>(conveyerSpeedController1));
    
    gearMoverGearSparkMotor.reset(new Spark(9));
    lw->AddActuator("GearMover", "GearSparkMotor", std::static_pointer_cast<Spark>(gearMoverGearSparkMotor));
    
    shooterShooterEncoder.reset(new Encoder(0, 1, false, Encoder::k4X));
    lw->AddSensor("Shooter", "ShooterEncoder", shooterShooterEncoder);
    shooterShooterEncoder->SetDistancePerPulse(1.0);
    shooterShooterEncoder->SetPIDSourceType(PIDSourceType::kRate);
    shooterShooterMotor.reset(new CANTalon(13));
    lw->AddActuator("Shooter", "ShooterMotor", shooterShooterMotor);
    
    climberClimberMotor.reset(new CANTalon(8));
    lw->AddActuator("Climber", "ClimberMotor", climberClimberMotor);
    
    shooterAdjusterShooterAdjust.reset(new VictorSP(1));
    lw->AddActuator("ShooterAdjuster", "ShooterAdjust", std::static_pointer_cast<VictorSP>(shooterAdjusterShooterAdjust));
    
    shooterAdjusterShooterPot.reset(new AnalogInput(0));
    lw->AddSensor("ShooterAdjuster", "ShooterPot", shooterAdjusterShooterPot);
    
    ledsLedSpike.reset(new Relay(1));
    lw->AddActuator("Leds", "LedSpike", ledsLedSpike);
    
    ropeGatherRopeGatherRelay.reset(new Relay(3));
    lw->AddActuator("RopeGather", "RopeGatherRelay", ropeGatherRopeGatherRelay);
    


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS


}
