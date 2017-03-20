/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : CE1.c
**     Project     : FRDM-KL27Z_McuOnEclipseLib
**     Processor   : MKL25Z128VLK4
**     Component   : SDK_BitIO
**     Version     : Component 01.022, Driver 01.00, CPU db: 3.00.000
**     Repository  : Legacy User Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-03-17, 08:48, # CodeGen: 119
**     Abstract    :
**
**     Settings    :
**          Component name                                 : CE1
**          SDK                                            : MCUC1
**          GPIO Name                                      : GPIOA
**          PORT Name                                      : PORTA
**          Pin Number                                     : 4
**          Pin Symbol                                     : nRF_CE
**          Do Pin Muxing                                  : yes
**          Init Direction                                 : Output
**          Init Value                                     : 0
**     Contents    :
**         GetDir    - bool CE1_GetDir(void);
**         SetDir    - void CE1_SetDir(bool Dir);
**         SetInput  - void CE1_SetInput(void);
**         SetOutput - void CE1_SetOutput(void);
**         GetVal    - bool CE1_GetVal(void);
**         PutVal    - void CE1_PutVal(bool Val);
**         ClrVal    - void CE1_ClrVal(void);
**         SetVal    - void CE1_SetVal(void);
**         NegVal    - void CE1_NegVal(void);
**         Init      - void CE1_Init(void);
**         Deinit    - void CE1_Deinit(void);
**
**     * Copyright (c) 2015-2017, Erich Styger
**      * Web:         https://mcuoneclipse.com
**      * SourceForge: https://sourceforge.net/projects/mcuoneclipse
**      * Git:         https://github.com/ErichStyger/McuOnEclipse_PEx
**      * All rights reserved.
**      *
**      * Redistribution and use in source and binary forms, with or without modification,
**      * are permitted provided that the following conditions are met:
**      *
**      * - Redistributions of source code must retain the above copyright notice, this list
**      *   of conditions and the following disclaimer.
**      *
**      * - Redistributions in binary form must reproduce the above copyright notice, this
**      *   list of conditions and the following disclaimer in the documentation and/or
**      *   other materials provided with the distribution.
**      *
**      * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**      * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**      * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**      * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**      * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**      * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**      * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**      * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**      * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**      * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file CE1.c
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup CE1_module CE1 module documentation
**  @{
*/         

/* MODULE CE1. */

#include "CE1.h"
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  #include "fsl_port.h" /* include SDK header file for port muxing */
  #include "fsl_gpio.h" /* include SDK header file for GPIO */
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  #include "fsl_gpio_driver.h" /* include SDK header file for GPIO */
#else
  #error "This component only works with the Kinetis SDK!"
#endif

#if MCUC1_CONFIG_NXP_SDK_2_0_USED

  static const gpio_pin_config_t CE1_configOutput = {
    kGPIO_DigitalOutput,  /* use as output pin */
    CE1_CONFIG_INIT_PIN_VALUE,  /* initial value */
  };

  static const gpio_pin_config_t CE1_configInput = {
    kGPIO_DigitalInput,  /* use as input pin */
    CE1_CONFIG_INIT_PIN_VALUE,  /* initial value */
  };
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  const gpio_output_pin_user_config_t CE1_OutputConfig[] = {
    {
      .pinName = nRF_CE,
      .config.outputLogic = CE1_CONFIG_INIT_PIN_VALUE,
    #if FSL_FEATURE_PORT_HAS_SLEW_RATE
      .config.slewRate = kPortSlowSlewRate,
    #endif
    #if FSL_FEATURE_PORT_HAS_OPEN_DRAIN
      .config.isOpenDrainEnabled = true,
    #endif
    #if FSL_FEATURE_PORT_HAS_DRIVE_STRENGTH
      .config.driveStrength = kPortLowDriveStrength,
    #endif
    },
    {
      .pinName = GPIO_PINS_OUT_OF_RANGE,
    }
  };

  const gpio_input_pin_user_config_t CE1_InputConfig[] = {
    {
      .pinName = nRF_CE,
    #if FSL_FEATURE_PORT_HAS_PULL_ENABLE
      .config.isPullEnable = true,
    #endif
    #if FSL_FEATURE_PORT_HAS_PULL_SELECTION
      .config.pullSelect = kPortPullDown,
    #endif
    #if FSL_FEATURE_PORT_HAS_PASSIVE_FILTER
      .config.isPassiveFilterEnabled = true,
    #endif
    #if FSL_FEATURE_PORT_HAS_DIGITAL_FILTER
      .config.isDigitalFilterEnabled = true,
    #endif
    #if FSL_FEATURE_GPIO_HAS_INTERRUPT_VECTOR
      .config.interrupt = kPortIntDisabled
    #endif
    },
    {
      .pinName = GPIO_PINS_OUT_OF_RANGE,
    }
  };

#endif

static bool CE1_isOutput = false;
/*
** ===================================================================
**     Method      :  CE1_ClrVal (component SDK_BitIO)
**     Description :
**         Clears the pin value (sets it to a low level)
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void CE1_ClrVal(void)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  GPIO_ClearPinsOutput(CE1_CONFIG_GPIO_NAME, 1<<CE1_CONFIG_PIN_NUMBER);
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_ClearPinOutput(nRF_CE);
#endif
}

/*
** ===================================================================
**     Method      :  CE1_SetVal (component SDK_BitIO)
**     Description :
**         Sets the pin value to a high value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void CE1_SetVal(void)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  GPIO_SetPinsOutput(CE1_CONFIG_GPIO_NAME, 1<<CE1_CONFIG_PIN_NUMBER);
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_SetPinOutput(nRF_CE);
#endif
}

/*
** ===================================================================
**     Method      :  CE1_NegVal (component SDK_BitIO)
**     Description :
**         Toggles/negates the pin value
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void CE1_NegVal(void)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  GPIO_TogglePinsOutput(CE1_CONFIG_GPIO_NAME, 1<<CE1_CONFIG_PIN_NUMBER);
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_TogglePinOutput(nRF_CE);
#endif
}

/*
** ===================================================================
**     Method      :  CE1_GetVal (component SDK_BitIO)
**     Description :
**         Returns the pin value
**     Parameters  : None
**     Returns     :
**         ---             - Returns the value of the pin:
**                           FALSE/logical level '0' or TRUE/logical
**                           level '1'
** ===================================================================
*/
bool CE1_GetVal(void)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  return GPIO_ReadPinInput(CE1_CONFIG_GPIO_NAME, CE1_CONFIG_PIN_NUMBER)!=0;
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  return GPIO_DRV_ReadPinInput(nRF_CE)!=0;
#else
  return FALSE;
#endif
}

/*
** ===================================================================
**     Method      :  CE1_GetDir (component SDK_BitIO)
**     Description :
**         Return the direction of the pin (input/output)
**     Parameters  : None
**     Returns     :
**         ---             - FALSE if port is input, TRUE if port is
**                           output
** ===================================================================
*/
bool CE1_GetDir(void)
{
  return CE1_isOutput;
}

/*
** ===================================================================
**     Method      :  CE1_SetDir (component SDK_BitIO)
**     Description :
**         Sets the direction of the pin (input or output)
**     Parameters  :
**         NAME            - DESCRIPTION
**         Dir             - FALSE: input, TRUE: output
**     Returns     : Nothing
** ===================================================================
*/
void CE1_SetDir(bool Dir)
{
  if (Dir) {
    CE1_SetOutput();
  } else {
    CE1_SetInput();
  }
}

/*
** ===================================================================
**     Method      :  CE1_SetInput (component SDK_BitIO)
**     Description :
**         Sets the pin as input
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void CE1_SetInput(void)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  GPIO_PinInit(CE1_CONFIG_GPIO_NAME, CE1_CONFIG_PIN_NUMBER, &CE1_configInput);
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_SetPinDir(nRF_CE, kGpioDigitalInput);
#endif
  CE1_isOutput = false;
}

/*
** ===================================================================
**     Method      :  CE1_SetOutput (component SDK_BitIO)
**     Description :
**         Sets the pin as output
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void CE1_SetOutput(void)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  GPIO_PinInit(CE1_CONFIG_GPIO_NAME, CE1_CONFIG_PIN_NUMBER, &CE1_configOutput);
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_SetPinDir(nRF_CE, kGpioDigitalOutput);
#endif
  CE1_isOutput = true;
}

/*
** ===================================================================
**     Method      :  CE1_PutVal (component SDK_BitIO)
**     Description :
**         Sets the pin value
**     Parameters  :
**         NAME            - DESCRIPTION
**         Val             - Value to set. FALSE/logical '0' or
**                           TRUE/logical '1'
**     Returns     : Nothing
** ===================================================================
*/
void CE1_PutVal(bool Val)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  if (Val) {
    GPIO_SetPinsOutput(CE1_CONFIG_GPIO_NAME, 1<<CE1_CONFIG_PIN_NUMBER);
  } else {
    GPIO_ClearPinsOutput(CE1_CONFIG_GPIO_NAME, 1<<CE1_CONFIG_PIN_NUMBER);
  }
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_WritePinOutput(nRF_CE, Val);
#endif
}

/*
** ===================================================================
**     Method      :  CE1_Init (component SDK_BitIO)
**     Description :
**         Driver initialization method
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void CE1_Init(void)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  #if CE1_CONFIG_DO_PIN_MUXING
  PORT_SetPinMux(CE1_CONFIG_PORT_NAME, CE1_CONFIG_PIN_NUMBER, kPORT_MuxAsGpio); /* mux as GPIO */
  #endif
#if CE1_CONFIG_INIT_PIN_DIRECTION == CE1_CONFIG_INIT_PIN_DIRECTION_INPUT
  CE1_SetInput();
#elif CE1_CONFIG_INIT_PIN_DIRECTION == CE1_CONFIG_INIT_PIN_DIRECTION_OUTPUT
  CE1_SetOutput();
#endif
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  /*! \todo Pin Muxing not implemented */
  GPIO_DRV_Init(CE1_InputConfig, CE1_OutputConfig);
#endif
}

/*
** ===================================================================
**     Method      :  CE1_Deinit (component SDK_BitIO)
**     Description :
**         Driver de-initialization method
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void CE1_Deinit(void)
{
  /* nothing needed */
}

/* END CE1. */

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/