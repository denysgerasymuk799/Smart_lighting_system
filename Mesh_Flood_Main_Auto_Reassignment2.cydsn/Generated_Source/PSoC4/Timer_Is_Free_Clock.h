/*******************************************************************************
* File Name: Timer_Is_Free_Clock.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Timer_Is_Free_Clock_H)
#define CY_CLOCK_Timer_Is_Free_Clock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void Timer_Is_Free_Clock_StartEx(uint32 alignClkDiv);
#define Timer_Is_Free_Clock_Start() \
    Timer_Is_Free_Clock_StartEx(Timer_Is_Free_Clock__PA_DIV_ID)

#else

void Timer_Is_Free_Clock_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void Timer_Is_Free_Clock_Stop(void);

void Timer_Is_Free_Clock_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 Timer_Is_Free_Clock_GetDividerRegister(void);
uint8  Timer_Is_Free_Clock_GetFractionalDividerRegister(void);

#define Timer_Is_Free_Clock_Enable()                         Timer_Is_Free_Clock_Start()
#define Timer_Is_Free_Clock_Disable()                        Timer_Is_Free_Clock_Stop()
#define Timer_Is_Free_Clock_SetDividerRegister(clkDivider, reset)  \
    Timer_Is_Free_Clock_SetFractionalDividerRegister((clkDivider), 0u)
#define Timer_Is_Free_Clock_SetDivider(clkDivider)           Timer_Is_Free_Clock_SetDividerRegister((clkDivider), 1u)
#define Timer_Is_Free_Clock_SetDividerValue(clkDivider)      Timer_Is_Free_Clock_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define Timer_Is_Free_Clock_DIV_ID     Timer_Is_Free_Clock__DIV_ID

#define Timer_Is_Free_Clock_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define Timer_Is_Free_Clock_CTRL_REG   (*(reg32 *)Timer_Is_Free_Clock__CTRL_REGISTER)
#define Timer_Is_Free_Clock_DIV_REG    (*(reg32 *)Timer_Is_Free_Clock__DIV_REGISTER)

#define Timer_Is_Free_Clock_CMD_DIV_SHIFT          (0u)
#define Timer_Is_Free_Clock_CMD_PA_DIV_SHIFT       (8u)
#define Timer_Is_Free_Clock_CMD_DISABLE_SHIFT      (30u)
#define Timer_Is_Free_Clock_CMD_ENABLE_SHIFT       (31u)

#define Timer_Is_Free_Clock_CMD_DISABLE_MASK       ((uint32)((uint32)1u << Timer_Is_Free_Clock_CMD_DISABLE_SHIFT))
#define Timer_Is_Free_Clock_CMD_ENABLE_MASK        ((uint32)((uint32)1u << Timer_Is_Free_Clock_CMD_ENABLE_SHIFT))

#define Timer_Is_Free_Clock_DIV_FRAC_MASK  (0x000000F8u)
#define Timer_Is_Free_Clock_DIV_FRAC_SHIFT (3u)
#define Timer_Is_Free_Clock_DIV_INT_MASK   (0xFFFFFF00u)
#define Timer_Is_Free_Clock_DIV_INT_SHIFT  (8u)

#else 

#define Timer_Is_Free_Clock_DIV_REG        (*(reg32 *)Timer_Is_Free_Clock__REGISTER)
#define Timer_Is_Free_Clock_ENABLE_REG     Timer_Is_Free_Clock_DIV_REG
#define Timer_Is_Free_Clock_DIV_FRAC_MASK  Timer_Is_Free_Clock__FRAC_MASK
#define Timer_Is_Free_Clock_DIV_FRAC_SHIFT (16u)
#define Timer_Is_Free_Clock_DIV_INT_MASK   Timer_Is_Free_Clock__DIVIDER_MASK
#define Timer_Is_Free_Clock_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_Timer_Is_Free_Clock_H) */

/* [] END OF FILE */
