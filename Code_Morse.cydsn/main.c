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
#include "letters_to_Morze_table.h"

#include <stdio.h>
#include <string.h>

char TEXT_BUF[20];

int get_letter_pos(char letter){
    int n_letter_in_table = -1;
    
    for (int n_letter_detail = 0; n_letter_detail < 4; n_letter_detail++){
        if (letter == letter_to_morse[n_letter_detail][0]){
            n_letter_in_table = n_letter_detail;
            break;
        }
    }
    
    return n_letter_in_table;
}

void word_to_morse(char word[]){
    int dot_len_delay = 500;
    int dash_period = 500;
    int dot_period = 9500;
    
    int i = 0;
    //int interrupt_flag  = 0;
    int n_letter_in_table = 0;
    
    for (uint16 n_letter = 0; n_letter < strlen(word); n_letter++){
        n_letter_in_table = get_letter_pos(word[n_letter]);
        
        uint16 letter_morze_code = letter_to_morse[n_letter_in_table][1];
        uint16 dash_or_dot_bit = 0x01;
        int len_morse_letter = letter_to_morse[n_letter_in_table][2];
        
        sprintf(TEXT_BUF,"\n");
        UART_UartPutString(TEXT_BUF);
        
        for (i = 0; i < len_morse_letter; i++){
            //interrupt_flag = 0;
            Pin_Red_Write(1);
            
            sprintf(TEXT_BUF,"%d\r\n", dash_or_dot_bit);
            UART_UartPutString(TEXT_BUF);
            
            if (letter_morze_code & dash_or_dot_bit){ // even if result == 4 will make this part of if
                // Dash
                PWM_1_WriteCompare(dash_period); // switches from low to high, if more - so less brightness
                PWM_1_Start();
                
                CyDelay(3 * dot_len_delay);
                Pin_Red_Write(0);
            } else {
                // Dot
                PWM_1_WriteCompare(dot_period);
                PWM_1_Start();
                
                CyDelay(dot_len_delay);
                Pin_Red_Write(0);
                }

            dash_or_dot_bit = dash_or_dot_bit << 1;
            CyDelay(dot_len_delay);
            PWM_1_Stop();
        }
        CyDelay(3 * dot_len_delay);
        }
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    /* Start SCB UART TX+RX operation */    
    UART_Start(); 
    UART_UartPutString("Start UART\n");
    
    CyDelay(100);
    
    char word[] = {'a', 'b', 'd'};
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    word_to_morse(word);
}
/* [] END OF FILE */
