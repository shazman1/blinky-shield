#include "BlinkyShield.h"
#include "PixelArray.h"
#include "WS2812.h"

BlinkyShield::BlinkyShield()
{
    _shield = new WS2812(D6, STRIPLEN, 0, 5, 5, 0);
    _px = new PixelArray(STRIPLEN);
    Off();
}

BlinkyShield::~BlinkyShield()
{
    delete _shield;
    delete _px;
}

void BlinkyShield::WipeColor(uint32_t color, uint8_t n_pixels=STRIPLEN)
{
    for (uint8_t i = 0; i < STRIPLEN; i++)
    {
        if (i < n_pixels)
        {
            _px->Set(i, color & 0xffffff);
        }
        else
        {
            _px->Set(i, 0);
        }
    }
    _shield->write_offsets(_px->getBuf(),0,0,0);
}

void BlinkyShield::Red(uint8_t intensity=UINT8_MAX, uint8_t n_pixels=STRIPLEN)
{
    WipeColor(0xff0000*intensity/UINT8_MAX, n_pixels);
}

void BlinkyShield::Green(uint8_t intensity=UINT8_MAX, uint8_t n_pixels=STRIPLEN)
{
    WipeColor(0x00ff00*intensity/UINT8_MAX, n_pixels);
}

void BlinkyShield::Blue(uint8_t intensity=UINT8_MAX, uint8_t n_pixels=STRIPLEN)
{
    WipeColor(0x0000ff*intensity/UINT8_MAX, n_pixels);
}

void BlinkyShield::Off()
{
    WipeColor(0);
}
