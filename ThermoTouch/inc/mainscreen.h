/*
 * mainscreen2.h
 *
 *  Created on: 30 Sep 2015
 *      Author: KNB, Innovdesign
 */

#ifndef mainscreen_h
#define mainscreen_h

#include <stdint.h>
#include <stdbool.h>

/* Exported types ------------------------------------------------------------*/

typedef enum {
  SCREEN_MAIN = 0,
  SCREEN_ALTERNATE,
  SCREEN_ERROR_TS
}SCREEN_TypeDef;



/* Exported variables ---------------------------------------------------*/
//extern bool redraw;
//extern SCREEN_TypeDef screen;

/* Exported functions ------------------------------------------------------- */
void mainScreenInit(void);
void DrawMainScreen(void);
void checkTouch(void);

#endif
