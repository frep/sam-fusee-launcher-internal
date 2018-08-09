//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  INCLUDES
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <Arduino.h>
#include "PayloadInjector.h"
// Contains fuseeBin and FUSEE_BIN_LENGTH
// Include only one payload here
// Use tools/binConverter.py to convert any payload bin you wish to load
#include "SXOS.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  DEFINES
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define PIN_D0_Rx  0    // GPIO, if used for serial, this is the Rx line
#define PIN_D1_Tx  1    // GPIO, if used for serial, this is the Tx line
#define PIN_D3     3    // GPIO
#define PIN_D4_On  4    // Pin to keep the circuit on (directly connected to transistor)

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  PROGRAM
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

PayloadInjector injector(fuseeBin, FUSEE_BIN_SIZE);

void setup()
{
  // Set the pins to power on in RCM mode
  pinMode(PIN_D4_On, OUTPUT);

  digitalWrite(PIN_D4_On, HIGH);  // Set On-signal high, so m0 chip is powered

  injector.injectPayload();

  // Set the pins to power off
  digitalWrite(PIN_D4_On, LOW); // Set On-signal low, so m0 chip is not supplied anymore
}

void loop()
{
}