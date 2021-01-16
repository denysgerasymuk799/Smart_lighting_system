/*******************************************************************************
* File Name: Change_Role_Isr.h
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
#if !defined(CY_ISR_Change_Role_Isr_H)
#define CY_ISR_Change_Role_Isr_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Change_Role_Isr_Start(void);
void Change_Role_Isr_StartEx(cyisraddress address);
void Change_Role_Isr_Stop(void);

CY_ISR_PROTO(Change_Role_Isr_Interrupt);

void Change_Role_Isr_SetVector(cyisraddress address);
cyisraddress Change_Role_Isr_GetVector(void);

void Change_Role_Isr_SetPriority(uint8 priority);
uint8 Change_Role_Isr_GetPriority(void);

void Change_Role_Isr_Enable(void);
uint8 Change_Role_Isr_GetState(void);
void Change_Role_Isr_Disable(void);

void Change_Role_Isr_SetPending(void);
void Change_Role_Isr_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Change_Role_Isr ISR. */
#define Change_Role_Isr_INTC_VECTOR            ((reg32 *) Change_Role_Isr__INTC_VECT)

/* Address of the Change_Role_Isr ISR priority. */
#define Change_Role_Isr_INTC_PRIOR             ((reg32 *) Change_Role_Isr__INTC_PRIOR_REG)

/* Priority of the Change_Role_Isr interrupt. */
#define Change_Role_Isr_INTC_PRIOR_NUMBER      Change_Role_Isr__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Change_Role_Isr interrupt. */
#define Change_Role_Isr_INTC_SET_EN            ((reg32 *) Change_Role_Isr__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Change_Role_Isr interrupt. */
#define Change_Role_Isr_INTC_CLR_EN            ((reg32 *) Change_Role_Isr__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Change_Role_Isr interrupt state to pending. */
#define Change_Role_Isr_INTC_SET_PD            ((reg32 *) Change_Role_Isr__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Change_Role_Isr interrupt. */
#define Change_Role_Isr_INTC_CLR_PD            ((reg32 *) Change_Role_Isr__INTC_CLR_PD_REG)



#endif /* CY_ISR_Change_Role_Isr_H */


/* [] END OF FILE */
