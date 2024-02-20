#include <stdint.h>
#include <stdio.h>
#include <malloc.h>

//------------------------------------------------------------------------------

#define BytesPerUint8  1
#define BytesPerUint16 2
#define BytesPerUint32 4
#define BytesPerUint64 8

//------------------------------------------------------------------------------

// Base types

#define uint8  uint8_t
#define uint16 uint16_t
#define uint32 uint32_t
#define uint64 uint64_t

#define byte uint8_t

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

void print_bytes(byte *x, int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            //printf(":");
            printf("-");
        }        
        printf("%02X", x[i]);
    }
}

//------------------------------------------------------------------------------

void exampleUint32() {

    uint32 a;
    a = 0x98765432;
    
    int n = BytesPerUint32;
    
    byte x[n];
    little_endian_put_uint32(x, a);
    
    printf("little endian: ");
    print_bytes(x, n);
    printf("\n");
    
    printf("big endian:    ");
    big_endian_put_uint32(x, a);
    print_bytes(x, n);
    printf("\n");
}

void exampleUint64() {

    uint64 a;
    a = 0xdcba9876543210fe;

    int n = BytesPerUint64;

    byte x[n];
    little_endian_put_uint64(x, a);

    printf("little endian: ");
    print_bytes(x, n);
    printf("\n");

    printf("big endian:    ");
    big_endian_put_uint64(x, a);
    print_bytes(x, n);
    printf("\n");
}

void exampleMalloc() {

    uint64 a;
    a = 0x9080706050403020;

    int n = BytesPerUint64;

    byte *x;
    x = malloc(n);
    little_endian_put_uint64(x, a);

    printf("little endian: ");
    print_bytes(x, n);
    printf("\n");

    printf("big endian:    ");
    big_endian_put_uint64(x, a);
    print_bytes(x, n);
    printf("\n");
}

int main() {

    //printf("Hello, Word!\n");

    exampleUint32();
    exampleUint64();
    exampleMalloc();

    return 0;
}
