/*******************************************************************************
* File Name: ADC_MIC_PM.c
* Version 2.50
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ADC_MIC.h"


/***************************************
* Local data allocation
***************************************/

static ADC_MIC_BACKUP_STRUCT  ADC_MIC_backup =
{
    ADC_MIC_DISABLED,
    0u    
};


/*******************************************************************************
* Function Name: ADC_MIC_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ADC_MIC_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_MIC_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ADC_MIC_RestoreConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_MIC_Sleep
********************************************************************************
*
* Summary:
*  Stops the ADC operation and saves the configuration registers and component
*  enable state. Should be called just prior to entering sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_MIC_backup - modified.
*
*******************************************************************************/
void ADC_MIC_Sleep(void)
{
    /* During deepsleep/ hibernate mode keep SARMUX active, i.e. do not open
    *   all switches (disconnect), to be used for ADFT
    */
    ADC_MIC_backup.dftRegVal = ADC_MIC_SAR_DFT_CTRL_REG & (uint32)~ADC_MIC_ADFT_OVERRIDE;
    ADC_MIC_SAR_DFT_CTRL_REG |= ADC_MIC_ADFT_OVERRIDE;
    if((ADC_MIC_SAR_CTRL_REG  & ADC_MIC_ENABLE) != 0u)
    {
        if((ADC_MIC_SAR_SAMPLE_CTRL_REG & ADC_MIC_CONTINUOUS_EN) != 0u)
        {
            ADC_MIC_backup.enableState = ADC_MIC_ENABLED | ADC_MIC_STARTED;
        }
        else
        {
            ADC_MIC_backup.enableState = ADC_MIC_ENABLED;
        }
        ADC_MIC_StopConvert();
        ADC_MIC_Stop();
        
        /* Disable the SAR internal pump before entering the chip low power mode */
        if((ADC_MIC_SAR_CTRL_REG & ADC_MIC_BOOSTPUMP_EN) != 0u)
        {
            ADC_MIC_SAR_CTRL_REG &= (uint32)~ADC_MIC_BOOSTPUMP_EN;
            ADC_MIC_backup.enableState |= ADC_MIC_BOOSTPUMP_ENABLED;
        }
    }
    else
    {
        ADC_MIC_backup.enableState = ADC_MIC_DISABLED;
    }
}


/*******************************************************************************
* Function Name: ADC_MIC_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component enable state and configuration registers.
*  This should be called just after awaking from sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_MIC_backup - used.
*
*******************************************************************************/
void ADC_MIC_Wakeup(void)
{
    ADC_MIC_SAR_DFT_CTRL_REG = ADC_MIC_backup.dftRegVal;
    if(ADC_MIC_backup.enableState != ADC_MIC_DISABLED)
    {
        /* Enable the SAR internal pump  */
        if((ADC_MIC_backup.enableState & ADC_MIC_BOOSTPUMP_ENABLED) != 0u)
        {
            ADC_MIC_SAR_CTRL_REG |= ADC_MIC_BOOSTPUMP_EN;
        }
        ADC_MIC_Enable();
        if((ADC_MIC_backup.enableState & ADC_MIC_STARTED) != 0u)
        {
            ADC_MIC_StartConvert();
        }
    }
}
/* [] END OF FILE */
