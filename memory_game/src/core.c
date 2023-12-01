#include "core.h"

void pinMode(volatile u8 *REG_DDRx, int PORTx, int MODE)
{

  if (MODE == OUTPUT)
  {
    *REG_DDRx |= (1 << PORTx);
  }
  if (MODE == INPUT)
  {
    *REG_DDRx &= ~(1 << PORTx);
  }
}

void setPin(volatile u8 *REG_PORT, int PIN, int bit)
{
  if (bit == 1)
  {
    *REG_PORT |= (1 << PIN);
  }
  if (bit == 0)
  {
    *REG_PORT &= ~(1 << PIN);
  }
}