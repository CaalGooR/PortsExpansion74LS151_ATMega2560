#ifndef _74LS151_H
#define _74LS151_H
#include <inttypes.h>

void INs74xx151_Init(uint8_t *pto,uint8_t Z,uint8_t S2,uint8_t S1,uint8_t S0,uint8_t _E);
uint8_t INs74xxx151_rdbit(uint8_t nbit);
uint8_t INs74xxx151_rdbyte();

#endif
