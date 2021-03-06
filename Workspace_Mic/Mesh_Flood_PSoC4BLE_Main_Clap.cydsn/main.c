    /******************************************************************************
* Project Name		: Mesh_Flood_PSoC4BLE
* File Name			: main.c
* Version 			: 1.0
* Device Used		: CY8C4247LQI-BL483
* Software Used		: PSoC Creator 3.1 SP1
* Compiler    		: ARM GCC 4.8.4, ARM RVDS Generic, ARM MDK Generic
* Related Hardware	: CY8CKIT-042-BLE Bluetooth Low Energy Pioneer Kit 
* Owner             : roit@cypress.com
*
********************************************************************************
* Copyright (2014-15), Cypress Semiconductor Corporation. All Rights Reserved.
********************************************************************************
* This software is owned by Cypress Semiconductor Corporation (Cypress)
* and is protected by and subject to worldwide patent protection (United
* States and foreign), United States copyright laws and international treaty
* provisions. Cypress hereby grants to licensee a personal, non-exclusive,
* non-transferable license to copy, use, modify, create derivative works of,
* and compile the Cypress Source Code and derivative works for the sole
* purpose of creating custom software in support of licensee product to be
* used only in conjunction with a Cypress integrated circuit as specified in
* the applicable agreement. Any reproduction, modification, translation,
* compilation, or representation of this software except as specified above 
* is prohibited without the express written permission of Cypress.
*
* Disclaimer: CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH 
* REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* Cypress reserves the right to make changes without further notice to the 
* materials described herein. Cypress does not assume any liability arising out 
* of the application or use of any product or circuit described herein. Cypress 
* does not authorize its products for use as critical components in life-support 
* systems where a malfunction or failure may reasonably be expected to result in 
* significant injury to the user. The inclusion of Cypress' product in a life-
* support systems application implies that the manufacturer assumes all risk of 
* such use and in doing so indemnifies Cypress against all charges. 
*
* Use of this Software may be limited by and subject to the applicable Cypress
* software license agreement. 
*******************************************************************************/
#include <main.h>
#include <customize.h>
#include <stdio.h>

extern uint8 switch_Role;
extern uint8 ble_gap_state;
extern uint8 deviceConnected;

extern uint8 restartScanning;

extern uint8 dataADVCounter;


#ifdef ENABLE_ADV_DATA_COUNTER
extern CYBLE_GAPP_DISC_DATA_T  new_advData;
extern uint8 potential_node_found;
extern uint8 potential_node_bdAddr[6];
extern uint8 potential_node_bdAddrType;
#endif

extern uint8 clientConnectToDevice;
extern CYBLE_GAP_BD_ADDR_T				peripAddr;

CY_ISR_PROTO(CC_TC_InterruptHandler);
void Change_brightness();


uint8 RGB_Collection[4][4] = {
    {0, 0, 0xFF, 0xFF},
    {0xFF, 0, 0xFF, 0xFF},
    {0, 0xFF, 0, 0xFF},
    {0xFF, 0xFF, 0, 0xFF},
};

uint8 On_Off_collection[2] = {0, 0xFF};

int interrupt_counter = 0;
int on_off_counter = 0;

int compare;
uint16 val;
uint16 prev_val;
uint16 init_val;

int clap_counter = 0;

/*******************************************************************************
* Function Name: main
********************************************************************************
* Summary:
*       Entry point for the firmware, Starts the system and continuously processes
* Application and BLE events.
*
* Parameters:
*  void
*
* Return:
*  int
*
*******************************************************************************/
int main()
{
    /* Initialize system */	
	InitializeSystem();
	
	#ifdef DEBUG_ENABLED
		UART_UartPutString("Sytem Started ");
		UART_UartPutCRLF(' ');
	#endif
   
    
    
    for(;;)
    {
		/* Process BLE Events. This function generates the respective 
		* events to application layer */
		CyBle_ProcessEvents();

		/* If flag is set, then switch the GAP role between Peripheral and 
		* Central. This function disconnects existing connection, if any, 
		* before switching role. Depending on switched role, the system will
		* either start scanning or start advertisement */
		SwitchRole();
		
		/* If a valid node is found, then this function will initiate a connection 
		* to that node. */
		ConnectToPeripheralDevice();
		
		/* This function will restart scanning when earlier connection has been
		* disconnected. This function also checks internal counter and sets flag to
		* switch role from Central to Peripheral when the count is above set value. */
		RestartCentralScanning();
        
        //Change_brightness();
    }
}
/*
CY_ISR(Timer_Int_Handler){
    clap_counter =Timer_Claps_ReadCapture();
    //if (counter > 10000){
      //  counter = 10000;
    //}
    char rez[30];
    sprintf(rez, "rewrite  = %d \n ", clap_counter);
    UART_UartPutString(rez);
    if (clap_counter > 450){
    }
    
    Timer_Claps_ClearInterrupt(Timer_Claps_INTR_MASK_CC_MATCH);
    
}*/

CY_ISR(Complete_Int_Handler){
    Pin_Timer_Clear_Write(1);
    //Pin_Timer_Clear_Write(0);
    //Pin_Timer_Clear_Write(1);
    char rez[30];
    sprintf(rez, "counter  = %d \n ", clap_counter);
    UART_UartPutString(rez);
    clap_counter = Timer_Claps_ReadCapture();
    sprintf(rez, "counter  = %d \n ", clap_counter);
    UART_UartPutString(rez);
    if (clap_counter < 350){
        
        CyGlobalIntDisable;
        
        on_off_counter++;
        if (on_off_counter == 2) {
            on_off_counter = 0;
        }
        
        interrupt_counter++;
        if (interrupt_counter == 4) {
                interrupt_counter = 0;
            }
        CyDelay(100);
        
        uint8 bright = On_Off_collection[on_off_counter];
        uint8 r[4];
        r[0] = RGB_Collection[interrupt_counter][0];
        r[1] = RGB_Collection[interrupt_counter][1];
        r[2] = RGB_Collection[interrupt_counter][2];
        r[3] = bright;
        
        sendColorDataToNetwork(r);
        SwitchRole();
    	ConnectToPeripheralDevice();
    	RestartCentralScanning();
        
        sprintf(rez, "small  = %d \n ", clap_counter);
        UART_UartPutString(rez);
        
        
        isr_complete_ClearPending();
        CyDelay(100);
        CyGlobalIntEnable;
    }else{
    
        on_off_counter++;
        if (on_off_counter == 2) {
            on_off_counter = 0;
        }
        
        
        CyGlobalIntDisable;
        uint8 bright = On_Off_collection[on_off_counter];
        uint8 r[4];
        r[0] = RGB_Collection[interrupt_counter][0];
        r[1] = RGB_Collection[interrupt_counter][1];
        r[2] = RGB_Collection[interrupt_counter][2];
        r[3] = bright;
        sendColorDataToNetwork(r);
        SwitchRole();
    	ConnectToPeripheralDevice();
    	RestartCentralScanning();
        
        sprintf(rez, "big  = %d \n ", clap_counter);
        UART_UartPutString(rez);
        
        
        isr_complete_ClearPending();
        CyDelay(100);
        CyGlobalIntEnable;
    }
    Pin_Timer_Clear_Write(0);
}

/*******************************************************************************
* Function Name: InitializeSystem
********************************************************************************
* Summary:
*       Starts the components in the project and registers BLE event handler 
* function. It also modifies the advertisement packet and appends data counter
* at its end.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void InitializeSystem(void)
{
    // ADC
    ADC_MIC_Start();
    ADC_MIC_StartConvert();
    uint16 val = ADC_MIC_GetResult16(0);
    uint16 prev_val;
    uint16 init_val = ADC_MIC_GetResult16(0);
    
    //isr_Counter_StartEx(CC_TC_InterruptHandler);
    
    // PWM
    //PWM_Brightness_Start();
    //int compare;
    
    
    //isr_Counter_SetPriority(0);
    
	/* Enable global interrupts. */
	CyGlobalIntEnable;
	
    Timer_Claps_Start();
    //isr_timer_StartEx(Timer_Int_Handler);
    isr_complete_StartEx(Complete_Int_Handler);
    
	/* Start BLE component and Register the generic Event callback function */
	CyBle_Start(GenericEventHandler);
    
    // Define interrupt handle for color changes
    //PWM_1sWindow_Start();
    //isr_Counter_StartEx(CC_TC_InterruptHandler);
	
	/* Start the PrISM component and configure drive mode of LED pins to be
	* initially OFF*/
	PrISM_1_Start();
	PrISM_2_Start();
	
	PrISM_1_WritePulse0(255);
	PrISM_1_WritePulse1(255);
	PrISM_2_WritePulse0(255);
	
	RED_SetDriveMode(RED_DM_STRONG);
	GREEN_SetDriveMode(GREEN_DM_STRONG);
	BLUE_SetDriveMode(BLUE_DM_STRONG);
	
	/* Configure the Watchdog (WDT) timer for 100 millisecond timing */
	InitializeWatchdog(WATCHDOG_COUNT_VAL);

	#ifdef ENABLE_ADV_DATA_COUNTER
	new_advData = *cyBle_discoveryModeInfo.advData;
	
	if( cyBle_discoveryModeInfo.advData->advDataLen < 29)
	{
		/* Initialize the DataCounter data in advertisement packet. This is custom data in 
		* ADV packet and used to track whether the RGB LED data is latest or not */
		new_advData.advData[cyBle_discoveryModeInfo.advData->advDataLen] = CUSTOM_ADV_DATA_MARKER;	
		new_advData.advData[cyBle_discoveryModeInfo.advData->advDataLen+1] = dataADVCounter;
		new_advData.advDataLen = cyBle_discoveryModeInfo.advData->advDataLen+2;
	}
	
	/* Assign the new ADV data to stack */
	cyBle_discoveryModeInfo.advData = &new_advData;
	#endif
	
    //Timet_new
	/* Provide a color pusle on RGB LED to indicate startup */
	//PrISM_1_WritePulse1(128);
	//CyDelay(20);
	//PrISM_1_WritePulse1(255);
	
    UART_Start();
    UART_UartPutString("Helloushki\n");
    
	#ifdef DEBUG_ENABLED
		
		UART_UartPutString("--------------------------Mesh Flood------------------------------------------");
		UART_UartPutCRLF(' ');
	#endif
}

void Change_brightness(){
    prev_val = val;
    val = ADC_MIC_GetResult16(0); // analog value from microphone
    if (init_val == 0){
    init_val = ADC_MIC_GetResult16(0);}
    compare = get_compare_from_analog(val, init_val, prev_val);
    RGB_Collection[interrupt_counter][3] = compare;
    char rez[30];
    sprintf(rez, "analog = %d led = %d \n ", val, compare);
    UART_UartPutString(rez);
    //PWM_Brightness_WriteCompare(compare); // change the brightness of LED
    
    sendColorDataToNetwork(RGB_Collection[interrupt_counter]);
}




/*******************************************************************************
* Function Name: UpdateRGBled
********************************************************************************
* Summary:
*        Update the RGB LED color by reconfiguring PrISM component. This function 
* is valid for PSoC 4 BLE parts and not PROC BLE, as PRoC BLE does not have UDBs
* that makes up the PrISM component. To replace this with software PrISM, refer to
* CY8CKIT-042-BLE Pioneer Kit example project, PRoC_BLE_CapSense_Slider_LED, from
* http://www.cypress.com/CY8CKIT-042-BLE
*
* Parameters:
*  rgb_led_data: array storing the RGB and Intensity vlaue
*  len: length of the array.
*
* Return:
*  void
*
*******************************************************************************/
void UpdateRGBled(uint8 * rgb_led_data, uint8 len)
{
	uint8 calc_red, calc_green, calc_blue;
	
	if(len == RGB_LED_DATA_LEN)
	{
		/* If a valid length packet has been sent, calculate the intensity of each of
		* R, G and B color and update the PrISM module */
		calc_red = (uint8)(((uint16)rgb_led_data[RGB_RED_INDEX]*rgb_led_data[RGB_INTENSITY_INDEX])/RGB_LED_MAX_VAL);
		calc_green = (uint8)(((uint16)rgb_led_data[RGB_GREEN_INDEX]*rgb_led_data[RGB_INTENSITY_INDEX])/RGB_LED_MAX_VAL);
		calc_blue = (uint8)(((uint16)rgb_led_data[RGB_BLUE_INDEX]*rgb_led_data[RGB_INTENSITY_INDEX])/RGB_LED_MAX_VAL);
		
		PrISM_1_WritePulse0(RGB_LED_MAX_VAL - calc_red);
		PrISM_1_WritePulse1(RGB_LED_MAX_VAL - calc_green);
		PrISM_2_WritePulse0(RGB_LED_MAX_VAL - calc_blue);
		
		#ifdef DEBUG_ENABLED
			UART_UartPutString("PrISM Updated ");
			UART_UartPutCRLF(' ');
		#endif
	}
}

/* [] END OF FILE */
