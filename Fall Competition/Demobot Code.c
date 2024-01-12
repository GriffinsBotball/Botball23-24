#include <kipr/wombat.h>
#include <library.h>

int main()
{	
    //Start up
    enable_servos();
    set_servo_position(3,1700);
    set_servo_position(1,1500);
    wait_for_light(5);
  	shut_down_in(115);
    
    //Square up at start of game
    squareUpReverse();
    
    //Wack the people into Zone B
    set_servo_position(3,700); 
    driveDistance(3);
    turnDegrees(-90);
    squareUpReverse();//
    driveDistance(3.5);//Square up at the begining
    
    set_servo_position(1,0);
    msleep(1000);
    set_servo_position(3,185);
    msleep(1000);
    turnDegrees(89);
    squareUpReverse();
    
    
    // Get Botguy
    driveDistance(53);
    turnDegrees(-1);
	ao();
    msleep(1000);
    enable_servos();
    set_servo_position(1,2000);
    msleep(1000);
    driveDistance(-20);
    set_servo_position(1,0);
    msleep(1000);
    set_servo_position(3,700);
    turnDegrees(5.5);
    squareUpReverse();
    
    //square back up to get orange poms
    set_servo_position(1,1500);
    set_servo_position(3,1400);
    squareUpReverse();
    turnDegrees(-90);
    squareUpReverse();
    turnDegrees(90);
    squareUpReverse();
   
    
    // Find second black line from starting box
    turnDegrees(2.5);
    driveDistance(45); 
    msleep(100);
    blackLineDetect(3800);
    printf("Find 2nd Black Line \n");
    
    // To here, good so far!
    
    //Travel near tall cup
    driveDistance(47);
    turnDegrees(80);
    msleep(50);
    printf("Travel to Cup \n");
    
    //Aim for cup with the arm
    set_servo_position(1, 750);
    msleep(2000);
    turnDegrees(-2.5);
    set_servo_position(3, 250);
    msleep(2000);
    driveDistance(4.25);// was 17.5
    msleep(2000);
    printf("Aim for Cup \n");
   
    //Grab cup and reverse
   	set_servo_position(1, 2000);
    msleep(500);
    driveDistance(-20);
    printf("Grabbed Cup \n");
    
    //Turn towards start box, drive forward to Zone B, Lift PVC holder.
    turnDegrees(110);
    driveDistance(30);
    turnDegrees(-30);
    driveDistance(25);
    
    //lifts the claw to drop the poms
    set_servo_position(3, 40);
    msleep(200);
    set_servo_position(3, 700);
    msleep(200);
    set_servo_position(3, 70);
    msleep(200);
    
    //turns to position poms
    set_servo_position(3, 250);
    msleep(200);
    turnDegrees(10);
    set_servo_position(3, 150);
    msleep(200);
    turnDegrees(10);
    set_servo_position(3,1000);
    msleep(1000);
    
    //sets down container
    set_servo_position(1,150);
    set_servo_position(3, 300);
    printf("Driving towards start box. \n");
    set_servo_position(3,1000);
    msleep(1000);
    
    turnDegrees(-45);
    

    return 0;
}
