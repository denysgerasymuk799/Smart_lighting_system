#include <main.h>
#include <customize.h>
#include <stdio.h>

extern uint8 RGBData;

int get_compare_from_analog(uint16 val, uint16 init_val, uint16 prev_val){
    /*if (val < init_val){
        val = init_val;
    }*/
    int diff = val > init_val ? val-init_val : init_val - val;
    
    char rez[30];
    sprintf(rez, "diff  = %d \n ", diff);
    UART_UartPutString(rez);
    CyDelay(50);
    return diff ;
}

int get_brightness_from_analog(uint16 val, uint16 init_val, uint16 prev_val){
    /*if (val < init_val){
        val = init_val;
    }*/
    int diff = val > init_val ? val-init_val : init_val - val;
    
    char rez[30];
    sprintf(rez, "diff  = %d \n ", diff);
    UART_UartPutString(rez);
    //CyDelay(150);
    CyDelay(50);
    
    return (val- 1110)*10;
}