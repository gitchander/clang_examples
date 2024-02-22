#ifndef __ENDIAN__
#define __ENDIAN__

//------------------------------------------------------------------------------

#include <stdint.h>

//------------------------------------------------------------------------------

#define BytesPerUint8  1
#define BytesPerUint16 2
#define BytesPerUint32 4
#define BytesPerUint64 8

//------------------------------------------------------------------------------

// Base types

//#define byte uint8_t
//#define uint8  uint8_t
//#define uint16 uint16_t
//#define uint32 uint32_t
//#define uint64 uint64_t

typedef uint8_t  byte;
typedef uint8_t  uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

//------------------------------------------------------------------------------

// LittleEndian

uint16 little_endian_get_uint16(byte *x);
void little_endian_put_uint16(byte *x, uint16 v);

uint32 little_endian_get_uint32(byte *x);
void little_endian_put_uint32(byte *x, uint32 v);

uint64 little_endian_get_uint64(byte *x);
void little_endian_put_uint64(byte *x, uint64 v);

//------------------------------------------------------------------------------

// BigEndian

uint16 big_endian_get_uint16(byte *x);
void big_endian_put_uint16(byte *x, uint16 v);

uint32 big_endian_get_uint32(byte *x);
void big_endian_put_uint32(byte *x, uint32 v);

uint64 big_endian_get_uint64(byte *x);
void big_endian_put_uint64(byte *x, uint64 v);

//------------------------------------------------------------------------------

#endif // __ENDIAN__
