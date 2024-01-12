#include <kipr/wombat.h>
#include "Demobot Functions.h"

int main()
{
    //Square up in starting box
    squareUpReverse();
    msleep(100);
    
    blackLineDetect(4000);
    driveDistance(5);
    //Second Black line from starting box
    blackLineDetect(4000);
    
    
    printf("End of Program. Sucess!");
    return 0;
}
