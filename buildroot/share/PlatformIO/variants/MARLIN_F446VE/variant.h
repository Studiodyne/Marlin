/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_ARDUINO_STM32_
#define _VARIANT_ARDUINO_STM32_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

#define PA0   PIN_A7  //D0
#define PA1   PIN_A8  //D1
#define PA2   PIN_A9  //D2
#define PA3   PIN_A0  //D3
#define PA4   PIN_A1  //D4
#define PA5   PIN_A10 //D5
#define PA6   PIN_A11 //D6
#define PA7   PIN_A12 //D7
#define PA8   8   //D8
#define PA9   9   //D9
#define PA10  10  //D10
#define PA11  11  //D11
#define PA12  12  //D12
#define PA13  13  //D13
#define PA14  14  //D14
#define PA15  15  //D15
#define PB0   PIN_A13 //D16
#define PB1   PIN_A14 //D17
#define PB2   18  //D18
#define PB3   19  //D19
#define PB4   20  //D20
#define PB5   21  //D21
#define PB6   22  //D22
#define PB7   23  //D23
#define PB8   24  //D24
#define PB9   25  //D25
#define PB10  26  //D26
#define PB11  27  //D27
#define PB12  28  //D28
#define PB13  29  //D29
#define PB14  30  //D30
#define PB15  31  //D31
#define PC0   PIN_A2  //D32
#define PC1   PIN_A3  //D33
#define PC2   PIN_A4  //D34
#define PC3   PIN_A5  //D35
#define PC4   PIN_A6  //D36
#define PC5   PIN_A15 //D37
#define PC6   38  //D38
#define PC7   39  //D39
#define PC8   40  //D40
#define PC9   41  //D41
#define PC10  42  //D42
#define PC11  43  //D43
#define PC12  44  //D44
#define PC13  45  //D45
#define PC14  46  //D46
#define PC15  47  //D47
#define PD0   48  //D48
#define PD1   49  //D49
#define PD2   50  //D50
#define PD3   51  //D51
#define PD4   52  //D52
#define PD5   53  //D53
#define PD6   54  //D54
#define PD7   55  //D55
#define PD8   56  //D56
#define PD9   57  //D57
#define PD10  58  //D58
#define PD11  59  //D59
#define PD12  60  //D60
#define PD13  61  //D61
#define PD14  62  //D62
#define PD15  63  //D63
#define PE0   64  //D64
#define PE1   65  //D65
#define PE2   66  //D66
#define PE3   67  //D67
#define PE4   68  //D68
#define PE5   69  //D69
#define PE6   70  //D70
#define PE7   71  //D71
#define PE8   72  //D72
#define PE9   73  //D73
#define PE10  74  //D74
#define PE11  75  //D75
#define PE12  76  //D76
#define PE13  77  //D77
#define PE14  78  //D78
#define PE15  79  //D79

// This must be a literal
#define NUM_DIGITAL_PINS        80
// This must be a literal with a value less than or equal to to MAX_ANALOG_INPUTS
#define NUM_ANALOG_INPUTS       16

// PWM resolution
#define PWM_FREQUENCY           75 // >= 20 Khz => inaudible noise for fans
#define PWM_MAX_DUTY_CYCLE      255

// On-board LED pin number
#define LED_BUILTIN             PB14
#define LED_HEARTBEAT           LED_BUILTIN

// SPI Definitions
#define PIN_SPI_SS              PA4
#define PIN_SPI_MOSI            PA7
#define PIN_SPI_MISO            PA6
#define PIN_SPI_SCK             PA5

// I2C Definitions
#define PIN_WIRE_SDA            PB9
#define PIN_WIRE_SCL            PB8

// Timer Definitions
// Use TIM6/TIM7 when possible as servo and tone don't need GPIO output pin
#ifndef TIMER_TONE
  #define TIMER_TONE            TIM6  // TIMER_TONE must be defined in this file
#endif

#ifndef TIMER_SERVO
  #define TIMER_SERVO           TIM7  // TIMER_SERVO must be defined in this file
#endif

#ifndef TIMER_SERIAL
  #define TIMER_SERIAL          TIM9  // TIMER_SERIAL must be defined in this file
#endif

// UART Definitions
#define SERIAL_UART_INSTANCE    1 // Connected to EXP3 header

// Default pin used for 'Serial' instance (ex: ST-Link)
// Mandatory for Firmata
#define PIN_SERIAL_RX           PA10
#define PIN_SERIAL_TX           PA9

/* HAL configuration */
#define HSE_VALUE               12000000U

#ifdef __cplusplus
} // extern "C"
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus
  // These serial port names are intended to allow libraries and architecture-neutral
  // sketches to automatically default to the correct port name for a particular type
  // of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
  // the first hardware serial port whose RX/TX pins are not dedicated to another use.
  //
  // SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
  //
  // SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
  //
  // SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
  //
  // SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
  //
  // SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
  //                            pins are NOT connected to anything by default.
  #define SERIAL_PORT_MONITOR     Serial
  #define SERIAL_PORT_HARDWARE_OPEN  Serial
#endif

#endif /* _VARIANT_ARDUINO_STM32_ */
