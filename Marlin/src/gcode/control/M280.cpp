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

#include "../../inc/MarlinConfig.h"

#if HAS_SERVOS

#include "../gcode.h"
#include "../../module/servo.h"
#include "../../module/planner.h"

/**
 * M280: Get or set servo position.
 *  P<index> - Servo index
 *  S<angle> - Angle to set, omit to read current angle, or use -1 to detach
 *  H<0/1>   - All tools high(1) or Low(0) for two servos configuration only
 *  C        - Active tool positionning (active tool lowered & inactive upped)
 *
 * With POLARGRAPH:
 *  T<ms>    - Duration of servo move
 */
void GcodeSuite::M280() {

  #if ENABLED(SWITCHING_NOZZLE_TWO_SERVOS)
    if (parser.seenval('H')) {
      const int anew = parser.value_int();
      if (anew) {
        servo[SWITCHING_NOZZLE_SERVO_NR].move(servo_angles[SWITCHING_NOZZLE_SERVO_NR][1]);
        servo[SWITCHING_NOZZLE_E1_SERVO_NR].move(servo_angles[SWITCHING_NOZZLE_SERVO_NR][1]);
      }
      else {
        servo[SWITCHING_NOZZLE_SERVO_NR].move(servo_angles[SWITCHING_NOZZLE_SERVO_NR][0]);
        servo[SWITCHING_NOZZLE_E1_SERVO_NR].move(servo_angles[SWITCHING_NOZZLE_SERVO_NR][0]);
      }
      servo[SWITCHING_NOZZLE_SERVO_NR].detach();
      servo[SWITCHING_NOZZLE_E1_SERVO_NR].detach();
      return;
    }
  #endif

  #if ENABLED(SWITCHING_NOZZLE_TWO_SERVOS)
    if (parser.seen('C')) {
      servo[active_extruder? SWITCHING_NOZZLE_SERVO_NR : SWITCHING_NOZZLE_E1_SERVO_NR ].move(servo_angles[SWITCHING_NOZZLE_SERVO_NR][1]);
      servo[active_extruder? SWITCHING_NOZZLE_E1_SERVO_NR : SWITCHING_NOZZLE_SERVO_NR ].move(servo_angles[SWITCHING_NOZZLE_SERVO_NR][0]);
      servo[SWITCHING_NOZZLE_SERVO_NR].detach();
      servo[SWITCHING_NOZZLE_E1_SERVO_NR].detach();
      return;
    }
  #endif

  if (!parser.seenval('P')) return;

  TERN_(POLARGRAPH, planner.synchronize());

  const int servo_index = parser.value_int();
  if (WITHIN(servo_index, 0, NUM_SERVOS - 1)) {
    if (parser.seenval('S')) {
      const int anew = parser.value_int();
      if (anew >= 0) {
        #if ENABLED(POLARGRAPH)
          if (parser.seenval('T')) { // (ms) Total duration of servo move
            const int16_t t = constrain(parser.value_int(), 0, 10000);
            const int aold = servo[servo_index].read();
            millis_t now = millis();
            const millis_t start = now, end = start + t;
            while (PENDING(now, end)) {
              safe_delay(50);
              now = _MIN(millis(), end);
              servo[servo_index].move(LROUND(aold + (anew - aold) * (float(now - start) / t)));
            }
          }
        #endif // POLARGRAPH
        servo[servo_index].move(anew);
      }
      else
        servo[servo_index].detach();
    }
    else
      SERIAL_ECHO_MSG(" Servo ", servo_index, ": ", servo[servo_index].read());
  }
  else
    SERIAL_ERROR_MSG("Servo ", servo_index, " out of range");

}

#endif // HAS_SERVOS
