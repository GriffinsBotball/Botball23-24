#include <kipr/wombat.h>
#include <sys/time.h>

//In main.c, add:
//#include "functions.h"

float driveSpeed = .3; // Measured in meters/sec
float rotateSpeed = 150; //Measured in degrees/sec

void driveDistance(float distance) // Drive forward distance in cm
{
    distance = distance/100; // convert to cm
    create3_drive_straight(-distance, driveSpeed);
}
void turnDegrees(float degrees) //Rotate a set number of degrees
{
    create3_rotate_degrees(-degrees, rotateSpeed);
}
void turnRadians(float radians)//Rotate a number of radians (pi = 180 degrees)
{
    create3_rotate_radians(-radians,2.64)
}
void ledColor(float rValue, float gValue, float bValue)
{
Create3LedColor color;
color.r = rValue;
color.g = gValue;
color.b = bValue;
Create3Lightring lightring;
lightring.led0 = color;
lightring.led1 = color;
lightring.led2 = color;
lightring.led3 = color;
lightring.led4 = color;
lightring.led5 = color;
create3_led_animation(Create3BlinkLights, lightring, 5.0); // Blink the lights green for 5 seconds.
}

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