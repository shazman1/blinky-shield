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
    void wipeColor(uint32_t color, uint8_t n_pixels=STRIPLEN);
    void red(uint8_t n_pixels=STRIPLEN);
    void green(uint8_t n_pixels=STRIPLEN);
    void blue(uint8_t n_pixels=STRIPLEN);
    void off();
    void drawPixel(int16_t x, int16_t y, uint16_t color);
    void scroll(const char *fmt, ...);
    void clear();
    void setIntensity(uint8_t intensity);

private:
    PixelArray* _px;
    WS2812* _shield;
};
#endif
