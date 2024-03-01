#include <kipr/wombat.h>
#include <sys/time.h>

//In main.c, add:
//#include "functions.h"

int movementSpeed = 50;

void timeServo(int port, int endAngle, int time) //Moves servo in "port" to position"endangle" in "time" milliseconds.
{
    enable_servos();
    int servoPosition = get_servo_position(port);
    int currentSegment = 0; //Which segment the program is currently on. Contrasted with segment count.
    
    int segmentCount = 100; //Works with value 100.
    float timeSegment = (time/segmentCount);
    float movementSegment = ((endAngle-servoPosition)/segmentCount);
    
    while(currentSegment < segmentCount)
    {
    servoPosition = get_servo_position(port);
    msleep(timeSegment);
    set_servo_position(port,servoPosition+movementSegment);
    currentSegment += 1;
    }
    
    set_servo_position(port, endAngle);
    disable_servos();
    ao();
}

void startup()
{
  wait_for_light(2);
  shut_down_in(115);
}

void turnDegrees(int deg)
{
  set_create_total_angle(0);
	if (deg>0) // Right turn
    {
    while (get_create_total_angle() >= deg*-1)
    	{
    	create_drive_direct(movementSpeed,-movementSpeed);
    	}
    ao();
    }
    else if (deg<0) // Left turn
    {
        while (get_create_total_angle() <= deg*-1)
    	{
    	create_drive_direct(-movementSpeed,movementSpeed);
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

void driveDistance(int dis) //Makes robot drive forward for a set number of cm.
{
    set_create_distance(0);
    dis = dis*10;
    if (dis>0)
    {
      while(get_create_distance() > -(dis))
        {
          create_drive_direct(-movementSpeed,-movementSpeed);
        }
      ao();
    }
    else if (dis<0)
      {
      while(get_create_distance() < -(dis)) // Gets current distance
        {
            create_drive_direct(movementSpeed,movementSpeed);
        }
      ao();
	     }
}

void driveDistancefast(int dis) //Makes robot drive forward for a set number of cm.
{
    dis = dis*10;
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
            create_drive_direct(0,movementSpeed);
        }
        else
        {
            create_drive_direct(0,0);
        }
        if(get_create_lbump() == 0)
        {
            create_drive_direct(movementSpeed,0);
        }
        else
        {
            create_drive_direct(0,0);  //motor 1 is right and motor 0 is left
        }
    }
}