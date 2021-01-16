/*******************************************************************************
* File Name: Isr_Waiting_Time.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_Isr_Waiting_Time_H)
#define CY_ISR_Isr_Waiting_Time_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Isr_Waiting_Time_Start(void);
void Isr_Waiting_Time_StartEx(cyisraddress address);
void Isr_Waiting_Time_Stop(void);

CY_ISR_PROTO(Isr_Waiting_Time_Interrupt);

void Isr_Waiting_Time_SetVector(cyisraddress address);
cyisraddress Isr_Waiting_Time_GetVector(void);

void Isr_Waiting_Time_SetPriority(uint8 priority);
uint8 Isr_Waiting_Time_GetPriority(void);

void Isr_Waiting_Time_Enable(void);
uint8 Isr_Waiting_Time_GetState(void);
void Isr_Waiting_Time_Disable(void);

void Isr_Waiting_Time_SetPending(void);
void Isr_Waiting_Time_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Isr_Waiting_Time ISR. */
#define Isr_Waiting_Time_INTC_VECTOR            ((reg32 *) Isr_Waiting_Time__INTC_VECT)

/* Address of the Isr_Waiting_Time ISR priority. */
#define Isr_Waiting_Time_INTC_PRIOR             ((reg32 *) Isr_Waiting_Time__INTC_PRIOR_REG)

/* Priority of the Isr_Waiting_Time interrupt. */
#define Isr_Waiting_Time_INTC_PRIOR_NUMBER      Isr_Waiting_Time__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Isr_Waiting_Time interrupt. */
#define Isr_Waiting_Time_INTC_SET_EN            ((reg32 *) Isr_Waiting_Time__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Isr_Waiting_Time interrupt. */
#define Isr_Waiting_Time_INTC_CLR_EN            ((reg32 *) Isr_Waiting_Time__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Isr_Waiting_Time interrupt state to pending. */
#define Isr_Waiting_Time_INTC_SET_PD            ((reg32 *) Isr_Waiting_Time__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Isr_Waiting_Time interrupt. */
#define Isr_Waiting_Time_INTC_CLR_PD            ((reg32 *) Isr_Waiting_Time__INTC_CLR_PD_REG)



#endif /* CY_ISR_Isr_Waiting_Time_H */


/* [] END OF FILE */
