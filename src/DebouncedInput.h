// Copyright 2016 Zorxx Software. All rights reserved.
// File: DebouncedInput.h
// Brief: Library implementing support for debounced digital inputs.

class DebouncedInput
{
  public:
    DebouncedInput(const int pin, const unsigned long debounce_ms);

  public:
    int Read();

  private:
    int m_pin;
    unsigned long m_debounce_ms;
    
    bool m_waiting;
    int m_state;
    unsigned long m_start_ms;

    unsigned long TimeDifference(unsigned long start_time, unsigned long stop_time);
};

