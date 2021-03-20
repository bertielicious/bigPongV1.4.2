
#include "config.h"
#include "arrays.h"
#include "sendSPIbyte.h"
#include "sendNoSPIbyte.h"
//void _interrupt isr(void)
//__interrupt() void MY_ISR(void)
__interrupt() void SHIT(void)
//void interrupt my_SHIT(void)
{
    uchar col;
    uchar row;
    if(INTCONbits.TMR0IF == HI)
    {
        for(col = 1; col <15; col++)
        {
        for(row = 0; row < 8; row++)
        {
            if(gameArray[row][col] == 1)
            {
                gameArray[row][col] = 0;
            }
            else
            {
                continue;
            }
                    
        }
        }
        DIAGNOSTIC_GREEN_LED = ~DIAGNOSTIC_GREEN_LED;
        TMR0 = 116;
        INTCONbits.TMR0IF = 0;
        
        
    }
    if(PIR1bits.TMR1IF == 1)
    {
        DIAGNOSTIC_BLUE_LED = ~DIAGNOSTIC_BLUE_LED;
        count = count + 1;
        TMR1H = 0;
        TMR1L = 0;
        PIR1bits.TMR1IF = 0;
        
       
    }
}