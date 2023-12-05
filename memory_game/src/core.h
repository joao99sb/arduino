// CPU frequency in Hz
#ifndef F_CPU
#define F_CPU 1000000UL
#endif

// define um tipo de 8bits
typedef unsigned int u8 __attribute__((__mode__(__QI__)));

#define PERIPH_BASE (0x20)
#define PORTD_OFFSET (0x0B)

#define DDRD_OFFSET (0x0A)
#define REG_PORTD ((volatile u8 *)PORTD_OFFSET + PERIPH_BASE)
#define REG_DDRD ((volatile u8 *)DDRD_OFFSET + PERIPH_BASE)

#define PIND_OFFSET (0x09)
#define PIND ((volatile u8 *)PIND_OFFSET + PERIPH_BASE)

#define TCNT0_OFFSET 0x26
#define TCNT0 ((volatile u8 *)TCNT0_OFFSET + PERIPH_BASE)

#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
#define PIN8 8
#define PIN9 9
#define PIN10 10

#define INPUT 1
#define OUTPUT 0

#define TRUE 1
#define FALSE 0

void pinMode(volatile u8 *REG_DDRx, int PORTx, int MODE);

void setPin(volatile u8 *REG_PORT, int PIN, int bit);

u8 getPinState(volatile u8 *REG_PIN, int PIN);

void delay(double ms);