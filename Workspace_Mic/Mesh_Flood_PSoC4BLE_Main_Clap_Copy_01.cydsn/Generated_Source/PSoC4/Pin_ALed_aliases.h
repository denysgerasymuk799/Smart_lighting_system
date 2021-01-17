/*******************************************************************************
* File Name: Pin_ALed.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Pin_ALed_ALIASES_H) /* Pins Pin_ALed_ALIASES_H */
#define CY_PINS_Pin_ALed_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Pin_ALed_0			(Pin_ALed__0__PC)
#define Pin_ALed_0_PS		(Pin_ALed__0__PS)
#define Pin_ALed_0_PC		(Pin_ALed__0__PC)
#define Pin_ALed_0_DR		(Pin_ALed__0__DR)
#define Pin_ALed_0_SHIFT	(Pin_ALed__0__SHIFT)
#define Pin_ALed_0_INTR	((uint16)((uint16)0x0003u << (Pin_ALed__0__SHIFT*2u)))

#define Pin_ALed_INTR_ALL	 ((uint16)(Pin_ALed_0_INTR))


#endif /* End Pins Pin_ALed_ALIASES_H */


/* [] END OF FILE */
