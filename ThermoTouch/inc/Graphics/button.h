/*
 * button.h
 *
 *  Created on: 1 Oct 2015
 *      Author: Keith Bryer, InnovoDesign Ltd
 */

#ifndef GRAPHICS_BUTTON_H_
#define GRAPHICS_BUTTON_H_

#include <stdint.h>
#include <stdbool.h>

#define maxButtons	10

struct ButtonTypeDef
{
  uint16_t  x;
  uint16_t y;
  uint16_t w;
  uint16_t h;
  void (*onClick)(void);
};


extern uint8_t buttonCount;
extern struct ButtonTypeDef buttonList[];

void clearButtons(void);
void addButton(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t* bmp,void (*event)(void));
bool buttonHit(uint16_t n, uint16_t x, uint16_t y);

#endif /* GRAPHICS_BUTTON_H_ */
