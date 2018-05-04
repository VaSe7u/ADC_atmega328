*ADC_atmega328 is a collection of functions for configuring and using the ADC on ATmega328.*

[![release](https://img.shields.io/badge/release-0.1.0-yellow.svg)](https://github.com/VaSe7u/ADC_atmega328/releases)
[![license](https://img.shields.io/github/license/mashape/apistatus.svg?maxAge=2592000)](https://opensource.org/licenses/mit-license.php)


**ADC_atmega328**.
This library is an alternative to Arduino's functions for working with the ADC. It is specifically for the ATmega328 and provides functions for setting a trigger source and changing the ADC circuit's operating frequency.


Resources
=========
 - [Examples][examples]
 - [Latest release][latest release]


Features
========
 - Configurable trigger source.
 - Configurable ADC circuit's operating frequency.
 - Lighter.


Requirements
============
 - ATmega328.


Quick start
===========
```c++
#include <ADC_atmega328.hpp>
using namespace m328; // namespace for ATmega328 specific code.

void setup() {
  adc::initialize(adc::Reference::INTERNAL1V1);
}

void loop() {
  int16_t adcReading = adc::read(3);
}

```

License
=======
The MIT License (MIT)

Copyright (c) 2016 Vasil Kalchev

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

[examples]: https://github.com/VaSe7u/ADC_atmega328/tree/master/examples
[latest release]: https://github.com/VaSe7u/ADC_atmega328/releases/latest
