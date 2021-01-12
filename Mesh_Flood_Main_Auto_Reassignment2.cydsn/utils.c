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

#include "main.h"
#include "utils.h"

//int MIN_WAITING_TIME = 20000;

void restart_peripheral_waiting_time()
{
    if (DEVICE_INDEX != 0)
    {    
        UART_UartPutString("\n\n start restart_peripheral_waiting_time \n \n");
        Timer_Waiting_Time_Stop();
        Timer_Waiting_Time_WriteCounter(0);
        
        Timer_Waiting_Time_WritePeriod(Waiting_Time_Period);
        Timer_Waiting_Time_Start();
    }
}


/* [] END OF FILE */
