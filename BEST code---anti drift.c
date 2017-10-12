#pragma config(Motor,  port2,           driveL,        tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           driveR,        tmotorServoContinuousRotation, openLoop)
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

task drive()
{
	while(on)
		if(vexRT[Btn5D])
	{
		motor[driveL] = ((-leftX - leftY)/slope)^2;
		motor[driveR] = ((-leftX + leftY)/slope)^2;
	}
	else
	{
		motor[driveL] = -leftX - leftY;
		motor[driveR] = -leftX + leftY;
	}
}

task manipulator()
{
	while(on)
	{
		{
			motor[scoop] = rightY;

			if(vexRT[Btn6U])
			{
				motor[scoop] = 55;//keep the scoop up for cans
			}

			if(vexRT[Btn6D])
			{
				motor[scoop] = -30;//keep the scoop down for cans
			}

			if(vexRT[Btn8D])
			{
				motor[scoop] = 20;
				wait1Msec(1000);
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

		if(vexRT[Btn8U])
		{
		motor[shooter] = -128;
		wait1Msec(300);
		motor[shooter] = 127;
		wait1Msec(750);
		motor[shooter] = -128;
		wait1Msec(475);
		motor[shooter] = 0;
		}

		if(vexRT[Btn8L])
		{
		motor[shooter] = 127;
		wait1Msec(500);
		motor[shooter] = 0;
		}

		if(vexRT[Btn8R])
		{
		motor[shooter] = -128;
		wait1Msec(500);
		motor[shooter] = 127;
		wait1Msec(500);
		motor[shooter] = 0;
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
