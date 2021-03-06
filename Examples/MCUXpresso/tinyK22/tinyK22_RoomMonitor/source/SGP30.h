/*
 * SGP30.h
 *
 *  Created on: 01.10.2018
 *      Author: Erich Styger
 */

#ifndef SOURCES_SGP30_H_
#define SOURCES_SGP30_H_

#include <stdint.h>
#include "MCUC1.h"

#define SGP30_I2C_ADDRESS   (0x58)  ///< 7bit I2C address of the device

#if MCUC1_CONFIG_CPU_IS_LITTLE_ENDIAN
  #define SGP30_FEATURESET       0x2000  ///< The required set for this library
#else
  #define SGP30_FEATURESET       0x0020  ///< The required set for this library
#endif
#define SGP30_CRC8_POLYNOMIAL  0x31    ///< Seed for SGP30's CRC polynomial
#define SGP30_CRC8_INIT        0xFF    ///< Init value for CRC
#define SGP30_WORD_LEN          2      ///< 2 bytes per word

/* Commands the sensor to take a single eCO2/VOC measurement. */
uint8_t SGP30_IAQmeasure(uint16_t *pTVOC, uint16_t *pCO2);

/* Request baseline calibration values for both CO2 and TVOC IAQ calculations. */
uint8_t SGP30_GetIAQBaseline(uint16_t *pTVOCbase, uint16_t *pCO2base);


uint8_t SGP30_Init(void);


#endif /* SOURCES_SGP30_H_ */
