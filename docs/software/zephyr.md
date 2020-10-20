# Zephyr

Notes about a possible zephyr port.

https://docs.platformio.org/en/latest/frameworks/zephyr.html
https://infocenter.nordicsemi.com/pdf/nwp_029.pdf - white paper

tutorial
https://docs.platformio.org/en/latest/tutorials/nordicnrf52/zephyr_debugging_unit_testing_inspect.html?utm_source=docs.zephyrproject.org - platformio + zephyr + bluetooth
https://www.novelbits.io/zephyr-getting-started-bluetooth-low-energy-development/
https://docs.zephyrproject.org/latest/getting_started/index.html - official
https://docs.zephyrproject.org/latest/application/index.html#application - how to format app and board tree
https://www.zephyrproject.org/getting-started-with-zephyr-rtos-on-nordic-nrf52832-hackable/ 

https://docs.zephyrproject.org/latest/guides/west/build-flash-debug.html#setting-a-default-board

https://docs.zephyrproject.org/latest/guides/debugging/gdbstub.html - adds debugging support without jtag hardware

both platforms use mcuboot as the bootloader

port to run on zephyr - mynewt seems to have poor support for nrf52833 and poor adoption

https://trends.google.com/trends/explore?date=2018-09-17%202020-10-17&geo=US&q=%2Fg%2F11c43x0zjj,%2Fg%2F11clw65g2k


## other options?

https://github.com/soburi/openthread_nrf52_arduino

or on mbed?
https://github.com/arduino/ArduinoCore-nRF528x-mbedos
framework-arduino-nrf52-mbedos

TODO - try framework-arduino-nrf52-mbedos experiment in platformio

## install

~/development/zephyrproject$ pip3 install -r ./zephyr/scripts/requirements.txt

https://docs.zephyrproject.org/latest/boards/arm/nrf52840dk_nrf52840/doc/index.html

## meshtastic port plan

* finish removing freertos
* test linux build
* build with sim on zephr measure ram/flash usage
* implement i2c/spi/interrupts/gpio
* implement ble
* make a ppr1 board def

## Samples

### blinky

~/development/zephyrproject/zephyr$ west build -p auto -b nrf52840dk_nrf52840 samples/basic/blinky
~/development/zephyrproject/zephyr$ west flash
-- west flash: rebuilding
[0/1] cd /home/kevinh/development/zephyrproject/zephyr/build/zephyr/cmake/flash && /usr/bin/cmake -E echo

-- west flash: using runner nrfjprog
Using board 683955052
-- runners.nrfjprog: Flashing file: /home/kevinh/development/zephyrproject/zephyr/build/zephyr/zephyr.hex
Parsing hex file.
Erasing page at address 0x0.
Erasing page at address 0x1000.
Erasing page at address 0x2000.
Erasing page at address 0x3000.
Applying system reset.
Checking that the area to write is not protected.
Programming device.
Enabling pin reset.
Applying pin reset.
-- runners.nrfjprog: Board with serial number 683955052 flashed successfully.
~/development/zephyrproject/zephyr$ 

### BLE peripheral

Uses 160KB of flash and 26KB RAM, not too bad... vs SoftDevice 7.2 needs 24KB of RAM and 160KB of flash.

west build -p auto -b nrf52840dk_nrf52840 samples/bluetooth/peripheral
[210/215] Linking C executable zephyr/zephyr_prebuilt.elf
Memory region         Used Size  Region Size  %age Used
           FLASH:      160248 B         1 MB     15.28%
            SRAM:       26576 B       256 KB     10.14%
        IDT_LIST:         152 B         2 KB      7.42%
[215/215] Linking C executable zephyr/zephyr.elf
