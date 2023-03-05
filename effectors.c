#include <kipr/wombat.h>
#include "effectors.h"
#include "constants.h"

void claw_open()
{
    set_servo_position(CLAW, CLAW_OPEN);
    msleep(750);
}

void claw_botgall()  
{ 
    set_servo_position(CLAW, CLAW_BOTGALL);
    msleep(750);
}

void arm_up()
{
    set_servo_position(ARM, ARM_UP);
    msleep(750);
}

void arm_down()
{
    set_servo_position(ARM, ARM_DOWN);
    msleep(750);
}

void arm_liftb()
{
    set_servo_position(ARM, ARM_LIFT);
    msleep(750);
}

void claw_cube()
{
    set_servo_position(CLAW, CLAW_CUBE);
    msleep(250);
}
void move_servo_slowly(int port, int end_pos)
{
    int current_pos;

    current_pos = get_servo_position(port);
    printf("%d, %d\n", current_pos, end_pos);

    if(current_pos < end_pos)
    {

        while (current_pos < end_pos)
        {
            current_pos += 10;
            set_servo_position(port, current_pos);
            msleep(30);
        }  
    }   
    else
    {
        while (current_pos > end_pos)
        {
            current_pos -= 10;
            set_servo_position(port, current_pos);
            msleep(30);
        } 

    }

    set_servo_position(port, end_pos);
}
void arm_cube()
{
    set_servo_position(ARM, ARM_CUBE);
    msleep(750);
}
