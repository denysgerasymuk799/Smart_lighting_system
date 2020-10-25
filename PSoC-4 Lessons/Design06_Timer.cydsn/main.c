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

CY_ISR (Timer_Int_Handler)
{
    uint16 counter = Timer_1_ReadCapture();
    
    if (counter > 10000)
    {
        counter = 10000;
    }
    PWM_1_WriteCompare(counter);
    
    Timer_1_ClearInterrupt(Timer_1_INTR_MASK_CC_MATCH);
 }

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    PWM_1_Start();
    
    Timer_1_Start();
    
    Timer_Int_StartEx(Timer_Int_Handler);
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    int i = 1;
    for(;;)
    {
    }
}

/* [] END OF FILE */
    