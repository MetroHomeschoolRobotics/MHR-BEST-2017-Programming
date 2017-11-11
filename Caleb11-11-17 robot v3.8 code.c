#pragma config(Motor,  port2,           driveR,        tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           driveL,        tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           scoop,         tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           shooter,       tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           feeder,        tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int leftX = 0;
int leftY = 0;
int rightY = 0;
int rightX = 0;
const bool on = true;
int thresh = 15;
int slope = 2.5;
int count = 1;

task drive()
{
	while(on)
{
	motor[driveL] = leftX - leftY;
	motor[driveR] = leftX + leftY;

		if(vexRT[Btn5D])
		{
			if(leftY+leftX == 0)
				//		{
			//			if(count == 1)
			{
				//			count++;

				motor[driveL] = 127;
				motor[driveR] = 10;
				wait1Msec(575);
				/*
				motor[driveL] = 127;
				motor[driveR] = -128;
				wait1Msec(2063);
				*/
				motor[driveL] = 80;
				motor[driveR] = -128;
				wait1Msec(1750);

				motor[driveL] = 127;
				motor[driveR] = 127;
				wait1Msec(850);

				motor[driveL] = -128;
				motor[driveR] = 127;
				wait1Msec(1250);

				motor[driveL] = 0;
				motor[driveR] = 0;
				/*
				motor[driveL] = -128;
				motor[driveR] = 0;
				wait1Msec(250);

				motor[driveL] = 127;
				motor[driveR] = -128;
				wait1Msec(2000);

				motor[driveL] = -128;
				motor[driveR] = 127;
				wait1Msec(250);
				*/

			}
			//		}
			/*		else if(|lexfY|+|leftX| != 0)
			{
			motor[driveL] = -leftX - leftY;
			motor[driveR] = -leftX + leftY;
			}
			*/		else
			{
				motor[driveL] = leftX - leftY;
				motor[driveR] = leftX + leftY;
			}
		}
	}
}

task manipulator()
{
	while(on)
	{
		{
			motor[scoop] = rightY + 20;

			if(vexRT[Btn6U])
			{
				motor[scoop] = 55;//keep the scoop up for cans
			}

			if(vexRT[Btn6D])
			{
				motor[scoop] = -30;//keep the scoop down for cans
			}

			if(vexRT[Btn5U])
			{
				motor[scoop] = 40;//manny anti-drift
				//wait1Msec(1000);
			}
		}

		/*
		if(vexRT[Btn8L])
		{
		motor[shooter] = -127;
		}

		if(vexRT[Btn8R])
		{
		motor[shooter] = 127;
		}*/

		if(vexRT[Btn8L])
		{
			motor[shooter] = 127;
		}

		else
		{
			motor[shooter] = 0;
		}
	}
}

task main()
{
	startTask(drive);
	startTask(manipulator);

	while(on)
	{
		rightX = vexRT(Ch1);
		if(abs(rightX)<thresh){
			rightX = 0;
		}
		rightY = vexRT(Ch2);
		if(abs(rightY)<thresh){
			rightY = 0;
		}
		leftY = vexRT(Ch3);
		if(abs(leftY)<thresh){
			leftY = 0;
		}
		leftX = vexRT(Ch4);
		if(abs(leftX)<thresh){
			leftX = 0;
		}
	}
}