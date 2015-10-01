/*
 * modbus.h
 *
 *  Created on: 30 Sep 2015
 *      Author: Keith Bryer, InnovoDesign Ltd
 */

#ifndef INC_MODBUS_H_
#define INC_MODBUS_H_

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "stm32f7xx_hal.h"
#include "stm32746g_discovery.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/


#define USARTx                           USART6
#define USARTx_CLK_ENABLE()              __USART6_CLK_ENABLE()
#define USARTx_RX_GPIO_CLK_ENABLE()      __GPIOC_CLK_ENABLE()
#define USARTx_TX_GPIO_CLK_ENABLE()      __GPIOC_CLK_ENABLE()

#define USARTx_FORCE_RESET()             __USART6_FORCE_RESET()
#define USARTx_RELEASE_RESET()           __USART6_RELEASE_RESET()

/* Definition for USARTx Pins */
#define USARTx_TX_PIN                    GPIO_PIN_6
#define USARTx_TX_GPIO_PORT              GPIOC
#define USARTx_TX_AF                     GPIO_AF8_USART6
#define USARTx_RX_PIN                    GPIO_PIN_7
#define USARTx_RX_GPIO_PORT              GPIOC
#define USARTx_RX_AF                     GPIO_AF8_USART6



/* Exported functions ------------------------------------------------------- */

void modbusInit(int baud);
void modbusUpdate();



#endif /* INC_MODBUS_H_ */
