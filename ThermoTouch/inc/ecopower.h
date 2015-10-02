/*
 * ecopower.h
 *
 *  Created on: 1 Oct 2015
 *      Author: Keith Bryer, InnovoDesign Ltd
 */

#ifndef ECOPOWER_H_
#define ECOPOWER_H_

#include <stdint.h>
#include <stdbool.h>

struct Tflags
{
   int on:1;
   int commander:1;
   int mainboard:1;
   int datachanged:1;
   int restart_on_powerup:1;
   int automode:1;
   int prevent_cold_blow:1;
   int prevent_0kw:1;
};


struct Tflagsx
{
	int	cool:1;
};

struct Tstatus
{
   int extAT:1;
   int extXT:1;
   int extIn0:1;
   int extIn1:1;
   int spare:2;
   int cooling:1;
   int doorSwitch:1;
   int bms_0_10V:1;
   int lat:1;
   int controlLAT:1;
   int relay1:1;
   int relay2:1;
   int preventColdBlow:1;
   int closeWVOnPowerup:1;
   int outsideIsWarm:1;
};

struct TFaults
{
   int lowVolts:1;
   int lowVoltsNoFan:1;
   int tstatOpen:1;
   int undef:1;
   int thermistor:1;
   int commsTimeout:1;
   int exttherm:1;
   int tstatOpenNow:1;

   int config:1;
   int reservedForFanProve:1;
   int latSensor:1;
   int spareb:1;
   int sparec:1;
   int spared:1;
   int sparee:1;
   int sparef:1;
};

struct TOption
{
   int noWallController:1;
   int enableCoolingLocalInput:1;
   int enableCoolingByWallSwitch:1;
   int compatibilityMode:1;	//enablePaella
   int b4:1;
   int b5:1;
   int b6:1;
   int b7:1;
   int b8:1;
   int b9:1;
   int b10:1;
   int b11:1;
   int b12:1;
   int b13:1;
   int b14:1;
   int b15:1;
};

struct TTestOptions
{
   int to0:1;
   int spare1:1;
   int ignoreWater:1;
   int forceWater:1;
   int ignoreECFan:1;
   int forceECFan:1;
   int ignoreSSR:1;
   int forceSSR:1;

   int ignoreLAT:1;
   int forceWeatherComp:1;
   int ignoreWeatherComp:1;
   int spareb:1;
   int sparec:1;
   int spared:1;
   int testMode2:1;
   int testMode1:1;
};

struct TModbusState
{
   int forceOn:1;
   int forceOff:1;
   int forceAuto:1;
   int forceMan:1;
   int setCool:1;
   int setWarm:1;
   int inhibitHeat:1;
   int inhibitFan:1;

   int wsLockOnOff:1;
   int wsLockAuto:1;
   int wsLockHeat:1;
   int wsLockFan:1;
   int sparec:1;	//reserved lock
   int spared:1;
   int sparee:1;
   int sparef:1;
} lastCoils;

#define   maxCoilRegisters   16

struct TeepromState
{
   int present:1;
   int failed:1;
   int corrupt:1;
   int blank:1;
   int hasHeader:1;
   int present01:1;
   int realTimeClock:1;
   int sp_ee7:1;
};

struct Tdips
{
   int interlock:1;
   int norunon:1;
   int master:1;
   int InhibitNoStop:1;
   int fanVariable:1;
   int heatVariable:1;
   int waterValve:1;
   int canCool:1;

   int interlock23:1;
   int outsideThermistor:1;
   int spare:6;
};


typedef uint8_t U8;
typedef uint16_t U16;

struct inputRegisters
{

	struct Tflags flags_in;    //parameter[0]
	U8    ___1;
	U8    heat_in;         //parameter[1]
	U8    ___3;
	U8    fan_in;            //parameter[2]
	U8    ___5;
	struct	Tflagsx more_flags;         //parameter[3]
	U8    ___7;

	struct Tflags    flags;      //parameter[4]
	U8    ___9;

	int    heat;            //parameter[5]
	U8    ___11;

	int    fan;             //parameter[6]
	U8    ___13;

	struct Tstatus status;      //parameter[7]

	struct Tdips   dipswitch;   //parameter[8]

	struct TFaults globalFaults;      //parameter[9]

	U8    AT;                //parameter[10]
	U8    ___21;

	U16    DT;               //parameter[11]

	U16    NTC1;            //parameter[12]

	U16    NTC2;            //parameter[13]

	U16   ADC_alarm;         // parameter[14]

	U16   IN0;            // parameter[15]

	U16   IN1;             //parameter[16]

	U16   LAT;         //parameter[17] was previously ext_AT_timer

	U16    outside;          //parameter[18]

	struct TeepromState eepromState;           //parameter[19]
	U8    ___39;

	U8   bms;            //parameter[20]
	U8   ___41;

	U16   LATtarget;         //parameter[21] was previously ext_AT_timer

	U16   integral2;          //parameter[22]

	U16   pwr;             //parameter[23]

	U16   WVtarget;         //parameter[24]

	U16   WVactual;         //parameter[25]

	U16   WVreserved;         //parameter[26]

	struct TFaults localFault;      //parameter[27]

	U16   rateOfChangeAT;      //parameter[27]

};


extern struct inputRegisters IR;





void setHeat(uint8_t heat);

void setFan(uint8_t heat);

void setOnOff(bool on);



#endif /* ECOPOWER_H_ */
