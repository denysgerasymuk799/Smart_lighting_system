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
    
    PWM_1_Start();
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    int i = 1;
    for(;;)
    {
        // Pin_Red_Write( Pin_SW2_Read() );
        // Pin_Blue_Write(~Pin_Blue_Read());
        PWM_1_WriteCompare(i);
        CyDelay(100);
        i += 100;
        if (i >= 9000) i = 0;
        
        
        

    }
}

/* [] END OF FILE */
    