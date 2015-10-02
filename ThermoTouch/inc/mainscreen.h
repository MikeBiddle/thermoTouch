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


/* Exported functions ------------------------------------------------------- */
void mainScreenInit(void);
void updateScreen(void);
void checkTouch(void);

#endif
