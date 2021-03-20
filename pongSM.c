#include "config.h"
#include "arrays.h"
#include "splashScreen.h"
#include "drawPaddle.h"
#include "writeMatrix.h"
#include "printDigit.h"
uchar pongSM(uchar state)
{
    switch(state)
    {
        case 0:
        splashScreen(splishR, splishL);
         __delay_ms(250);   
         state = 1;
        break;            // display 'PONG' splashscreen for 1 sec, then clear screen
        
        case 1:
         splashScreen(plyL, plyR);// display L 1 R 2 player
         while(LPB1&&RPB1==HI);     // wait for player selection button press
         if(LPB1==LO&&RPB1==HI)     // L = 1 plyr, R = 2 plyr
         {
             state = 2;
         }
         else if(LPB1==HI&&RPB1==LO)
         {
             state = 3;
         }
        break;
        
        case 2:
        writeMatrix(0,7,0,15);              // write gameArray[][] which contains all zeros
        drawPaddle(lPaddle, 0);             // draw paddle on left col 0 
        writeMatrix(0,7,0,0);
        drawPaddle(rBarrier,15);            // draw wall on right col 15
        writeMatrix(0,7,15,15);
        state = 4;
        break;
        
        
        case 3:
         writeMatrix(0,7,0,15);             // write gameArray[][] which contains all zeros
        drawPaddle(lPaddle, 0);             // draw paddle on left col 0 
        writeMatrix(0,7,0,0);
        drawPaddle(rPaddle,15);            // draw paddle on right col 15
        writeMatrix(0,7,15,15);
        state = 4;
        break;
        
        case 4:
            gameArray[5][1] = HI;       // draw ball at row 5, col 1
            writeMatrix(0,7,1,1);
            
            printDigit(6,8,tres);       // count down from 3 to 0 before ball starts to move
            __delay_ms(100);
            printDigit(6,8,dos);
            __delay_ms(100);
            printDigit(6,8,uno);
            __delay_ms(100);
            printDigit(6,8,cero);
            __delay_ms(100);
            printDigit(6,8,null);
            state = 5;
        break;
            
        case 5:
                        //start ball moving
        break;
    }
    return state;
}
