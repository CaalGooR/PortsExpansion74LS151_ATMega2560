#include "74LS151.h"

volatile static uint8_t *port,z,A0,A1,A2,_e;

void INs74xx151_Init(uint8_t *pto,uint8_t Z,uint8_t S2,uint8_t S1,uint8_t S0,uint8_t _E)
{
    port = pto; // DDRx
    z = Z;      // Entrada
    A0 = S0;
    A1 = S1;
    A2 = S2;
    _e = _E;
    *port = (1<<A0) | (1<<A1) | (1<<A2) | (1<<_e);
    *port &= ~(1<<z);

    *port++;            // PORTx
    *port = (1<<_e);    // Deshabilitamos CI hasta la proxima escritura (Puertos de entrada se configuran con alta impedancia)
}

uint8_t INs74xxx151_rdbit(uint8_t nbit)
{ 
    volatile static uint8_t *pinx,result = 0;
    *port |= (((nbit&4)>>2)<<A2) | (((nbit&2)>>1)<<A1) | ((nbit&1)<<A0);
    *port &= ~(1<<_e);
    pinx = port - 2;
    result = (*pinx & 1<<z) ? (1) : (0);
    *port = (1<<_e);
    return result;
}

uint8_t INs74xxx151_rdbyte()
{
    static uint8_t data = 0,i;
    for (i = 0;i<8;i++) 
        data |= INs74xxx151_rdbit(i)<<i;
    return data ;
}
