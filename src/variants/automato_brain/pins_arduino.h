#ifndef Pins_Arduino_h
#define Pins_Arduino_h

// AUTOMATO_BRAIN

#include <stdint.h>
#include "soc/soc_caps.h"

// Default USB CDC On Boot setting
#ifndef ARDUINO_USB_CDC_ON_BOOT
#define ARDUINO_USB_CDC_ON_BOOT 1
#endif

// Default USB Firmware MSC On Boot setting  
#ifndef ARDUINO_USB_MSC_ON_BOOT
#define ARDUINO_USB_MSC_ON_BOOT 0
#endif

// Default USB DFU On Boot setting
#ifndef ARDUINO_USB_DFU_ON_BOOT  
#define ARDUINO_USB_DFU_ON_BOOT 0
#endif

// Digital pins
static const uint8_t LED_BUILTIN = 23;
#define BUILTIN_LED LED_BUILTIN

// GPIO pins available on ESP32-C6-MINI-1
static const uint8_t D0   = 0;
static const uint8_t D1   = 1;
static const uint8_t D2   = 2;
static const uint8_t D3   = 3;
static const uint8_t D4   = 4;
static const uint8_t D5   = 5;
static const uint8_t D6   = 6;
static const uint8_t D7   = 7;
static const uint8_t D8   = 8;
static const uint8_t D9   = 9;
static const uint8_t D10  = 10;
static const uint8_t D11  = 11;
static const uint8_t D12  = 12;
static const uint8_t D13  = 13;
static const uint8_t D14  = 14;
static const uint8_t D15  = 15;
static const uint8_t D16  = 16;
static const uint8_t D17  = 17;
static const uint8_t D18  = 18;
static const uint8_t D19  = 19;
static const uint8_t D20  = 20;
static const uint8_t D21  = 21;
static const uint8_t D22  = 22;
static const uint8_t D23  = 23;

// Analog pins (ADC1)
static const uint8_t A0   = 0;
static const uint8_t A1   = 1;
static const uint8_t A2   = 2;
static const uint8_t A3   = 3;
static const uint8_t A4   = 4;
static const uint8_t A5   = 5;
static const uint8_t A6   = 6;

// SPI pins - adjust based on your PCB design
static const uint8_t SS    = 10;
static const uint8_t MOSI  = 19;
static const uint8_t MISO  = 20;
static const uint8_t SCK   = 21;

// I2C pins - adjust based on your PCB design
static const uint8_t SDA   = 6;
static const uint8_t SCL   = 7;

// UART pins
static const uint8_t TX = 16;
static const uint8_t RX = 17;

// USB pins (built-in on ESP32-C6)
static const uint8_t USB_DM = 12;
static const uint8_t USB_DP = 13;

// Boot button (usually GPIO9 on ESP32-C6)
static const uint8_t BOOT_BTN = 9;

// Number of pins defined
#define NUM_DIGITAL_PINS        24
#define NUM_ANALOG_INPUTS       7

// Define which analog pins can be used
#define analogInputToDigitalPin(p)  (((p)<NUM_ANALOG_INPUTS) ? (esp32_adc2gpio[(p)]) : -1)
#define digitalPinToInterrupt(p)    (((p)<NUM_DIGITAL_PINS) ? (p) : -1)
#define digitalPinHasPWM(p)         (p < NUM_DIGITAL_PINS)

// SPI definitions
#define PIN_SPI_SS    SS
#define PIN_SPI_MOSI  MOSI
#define PIN_SPI_MISO  MISO
#define PIN_SPI_SCK   SCK

static const uint8_t SS   = PIN_SPI_SS;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;

// Wire (I2C) definitions
#define PIN_WIRE_SDA        SDA
#define PIN_WIRE_SCL        SCL

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

#endif /* Pins_Arduino_h */
