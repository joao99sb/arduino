#include "core.h"
#include "Array.h"

// Where is the led connected?
// Port: D
// Pins: 7,6,5,4

#define INPUT_MODE 0
#define OUTPUT_MODE 1
#define END_GAME_MODE 2
#define LEVEL_SIZE 10

int game_mode = OUTPUT_MODE;

void change_game_mode(int mode)
{
  game_mode = mode;
}

void configOutputMode()
{
  pinMode(REG_DDRD, PIN4, OUTPUT);
  pinMode(REG_DDRD, PIN5, OUTPUT);
  pinMode(REG_DDRD, PIN6, OUTPUT);
  pinMode(REG_DDRD, PIN7, OUTPUT);
}

void configInputMode()
{

  pinMode(REG_DDRD, PIN4, INPUT);
  pinMode(REG_DDRD, PIN5, INPUT);
  pinMode(REG_DDRD, PIN6, INPUT);
  pinMode(REG_DDRD, PIN7, INPUT);

  // configurar  todos como pull down
  setPin(REG_PORTD, PIN4, 0);
  setPin(REG_PORTD, PIN5, 0);
  setPin(REG_PORTD, PIN6, 0);
  setPin(REG_PORTD, PIN7, 0);
}

void loseAnimation(Array *pin_array)
{

  pinMode(REG_DDRD, PIN4, OUTPUT);
  pinMode(REG_DDRD, PIN5, OUTPUT);
  pinMode(REG_DDRD, PIN6, OUTPUT);
  pinMode(REG_DDRD, PIN7, OUTPUT);

  for (int i = 0; i < 3; i++)
  {
    setPin(REG_PORTD, PIN4, 1);
    setPin(REG_PORTD, PIN5, 1);
    setPin(REG_PORTD, PIN6, 1);
    setPin(REG_PORTD, PIN7, 1);
    delay(200);

    setPin(REG_PORTD, PIN4, 0);
    setPin(REG_PORTD, PIN5, 0);
    setPin(REG_PORTD, PIN6, 0);
    setPin(REG_PORTD, PIN7, 0);
    delay(200);
  }
}
void winAnimation()
{

  pinMode(REG_DDRD, PIN4, OUTPUT);
  pinMode(REG_DDRD, PIN5, OUTPUT);
  pinMode(REG_DDRD, PIN6, OUTPUT);
  pinMode(REG_DDRD, PIN7, OUTPUT);

  setPin(REG_PORTD, PIN4, 1);
  setPin(REG_PORTD, PIN5, 1);
  setPin(REG_PORTD, PIN6, 1);
  setPin(REG_PORTD, PIN7, 1);
  delay(500);

  setPin(REG_PORTD, PIN4, 0);
  setPin(REG_PORTD, PIN5, 0);
  setPin(REG_PORTD, PIN6, 0);
  setPin(REG_PORTD, PIN7, 0);
  delay(200);
  setPin(REG_PORTD, PIN4, 1);
  delay(200);
  setPin(REG_PORTD, PIN4, 0);
  setPin(REG_PORTD, PIN5, 1);
  delay(200);
  setPin(REG_PORTD, PIN5, 0);
  setPin(REG_PORTD, PIN6, 1);
  delay(200);
  setPin(REG_PORTD, PIN6, 0);

  setPin(REG_PORTD, PIN7, 1);
  delay(200);
  setPin(REG_PORTD, PIN7, 0);

  delay(200);

  setPin(REG_PORTD, PIN4, 1);
  delay(200);
  setPin(REG_PORTD, PIN4, 0);
  setPin(REG_PORTD, PIN5, 1);
  delay(200);
  setPin(REG_PORTD, PIN5, 0);
  setPin(REG_PORTD, PIN6, 1);
  delay(200);
  setPin(REG_PORTD, PIN6, 0);

  setPin(REG_PORTD, PIN7, 1);
  delay(200);
  setPin(REG_PORTD, PIN7, 0);

  delay(200);

  setPin(REG_PORTD, PIN7, 1);
  delay(200);
  setPin(REG_PORTD, PIN7, 0);
  setPin(REG_PORTD, PIN6, 1);
  delay(200);
  setPin(REG_PORTD, PIN6, 0);
  setPin(REG_PORTD, PIN5, 1);
  delay(200);
  setPin(REG_PORTD, PIN5, 0);

  setPin(REG_PORTD, PIN4, 1);
  delay(200);
  setPin(REG_PORTD, PIN4, 0);

  delay(200);

  setPin(REG_PORTD, PIN7, 1);
  delay(200);
  setPin(REG_PORTD, PIN7, 0);
  setPin(REG_PORTD, PIN6, 1);
  delay(200);
  setPin(REG_PORTD, PIN6, 0);
  setPin(REG_PORTD, PIN5, 1);
  delay(200);
  setPin(REG_PORTD, PIN5, 0);

  setPin(REG_PORTD, PIN4, 1);
  delay(200);
  setPin(REG_PORTD, PIN4, 0);

  setPin(REG_PORTD, PIN4, 1);
  setPin(REG_PORTD, PIN5, 1);
  setPin(REG_PORTD, PIN6, 1);
  setPin(REG_PORTD, PIN7, 1);
  delay(500);

  setPin(REG_PORTD, PIN4, 0);
  setPin(REG_PORTD, PIN5, 0);
  setPin(REG_PORTD, PIN6, 0);
  setPin(REG_PORTD, PIN7, 0);
}

int hasBeenPressed()
{
  return getPinState(PIND, PIN4) ||
         getPinState(PIND, PIN5) ||
         getPinState(PIND, PIN6) ||
         getPinState(PIND, PIN7);
};

int gameAnnihilator(Array *pin_array)
{
  pin_array->pin_level = 0;
  pin_array->current_pin = 0;
  pin_array->next = 0;
  destroyArray(&pin_array);
}

int level1[LEVEL_SIZE] = {PIN5, PIN7, PIN6, PIN4, PIN7, PIN5, PIN6, PIN4, PIN4, PIN5};
int main(void)
{
  Array pin_array = createArray(10);

  while (1)
  {

    if (pin_array.A == NULL)
    {
      pin_array = createArray(10);
    }
    if (game_mode == OUTPUT_MODE)
    {

      if (pin_array.next)
      {
        appendArray(&pin_array, level1[pin_array.pin_level]);
        pin_array.current_pin = 0;
      }
      configOutputMode();
      for (int i = 0; i < pin_array.length; i++)
      {
        setPin(REG_PORTD, pin_array.A[i], 1);

        delay(200);
        setPin(REG_PORTD, pin_array.A[i], 0);
        delay(200);
      }
      change_game_mode(INPUT_MODE);
    }
    else if (game_mode == INPUT_MODE)
    {
      configInputMode();

      if (hasBeenPressed() && getPinState(PIND, pin_array.A[pin_array.current_pin]))
      {

        if (pin_array.current_pin + 1 == LEVEL_SIZE)
        {
          delay(200);
          change_game_mode(END_GAME_MODE);
          continue;
        }

        if (pin_array.length == pin_array.current_pin + 1)
        {
          pin_array.next = 1;
          pin_array.pin_level++;

          change_game_mode(OUTPUT_MODE);
          delay(400);
        }
        else
        {
          pin_array.current_pin++;
          delay(300);
        }
      }
      else if (hasBeenPressed() && !getPinState(PIND, pin_array.A[pin_array.current_pin]))
      {
        loseAnimation(&pin_array);
        gameAnnihilator(&pin_array);
        change_game_mode(OUTPUT_MODE);
      }

      // change_game_mode(OUTPUT_MODE);
    }
    else if (game_mode == END_GAME_MODE)
    {
      winAnimation();
      gameAnnihilator(&pin_array);
      change_game_mode(OUTPUT_MODE);

      delay(1000);
    }

    // set port

    // unset
  }

  return 0;
}