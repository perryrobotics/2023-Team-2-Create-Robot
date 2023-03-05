#include <kipr/wombat.h>
#include "movement.h"
#include "sensors.h"
#include "effectors.h"
#include "constants.h"
int main()
{
    printf("Hello World!\n");

    create_connect();
    create_full(); //CONETCT
    
    enable_servos();
    msleep(2000);
    //GET INTO START POSITION
    
    move_servo_slowly(ARM, ARM_DOWN+350); //START POSITION
    claw_botgall();
    printf("lets'a go\n");
    msleep(5000);
    
    //wait_for_light(LIGHT); //WAIT FOR LIGHT
    shut_down_in(119);
    //enable_servos();
    //claw_botgall();
    arm_up();
    claw_open();

    
	drive_to_black(200); //MOVE FORWARD TO BOTGALL
    forward_mm(200,600);
    CW(100,30);
    drive_to_black(200);
    forward_mm(200,100);
    CCW(100, 70);
    forward_mm(200,225); //LINE UP WITH PIPE
    
    claw_botgall();//GRAB BOTGALL
    arm_liftb(); 

   
   
    backward_mm(200, 73); //GET TO THE BUMP
    
    CW(200,80);
   // turn to face far end of table
    drive_to_bump(200);
  
    forward_mm(200,50);//GET TO THE ANALISIS LAB
    CW(200, 78);
   
    forward_mm(200, 500);
    CCW(200, 70);
    forward_mm(200, 300);
    //arm_down();  // DROP HER!
    move_servo_slowly(ARM, ARM_DOWN);
    msleep(500); // CALM DOWN BEFORE OPEN
    claw_open();
    msleep(1000);
      arm_up();
    // ============================BOTGALL DELIVERED=========================
    msleep(3000);
    drive_to_bump(200); // GET TO CUBE
    forward_mm(200, 50);
    CW(200, 70);
    forward_mm(200,400); // LINE UP WITH PIPE IN START BOX
    msleep(32400); //WAIT FOR MAD SCIENTIST
    drive_to_black(-200);//GO FORWARD TO CUBE
    drive_to_bump(200);
    forward_mm(200, 60);
    CCW(200, 190);
    forward_mm(200,50);
    move_servo_slowly(ARM,ARM_CUBE);
    claw_cube(); // GRAB CUBE FIRST CUBE
    msleep(1000);
    arm_up();
    CW(200,10);
    drive_to_bump(200); //GET TO ANALISIS LAB
    CW(200,105);
    forward_mm(200,450);
    CCW(200, 20);//turn to face analysis lab
   
  
     // drop FIRST cube
    move_servo_slowly(ARM, ARM_DOWN);
    move_servo_slowly(CLAW, CLAW_OPEN);  // CUBE ONE SCORED!!
    
    // ==============GET CUBE TWO!!===================
    arm_up();
    backward_mm(200, 200); //GET OUT OF ANALISIS LAB
    
    CCW(200, 55); //GET TO CUBE 2
    forward_mm(200, 730); // go forward to align with cube before turning to it
  
    CCW(200,55);
    forward_mm(200, 520);

    claw_botgall();//GRAB CUBE 2
    arm_liftb(); // CUBE TWO GRABBED
    backward_mm(200, 250);
    
    CW(200,245);
    forward_mm(200,150);
    //arm_down();
    move_servo_slowly(ARM,ARM_DOWN+100); //DELIVER CUBE 2
    //move_servo_slowly(CLAW,CLAW_CUBE-350);
    
    disable_servos();
    create_disconnect();
    msleep(9000);
    
    return 0;
}
