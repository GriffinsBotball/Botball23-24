#include <kipr/wombat.h>

int main()
{		
    //Variables
    //PLEASE NOTE: do not change variables unless they say to
    	//Integers
    	int thresholdR = 2600; //change these based on room brightness
    	int thresholdL = 2600; //change these based on room brightness
    
    	//Floats
    	float rightM = 1.0f; // change these based on battery percent 1.0 = 100%
    	float leftM = 1.0f; //change these based on bettery percent 1.0 = 100%
    
    	float averageM = ((rightM + leftM)/2); //average of the two 
    
    	float changeMsleep = 2 - averageM; //changes Msleep to correct for battery slowness
    
	//Segment 1
    create_connect();

    enable_servos();//opens scissors
    set_servo_position(0, 1500);
    
    create_drive_direct(100 * leftM,-100 * leftM); //turns to be ready
    msleep(1600 * changeMsleep);
    
    create_drive_direct(-100 * leftM, -50 * rightM);
    msleep(1000 * changeMsleep);

    create_drive_direct(-50 * leftM, -100 * rightM);//gets out of start box
    msleep(1000 * changeMsleep);

    create_drive_direct(-300 * leftM, -300 * rightM);//goes to get first rocks
    msleep(4000 * changeMsleep);
    
    
    //Segment 2
    create_drive_direct(-200 * leftM,-0 * rightM);//perfect 90* turn
    msleep(1350 * changeMsleep);
    
    create_drive_direct(-200 * leftM,-195 * rightM);//pushes rocks into box
    msleep(2500 * changeMsleep);

    create_drive_direct(-0 * leftM,-200 * rightM);
    msleep(1000 * changeMsleep);
    
    enable_servos();//closes arm
    set_servo_position(0, 930);
    
    
    //Segment 3
    create_drive_direct(100 * leftM, 100 * rightM);//fixed (backs out of the E zone)
    msleep(1000 * changeMsleep);

    create_drive_direct(-0 * leftM, 205 * rightM);
    msleep(1350 * changeMsleep);//this is supposed to turn a correct ammount 

    
    //Segment 4
    while (get_create_rbump() == 0 && get_create_lbump() == 0) //backs to be the very center of the T shaped PVC
    { 
        create_drive_direct(300 * leftM, 300 * rightM);
    }
    
    create_drive_direct(-200 * leftM,200 * rightM); //turns to not collide with demobot
    msleep(1000 * changeMsleep);

    create_disconnect();
    msleep(5000);//waiting
    create_connect();

    create_drive_direct(200 * leftM,-200 * rightM); //turns to go straight again
    msleep(1000 * changeMsleep);

    
    //Segment 5
    create_drive_direct(-200 * leftM,0 * rightM); //it turns towards the orange poms
    msleep(650 * changeMsleep);
    
    enable_servos();//opens scissors
    set_servo_position(0, 1500);

    create_drive_direct(-200 * leftM,-199 * rightM);//now it goes forwards
    msleep(3000 * changeMsleep);

    create_drive_direct(0 * leftM,-200 * rightM); //turns back to be purpendicular to the board
    msleep(650 * changeMsleep);

    create_drive_direct(200 * leftM,200 * rightM); //backs up
    msleep(1000 * changeMsleep);
    
    
    //Segment 6
    create_drive_direct(0 * leftM,200 * rightM); //turns to go back to the T
    msleep(1300 * changeMsleep);

    create_drive_direct(200 * leftM,200 * rightM);//backs up a small bit
    msleep(1000 * changeMsleep);

    create_drive_direct(200 * leftM,0 * rightM); //Levels out to the T again
    msleep(1300 * changeMsleep);

    
    //Segment 7
    while (get_create_rbump() == 0 && get_create_lbump() == 0) //backs to be the very center of the T shaped PVC
    { 
        create_drive_direct(100 * leftM, 100 * rightM);
    }
    
    while(get_create_rcliff_amt() > thresholdR || get_create_lcliff_amt() > thresholdL)	//lines up on black line
    {
        if(get_create_rcliff_amt() > thresholdR)
        {
            create_drive_direct(0 * leftM,-100 * rightM);
        }
        if(get_create_lcliff_amt() > thresholdL)
        {
            create_drive_direct(-100 * leftM,0 * rightM);
        }
    }
    
	while (get_create_rbump() == 0 && get_create_lbump() == 0) //backs to be the very center of the T shaped PVC
    { 
        create_drive_direct(100 * leftM, 100 * rightM);
    }
    
    //Segment 8
    ao();
    
    create_disconnect();
    return 0;
}
