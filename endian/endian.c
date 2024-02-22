#include "endian.h"

//------------------------------------------------------------------------------

// LittleEndian

uint16 little_endian_get_uint16(byte *x) {
    uint16 r = 0;
    r |= ((uint16)(x[0]) << 0);
    r |= ((uint16)(x[1]) << 8);
    return r;
}

void little_endian_put_uint16(byte *x, uint16 v) {
    x[0] = (byte)(v >> 0);
    x[1] = (byte)(v >> 8);
}

uint32 little_endian_get_uint32(byte *x) {
    uint32 r = 0;
    r |= ((uint32)(x[0]) << 0);
    r |= ((uint32)(x[1]) << 8);
    r |= ((uint32)(x[2]) << 16);
    r |= ((uint32)(x[3]) << 24);
    return r;
}

void little_endian_put_uint32(byte *x, uint32 v) {
    x[0] = (byte)(v >> 0);
    x[1] = (byte)(v >> 8);
    x[2] = (byte)(v >> 16);
    x[3] = (byte)(v >> 24);
}

uint64 little_endian_get_uint64(byte *x) {
    uint64 r = 0;
    r |= ((uint64)(x[0]) << 0);
    r |= ((uint64)(x[1]) << 8);
    r |= ((uint64)(x[2]) << 16);
    r |= ((uint64)(x[3]) << 24);
    r |= ((uint64)(x[4]) << 32);
    r |= ((uint64)(x[5]) << 40);
    r |= ((uint64)(x[6]) << 48);
    r |= ((uint64)(x[7]) << 56);
    return r;
}

void little_endian_put_uint64(byte *x, uint64 v) {
   x[0] = (byte)(v >> 0);
   x[1] = (byte)(v >> 8);
   x[2] = (byte)(v >> 16);
   x[3] = (byte)(v >> 24);
   x[4] = (byte)(v >> 32);
   x[5] = (byte)(v >> 40);
   x[6] = (byte)(v >> 48);
   x[7] = (byte)(v >> 56);
}

//------------------------------------------------------------------------------

// BigEndian

uint16 big_endian_get_uint16(byte *x) {
    uint16 r = 0;
    r |= ((uint16)(x[0]) << 8);
    r |= ((uint16)(x[1]) << 0);
    return r;
}

void big_endian_put_uint16(byte *x, uint16 v) {
    x[0] = (byte)(v >> 8);
    x[1] = (byte)(v >> 0);
}

uint32 big_endian_get_uint32(byte *x) {
    uint32 r = 0;
    r |= ((uint32)(x[0]) << 24);
    r |= ((uint32)(x[1]) << 16);
    r |= ((uint32)(x[2]) << 8);
    r |= ((uint32)(x[3]) << 0);
    return r;
}

void big_endian_put_uint32(byte *x, uint32 v) {
    x[0] = (byte)(v >> 24);
    x[1] = (byte)(v >> 16);
    x[2] = (byte)(v >> 8);
    x[3] = (byte)(v >> 0);
}

uint64 big_endian_get_uint64(byte *x) {
    uint64 r = 0;
    r |= ((uint64)(x[0]) << 56);
    r |= ((uint64)(x[1]) << 48);
    r |= ((uint64)(x[2]) << 40);
    r |= ((uint64)(x[3]) << 32);
    r |= ((uint64)(x[4]) << 24);
    r |= ((uint64)(x[5]) << 16);
    r |= ((uint64)(x[6]) << 8);
    r |= ((uint64)(x[7]) << 0);
    return r;
}

void big_endian_put_uint64(byte *x, uint64 v) {
    x[0] = (byte)(v >> 56);
    x[1] = (byte)(v >> 48);
    x[2] = (byte)(v >> 40);
    x[3] = (byte)(v >> 32);
    x[4] = (byte)(v >> 24);
    x[5] = (byte)(v >> 16);
    x[6] = (byte)(v >> 8);
    x[7] = (byte)(v >> 0);
}

//------------------------------------------------------------------------------
