#ifndef BLINKYSHIELD_H
#define BLINKYSHIELD_H

#include "mbed.h"
#include "PixelArray.h"
#include "WS2812.h"
#include "Adafruit_GFX.h"

#define STRIPLEN 40

class BlinkyShield : public Adafruit_GFX
{
public:
    BlinkyShield(PinName pin=D6);
    ~BlinkyShield();
    void WipeColor(uint32_t, uint8_t, uint8_t);
    void Red(uint8_t, uint8_t);
    void Green(uint8_t, uint8_t);
    void Blue(uint8_t, uint8_t);
    void Off();
    void drawPixel(int16_t x, int16_t y, uint16_t color);
    void scroll(const char *fmt, ...);
    void clear();

private:
    PixelArray* _px;
    WS2812* _shield;
};
#endif
