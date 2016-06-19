// Copyright 2016 Zorxx Software. All rights reserved.
// File: DebouncedInput.cpp
// Brief: Library implementing support for debounced digital inputs.

#include <limits.h>
#include "Arduino.h"
#include <DebouncedInput.h>

DebouncedInput::DebouncedInput(const int pin, const unsigned long debounce_ms):
  m_pin(pin), m_debounce_ms(debounce_ms), m_waiting(false)
{
  pinMode(m_pin, INPUT);
  m_state = digitalRead(m_pin);
}

int DebouncedInput::Read()
{
  unsigned long current_time = millis();
  int val = digitalRead(m_pin);
    
  if(m_waiting)
  {
    if(TimeDifference(m_start_ms, current_time) > m_debounce_ms)
    {
      m_state = val;
      m_waiting = false;
    }
  }
  else
  {
    if(m_state != val)
    {
      m_start_ms = current_time;
      m_waiting = true;        
    }
  }

  return m_state;
}

unsigned long DebouncedInput::TimeDifference(unsigned long start_time, unsigned long stop_time)
{
  if(stop_time < start_time)
    return (stop_time + (ULONG_MAX - start_time));
  else
    return stop_time - start_time;
}
