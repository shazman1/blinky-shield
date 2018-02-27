#include "mbed.h"
#include "BlinkyShield.h"
#include "PixelArray.h"
#include "WS2812.h"
#include "string.h"
#include "stdio.h"

BlinkyShield::BlinkyShield(PinName pin)
: Adafruit_GFX(5, 8)
{
    _shield = new WS2812((PinName)pin, STRIPLEN,
        MBED_CONF_BLINKY_SHIELD_WS2812_ZERO_HIGH,
        MBED_CONF_BLINKY_SHIELD_WS2812_ZERO_LOW,
        MBED_CONF_BLINKY_SHIELD_WS2812_ONE_HIGH,
        MBED_CONF_BLINKY_SHIELD_WS2812_ONE_LOW);
    _px = new PixelArray(STRIPLEN);
    off();
}

BlinkyShield::~BlinkyShield()
{
    delete _shield;
    delete _px;
}

void BlinkyShield::setIntensity(uint8_t intensity)
{
    _shield->useII(WS2812::GLOBAL);
    _shield->setII(intensity);
}

void BlinkyShield::wipeColor(uint32_t color, uint8_t n_pixels)
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

void BlinkyShield::red(uint8_t n_pixels)
{
    wipeColor(0xff0000, n_pixels);
}

void BlinkyShield::green(uint8_t n_pixels)
{
    wipeColor(0x00ff00, n_pixels);
}

void BlinkyShield::blue(uint8_t n_pixels)
{
    wipeColor(0x0000ff, n_pixels);
}

void BlinkyShield::off()
{
    wipeColor(0);
}

void BlinkyShield::drawPixel(int16_t x, int16_t y, uint16_t color)
{
    if ((x >= this->width()) || (y >= this->height()))
        return;

    uint8_t n = y + (this->width() - x - 1) * this->height();

    uint8_t r = color >> 11;
    uint8_t g = color >> 5 & 0x3f;
    uint8_t b = color & 0x1f;
    uint32_t c = r << 16 | g << 8 | b;

    _px->Set(n, c & 0xffffff);
    _shield->write_offsets(_px->getBuf(),0,0,0);
}


void BlinkyShield::scroll(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    const uint8_t max_str_len = 100;
    char s[max_str_len] = {0};
    vsnprintf(s, max_str_len, fmt, args);
    uint8_t len = strnlen(s, max_str_len);
    int len_in_px = len * 6;
    this->setTextWrap(false);
    for (int x = this->width(); x > -len_in_px; --x)
    {
        this->clear();
        this->setCursor(x, 1);
        this->printf(s);
        wait_ms(200);
    }
    va_end(args);
}

void BlinkyShield::clear()
{
    this->off();
    this->setCursor(0, 0);
}
