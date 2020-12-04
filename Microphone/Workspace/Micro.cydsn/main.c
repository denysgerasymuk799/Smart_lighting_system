/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_Start();
    char rez[30];
    for(;;)
    {
        //Pin_2_Write(~Pin_2_Read());
        sprintf(rez, "%d\n", Pin_1_Read());
        
        UART_UartPutString(rez);
        CyDelay(50);
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
