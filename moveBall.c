#include "config.h"
#include "arrays.h"
//uchar col = 2;  // starting position of ball
//uchar row = 4;

void moveBall(bool ballState)// ballState is either start(1) or stop(0))
{
    
    /*static char colSpeed;
    static char rowSpeed;
    if(ballState == START)
    {
         colSpeed = 1;
         rowSpeed = 1;
    }
    else if(ballState == STOP)
    {
         colSpeed = 0;
         rowSpeed = 0;
    }*/
        
    
    if(x < 2 || x >=14)
    {
        xSpeed = -xSpeed;
        //count = count + 1;
        //printf("%d\n", count);
    }
    if(y < 1 || y >= 7)
    {
        ySpeed = -ySpeed;
       
    }
    gameArray[(int)y][(int)x] = 1;
     x = x + xSpeed;
     y = y + ySpeed;
    
    //printf("gameArray[%d][%d] = %d\n", y, x, gameArray[y][x]);
}
