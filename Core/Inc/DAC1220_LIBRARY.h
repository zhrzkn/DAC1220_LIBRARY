/*
 * DAC1220_LIBRARY.h
 *
 *  Created on: Apr 14, 2022
 *      Author: MONSTER
 */

#ifndef INC_DAC1220_LIBRARY_H_
#define INC_DAC1220_LIBRARY_H_


void SPI_DAC_RESET();
void SPI_DAC_SELFCAL();




/*Register Memory Map*/

#define DIR_Byte2  0x00
#define DIR_Byte1  0x01
#define DIR_Byte0  0x02
#define CMR_Byte1  0x04
#define CMR_Byte0  0x05
#define OCR_Byte2  0x08
#define OCR_Byte1  0x09
#define OCR_Byte0  0x0A
#define FCR_Byte2  0x0B
#define FCR_Byte1  0x0C
#define FCR_Byte0  0x0D


#define R_REGISTER_2Byte    0x0A
#define R_REGISTER_3Byte    0x0C
#define W_REGISTER_2Byte    0x20
#define W_REGISTER_3Byte    0x40

#define RESOLUTION_16Bit    0x21
#define RESOLUTION_20Bit    0x1A

//
//uint8_t CommandRegMSB = 0;
//      // ADPT
//      CommandRegMSB |= (DISF << 7);
//      // CALPIN
//      CommandRegMSB &= ~(1 << 6);
//      // CRST
//      CommandRegMSB |= (CRST << 1);
//
//      uint8_t CommandRegLSB = 0;
//      // RES
//      CommandRegLSB |= (RES << 7);
//      // CLR
//      CommandRegLSB |= (CRST << 6);
//      // DF
//      CommandRegLSB |= (DF << 5);
//      // DISF
//      CommandRegLSB |= (DISF << 4);
//      // MSB
//      CommandRegLSB |= (MSB << 2);
//      // MD
//      CommandRegLSB |= (MD << 0);

void SPI_DAC_RESET();
void SPI_DAC_SELFCAL();

#endif /* INC_DAC1220_LIBRARY_H_ */
