/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * Pin assignments for the MKS RUMBA32
 *
 * https://github.com/makerbase-mks/MKS-RUMBA32
 *
 * The MKS and Aus3D versions have the same pinout but the MKS version
 * has some added resistors and LEDs.  The resistors needed for the
 * TMC2208/9  UART interface are among the additions.  Also added were
 * connectors and resistors dedicated to the TMC2130 sensorless homing
 * interface.
 */

#define BOARD_INFO_NAME "MKS RUMBA32"

#if NO_EEPROM_SELECTED
  #define FLASH_EEPROM_EMULATION
  #define MARLIN_EEPROM_SIZE             0x1000U  // 4K
#endif

#if ENABLED(FLASH_EEPROM_EMULATION)
  // Decrease delays and flash wear by spreading writes across the
  // 128 kB sector allocated for EEPROM emulation.
  #define FLASH_EEPROM_LEVELING
#endif

#define ENABLE_SPI1

#include "pins_RUMBA32_common.h"

#if HAS_TMC_UART
  /**
   * TMC2208/TMC2209 stepper drivers
   *
   * Hardware serial communication ports.
   * If undefined software serial is used according to the pins below
   */
  //#define X_HARDWARE_SERIAL  Serial1
  //#define X2_HARDWARE_SERIAL Serial1
  //#define Y_HARDWARE_SERIAL  Serial1
  //#define Y2_HARDWARE_SERIAL Serial1
  //#define Z_HARDWARE_SERIAL  Serial1
  //#define Z2_HARDWARE_SERIAL Serial1
  //#define E0_HARDWARE_SERIAL Serial1
  //#define E1_HARDWARE_SERIAL Serial1
  //#define E2_HARDWARE_SERIAL Serial1
  //#define E3_HARDWARE_SERIAL Serial1
  //#define E4_HARDWARE_SERIAL Serial1

  //
  // Software serial
  //
  /*
  #define X_SERIAL_TX_PIN                   PA3
  #define X_SERIAL_RX_PIN                   PC14

  #define Y_SERIAL_TX_PIN                   PA4
  #define Y_SERIAL_RX_PIN                   PE4

  #define Z_SERIAL_TX_PIN                   PD13
  #define Z_SERIAL_RX_PIN                   PE0

  #define E0_SERIAL_TX_PIN                  PD14
  #define E0_SERIAL_RX_PIN                  PC13

  #define E1_SERIAL_TX_PIN                  PD15
  #define E1_SERIAL_RX_PIN                  PD5

  #define E2_SERIAL_TX_PIN                  PD12
  #define E2_SERIAL_RX_PIN                  PD1
  */

#endif
#undef BTN_PIN
#undef TEMP_3_PIN
#undef X_MAX_PIN
#undef Y_MIN_PIN
#undef Z_MAX_PIN
#undef FAN1_PIN
//PD2
#undef E2_STEP_PIN
//PD3
#undef E2_DIR_PIN
//PD0
#undef E2_ENABLE_PIN


//Inputs
#define FIL_RUNOUT_PIN                      PB13 // X_MAX_PIN
#define FIL_RUNOUT2_PIN                     PB15 // Y_MIN_PIN
#define FIL_RUNOUT3_PIN                     PC10 // BTN_PIN
#define CALIBRATION_PIN                     PC2// TEMP_SENSOR_2_PIN
#define CALIBRATION_PIN_INVERTING true      // Set to true to invert the custom pin
//#define TEMP_BOARD_PIN                    PC1 // TEMP_SENSOR_2_PIN
#define TEMP_CHAMBER_PIN                    PC1 // TEMP_SENSOR_2_PIN
#define TEMP_BOARD_PIN                      PC1 // TEMP_SENSOR_2_PIN

//#define POWER_LOSS_PIN                      PD0 //1 sur driver e2
#define COOLANT_FLOOD_PIN                   PD2 //7 sur driver e2
#define COOLANT_MIST_PIN                    PD3 //8 sur driver e2

//Outputs
#define SERVO0_PIN                          PB8  // i2cbus
#define SERVO1_PIN                          PB9  // i2cbus
#define SERVO2_PIN                          PA3  // i2cbus
//#define SMS_PAUSE_PIN                       PA4  // TEMP_3_PIN
//#define SMS_STOP_PIN                        PA3  // UART E2
//#define COOLANT_FLOOD_PIN                   PD10
//#define COOLANT_MIST_PIN                    PA4
//#define NEOPIXEL_PIN                        PD14 // UART E0
//#define FAN3_PIN                            PD15 // UART Z
#define RGB_LED_R_PIN                       PD12 // UART E2
#define RGB_LED_G_PIN                       PD13 // UART Z
#define RGB_LED_B_PIN                       PD14 // UART E0
#define RGB_LED_W_PIN                       PD15 // UART E1


/*#undef ST7920_DELAY_1
#undef ST7920_DELAY_2
#undef ST7920_DELAY_2
#define ST7920_DELAY_1 DELAY_NS(200) // After CLK LOW
#define ST7920_DELAY_2 DELAY_NS(400) // After DAT
#define ST7920_DELAY_3 DELAY_NS(200) // After CLK HIGH*/
