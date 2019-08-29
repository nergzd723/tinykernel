#ifndef TYPES_H
#define TYPES_H
typedef unsigned int   u32;
typedef          int   s32;
typedef unsigned short u16;
typedef          short s16;
typedef unsigned char  u8;
typedef          char  s8;
#define low_16(address) (u16)((address) & 0xFFFF)
#define high_16(address) (u16)(((address) >> 16) & 0xFFFF)
typedef unsigned char int8;
typedef int8 byte;
typedef unsigned short int16;
typedef int16 byte2;
typedef unsigned long int32;
typedef int16 byte4;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
#endif
