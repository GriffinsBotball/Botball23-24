#include <kipr/wombat.h>
#include "Create3Functions.h"

int main()
{
//Setup
create3_connect();

// Move claw and drive to first rocks
timeServo(0,1500,1);

driveDistance(180);
turnDegrees(-90);

driveDistance(50);
turnDegrees(45);

driveDistance(20);


create3_disconnect();
return 0;
}