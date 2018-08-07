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
#define PIN_DO_Rx  0    // GPIO, if used for serial, this is the Rx line
#define PIN_D1_Tx  1    // GPIO, if used for serial, this is the Tx line
#define PIN_D3_RCM 3    // GPIO, used as RCM_Strap here
#define PIN_D4_On  4    // Pin to keep the circuit on (directly connected to transistor)

#define RCM_STRAP_TIME_us 1000000  // Amount of time to hold RCM_STRAP low and then launch payload

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  PROGRAM
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

PayloadInjector injector(fuseeBin, FUSEE_BIN_SIZE);

void setup()
{
  // Set the pins to power on in RCM mode
  pinMode(PIN_D3_RCM, OUTPUT);
  pinMode(PIN_D4_On, OUTPUT);

  digitalWrite(PIN_D3_RCM, LOW);  // Set RCM_Strap low
  digitalWrite(PIN_D4_On, HIGH);  // Set On-signal high, so m0 chip is powered

  // Wait a second (I tried to reduce this but 1 second is good)
  delayMicroseconds(RCM_STRAP_TIME_us);

  injector.injectPayload();

  // Set the pins to power off
  digitalWrite(PIN_D4_On, LOW); // Set On-signal low, so m0 chip is not supplied anymore
  pinMode(PIN_D3_RCM, INPUT);   // Don't tie RCM_strap down to ground any longer!
}

void loop()
{
  // wait until supply drops so much, that m0 turns off
}
