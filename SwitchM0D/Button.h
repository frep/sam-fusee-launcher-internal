#ifndef BUTTON_H_
#define BUTTON_H_

#define debounceTimeMs  20  // 20ms debounce time

#include "Arduino.h"

class Button {
public:

	Button(int pinNr, boolean logicLevel);
	~Button();

	void init();
	void initWithInternalPullup();
	boolean getValue();
	void checkButton();
	void buttonPressed();
  void buttonReleased();
	void attachFunctionOnButtonPressed(void (*func)());
	void attachFunctionOnButtonReleased(void (*func)());
	void detachFunctionOnButtonPressed();
	void detachFunctionOnButtonReleased();

protected:

	int pin;
	boolean isActiveLow;
	boolean state;
  unsigned long eventTime;
  boolean debounced;

	void (*fctButtonPressed)();
	void (*fctButtonReleased)();
};

#endif /* BUTTON_H_ */
