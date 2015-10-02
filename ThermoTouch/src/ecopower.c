/*
 * ecopower.c
 *
 *  Created on: 1 Oct 2015
 *      Author: Keith Bryer, InnovoDesign Ltd
 */
#include "ecopower.h"
#include "modbus.h"

struct inputRegisters IR;
bool IRneedsUpdate;


void setHeat(uint8_t heat)
{
	modbusWriteHoldingReg(1,heat); //TODO
	IR.heat=heat;
	IRneedsUpdate=true;
}

void setFan(uint8_t fan)
{
	modbusWriteHoldingReg(3,fan); //TODO
	IR.fan=fan;
	IRneedsUpdate=true;
	//TODO
}

void setOnOff(bool on)
{
	IR.flags.on = on;
	if(on)
		modbusWriteHoldingReg(2,1); //TODO
	else
		modbusWriteHoldingReg(2,2); //TODO

	IRneedsUpdate=true;

	//TODO

}

