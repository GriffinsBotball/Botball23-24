#include <kipr/wombat.h>
#include <sys/time.h>

//In main.c, add:
//#include "functions.h"

void slowServo(int servo, int endAngle, int speed) //Slowly controls the servo to move to the correct position at the correct speed.
{
  if (get_servo_position(servo) > endAngle)
  {
	   enable_servo(servo);
     while (get_servo_position(servo) > endAngle)
		   {

  			set_servo_position(servo, get_servo_position(servo)-2);
  			msleep(speed);


		   }
	  ao();
  }
  else if (get_servo_position(servo) < endAngle)
    {
	   enable_servo(servo);
     while (get_servo_position(servo) < endAngle)
		   {

  			set_servo_position(servo, get_servo_position(servo)+2);
  			msleep(speed);


		    }
	   ao();
    }
}

void startup()
{
  wait_for_light(2);
  shut_down_in(115);
}


void turnDegrees(int deg)
{
   	set_create_total_angle(0);
	if (deg>0)
    {
    while (get_create_total_angle() >= deg*-1)
    	{
    	create_drive_direct(100,-100);
    	}
    ao();
    }
    else if (deg<0)
    {
        while (get_create_total_angle() <= deg*-1)
    	{
    	create_drive_direct(-100,100);
    	}
    ao();
    }
}

void line_follow(int tophat_port, int threshold, int milliseconds) {
    struct timeval start, stop;
    gettimeofday(&start, NULL);
    gettimeofday(&stop, NULL);
    int diff_ms = (stop.tv_sec - start.tv_sec)*1000 + (stop.tv_usec - start.tv_usec)/1000;

    while(diff_ms<=milliseconds){
        while(analog(tophat_port) < threshold && diff_ms<=milliseconds) //on white
        {

            create_drive_direct(-175,0);
            gettimeofday(&stop, NULL);
        	diff_ms = (stop.tv_sec - start.tv_sec)*1000 + (stop.tv_usec - start.tv_usec)/1000;
        }
        while(analog(tophat_port) > threshold  && diff_ms<=milliseconds) //on black
        {

            create_drive_direct(0,-175);
            gettimeofday(&stop, NULL);
        	diff_ms = (stop.tv_sec - start.tv_sec)*1000 + (stop.tv_usec - start.tv_usec)/1000;
        }
	create_drive_direct(0,0);
    msleep(100);
    }
}


void lineFollowCliff(int threshold, int milliseconds) {
    struct timeval start, stop;
    gettimeofday(&start, NULL);
    gettimeofday(&stop, NULL);
    int diff_ms = (stop.tv_sec - start.tv_sec)*1000 + (stop.tv_usec - start.tv_usec)/1000;

    while(diff_ms<=milliseconds){
        while(get_create_lfcliff_amt() < threshold && diff_ms<=milliseconds) //on white
        {
            printf("On straight");
            create_drive_direct(-100, 50);
            gettimeofday(&stop, NULL);
        	diff_ms = (stop.tv_sec - start.tv_sec)*1000 + (stop.tv_usec - start.tv_usec)/1000;
        }
        while(get_create_lfcliff_amt() > threshold  && diff_ms<=milliseconds) //on black
        {
            printf("On black");
            create_drive_direct(50, -100);
            gettimeofday(&stop, NULL);
        	diff_ms = (stop.tv_sec - start.tv_sec)*1000 + (stop.tv_usec - start.tv_usec)/1000;
        }
        while(get_create_rfcliff_amt() < threshold && diff_ms<=milliseconds) //on white
        {
            printf("On gray");
            create_drive_direct(50, -100);
            gettimeofday(&stop, NULL);
        	diff_ms = (stop.tv_sec - start.tv_sec)*1000 + (stop.tv_usec - start.tv_usec)/1000;
        }
        while(get_create_rfcliff_amt() > threshold  && diff_ms<=milliseconds) //on black
        {
            printf("On black");
            create_drive_direct(-100, 50);
            gettimeofday(&stop, NULL);
        	diff_ms = (stop.tv_sec - start.tv_sec)*1000 + (stop.tv_usec - start.tv_usec)/1000;
        }




	create_drive_direct(0,0);
    msleep(100);
    }}


void driveDistance(int dis) //Makes robot drive forward for a set number of inches.
{
    set_create_distance(0);


    if (dis>0)
    {
      while(get_create_distance() > -(dis))
        {
          create_drive_direct(-50,-50);
        }
      ao();
    }
    else if (dis<0)
      {
      while(get_create_distance() < -(dis)) // Gets current distance
        {
            create_drive_direct(50,50);
        }
      ao();
	     }
}
void driveDistancefast(int dis) //Makes robot drive forward for a set number of inches.
{
    set_create_distance(0);


    if (dis>0)
    {
      while(get_create_distance() > -(dis))
        {
          create_drive_direct(-250,-250);
        }
      ao();
    }
    else if (dis<0)
      {
      while(get_create_distance() < -(dis)) // Gets current distance
        {
            create_drive_direct(250,250);
        }
      ao();
	     }
}
void Bump_Square_Up() {
    while(get_create_rbump() == 0 || get_create_lbump() == 0)
    {
        if(get_create_rbump() == 0)
        {
            create_drive_direct(0,50);
        }
        else
        {
            create_drive_direct(0,0);
        }
        if(get_create_lbump() == 0)
        {
            create_drive_direct(50,0);
        }
        else
        {
            create_drive_direct(0,0);  //motor 1 is right and motor 0 is left
        }
    }
}
