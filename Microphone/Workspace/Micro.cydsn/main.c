#include <stdio.h>

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

int get_compare_from_analog(uint16 val, uint16 init_val, uint16 prev_val){
    int change = val > prev_val ? val-prev_val : prev_val - val;
    
    if (change > 2){
        val = val > prev_val ? prev_val + 2 : prev_val - 2;
    }else{val = prev_val;}
    
    int diff = val > init_val ? val-init_val : init_val - val;
    CyDelay(150);
    
    return 1000 + 1000*(diff);
}

CY_ISR(CC_TC_InterruptHandler)
{
    Pin_DLed_Write(~Pin_DLed_Read());
    
    //isr_Counter_ClearPending();
    //CyDelay(100);
    
    //PWM_1sWindow_ClearInterrupt(PWM_1sWindow_INTR_MASK_CC_MATCH);
    //PWM_1sWindow_ClearInterrupt(PWM_1sWindow_INTR_MASK_TC);
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    // UART
    UART_Start();
    char rez[30];
    
    // ADC
    ADC_MIC_Start();
    ADC_MIC_StartConvert();
    uint16 val = ADC_MIC_GetResult16(0);
    uint16 prev_val;
    uint16 init_val = ADC_MIC_GetResult16(0);
    
    isr_Counter_StartEx(CC_TC_InterruptHandler);
    
    // PWM
    PWM_Brightness_Start();
    int compare;
    
    for(;;)
    {
        prev_val = val;
        val = ADC_MIC_GetResult16(0); // analog value from microphone
        
        compare = get_compare_from_analog(val, init_val, prev_val); 
        PWM_Brightness_WriteCompare(compare); // change the brightness of LED
        
        sprintf(rez, "analog = %d led = %d \n ", val, compare);
        UART_UartPutString(rez);
        
        CyDelay(10);
    }
}

/* [] END OF FILE */
