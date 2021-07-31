#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <stdint.h>

#define EXTERNAL_NUM_INTERRUPTS 16
#define NUM_DIGITAL_PINS        40
#define NUM_ANALOG_INPUTS       16

#define analogInputToDigitalPin(p)  (((p)<20)?(esp32_adc2gpio[(p)]):-1)
#define digitalPinToInterrupt(p)    (((p)<40)?(p):-1)
#define digitalPinHasPWM(p)         (p < 34)

// UART
static const uint8_t TX = 1;
static const uint8_t RX = 3;

// I2C
static const uint8_t SDA = 21;
static const uint8_t SCL = 22;

// SPI
static const uint8_t MOSI        = 23;
static const uint8_t MISO        = 19;
static const uint8_t SCK         = 18;
static const uint8_t SS          = 5;
static const uint8_t PIN_LORA_CS = 5;
static const uint8_t PIN_LCD_CS  = 12;
static const uint8_t PIN_SD_CS   = 14;

// LCD
static const uint8_t PIN_LED_LCD = 16;
static const uint8_t PIN_LCD_RST = 15;
static const uint8_t PIN_LCD_DC  = 25;

// LORA
static const uint8_t PIN_LORA_IRQ = 4;
static const uint8_t PIN_LORA_RST = 2;

// TCH
static const uint8_t PIN_TCH_CS  = 13;
static const uint8_t PIN_TCH_IRQ = 17;

// Other board-specific
static const uint8_t PIN_LED = 26;
static const uint8_t SW_PUSH = 0;

// ESP32 generic
static const uint8_t A0 = 36;
static const uint8_t A1 = 37;
static const uint8_t A3 = 39;
static const uint8_t A4 = 32;
static const uint8_t A5 = 33;
static const uint8_t A6 = 34;
static const uint8_t A7 = 35;
static const uint8_t A10 = 4;
static const uint8_t A11 = 0;
static const uint8_t A12 = 2;
static const uint8_t A14 = 13;
static const uint8_t A16 = 14;
static const uint8_t A17 = 27;

static const uint8_t T3 = 15;
static const uint8_t T5 = 12;
static const uint8_t T7 = 27;
static const uint8_t T8 = 33;
static const uint8_t T9 = 32;

static const uint8_t DAC1 = 25;
static const uint8_t DAC2 = 26;

#endif /* Pins_Arduino_h */
