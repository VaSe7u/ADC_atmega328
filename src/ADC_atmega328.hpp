#pragma once
#include <stdint.h>
#include <avr/io.h>
#include <math.h>

namespace m328 {
namespace adc {

enum class Reference : uint8_t {
  AREF = 0, VCC = 1, INTERNAL1V1 = 3,
};
enum class AutoTriggerSource : uint8_t {
  FreeRunningMode = 0,
  AnalogComparator = 1,
  ExternalInterruptRequest0 = 2,
  TimerCounter0CompareMatchA = 3,
  TimerCounter0Overflow = 4,
  TimerCounter1CompareMatchB = 5,
  TimerCounter1Overflow = 6,
  TimerCounter1CaptureEvent = 7,
  Disable = 123,
};

bool initialize(Reference adcReference = Reference::VCC,
                uint8_t adcPrescaler = 0);
void setReference(Reference adcReference);
uint16_t getPrescaler();
bool setPrescaler(uint8_t adcPrescaler);
float getFrequency();
void setAutoTriggerSource(AutoTriggerSource autoTriggerSource);
int16_t read(uint8_t channel);

} //namespace adc
} //namespace m328

namespace atmega328 = m328;
namespace atmega328p = m328;

/*
| CPU clock | Prescale | ADC frequency | ADCSRA bits set           |
|-----------|----------|---------------|---------------------------|
| 1 MHz     | 4        | 250 kHz       | ADPS1                     |
|           | 8        | 125 kHz       | ADPS1 and ADPS0           |
|           | 16       | 62.5 kHz      | ADPS2                     |
|           | 32       | 31.25 kHz     | ADPS2 and ADPS0           |
| 8 MHz     | 16       | 250 kHz       | ADPS2                     |
|           | 32       | 125 kHz       | ADPS2 and ADPS0           |
|           | 64       | 62.5 kHz      | ADPS2 and ADPS1           |
|           | 128      | 31.25 kHz     | ADPS2 and ADPS1 and ADPS0 |
| 12 MHz    | 64       | 187.5 kHz     | ADPS2 and ADPS1           |
|           | 128      | 93.75 kHz     | ADPS2 and ADPS1 and ADPS0 |
| 16 MHz    | 64       | 250 kHz       | ADPS2 and ADPS1           |
|           | 128      | 125 kHz       | ADPS2 and ADPS1 and ADPS0 |
*/