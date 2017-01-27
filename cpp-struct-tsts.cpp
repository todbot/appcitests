
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int ledRangez[4][2] =
    {
        {0,4},   // step 0: low LED, high LED
        {0,12},
        {0,13},
        {0,20}
    };

typedef struct LedRange
{
    int low;
    int high;
    uint32_t color;

    LedRange( int l, int h, uint32_t c): low(l), high(h), color(c) {};
    LedRange(): low(0), high(255), color(0x000000) {};
    inline bool isBlack() { return color == 0; }

} LedRange;

LedRange ledRanges[4] =
    {
    LedRange(0,4, 0xff00ff),
    LedRange(0,12, 0x00ff00),
    LedRange(0,13, 0x123456),
    //    { 0, 4,  0xff00ff },
    //    { 0, 12, 0x00ffff },
    //    { 0, 13, 0x123456 },
    //    { .low = 2, .high = 5, .color = 0xabcd1234 },
    };

LedRange ledRangesB[4] =
{
};

LedRange foo1 = LedRange( 0, 4, 0xff00ff );
//LedRange foo1 = { 0, 4, 0xff00ff };
//LedRange foo2 = { .low=0, .high=4, .color = 0xff00ff };

typedef uint32_t color_t;
const int ledCnt = 10;
typedef struct LedState
{
    color_t colors[ledCnt];

} LedState;



int main()
{

    printf("hello there\n");

    LedRange ledRange;
    for( int i=0; i<4; i++ ) {
        ledRange = ledRanges[i];
        printf("ledL:%3d, ledH:%3d  color:#%6.6x\n", ledRange.low, ledRange.high, ledRange.color);
    }

}
