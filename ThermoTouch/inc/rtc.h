/*
 * rtc.h
 *
 *  Created on: 1 Oct 2015
 *      Author: Keith Bryer, Innovodesign
 */

#ifndef RTC_H_
#define RTC_H_

#include <stdint.h>

// using MCP7940M

struct TClock
{
	uint8_t ss;
	uint8_t mm;
	uint8_t hh;
	uint8_t dow;
	uint8_t date;
	uint8_t month;
	uint8_t year;
};

extern struct TClock now;

void rtcInit();

void rtcRead();

void rtcWrite();

uint8_t* rtcTimeString();

#endif /* RTC_H_ */
