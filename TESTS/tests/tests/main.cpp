#include "mbed.h"
#include "BlinkyShield.h"

int main()
{
    BlinkyShield* blinky_shield;
    uint32_t BLINKY_COLOR = 0x00ffff;
    uint8_t BLINKY_COLOR_INTENSITY = 10;
    #define BLINKY_PIN D13

    blinky_shield = new BlinkyShield(BLINKY_PIN);

    blinky_shield->Red(BLINKY_COLOR_INTENSITY, 40);
    wait_ms(500);
    blinky_shield->Green(BLINKY_COLOR_INTENSITY, 40);
    wait_ms(500);
    blinky_shield->Blue(BLINKY_COLOR_INTENSITY, 40);
    wait_ms(500);
    blinky_shield->Off();
    wait_ms(500);
    blinky_shield->WipeColor(BLINKY_COLOR, BLINKY_COLOR_INTENSITY, 40);
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
