/*
 * button.c
 *
 *  Created on: 1 Oct 2015
 *      Author: Keith Bryer, InnovoDesign Ltd
 */
#include "button.h"
#include "stm32746g_discovery_lcd.h"

struct ButtonTypeDef buttonList[maxButtons];

uint8_t buttonCount;



void clearButtons(void) {
	buttonCount = 0;
}


void addButton(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t* bmp,
		void (*event)(void)) {

	buttonList[buttonCount].x = x;
	buttonList[buttonCount].y = y;
	buttonList[buttonCount].w = w;
	buttonList[buttonCount].h = h;
	buttonList[buttonCount].onClick = event;
	buttonCount++;
	BSP_LCD_DrawBitmap(x, y, (uint8_t *) bmp);
	HAL_Delay(100);
}

bool buttonHit(uint16_t n, uint16_t x, uint16_t y)
{

	return ((x > buttonList[n].x)
			&& (x < (buttonList[n].x + buttonList[n].w))
			&& (y > buttonList[n].y)
			&& (y < (buttonList[n].y + buttonList[n].h)));

}
