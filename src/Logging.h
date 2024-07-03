#pragma once

#include "../freertosinc.h"
#include <Print.h>
#include <stdarg.h>
#include <string>

/**
 * This was originally part of RedirectablePrint but:
 * a. (arguably) it should have never been there
 * b. as we've grown we now send logs to lots of different places (BLE, syslog, serial, TCP etc) so it doesn't make sense
 * to be in a class which was really just meant to be a redirectable smart pointer.
 */
class Logging
{
    /// Used to allow multiple logDebug messages to appear on a single log line
    bool isContinuationMessage = false;

#ifdef HAS_FREE_RTOS
    SemaphoreHandle_t inDebugPrint = nullptr;
    StaticSemaphore_t _MutexStorageSpace;
#else
    volatile bool inDebugPrint = false;
#endif
  public:
    Logging();

    /**
     * Debug logging print message
     *
     * If the provide format string ends with a newline we assume it is the final print of a single
     * log message.  Otherwise we assume more prints will come before the log message ends.  This
     * allows you to call logDebug a few times to build up a single log message line if you wish.
     */
    void log(const char *logLevel, const char *format, ...) __attribute__((format(printf, 3, 4)));

    /** like printf but va_list based */
    size_t vprintf(const char *logLevel, const char *format, va_list arg);

    void hexDump(const char *logLevel, unsigned char *buf, uint16_t len);

    std::string mt_sprintf(const std::string fmt_str, ...);

  private:
    void log_to_serial(const char *logLevel, const char *format, va_list arg);
    void log_to_syslog(const char *logLevel, const char *format, va_list arg);
    void log_to_ble(const char *logLevel, const char *format, va_list arg);
};