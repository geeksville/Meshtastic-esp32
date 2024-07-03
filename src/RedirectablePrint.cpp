#include "RedirectablePrint.h"
#include "NodeDB.h"
#include "RTC.h"
#include "concurrency/OSThread.h"
#include "configuration.h"
#include "main.h"
#include <assert.h>
#include <cstring>
#include <memory>
#include <stdexcept>
#include <sys/time.h>
#include <time.h>

#ifdef ARCH_PORTDUINO
#include "platform/portduino/PortduinoGlue.h"
#endif

void RedirectablePrint::setDestination(Print *_dest)
{
    assert(_dest);
    dest = _dest;
}

size_t RedirectablePrint::write(uint8_t c)
{
    // Always send the characters to our segger JTAG debugger
#ifdef USE_SEGGER
    SEGGER_RTT_PutChar(SEGGER_STDOUT_CH, c);
#endif

    if (!config.has_lora || config.device.serial_enabled)
        dest->write(c);

    return 1; // We always claim one was written, rather than trusting what the
              // serial port said (which could be zero)
}