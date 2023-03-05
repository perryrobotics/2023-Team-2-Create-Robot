#include <kipr/wombat.h>
#include "movement.h"
#include "constants.h"

void drive_to_bump(int speed)
{
    create_drive_straight(speed);
    while ( (get_create_lbump() == 0) && (get_create_rbump() == 0) )
    {
    }
    
    create_drive_direct(0,0);
}

void drive_to_black(int speed)
{
    create_drive_straight(-speed);
    while ( (analog(LINE) < BLACK) )
    {
    }
    
    create_drive_direct(0,0);
}