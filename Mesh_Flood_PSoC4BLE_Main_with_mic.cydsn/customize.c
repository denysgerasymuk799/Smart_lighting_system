#include <main.h>

extern uint8 RGBData;

int get_compare_from_analog(uint16 val, uint16 init_val, uint16 prev_val){
    /*if (val < init_val){
        val = init_val;
    }*/
    int diff = val > init_val ? val-init_val : init_val - val;
    
    CyDelay(150);
    return 10 + diff*12 ;
}