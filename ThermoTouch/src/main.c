/**
 ******************************************************************************
 * @file    BSP/Src/main.c
 * @author  MCD Application Team
 * @version V1.0.0
 * @date    25-June-2015
 * @brief   This example code shows how to use the STM32746G Discovery BSP Drivers
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT(c) 2015 STMicroelectronics</center></h2>
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *   3. Neither the name of STMicroelectronics nor the names of its contributors
 *      may be used to endorse or promote products derived from this software
 *      without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup STM32F7xx_HAL_Examples
 * @{
 */

/** @addtogroup BSP
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Global extern variables ---------------------------------------------------*/

uint8_t TSstatus;






#ifndef USE_FULL_ASSERT
uint32_t ErrorCounter = 0;
#endif

/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
//static void Display_DemoDescription(void);
static void CPU_CACHE_ENABLE(void);

/*
 BSP_DemoTypedef  BSP_examples[] =
 {
 {LCD_demo, "LCD", 0},
 {Touchscreen_demo, "TOUCHSCREEN", 0},
 //    {AudioRec_demo, "AUDIO RECORD", 0},
 //    {AudioLoopback_demo, "AUDIO LOOPBACK", 0},
 //    {AudioPlay_demo, "AUDIO PLAY", 0},
 //    {SD_demo, "mSD", 0},
 //    {Log_demo, "LCD LOG", 0},
 //    {SDRAM_demo, "SDRAM", 0},
 //    {SDRAM_DMA_demo, "SDRAM DMA", 0},
 {EEPROM_demo, "EEPROM", 0},
 //    {QSPI_demo, "QSPI", 0},
 };
 */
/* Private functions ---------------------------------------------------------*/

/**
 * @brief  Main program
 * @param  None
 * @retval None
 */

/**
 * @brief  System Clock Configuration
 *         The system Clock is configured as follow :
 *            System Clock source            = PLL (HSE)
 *            SYSCLK(Hz)                     = 200000000
 *            HCLK(Hz)                       = 200000000
 *            AHB Prescaler                  = 1
 *            APB1 Prescaler                 = 4
 *            APB2 Prescaler                 = 2
 *            HSE Frequency(Hz)              = 25000000
 *            PLL_M                          = 25
 *            PLL_N                          = 400
 *            PLL_P                          = 2
 *            PLL_Q                          = 8
 *            VDD(V)                         = 3.3
 *            Main regulator output voltage  = Scale1 mode
 *            Flash Latency(WS)              = 5
 * @param  None
 * @retval None
 */
static void SystemClock_Config(void) {
	HAL_StatusTypeDef ret = HAL_OK;
	RCC_ClkInitTypeDef RCC_ClkInitStruct;
	RCC_OscInitTypeDef RCC_OscInitStruct;

	/* Enable Power Control clock */
	__HAL_RCC_PWR_CLK_ENABLE()
	;

	/* The voltage scaling allows optimizing the power consumption when the device is
	 clocked below the maximum system frequency, to update the voltage scaling value
	 regarding system frequency refer to product datasheet.  */
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/* Enable HSE Oscillator and activate PLL with HSE as source */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 25;
	RCC_OscInitStruct.PLL.PLLN = 400;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 8;
	ret = HAL_RCC_OscConfig(&RCC_OscInitStruct);
	ASSERT(ret != HAL_OK);

	/* activate the OverDrive to reach the 180 Mhz Frequency */
	ret = HAL_PWREx_ActivateOverDrive();
	ASSERT(ret != HAL_OK);

	/* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
	 clocks dividers */
	RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	ret = HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);
	ASSERT(ret != HAL_OK);
}

/**
 * @brief  Display main demo messages.
 * @param  None
 * @retval None
 */

/**
 * @brief  Check for user input.
 * @param  None
 * @retval Input state (1 : active / 0 : Inactive)
 */
uint8_t CheckForUserInput(void) {
	if (BSP_PB_GetState(BUTTON_KEY) != RESET) {
		HAL_Delay(10);
		while (BSP_PB_GetState(BUTTON_KEY) != RESET)
			;
		return 1;
	}
	return 0;
}

/**
 * @brief  Toggle Leds.
 * @param  None
 * @retval None
 */
void Toggle_Leds(void) {
	static uint32_t ticks = 0;

	if (ticks++ > 200) {
		BSP_LED_Toggle(LED1);
		ticks = 0;
	}
}

/**
 * @brief EXTI line detection callbacks.
 * @param GPIO_Pin: Specifies the pins connected EXTI line
 * @retval None
 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	static uint32_t debounce_time = 0;

	if (GPIO_Pin == KEY_BUTTON_PIN) {
		/* Prevent debounce effect for user key */
		if ((HAL_GetTick() - debounce_time) > 50) {
			debounce_time = HAL_GetTick();
		}
	}
}

/**
 * @brief  CPU L1-Cache enable.
 *         Invalidate Data cache before enabling
 *         Enable Data & Instruction Cache
 * @param  None
 * @retval None
 */
static void CPU_CACHE_ENABLE(void) {
	(*(uint32_t *) 0xE000ED94) &= ~0x5;
	(*(uint32_t *) 0xE000ED98) = 0x0; //MPU->RNR
	(*(uint32_t *) 0xE000ED9C) = 0x20010000 | 1 << 4; //MPU->RBAR
	(*(uint32_t *) 0xE000EDA0) = 0 << 28 | 3 << 24 | 0 << 19 | 0 << 18 | 1 << 17
			| 0 << 16 | 0 << 8 | 30 << 1 | 1 << 0; //MPU->RASE  WT
	(*(uint32_t *) 0xE000ED94) = 0x5;

	/* Invalidate I-Cache : ICIALLU register*/
	SCB_InvalidateICache();

	/* Enable branch prediction */
	SCB->CCR |= (1 << 18);
	__DSB();

	/* Enable I-Cache */
	SCB_EnableICache();

	/* Enable D-Cache */
	SCB_InvalidateDCache();
	SCB_EnableDCache();
}

#ifdef USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t* file, uint32_t line)
{
	/* User can add his own implementation to report the file name and line number,
	 ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while (1)
	{
	}
}
#endif /* USE_FULL_ASSERT */

uint32_t lastTick100ms;

bool elapsed100ms()
{
	uint32_t t=HAL_GetTick()-lastTick100ms;
	if(t<100)
		return false;
	lastTick100ms=HAL_GetTick();
	return true;
}


int main(void) {
	uint8_t lcd_status = LCD_OK;

	CPU_CACHE_ENABLE();
	HAL_Init();
	SystemClock_Config();
	BSP_LED_Init(LED1);
	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
	lcd_status = BSP_LCD_Init();
	ASSERT(lcd_status != LCD_OK);
	BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FRAME_BUFFER);
	BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
	BSP_LCD_SetFont(&LCD_DEFAULT_FONT);

	modbusInit(19200);
	mainScreenInit();
	rtcInit();

	while (1) {
		if(elapsed100ms())
		{
			checkTouch();
			updateScreen();

		}
		modbusUpdate();
	}

}

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
