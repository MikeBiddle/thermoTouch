/* @file    BSP/Src/mainscreen.c
 * @author  Keith Bryer, Innovodesign
 * @version V1.0.0
 * @date    25-Sept-2015
 * @brief   This provides the main screen

 ******************************************************************************
 * @attention
 *  ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/

#include "main.h"
#include "mainscreen.h"
#include "buttonBmp.h"
#include "button.h"
#include "rtc.h"
#include <stdbool.h>

/** @addtogroup Thermoscreens
 * @{
 */

/** @addtogroup Graphics
 * @{
 */
SCREEN_TypeDef screen;

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static TS_StateTypeDef TS_State;
bool lastTouch;
bool redraw;
/* Private function prototypes -----------------------------------------------*/
//static void mainscreen_SetHint(void);
/* Private functions ---------------------------------------------------------*/

/**
 * @brief  Touchscreen Demo
 * @param  None
 * @retval None
 */

void checkTouch(void) {
	uint8_t n;
	uint16_t x, y;
	if (TSstatus == TS_OK) {
		BSP_TS_GetState(&TS_State);
		if (TS_State.touchDetected && !lastTouch) {
			x = TS_State.touchX[0];
			y = TS_State.touchY[0];
			for (n = 0; n < buttonCount; n++)
				if (buttonHit(n, x, y))
					buttonList[n].onClick();
		}
		lastTouch = TS_State.touchDetected;
	}

}

void doNothing(void) {
}

void heatDown(void) {
	if(IR.heat>0x20)
		setHeat((IR.heat-0x20)&0xE0);
	else
		setHeat(0);

}

void heatUp(void) {
	if(IR.heat<0xE0)
		setHeat((IR.heat+0x20)&0xE0);
	else
		setHeat(0xE0);

}

void fanDown(void) {
	if(IR.fan>0x7F)
		setFan((IR.fan-0x40)&0xC0);
}

void fanUp(void) {
	if(IR.fan<0xC0)
		setFan((IR.fan+0x40)&0xC0);

}

void goMainScreen(void) {
	screen = SCREEN_MAIN;
	redraw = true;
}

void goAlternateScreen(void) {
	screen = SCREEN_ALTERNATE;
	redraw = true;
}

void mainScreenInit() {
	screen = SCREEN_MAIN;
	redraw = true;
	TSstatus = BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());	//Touchscreen status
	if (TSstatus != TS_OK)
		screen = SCREEN_ERROR_TS;

}

void drawScreenBackground() {

	redraw = false;
	switch (screen) {
	case SCREEN_MAIN:
		BSP_LCD_Clear(LCD_COLOR_WHITE);
		BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
		BSP_LCD_FillRect(0, 0, BSP_LCD_GetXSize(), 56);
		BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
		BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
		BSP_LCD_SetFont(&Font12);
		BSP_LCD_DisplayStringAt(0, 0, (uint8_t *) "Main Screen", CENTER_MODE);
		BSP_LCD_SetFont(&Font12);
		BSP_LCD_DisplayStringAt(0, 30,
				(uint8_t *) "Difficulties strengthen the mind, as labour does the body.",
				CENTER_MODE);
		BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
		BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
		BSP_LCD_DisplayStringAt(250, 70,(uint8_t *) "Time : ",RIGHT_MODE);
		BSP_LCD_DisplayStringAt(250, 80,(uint8_t *) "On/Off : ",RIGHT_MODE);
		BSP_LCD_DisplayStringAt(250, 90,(uint8_t *) "Fan : ",RIGHT_MODE);
		BSP_LCD_DisplayStringAt(250, 100,(uint8_t *) "Heat : ",RIGHT_MODE);


		BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
		BSP_LCD_DrawRect(10, 58, BSP_LCD_GetXSize() - 20,
				BSP_LCD_GetYSize() - 64);
		BSP_LCD_DrawRect(11, 59, BSP_LCD_GetXSize() - 22,
				BSP_LCD_GetYSize() - 66);

		clearButtons();
		addButton(12, 60, 100, 100, (uint8_t *) &buttonBmp, fanUp);
		addButton(12, 162, 100, 100, (uint8_t *) &buttonBmp, fanDown);
		addButton(368, 60, 100, 100, (uint8_t *) &buttonBmp, heatUp);
		addButton(368, 162, 100, 100, (uint8_t *) &buttonBmp, heatDown);
		addButton(368-100, 111, 100, 100, (uint8_t *) &buttonBmp,
				goAlternateScreen);

		break;
	case SCREEN_ALTERNATE:
		BSP_LCD_Clear(LCD_COLOR_WHITE);
		BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
		BSP_LCD_FillRect(0, 0, BSP_LCD_GetXSize(), 56);
		BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
		BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
		BSP_LCD_SetFont(&Font24);
		BSP_LCD_DisplayStringAt(0, 0, (uint8_t *) "Alternate Screen",
				CENTER_MODE);
		BSP_LCD_SetFont(&Font12);
		BSP_LCD_DisplayStringAt(0, 30,
				(uint8_t *) "A stitch in time would have confused Einstein.",
				CENTER_MODE);
		BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
		BSP_LCD_DrawRect(10, 58, BSP_LCD_GetXSize() - 20,
				BSP_LCD_GetYSize() - 64);
		BSP_LCD_DrawRect(11, 59, BSP_LCD_GetXSize() - 22,
				BSP_LCD_GetYSize() - 66);

		clearButtons();
		addButton(240 - 150, 111, 100, 100, (uint8_t *) &buttonBmp,
				goMainScreen);
		addButton(240 - 50, 111, 100, 100, (uint8_t *) &buttonBmp,
				goMainScreen);
		addButton(240 + 50, 111, 100, 100, (uint8_t *) &buttonBmp,
				goMainScreen);

		break;

	case SCREEN_ERROR_TS:
		BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
		BSP_LCD_SetTextColor(LCD_COLOR_RED);
		BSP_LCD_DisplayStringAt(0, BSP_LCD_GetYSize() - 95, (uint8_t *) "ERROR",
				CENTER_MODE);
		BSP_LCD_DisplayStringAt(0, BSP_LCD_GetYSize() - 80,
				(uint8_t *) "Touchscreen cannot be initialized", CENTER_MODE);
		break;
	}
}

void updateScreen() {
	uint8_t str[20];
	if (redraw)
	{
		drawScreenBackground();
		switch (screen) {
		case SCREEN_MAIN:
			BSP_LCD_DisplayStringAt(220, 70,rtcTimeString(),LEFT_MODE);

			sprintf(str,"0x%2.2X",IR.flags.on);
			BSP_LCD_DisplayStringAt(220, 80,str,LEFT_MODE);

			sprintf(str,"0x%2.2X",IR.fan);
			BSP_LCD_DisplayStringAt(220, 90,str,LEFT_MODE);

			sprintf(str,"0x%2.2X",IR.heat);
			BSP_LCD_DisplayStringAt(220, 100,str,LEFT_MODE);

			break;
		case SCREEN_ALTERNATE:
			break;

		case SCREEN_ERROR_TS:
			break;

		}
	}
}
