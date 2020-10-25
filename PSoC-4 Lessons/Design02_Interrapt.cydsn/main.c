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

CY_ISR(Pin_SW2_Handler)
{
    Pin_Red_Write( Pin_Green_Read());    
    // Pin_Blue_Write(~ Pin_Blue_Read());    
    Pin_Green_Write(~ Pin_Red_Read());    
    
    Pin_SW2_ClearInterrupt();
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Pin_SW2_Intr_StartEx(Pin_SW2_Handler);
    for(;;)
    {
        // Pin_Red_Write( Pin_SW2_Read() );
        // Pin_Blue_Write(~Pin_Blue_Read());

    }
}

/* [] END OF FILE */
    