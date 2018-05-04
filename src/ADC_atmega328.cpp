#include "ADC_atmega328.hpp"

namespace m328 {
namespace adc {

bool initialize(Reference adcReference, uint8_t adcPrescaler) {
  setReference(adcReference);
  bool s = setPrescaler(adcPrescaler);

  PRR &= ~(1 << PRADC); // Disable ADC Power Reduction

  // ADEN ADC ENable
  ADCSRA |= (1 << ADEN); // enable ADC

  // ADMUX = (0xf0 & ADMUX) | PC3;

  // ADCSRA |= (1 << ADSC); // start first conversion
  return s;
}

void setReference(Reference adcReference) {
  uint8_t refMask = 0b11000000 & ((uint8_t)adcReference << 6);
  // adcRef          00000001 (VCC)
  // adcRefShifted6  01000000
  // mask            11000000
  // refMask&        01000000

  uint8_t chMask = ADMUX & 0b00001111;
  // ADMUX           11100010
  // mask            00001111
  // chMask&         00000010

  ADMUX = refMask | chMask;
  // refMask         01000000
  // chMask          00000010
  // ADMUX           01000010
}

uint16_t getPrescaler() {
  return round(pow(2, ADCSRA & 0b00000111));
}

bool setPrescaler(uint8_t adcPrescaler) {
  if (adcPrescaler == 0) {
    adcPrescaler = F_CPU / 200000; // 16M/200k = 80

    while (adcPrescaler <= 128) {
      float adcPrescaler_log2 = log(adcPrescaler) / log(2); // log2(adcPrescaler)
      if (adcPrescaler_log2 == ceilf(adcPrescaler_log2)) break; // break loop if real number
      ++adcPrescaler;
    }
  } else {
    float adcPrescaler_log2 = log(adcPrescaler) / log(2); // log2(adcPrescaler)
    if (adcPrescaler_log2 == ceilf(adcPrescaler_log2)) return false; // exit if invalid prescaler
  }

  uint8_t mask = 0b00000111 & ((uint8_t)(log(adcPrescaler) / log(2)));
  ADCSRA = (ADCSRA & 0b11111000) | mask;
  return true;
}

float getFrequency() {
  return F_CPU / getPrescaler();
}

void setAutoTriggerSource(AutoTriggerSource autoTriggerSource) {
  ADCSRB = (ADCSRB & 0b11111000) | (uint8_t)autoTriggerSource;
  ADCSRA |= (1 << ADATE);
  if (autoTriggerSource == AutoTriggerSource::FreeRunningMode) {
    ADCSRA |= (1 << ADSC);
  } else if (autoTriggerSource == AutoTriggerSource::Disable) {
    ADCSRA &= ~(1 << ADATE);
  }
}

int16_t read(uint8_t channel) {
  // if not same channel and in freerunning
  if (!( (ADMUX & 0xf0) & (0xf0 & channel) )) { // if not same channel
    ADMUX = (0xf0 & ADMUX) | channel;
    if (ADCSRA & (1 << ADATE)) { // if in freerunning
      ADCSRA &= ~(1 << ADEN);
      ADCSRA &= ~(1 << ADATE);
      ADCSRA |= (1 << ADEN);
      ADCSRA |= (1 << ADATE);
      ADCSRA |= (1 << ADSC);
    }
  }
  if (!(ADCSRA & (1 << ADATE))) { // if not in free running
    ADCSRA |= (1 << ADSC);
  while (ADCSRA & (1 << ADSC));
  } else {
    // while (!(ADCSRA & (1 << ADIF)));
    // ADCSRA &= ~(1 << ADIF);
  }
  return ADC;
}

} //namespace adc
} //namespace m328