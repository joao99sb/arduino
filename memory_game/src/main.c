#include <util/delay.h>
#include "core.h"
#include "Array.h"

// Where is the led connected?
// Port: D
// Pins: 7,6,5,4

#define INPUT_MODE 0
#define OUTPUT_MODE 1
#define END_MODE 2

// #define __DEBUG 0

int game_mode = OUTPUT_MODE;

void change_game_mode(int mode)
{
  game_mode = mode;
}

void configOutputMode(Array *pin_array)
{
  for (int i = 0; i < pin_array->length; i++)
  {
    pinMode(REG_DDRD, pin_array->A[i], OUTPUT);
  }
}

void configInputMode(Array *pin_array)
{

  for (int i = 0; i < pin_array->length; i++)
  {
    pinMode(REG_DDRD, pin_array->A[i], INPUT);

    // configurar  todos como pull down
    setPin(REG_PORTD, pin_array->A[i], 0);
  }
}

void loseAnimation(Array *pin_array)
{
  for (int i = 0; i < pin_array->length; i++)
  {
    pinMode(REG_DDRD, PIN4, OUTPUT);
    pinMode(REG_DDRD, PIN5, OUTPUT);
    pinMode(REG_DDRD, PIN6, OUTPUT);
    pinMode(REG_DDRD, PIN7, OUTPUT);
  }

  for (int i = 0; i < 3; i++)
  {
    setPin(REG_PORTD, PIN4, 1);
    setPin(REG_PORTD, PIN5, 1);
    setPin(REG_PORTD, PIN6, 1);
    setPin(REG_PORTD, PIN7, 1);
    _delay_ms(500);

    setPin(REG_PORTD, PIN4, 0);
    setPin(REG_PORTD, PIN5, 0);
    setPin(REG_PORTD, PIN6, 0);
    setPin(REG_PORTD, PIN7, 0);
    _delay_ms(500);
  }
}

int hasBeenPressed()
{
  return getPinState(PIND, PIN4) ||
         getPinState(PIND, PIN5) ||
         getPinState(PIND, PIN6) ||
         getPinState(PIND, PIN7);
};

int level1[5] = {PIN4, PIN6, PIN7, PIN4, PIN5};
int current_iter = 0;
int main(void)
{
  Array pin_array = createArray(12);

  appendArray(&pin_array, PIN4);
  appendArray(&pin_array, PIN6);
  appendArray(&pin_array, PIN7);
  appendArray(&pin_array, PIN5);
  appendArray(&pin_array, PIN6);
  appendArray(&pin_array, PIN7);
  appendArray(&pin_array, PIN5);
  appendArray(&pin_array, PIN4);
  appendArray(&pin_array, PIN4);
  appendArray(&pin_array, PIN6);
  appendArray(&pin_array, PIN7);
  appendArray(&pin_array, PIN5);

  int current_iter = 0;

  while (1)
  {
    if (game_mode == OUTPUT_MODE)
    {
      configOutputMode(&pin_array);

      for (int i = 0; i < pin_array.length; i++)
      {
        setPin(REG_PORTD, pin_array.A[i], 1);

        _delay_ms(200);
        setPin(REG_PORTD, pin_array.A[i], 0);
        _delay_ms(200);
      }
      change_game_mode(INPUT_MODE);
    }
    else if (game_mode == INPUT_MODE)
    {
      configInputMode(&pin_array);

      if (hasBeenPressed() && getPinState(PIND, pin_array.A[current_iter]))
      {

        current_iter++; // Avança para o próximo iterador apenas se o pino estiver excitado
        if (current_iter >= pin_array.length)
        {
          current_iter = 0; // Reinicia se atingir o final do array
          change_game_mode(OUTPUT_MODE);
          _delay_ms(500);
        }
        _delay_ms(400);
      }
      if (hasBeenPressed() && !getPinState(PIND, pin_array.A[current_iter]))
      {
        loseAnimation(&pin_array);
        current_iter = 0;
        change_game_mode(OUTPUT_MODE);
      }
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