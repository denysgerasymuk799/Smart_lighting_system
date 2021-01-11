/*******************************************************************************
* File Name: Isr_Heart_beat.h
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
#if !defined(CY_ISR_Isr_Heart_beat_H)
#define CY_ISR_Isr_Heart_beat_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Isr_Heart_beat_Start(void);
void Isr_Heart_beat_StartEx(cyisraddress address);
void Isr_Heart_beat_Stop(void);

CY_ISR_PROTO(Isr_Heart_beat_Interrupt);

void Isr_Heart_beat_SetVector(cyisraddress address);
cyisraddress Isr_Heart_beat_GetVector(void);

void Isr_Heart_beat_SetPriority(uint8 priority);
uint8 Isr_Heart_beat_GetPriority(void);

void Isr_Heart_beat_Enable(void);
uint8 Isr_Heart_beat_GetState(void);
void Isr_Heart_beat_Disable(void);

void Isr_Heart_beat_SetPending(void);
void Isr_Heart_beat_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Isr_Heart_beat ISR. */
#define Isr_Heart_beat_INTC_VECTOR            ((reg32 *) Isr_Heart_beat__INTC_VECT)

/* Address of the Isr_Heart_beat ISR priority. */
#define Isr_Heart_beat_INTC_PRIOR             ((reg32 *) Isr_Heart_beat__INTC_PRIOR_REG)

/* Priority of the Isr_Heart_beat interrupt. */
#define Isr_Heart_beat_INTC_PRIOR_NUMBER      Isr_Heart_beat__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Isr_Heart_beat interrupt. */
#define Isr_Heart_beat_INTC_SET_EN            ((reg32 *) Isr_Heart_beat__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Isr_Heart_beat interrupt. */
#define Isr_Heart_beat_INTC_CLR_EN            ((reg32 *) Isr_Heart_beat__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Isr_Heart_beat interrupt state to pending. */
#define Isr_Heart_beat_INTC_SET_PD            ((reg32 *) Isr_Heart_beat__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Isr_Heart_beat interrupt. */
#define Isr_Heart_beat_INTC_CLR_PD            ((reg32 *) Isr_Heart_beat__INTC_CLR_PD_REG)



#endif /* CY_ISR_Isr_Heart_beat_H */


/* [] END OF FILE */
