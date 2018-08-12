#include <stdarg.h>
#include <Arduino.h>

#define DEBUG 1

void InitializeLogs()
{
  #ifdef DEBUG
  Serial.begin(9600);
  #endif

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void Logf(char *fmt, ... )
{
#ifdef DEBUG
        char buf[128]; // resulting string limited to 128 chars
        va_list args;
        va_start (args, fmt );
        vsnprintf(buf, 128, fmt, args);
        va_end (args);
        Serial.println(buf);
#endif
}
