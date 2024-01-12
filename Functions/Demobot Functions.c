#include "library.h"
#include <kipr/wombat.h>

// Different variables that need to be changed per code.
// Motor Controls
int leftMotor = 0;
int rightMotor = 1;
int motorSpeed = 100;
int stepFactor = 78.7; // Default for traditional demobot, controls the motor position it will drive. (default:508[cm]) 
int rotationalDegrees = 26.11; //Default for traditional demobot is 26.11, controls the amount of degrees it will drive.

// Adjustment for motors
int rightAdjustment = 0;
int leftAdjustment = 0;
//Sensors
int leftBumper = 4;
int rightBumper = 5;
int infaredSensor = 0;
int leftRearBumper = 0;
int rightRearBumper = 2;
//Sensor Values
int blackLine = 0; //Should be set to the value of a black line with the Infared sensor. Needs to be set, more often the better.


void blackLineDetect(int shade) //drive till the tophat is on black which is value int "shade"
{
    while(analog(infaredSensor) <= shade)
    {
        motor(leftMotor, (motorSpeed+leftAdjustment)*.75);
        motor(rightMotor, (motorSpeed+rightAdjustment)*.75);
    }
}

void blackLineDetectReverse(int shade) //Drive backwards until the tophat is on black("shade")
{
    while(analog(infaredSensor) <= shade)
    {
        motor(leftMotor, -motorSpeed-leftAdjustment);
        motor(rightMotor, -motorSpeed-rightAdjustment);
    }
    ao();
}


void driveDistance(int distance) // Drives forward for value int "distance". If distance is negative, drive backwards. Distance is in "cm".
{
  // May be having some problems based on hardware configuration.
    cmpc(leftMotor);
    cmpc(rightMotor);
    if(distance>0)
    {
      while(gmpc(rightMotor)<stepFactor*distance || gmpc(leftMotor)<stepFactor*distance) //Makes straight line with set number of cm
      {
        if((gmpc(leftMotor)<stepFactor*distance ))
        {
          motor(leftMotor, motorSpeed+leftAdjustment);
        }
        if(gmpc(rightMotor)<stepFactor*distance)
        {
          motor(rightMotor, motorSpeed+rightAdjustment);
        }
      }
    }
    else
    {
      while(gmpc(rightMotor)>stepFactor*distance || gmpc(leftMotor)>stepFactor*distance) //Makes straight line with set number of cm
      {
        if(gmpc(leftMotor)>stepFactor*distance)
        {
          motor(leftMotor, -motorSpeed-leftAdjustment);
        }
        if(gmpc(rightMotor)>stepFactor*distance)
        {
          motor(rightMotor, -motorSpeed-rightAdjustment);
        }
      }
    }
    ao();
}


void lineFollow(int shade) // Follow a line with a darkness value of int "shade".
{
  int X = 2000;
  while((X) >= 1)
    {
    	 if(analog(infaredSensor) >= shade)
    		{
        motor(leftMotor, 25);
        motor(rightMotor, motorSpeed);
     	}
    	 if(analog(infaredSensor) < shade)
    	{
        motor(leftMotor, motorSpeed);
    	motor(rightMotor, 25);
     	}
    }
 }


void lineFollowSquare() // Square up by following a line
{
    while(digital(leftBumper) == 0 && digital(rightBumper) == 0)
    {
   	  	if (digital(leftBumper) == 1 || digital(rightBumper) == 1)
     {
         if (digital(leftBumper) == 1)
         {
           motor(leftMotor, 100);
         }
         else
         	{
            motor(rightMotor, 100);
          }
      }
       	else if (analog(infaredSensor) >= 3650)
     		{
          motor(leftMotor, 25);
          motor(rightMotor, motorSpeed);
       	}
     	 	else if (analog(infaredSensor) < 3650)
      	{
          motor(leftMotor, motorSpeed);
      	  motor(rightMotor, 25);
     	  }
    }
}


void lineFollowSquareReverse(int shade) // Back up until you are alligned to the wall behind you. Line is value of int "shade"
{
    while(digital(leftRearBumper) == 0 && digital(rightRearBumper) == 0)
    {
   	  	if (digital(leftRearBumper) == 1)
        {
     		motor(rightMotor, -25);
            motor(leftMotor, 0);
     	}

        else if (digital(rightRearBumper) == 1)
        {
     		motor(leftMotor, -25);
            motor(rightMotor, 0);
     	}

        else if (analog(1) > shade)
    	{
        motor(leftMotor, -40);
    	motor(rightMotor, -motorSpeed);
     	}

     	else if (analog(1) <= shade)
   		{
        motor(leftMotor, -motorSpeed);
        motor(rightMotor, -40);
     	}
    }
}


void squareUp() // Square up by driving forward
{
	while(digital(leftBumper) == 0 && digital(rightBumper) == 0)
    {
      if(digital(leftBumper)==0)
      {
      	motor(leftMotor, 75);
      }
      if(digital(3)==0)
      {
        motor(rightMotor, 75);
      }
    }
}


void squareUpReverse() // Square up by backing up
{
	while(digital(leftRearBumper) == 0 || digital(rightRearBumper) == 0)
    {
        if(digital(leftBumper)==0)
      {
      	motor(leftMotor, -50);
      }
        if(digital(2)==0)
      {
        motor(rightMotor, -50);
      }
        // \/ this may be no good \/
        else if (digital(leftBumper)==1)
      {
      	motor(rightMotor, -50);
      }
        else if (digital(rightBumper)==1)
      {
      	motor(leftMotor, -50);
      }
    }
}

void servoPosition(int servo, int position)
{
  enable_servos();
  set_servo_position(servo, position);
  disable_servos();
  ao();
}

void timeServo(int port, int endAngle, float time) //Moves servo in "port" to "endangle" in "time" seconds.
{
  enable_servo(port);
  int segment = 100; // Determines how many 'segments' the movement should be broken into, is arbitrary.
  int position = get_servo_position(port);
  // Equation to find delay is the abs of the endAngle - the position, / milliseconds. (This may need tweaking.)
  int moveSegments = ((endAngle-position)/segment);
  int timeSegments = (time*1000/segment) + 0.00000001; // Milliseconds divided by segments. Adding a very small amount because this seems to fix some random problems.
  if(endAngle > position)
  {
    while(endAngle > position) // Move servo negatively
    {
      msleep(timeSegments);
      set_servo_position(port, position+moveSegments);
      position = get_servo_position(port);
    }
  }
  else if(endAngle < position)
  {
    while(endAngle < position) // Move servo positively
    {
      msleep(timeSegments);
      set_servo_position(port, position+moveSegments);
      position = get_servo_position(port);
    }
  }
    ao();
}


void turnDegrees(int degrees) // Turn a specified number of degrees
{
  cmpc(leftMotor);
  cmpc(rightMotor);
  if (degrees>0) // A right turn
  {
    while(gmpc(leftMotor)<=rotationalDegrees*degrees) //Turning right, measure the motor that moves, which is the opposite to the direction of movement
    {
      motor(rightMotor,1);
      motor(leftMotor, motorSpeed);
    }
  }
  else // A left turn
  {
    while (gmpc(rightMotor)<=rotationalDegrees*degrees*-1) // Turning left
      {
        motor(rightMotor, motorSpeed);
        motor(leftMotor,1);
      }
  }
  ao();
}
