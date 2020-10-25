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

CY_ISR (Counter_Int_Handler)
{
    Pin_Green_Write( ~ Pin_Green_Read());
    
    Counter_ClearInterrupt(Counter_INTR_MASK_TC);
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Counter_Start();
    Counter_Int_StartEx(Counter_Int_Handler);
    for(;;)
    {
        // Pin_Red_Write( Pin_SW2_Read() );
        // Pin_Blue_Write(~Pin_Blue_Read());

    }
}

/* [] END OF FILE */
    