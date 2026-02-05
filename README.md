# Zephyr ADC code example

**Analog-to-Digital Converter (ADC) with devicetree**
**Relevant api** adc_interface

**Reads analog inputs from ADC channels.**

---

## Overview

This sample demonstrates how to use the [ADC driver API](https://docs.zephyrproject.org/latest/samples/drivers/adc/adc_dt/README.html).

The [`main.c`](/src/main.c) reads ADC samples from one channel (see `boards/disco_l475_iot1.overlay`) and prints the readings on the console. If voltage of the used reference can be obtained, the raw readings are converted to millivolts.

Recommended reading for the `src/main.c` example: [adc.h File Reference](https://docs.zephyrproject.org/latest/doxygen/html/drivers_2adc_8h.html)

The pins of the ADC channels are board-specific. Please see [board pinout](https://os.mbed.com/platforms/ST-Discovery-L475E-IOT01A/#board-pinout) for ADC pinout range.

## Building and Running

The ADC peripheral and pinmux is configured in the board's ``.dts`` file. Make
sure that the ADC is enabled (``status = "okay";``).

In addition to that, this sample requires an ADC channel specified in the
``io-channels`` property of the ``zephyr,user`` node. This is usually done with
a devicetree overlay.

Configuration of channels (settings like gain, reference, or acquisition time)
also needs to be specified in devicetree, in ADC controller child nodes. Also
the ADC resolution and oversampling setting (if used) need to be specified
there. See `boards/disco_l475_iot1.overlay` for an example of
such setup.

## Building and Running for Disco L475 IOT01

The sample can be built and executed for the
[disco_l475_iot1](https://docs.zephyrproject.org/latest/boards/st/disco_l475_iot1/doc/index.html) as follows:

```bash
west build -b disco_l475_iot1 .
west flash
```

## Sample output

You should get a similar output as below, repeated every second:

```bash
ADC reading:
- ADC_0, channel 7: 36 = 65mV
```

> Note: If the pin is not supported, the output will be an error message.
