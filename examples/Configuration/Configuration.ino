/*
 * ADC_atmega328 library - Configuration.ino
 *
 * This is an example of configuring the ADC on Arduino.
 *
 * Created May 4, 2018
 * by Vasil Kalchev
 *
 * https://github.com/VasilKalchev/ADC_atmega328
 *
 */

#include <ADC_atmega328.hpp>

/* This library uses namespaces for encapsulation. ATmega328 specific
   code is under the namespace 'm328', the ADC code is under the
   namespace 'adc'. */
using namespace m328; // namespace for ATmega328 specific code.

void setup() {
  Serial.begin(250000);

  adc::initialize(adc::Reference::INTERNAL1V1,
                  adc::AutoTriggerSource::FreeRunningMode);
  // The ADC can also be configured with the following functions:
  // adc::setReference(adc::Reference::VCC);
  // adc::setAutoTriggerSource(adc::AutoTriggerSource::Disable);
  // adc::setPrescaler(128);
}

void loop() {
  // Read the analog voltage on channel 3.
  Serial.print("ADC reading: "); Serial.println(adc::read(3));
  delay(1);
}