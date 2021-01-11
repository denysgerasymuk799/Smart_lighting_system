/*******************************************************************************
* File Name: Timer_Is_Free_PM.c
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

#include "Timer_Is_Free.h"

static Timer_Is_Free_BACKUP_STRUCT Timer_Is_Free_backup;


/*******************************************************************************
* Function Name: Timer_Is_Free_SaveConfig
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
void Timer_Is_Free_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: Timer_Is_Free_Sleep
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
void Timer_Is_Free_Sleep(void)
{
    if(0u != (Timer_Is_Free_BLOCK_CONTROL_REG & Timer_Is_Free_MASK))
    {
        Timer_Is_Free_backup.enableState = 1u;
    }
    else
    {
        Timer_Is_Free_backup.enableState = 0u;
    }

    Timer_Is_Free_Stop();
    Timer_Is_Free_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_Is_Free_RestoreConfig
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
void Timer_Is_Free_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: Timer_Is_Free_Wakeup
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
void Timer_Is_Free_Wakeup(void)
{
    Timer_Is_Free_RestoreConfig();

    if(0u != Timer_Is_Free_backup.enableState)
    {
        Timer_Is_Free_Enable();
    }
}


/* [] END OF FILE */
