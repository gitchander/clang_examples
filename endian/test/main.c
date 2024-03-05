#include <stdint.h>
#include <stdio.h>
#include <malloc.h>

//------------------------------------------------------------------------------

#include "../endian.h"

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

    exampleUint32();
    exampleUint64();
    exampleMalloc();

    return 0;
}
