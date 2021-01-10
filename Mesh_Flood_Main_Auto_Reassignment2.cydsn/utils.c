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

int MIN_WAITING_TIME = 2000;

void restart_peripheral_waiting_time()
{
    UART_UartPutString("\n\n start restart_peripheral_waiting_time \n \n");
    Timer_1_Stop();
    Timer_1_WriteCounter(0);
    
    Timer_1_Start();
    Timer_1_WritePeriod(DEVICE_INDEX * MIN_WAITING_TIME);
}


/* [] END OF FILE */
