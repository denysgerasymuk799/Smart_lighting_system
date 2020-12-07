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
#include <stdlib.h>

char TEXT_BUF[20];
int DOT_LEN_DELAY = 500;


int get_letter_pos(char letter){
    int n_letter_in_table = -1;
    
    for (int n_letter_detail = 0; n_letter_detail < 20; n_letter_detail++){
        if (letter == letter_to_morse[n_letter_detail][0]){
            n_letter_in_table = n_letter_detail;
            break;
        }
    }
    
    return n_letter_in_table;
}

void word_to_morse(char word[]){
    int dash_period = 500;
    int dot_period = 9500;
    
    int i = 0;
    int n_letter_in_table = 0;
    
    PWM_1_Start();
    //Pin_Red_Write(0);
    CyDelay(1000);
    for (uint16 n_letter = 0; n_letter < strlen(word); n_letter++){
        if (word[n_letter] == ' ') {
            sprintf(TEXT_BUF,"\nspace\r\n");
            CyDelay(7 * DOT_LEN_DELAY);
            UART_UartPutString(TEXT_BUF);
            continue;
        }
        n_letter_in_table = get_letter_pos(word[n_letter]);
        
        uint16 letter_morze_code = letter_to_morse[n_letter_in_table][1];
        uint16 dash_or_dot_bit = 0x01;
        int len_morse_letter = letter_to_morse[n_letter_in_table][2];
        
        //sprintf(TEXT_BUF,"\n");
        //UART_UartPutString(TEXT_BUF);
        
        sprintf(TEXT_BUF,"\nletter == %c\r\n", word[n_letter]);
        UART_UartPutString(TEXT_BUF);
        
        for (i = 0; i < len_morse_letter; i++){
            Pin_Red_Write(1);
            
            if (letter_morze_code & dash_or_dot_bit){ // even if result == 4 will make this part of if
                // Dash
                //Pin_Red_Write(0);
                sprintf(TEXT_BUF,"1 ");
                UART_UartPutString(TEXT_BUF);
                
                PWM_1_WriteCompare(dash_period); // switches from low to high, if more - so less brightness
                //PWM_1_Start();
                
                CyDelay(3 * DOT_LEN_DELAY);
                Pin_Red_Write(0);
            } else {
                // Dot
                //Pin_Red_Write(1);
                sprintf(TEXT_BUF,"0 ");
                UART_UartPutString(TEXT_BUF);
                PWM_1_WriteCompare(dot_period);
                //PWM_1_Start();
                
                CyDelay(DOT_LEN_DELAY);
                Pin_Red_Write(0);
                }

            dash_or_dot_bit = dash_or_dot_bit << 1;
            CyDelay(DOT_LEN_DELAY);
            //PWM_1_Stop();
        }
        CyDelay(3 * DOT_LEN_DELAY);
        }
}

int main(void)
{
    Pin_Red_Write(0);
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    /* Start SCB UART TX+RX operation */    
    UART_Start(); 
    UART_UartPutString("Start UART\n");
    
    CyDelay(1000);
    
    //char word[] = {'a', 'b', 'd', 'e'};
    //char word[] = {'h', 'e', 'l', 'l', 'o'};
    char word[100];
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    //word_to_morse(word);
    
    uint8 ch;
    int idx = 0;
    for(;;)
    {
        ch = UART_UartGetChar();
        
        if (ch==0) continue;
        
        UART_UartPutChar(ch);
        
        if (ch == '.') {
            word[idx++] = '\0';
            word_to_morse(word);
            free(word);
            idx = 0;
        } else {
            word[idx++] = ch;
        }
    }
}
/* [] END OF FILE */
