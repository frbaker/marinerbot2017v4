// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include <Commands/VibrateBalls.h>
#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/ClimbDaRope.h"
#include "Commands/DriveWithJoy.h"
#include "Commands/FireBalls.h"
#include "Commands/LowerShooterAngle.h"
#include "Commands/MoveDaRope.h"
#include "Commands/OffLeds.h"
#include "Commands/RaiseShooterAngle.h"
#include "Commands/TurnConveyer.h"
#include "Commands/UseBallFeeder.h"
#include "Commands/UseGearMover.h"
#include "Commands/UseLeds.h"
#include "Commands/UseShooter.h"
#include "Commands/VibrateBalls.h"
#include "Commands/NotVibrateBalls.h"
#include "XboxController.h"
#include "Commands/MoveDaRopeOff.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    joystick2.reset(new Joystick(1));

    joystick1.reset(new Joystick(0));
    

       joystickButton2.reset(new JoystickButton(joystick1.get(), 2));
       joystickButton2->WhileHeld(new MoveDaRope());

       joystickButton206.reset(new JoystickButton(joystick2.get(), 6));
       joystickButton206->WhileHeld(new MoveDaRopeOff());

       /*joystickButton6.reset(new JoystickButton(joystick1.get(), 6));
       joystickButton6->WhileHeld(new ClimbDaRope());*/

       joystickButton203.reset(new JoystickButton(joystick2.get(), 3));
       joystickButton203->WhileHeld(new ClimbDaRope());

       joystickButton11.reset(new JoystickButton(joystick1.get(), 11));
       joystickButton11->WhenPressed(new UseLeds());
       joystickButton10.reset(new JoystickButton(joystick1.get(), 10));
       joystickButton10->WhenPressed(new OffLeds());
       /*joystickButton5.reset(new JoystickButton(joystick1.get(), 5));
       joystickButton5->WhileHeld(new UseGearMover());*/

       joystickButton204.reset(new JoystickButton(joystick2.get(), 4));
       joystickButton204->WhileHeld(new UseGearMover());


       /*joystickButton4.reset(new JoystickButton(joystick1.get(), 4));
       joystickButton4->WhileHeld(new TurnConveyer());*/

       joystickButton201.reset(new JoystickButton(joystick2.get(), 1));
       joystickButton201->WhileHeld(new TurnConveyer());
       joystickButton202.reset(new JoystickButton(joystick2.get(), 2));
       joystickButton202->WhileHeld(new VibrateBalls());
       joystickButton205.reset(new JoystickButton(joystick2.get(), 5));
       joystickButton205->WhileHeld(new NotVibrateBalls());

       joystickButton5.reset(new JoystickButton(joystick1.get(), 5));
       joystickButton5->WhileHeld(new RaiseShooterAngle());

      /* joystickButton2.reset(new JoystickButton(joystick1.get(), 2));
       joystickButton2->WhileHeld(new LowerShooterAngle());*/
       joystickButton3.reset(new JoystickButton(joystick1.get(), 3));
       joystickButton3->WhileHeld(new LowerShooterAngle());
       joystickButton1.reset(new JoystickButton(joystick1.get(), 1));
       joystickButton1->WhileHeld(new FireBalls());





    /*

    joystickButton1 = joystick1->GetAButton();
    joystickButton2 = joystick1->GetBButton();
    joystickButton3 = joystick1->GetXButton();
    joystickButton4 = joystick1->GetYButton();
    joystickButton5 = joystick1->GetBackButton();
    joystickButton6 = joystick1->GetBumper(frc::GenericHID::JoystickHand::kLeftHand);
    joystickButton7 = joystick1->GetBumper(frc::GenericHID::JoystickHand::kRightHand);
    joystickButton10 = joystick1->GetStickButton(frc::GenericHID::JoystickHand::kLeftHand);
    joystickButton11 = joystick1->GetStickButton(frc::GenericHID::JoystickHand::kRightHand);
    //joystickButton7.reset(new XboxController(GetAButton()));

    if(joystickButton1 == true){
    	new MoveDaRope();
    }

    joystickButton2->new OffLeds();
    joystickButton3->WhileHeld(new ClimbDaRope());
    joystickButton4->WhileHeld(new UseLeds());
    joystickButton5->WhileHeld(new UseGearMover());
    joystickButton6->WhileHeld(new TurnConveyer());
    joystickButton7->WhileHeld(new RaiseShooterAngle());
    joystickButton10->WhileHeld(new LowerShooterAngle());
    joystickButton11->WhileHeld(new FireBalls());

*/

    /*
    joystickButton10.reset(new JoystickButton(joystick1.get(), 10));
    joystickButton10->WhenPressed(new OffLeds());
    joystickButton6.reset(new JoystickButton(joystick1.get(), 6));
    joystickButton6->WhileHeld(new ClimbDaRope());
    joystickButton11.reset(new JoystickButton(joystick1.get(), 11));
    joystickButton11->WhenPressed(new UseLeds());
    joystickButton5.reset(new JoystickButton(joystick1.get(), 5));
    joystickButton5->WhileHeld(new UseGearMover());
    joystickButton4.reset(new JoystickButton(joystick1.get(), 4));
    joystickButton4->WhileHeld(new TurnConveyer());
    joystickButton3.reset(new JoystickButton(joystick1.get(), 3));
    joystickButton3->WhileHeld(new RaiseShooterAngle());
    joystickButton2.reset(new JoystickButton(joystick1.get(), 2));
    joystickButton2->WhileHeld(new LowerShooterAngle());
    joystickButton1.reset(new JoystickButton(joystick1.get(), 1));
    joystickButton1->WhileHeld(new FireBalls());
     */
    // SmartDashboard Buttons
    SmartDashboard::PutData("MoveDaRope", new MoveDaRope());
    SmartDashboard::PutData("Vibrate Balls", new VibrateBalls());
    //SmartDashboard::PutData("Command 1", new Command1());
    SmartDashboard::PutData("OffLeds", new OffLeds());
    SmartDashboard::PutData("ClimbDaRope", new ClimbDaRope());
    SmartDashboard::PutData("DriveWithJoy", new DriveWithJoy());
    SmartDashboard::PutData("UseLeds", new UseLeds());
    SmartDashboard::PutData("UseGearMover", new UseGearMover());
    SmartDashboard::PutData("TurnConveyer", new TurnConveyer());
    SmartDashboard::PutData("LowerShooterAngle", new LowerShooterAngle());
    SmartDashboard::PutData("RaiseShooterAngle", new RaiseShooterAngle());
    SmartDashboard::PutData("FireBalls", new FireBalls());
    SmartDashboard::PutData("UseShooter", new UseShooter());
    SmartDashboard::PutData("UseBallFeeder", new UseBallFeeder());
    SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<Joystick> OI::getJoystick1() {
   return joystick1;
}

std::shared_ptr<Joystick> OI::getJoystick2() {
   return joystick2;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
