#include <kipr/wombat.h>
#include <library.h>

int main()
{	
    
    //Square up at start of game
    enable_servos();
    set_servo_position(2,1700);
    set_servo_position(1,1500);
    squareUpReverse();
    
    //Wack the people into Zone B
    set_servo_position(2,700); 
    driveDistance(3);
    turnDegrees(-90);
    squareUpReverse();//
    driveDistance(5);//Square up at the begining
    
    set_servo_position(1,0);
    msleep(1000);
    set_servo_position(2,0);
    msleep(1000);
    turnDegrees(90);
    driveDistance(10);
    
    //square back up to get orange poms
    set_servo_position(1,1500);
    squareUpReverse();
    turnDegrees(-90);
    squareUpReverse();
    turnDegrees(90);
    squareUpReverse();
    
    // Find second black line from starting box
    driveDistance(45); 
    msleep(100);
    blackLineDetect(3800);
    printf("Find 2nd Black Line \n");
    
    // To here, good so far!
    
    
    //Travel near tall cup
    driveDistance(51);
    turnDegrees(80);
    msleep(50);
    printf("Travel to Cup \n");
    
    //Aim for cup with the arm
    set_servo_position(1, 40);
    set_servo_position(2, 400);
    msleep(1000);
    driveDistance(17);
    msleep(200);
    printf("Aim for Cup \n");
   
    //Grab cup and reverse
   	set_servo_position(2, 2040);
    msleep(500);
    driveDistance(-15);
    printf("Grabbed Cup \n");
    
    //Turn towards start box, drive forward to Zone B, Lift PVC holder.
    turnDegrees(105);
    driveDistance(30);
    turnDegrees(-30);
    driveDistance(25);
    
    //lifts the claw to drop the poms
    set_servo_position(1, 40);
    msleep(200);
    set_servo_position(1, 150);
    msleep(200);
    set_servo_position(1, 70);
    msleep(200);
    
    //turns to position poms
    set_servo_position(1, 250);
    msleep(200);
    turnDegrees(10);
    set_servo_position(1, 150);
    msleep(200);
    turnDegrees(10);
    set_servo_position(1,1000);
    msleep(1000);
    
    //sets down container
    set_servo_position(1,150);
    set_servo_position(2, 300);
    printf("Driving towards start box. \n");
    set_servo_position(1,1000);
    msleep(1000);
    
    turnDegrees(-45);
    

    return 0;
}
