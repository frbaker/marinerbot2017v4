// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "Auton2.h"

#include "Commands/Autonomous/Shooting/AutoDriveStraight.h"
#include "Commands/Autonomous/Shooting/AutoTurnToShoot.h"
#include "Commands/Autonomous/Shooting/Spot2/AutoDriveStraight3.h"
#include "Commands/Autonomous/Shooting/AutoTurnToShoot2.h"
#include "Commands/Autonomous/Shooting/AutoDriveStraight02.h"
#include "Commands/FireBalls.h"

/* Add for any subcommands*/
//#include "Commands/UseBallFeeder.h"
//#include "Commands/UseShooter.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR


//Auton 1 is for driving and shooting. It is for the longest driving route.


Auton2::Auton2() {
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
     // Add Commands here:
    // e.g. AddSequential(new Command1());
    //      AddSequential(new Command2());
    // these will run in order.

    // To run multiple commands at the same time,
    // use AddParallel()
    // e.g. AddParallel(new Command1());
    //      AddSequential(new Command2());
    // Command1 and Command2 will run in parallel.

    // A command group will require all of the subsystems that each member
    // would require.
    // e.g. if Command1 requires chassis, and Command2 requires arm,
    // a CommandGroup containing them would require both the chassis and the
    // arm.
              // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=COMMAND_DECLARATIONS
	/*Add Parallel or Sequential commands*/


AddSequential(new AutoDriveStraight);
AddSequential(new AutoTurnToShoot);
AddSequential(new AutoDriveStraight3);
AddSequential(new AutoTurnToShoot2);
AddSequential(new AutoDriveStraight02);
AddSequential(new FireBalls);


//AddSequential(new )
       // AddParallel(new UseBallFeeder());
        //AddParallel(new UseShooter());
              // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=COMMAND_DECLARATIONS
 }
