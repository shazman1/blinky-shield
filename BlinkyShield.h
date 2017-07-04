#ifndef BLINKYSHIELD_H
#define BLINKYSHIELD_H

#include "PixelArray.h"
#include "WS2812.h"

#define STRIPLEN 40

class BlinkyShield
{
public:
    BlinkyShield();
    ~BlinkyShield();
    void WipeColor(uint32_t, uint8_t);
    void Red(uint8_t, uint8_t);
    void Green(uint8_t, uint8_t);
    void Blue(uint8_t, uint8_t);
    void Off();

private:
    PixelArray* _px;
    WS2812* _shield;
};
#endif
