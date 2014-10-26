/* Limited recreation of expected arduino header for testing */

#ifndef Virtuino_h
#define Virtuino_h


#include <stdlib.h>
#include "Serial.h"

#ifdef __cplusplus
extern "C" {
#endif


#define OUTPUT 1
#define HIGH 2
#define LOW 3

// TODO link against real headers
void pinMode      ( uint8_t, uint8_t );
void digitalWrite ( uint8_t, uint8_t );
int  digitalRead  ( uint8_t );
void delay        ( unsigned long );


#ifdef __cplusplus
} // extern C
#endif

#endif // Virduino_h
