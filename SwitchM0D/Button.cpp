#include "Button.h"

Button::Button(int pinNr, boolean logicLevel)
: pin(pinNr), state(false), isActiveLow(logicLevel), eventTime(0), debounced(true)
{
  fctButtonPressed  = NULL;
  fctButtonReleased = NULL;
}

Button::~Button()
{
}

void Button::init()
{
  pinMode(pin, INPUT);
  state = getValue();
}

void Button::initWithInternalPullup()
{
  pinMode(pin, INPUT_PULLUP);
  state = getValue();
}

boolean Button::getValue()
{
  return digitalRead(pin);
}

void Button::checkButton()
{
    if(!debounced)
    {
      unsigned long currentMillis = millis();
      if(currentMillis - eventTime >= debounceTimeMs)
      {
        debounced = true;  
      }
    }
    if((state != getValue()) && debounced)
    {
      // Button state has changed
      if(getValue() == false)
      {
        if(isActiveLow)
        {
          buttonPressed();
        }
        else
        {
          buttonReleased();
        }
      }
      else
      {
        if(isActiveLow)
        {
          buttonReleased();
        }
        else
        {
          buttonPressed();
        }
      }
      state = getValue();
      eventTime = millis();
      debounced = false;
    }
}

void Button::buttonPressed()
{
    // if a function is attached to the buttonPressed event, execute it!
    if(fctButtonPressed != NULL)
    {
      (*fctButtonPressed)();
    }  
}

void Button::buttonReleased()
{
  // if a function is attached to the buttonReleased event, execute it!
  if(fctButtonReleased != NULL)
  {
    (*fctButtonReleased)();
  }
}

void Button::attachFunctionOnButtonPressed(void (*func)())
{
  fctButtonPressed = func;
}

void Button::attachFunctionOnButtonReleased(void (*func)())
{
  fctButtonReleased = func;
}

void Button::detachFunctionOnButtonPressed()
{
  fctButtonPressed = NULL;
}

void Button::detachFunctionOnButtonReleased()
{
  fctButtonReleased = NULL;
}
