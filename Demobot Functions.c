#include "functions.h"
#include <kipr/wombat.h>

void LFSQR()
{
    
   
    while(digital(0) == 0 && digital(1) == 0)
    {
   	  	if (digital(0) == 1 || digital(1) == 1)
     { 
         if (digital(0) == 1)
         {
         motor(0, 100);
         }
         else
         	{
                motor(1, 100);
            }
     }
     	else if (analog(0) >= 3650)
   		{   
        motor(0, 25);
        motor(1, 50);
     	} 
        
   	 	else if (analog(0) < 3650)     
    	{    
        motor(0, 50);
    	motor(1, 25);
     	}  
    
    }
}



void R90(int deg)
{






    cmpc(0);
    while(gmpc(0)<26.11*deg) 
    //while(gmpc(0)<2200*1) //Right 90
    {
        motor(0,56);
        motor(1,-1);
    }
    ao();
}

void L90()
{



    cmpc(1);
    while(gmpc(1)<2200*1) //Right 90
    {
        motor(1,50);
        motor(0,-1);
    }
    ao();
}

void F12()
{


    cmpc(0);
    cmpc(1);
    while(gmpc(1)<2420*1 || gmpc(0)<2420*1) //Multiply by 1 for 12 inches. Makes straight line.
    {
        motor(0,50);
        motor(1,50);
    }
    ao();

}

void B12()
{


    cmpc(0);
    cmpc(1);
    while(gmpc(1)>-2420*1 || gmpc(0)>-2420*1) //Multiply by 1 for 12 inches. Makes straight line.
    {
        motor(0,-50);
        motor(1,-50);
    }
    ao();



}

void SC() //servo cloosed
{
    enable_servos();
    set_servo_position(0, 2000);
    msleep(50);
    set_servo_position(0, 1500);
    msleep(50);
    set_servo_position(0, 1000);
    msleep(50);
    set_servo_position(0, 650);
    msleep(50);
    set_servo_position(0, 450);
    msleep(50);
    set_servo_position(0, 300);
    msleep(50);
    set_servo_position(0, 200);
    msleep(50);
    set_servo_position(0, 100);
    msleep(50);
    set_servo_position(0, 0);

}

void F6()
{


    cmpc(0);
    cmpc(1);
    while(gmpc(1)<2420/2 || gmpc(0)<2420/2) // Six-Inch Makes straight line.
    {
        motor(0,50);
        motor(1,50);
    }
    ao();
}


void B6()
{


    cmpc(0);
    cmpc(1);
    while(gmpc(1)>-2420/2 || gmpc(0)>-2420/2) //Multiply by 1 for 12 inches. Makes straight line.
    {
        motor(0,-50);
        motor(1,-50);
    }
    ao();



}

// this is brody approved do not change
void SO()//servo open 
{
    enable_servos();
    set_servo_position(0, 300);
    msleep(50);
    set_servo_position(0, 400);
    msleep(50);
    set_servo_position(0, 650);
    msleep(50);
    set_servo_position(0, 780);
    msleep(50);
    set_servo_position(0, 900);
    msleep(50);
    set_servo_position(0, 1150);
    msleep(50);
	set_servo_position(0, 1200);
    msleep(50);
    set_servo_position(0, 1500);
    msleep(50);
    set_servo_position(0, 1700);
    msleep(50);
    set_servo_position(0, 2000);
    msleep(50);
}

void F1()
{


    cmpc(0);
    cmpc(1);
    while(gmpc(1)<2420/12 || gmpc(0)<2420/12) //Multiply by 1 for 12 inches. Makes straight line.
    {
        motor(0,50);
        motor(1,50);
    }
    ao();

}


void B1()
{


    cmpc(0);
    cmpc(1);
    while(gmpc(1)>-2420/12 || gmpc(0)>-2420/12) //Multiply by 1 for 12 inches. Makes straight line.
    {
        motor(0,-50);
        motor(1,-50);
    }
    ao();



}


void SQR()
{
	while(digital(0) == 0 && digital(1) == 0)
    {
    
    if(digital(0)==0)
    {
    	motor(0, 25);
    } 
    if(digital(3)==0)
    {
        motor(1, 25);
    }
    }
}

void SQRB()
{
	while(digital(4) == 0 && digital(5) == 0)
    {
    
    if(digital(0)==0)
    {
    	motor(0, -25);
    } 
    if(digital(3)==0)
    {
        motor(1, -25);
    }
    }
}

void LF()
{
    
 int X = 2000;
    
    while((X) >= 1)
    {
   	 if(analog(0) >= 3850)
   		{   
        motor(0, 25);
        motor(1, 50);
     	} 
   	 if(analog(0) < 3850)     
    	{    
        motor(0, 50);
    	motor(1, 25);
     	}   
    
    }
}

void BTB() //back up till the tophat is on black
{
    while(analog(0) <= 3850)
    {  
        motor(0, -50);
        motor(1, -50);
    }
}



void SD(int a) //servo down
{
    enable_servos();
    set_servo_position(1, 1000);
    msleep(100);
    set_servo_position(1, 950);
    msleep(100);
    set_servo_position(1, 900);
    msleep(100);
    set_servo_position(1, 850);
    msleep(100);
    set_servo_position(1, 800);
    msleep(100);
    set_servo_position(1, 750);
    msleep(100);
    set_servo_position(1, 700);
    msleep(100);
    set_servo_position(1, 650);
    msleep(100);
    set_servo_position(1, 600);
    msleep(100);
    set_servo_position(1, 550);
    msleep(100);
    set_servo_position(1, 500);
    msleep(100);
    set_servo_position(1, 450);
    msleep(100);
    set_servo_position(1, 400);
    msleep(100);
    set_servo_position(1, 350);
    msleep(100);
    set_servo_position(1, a);
}

void SU() //servo up
{
    enable_servos();
    set_servo_position(1, 250);
    msleep(100);
    set_servo_position(1, 300);
    msleep(100);
    set_servo_position(1, 350);
    msleep(100);
    set_servo_position(1, 400);
    msleep(100);
    set_servo_position(1, 450);
    msleep(100);
    set_servo_position(1, 500);
    msleep(100);
    set_servo_position(1, 550);
    msleep(100);
    set_servo_position(1, 600);
    msleep(100);
    set_servo_position(1, 650);
    msleep(100);
    set_servo_position(1, 700);
    msleep(100);
    set_servo_position(1, 750);
    msleep(100);
    set_servo_position(1, 800);
    msleep(100);
    set_servo_position(1, 850);
    msleep(100);
    set_servo_position(1, 900);
    msleep(100);
    set_servo_position(1, 950);
    msleep(100);
    set_servo_position(1, 1000);
    msleep(100);
    set_servo_position(1, 1300);
    
}


void GFPBL()
    {
     	while (analog(0) < 3850)
        {
        motor(0, 100);
        motor(1, 100);
        }
    }

void SUH()
	{
		enable_servos();
    	set_servo_position(1, 250);
    	msleep(200);
    	set_servo_position(1, 300);
    	msleep(200);
    	set_servo_position(1, 350);
    	msleep(200);
   	 	set_servo_position(1, 400);
   	 	msleep(200);
    	set_servo_position(1, 450);
    	msleep(200);
    	set_servo_position(1, 500);
    	msleep(200);
    	set_servo_position(1, 550);
    	msleep(200);
	}

void SDH()
	{
		enable_servos();
    	set_servo_position(1, 1000);
    	msleep(100);
    	set_servo_position(1, 950);
    	msleep(100);
    	set_servo_position(1, 900);
    	msleep(100);
    	set_servo_position(1, 850);
    	msleep(100);
    	set_servo_position(1, 800);
    	msleep(100);
    	set_servo_position(1, 750);
    	msleep(100);
    	set_servo_position(1, 700);
    	msleep(100);
    	set_servo_position(1, 650);
    	msleep(100);
    	set_servo_position(1, 600);
    	msleep(100);
    	set_servo_position(1, 550);
    	msleep(100);
	}

void LFSQRB()
{
    
    while(digital(4) == 0 && digital(5) == 0)
    {
   	  	if (digital(4) == 1)
        {
     		motor(1, -25);
            motor(0, 0);
     	}
        
        else if (digital(5) == 1)
        {
     		motor(0, -25);
            motor(1, 0);
     	}
        
        else if (analog(1) > 3650)     
    	{    
        motor(0, -40);
    	motor(1, -50);
     	}  
        
     	else if (analog(1) <= 3650)
   		{   
        motor(0, -50);
        motor(1, -40);
     	} 
        
   	 	
    
    }
     
}

void SSP(int a)
{
    enable_servos();
    set_servo_position(1, a);
}

void ForwardDrive(int dis)
{


    cmpc(0);
    cmpc(1);
    while(gmpc(1)<200*dis || gmpc(0)<200*dis) //Makes straight line with set number of inches
    {
        motor(0,50);
        motor(1,50);
    }
    ao();

}


void L45()
{



    cmpc(1);
    while(gmpc(1)>-1100*1) //left 90
    {
        motor(1,-50);
        motor(0,1);
    }
    ao();
}

void R45()
{
	cmpc(0);
    while(gmpc(0)>-1100*1) //Right 90
    {
        motor(1, 1);
        motor(0,-50);
    }
    ao();


 //ghouae
}