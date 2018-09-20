#ifndef LED_LED_H_
#define LED_LED_H_

#include "Arduino.h"

class Led
{

 public:

  Led(int pinNr, boolean logicLevel);
  ~Led();
  void init();

  void setOn();
  void setOff();
  void toggle();

  boolean isOn();

 private:

  int pin;
  boolean activeLow;
  boolean ledIsOn;

};

#endif /* LED_LED_H_ */
