#include <util/delay.h>
#include "core.h"
#include "Array.h"

// Where is the led connected?
// Port: D
// Pins: 7,6,5,4

#define INPUT_MODE 0
#define OUTPUT_MODE 1
#define END_MODE 2

int game_mode = OUTPUT_MODE;

int main(void)
{
  Array pin_array = createArray(5);

  appendArray(&pin_array, PIN4);
  appendArray(&pin_array, PIN5);
  appendArray(&pin_array, PIN6);

  while (1)
  {
    if (game_mode == OUTPUT_MODE)
    {
      for (int i = 0; i < pin_array.length; i++)
      {
        pinMode(REG_DDRD, pin_array.A[i], OUTPUT);
        setPin(REG_PORTD, pin_array.A[i], 1);

        _delay_ms(500);
        setPin(REG_PORTD, pin_array.A[i], 0);
      }
    }
    else if (game_mode == INPUT_MODE)
    {
    }
    else
    {

      break;
    }
    // set port

    // unset
  }

  return 0;
}