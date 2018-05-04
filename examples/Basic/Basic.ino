/*
 * ADC_atmega328 library - Basic.ino
 *
 * This is a basic example of using the library with Arduino.
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

	adc::initialize(); // ADC default initialization.
	/* Default reference is VCC.
	   Default prescaler is calculated to divide the frequency to a
	   number below 200kHz. */
}

void loop() {
	// Read the analog voltage on channel 3.
	Serial.print("ADC reading: "); Serial.println(adc::read(3));
	delay(1);
}