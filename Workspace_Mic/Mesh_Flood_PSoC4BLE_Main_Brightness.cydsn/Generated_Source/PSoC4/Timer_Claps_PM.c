/*******************************************************************************
* File Name: Timer_Claps_PM.c
* Version 2.10
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Timer_Claps.h"

static Timer_Claps_BACKUP_STRUCT Timer_Claps_backup;


/*******************************************************************************
* Function Name: Timer_Claps_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Timer_Claps_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: Timer_Claps_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Timer_Claps_Sleep(void)
{
    if(0u != (Timer_Claps_BLOCK_CONTROL_REG & Timer_Claps_MASK))
    {
        Timer_Claps_backup.enableState = 1u;
    }
    else
    {
        Timer_Claps_backup.enableState = 0u;
    }

    Timer_Claps_Stop();
    Timer_Claps_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_Claps_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Timer_Claps_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: Timer_Claps_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Timer_Claps_Wakeup(void)
{
    Timer_Claps_RestoreConfig();

    if(0u != Timer_Claps_backup.enableState)
    {
        Timer_Claps_Enable();
    }
}


/* [] END OF FILE */
