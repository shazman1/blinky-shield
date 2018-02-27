#include "mbed.h"
#include "BlinkyShield.h"

int main()
{
    BlinkyShield* blinky_shield;
    uint32_t BLINKY_COLOR = CYAN;
    uint8_t BLINKY_COLOR_INTENSITY = 10;
    #define BLINKY_PIN D13

    blinky_shield = new BlinkyShield(BLINKY_PIN);
    blinky_shield->setIntensity(10);

    blinky_shield->red();
    wait_ms(500);
    blinky_shield->green();
    wait_ms(500);
    blinky_shield->blue();
    wait_ms(500);
    blinky_shield->off();
    wait_ms(500);
    blinky_shield->wipeColor(BLINKY_COLOR);
    wait_ms(500);
    blinky_shield->clear();
    blinky_shield->setTextColor(BLINKY_COLOR);
    blinky_shield->putc('A');
    wait_ms(500);
    blinky_shield->clear();
    blinky_shield->setCursor(1, 1);
    blinky_shield->putc('B');
    wait_ms(500);
    blinky_shield->clear();
    blinky_shield->setCursor(2, 1);
    blinky_shield->putc('C');
    wait_ms(500);
    blinky_shield->clear();
    blinky_shield->setCursor(3, 1);
    blinky_shield->putc('D');

    int number = 1;
    wait_ms(500);
    blinky_shield->clear();
    blinky_shield->scroll("armMbed %i", number);
    /* code */
    return 0;
}
