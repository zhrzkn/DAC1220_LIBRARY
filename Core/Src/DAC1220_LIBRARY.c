/*
 * DAC1220_LIBRARY.c
 *
 *  Created on: Apr 14, 2022
 *      Author: MONSTER
 */

#include "DAC1220_LIBRARY.h"
#include "stm32f4xx_hal.h"

extern SPI_HandleTypeDef hspi2;
#define DAC1220E_SPI &hspi2


#define DAC1220E_CS_PORT   GPIOB
#define DAC1220E_CS_PIN    GPIO_PIN_5


void CS_Select (void)
{
	HAL_GPIO_WritePin( DAC1220E_CS_PORT, DAC1220E_CS_PIN, GPIO_PIN_RESET);
}

void CS_UnSelect (void)
{
	HAL_GPIO_WritePin( DAC1220E_CS_PORT, DAC1220E_CS_PIN , GPIO_PIN_SET);
}


void DAC1220E_WriteReg (uint8_t Reg, uint8_t Data)
{
	uint8_t dac_buf[2];
	dac_buf[0] = Reg|1<<5;
	dac_buf[1] = Data;

	// Pull the CS Pin LOW to select the device
	CS_Select();

	HAL_SPI_Transmit(DAC1220E_SPI, dac_buf, 2, 100);

	// Pull the CS HIGH to release the device
	CS_UnSelect();
}

void DAC1220E_WriteRegMulti (uint8_t Reg, uint8_t *data, int size)
{
	uint8_t dac_buf[2];
	dac_buf[0] = Reg|1<<5;


	// Pull the CS Pin LOW to select the device
	CS_Select();

	HAL_SPI_Transmit(DAC1220E_SPI, dac_buf, 1, 100);
	HAL_SPI_Transmit(DAC1220E_SPI, data, size, 100);

	// Pull the CS HIGH to release the device
	CS_UnSelect();
}

uint8_t DAC1220E_ReadReg (uint8_t Reg)
{
	uint8_t data=0;

	// Pull the CS Pin LOW to select the device
	CS_Select();

	HAL_SPI_Transmit(DAC1220E_SPI, &Reg, 1, 100);
	HAL_SPI_Receive(DAC1220E_SPI, &data, 1, 100);

	// Pull the CS HIGH to release the device
	CS_UnSelect();

	return data;
}


/* Read multiple bytes from the register */
void DAC1220E_ReadRegMulti (uint8_t Reg, uint8_t *data, int size)
{
	// Pull the CS Pin LOW to select the device
	CS_Select();

	HAL_SPI_Transmit(DAC1220E_SPI, &Reg, 1, 100);
	HAL_SPI_Receive(DAC1220E_SPI, data, size, 100);

	// Pull the CS HIGH to release the device
	CS_UnSelect();
}



void SPI_DAC_RESET()
{
	CS_Select();
	CS_UnSelect();
	HAL_Delay(264);

	CS_Select();
	CS_UnSelect();
	HAL_Delay(570);

	CS_Select();
	CS_UnSelect();
	HAL_Delay(903);
}

void SPI_DAC_SELFCAL()
{


}
