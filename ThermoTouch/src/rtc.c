/*
 * rtc.c
 *
 *  Created on: 1 Oct 2015
 *      Author: Keith Bryer, Innovodesign Ltd
 */

#include "rtc.h"

struct TClock now;
char tString[20];
int div10;	// just a fudge for now - systick calls update every 100ms - use this until I2C hardware working

void rtcInit()
{
	//TODO
	now.ss=0x56;
	now.mm=0x34;
	now.hh=0x12;
	now.dow=1;
	now.month=0x5;
	now.date=0x11;
	now.year=0x15;
}


void rtcRead()
{
	//TODO



}

void rtcWrite()
{
	//TODO
}



void incTime()
{
	if(++div10==10)
	{
		div10=0;
		now.ss++;
		if((now.ss & 15)==10)
			now.ss+=6;
		if (now.ss==0x60)
		{
			now.ss=0;
			if((++now.mm & 15)==10)
				now.mm+=6;
			if(now.mm==0x60)
			{
				now.mm=0x0;
				now.hh=(now.hh+1)%24;
			}
		}

	}
}

uint8_t* rtcTimeString()
{
	incTime();
	sprintf(tString,"%2X:%.2.2X:%2.2X",now.hh,now.mm,now.ss);
	return (uint8_t*)tString;
}
