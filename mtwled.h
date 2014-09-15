/*
  mtwled.h
  header file for Makers Tool Works RGB LED I2C control

  Led Strip Driver for MTW Printers.
  I2C output
  I2C Device ID = 74
  Data Value of 1 is used for no selection = do nothing
  report the heat cool values at the same rate its reported to the UI
*/

#if (ARDUINO >= 100)
  # include "Arduino.h"
#else
  # include "WProgram.h"
#endif

#include "Wire.h"

void MTWLEDUpdate(byte pattern);
void MTWLEDLogic();
void MTWLEDTemp();

// Pattern Selection Table
#define mtwled_nochange 	1	// Reserved for no change to LED Strip
#define mtwled_ready		2	// Marlin Ready
#define mtwled_startup		5	// Marlin startup
#define mtwled_tempready	8	// Hotend is at requested temp
#define mtwled_heateron		9	// Hotend heater is on
#define mtwled_heateroff	10	// Hotend heater is off
#define mtwled_printdone	13	// Print Finished

/*
90-99 Reserved for heating and cooling values
Fixed values for heating and cooling cycle
Heating   will use a value of 10,20,30,40,50,60,70,80,90,100 % to change the
colors on the led strip the % is based on the ((current temp /requested temp-starting temp)rounded to the nearest 10th

*/
