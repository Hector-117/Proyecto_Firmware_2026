#include "hal_board.h"
#include "bsp_board.h"

static const int leds[] = {
    BOARD_LED1,
    BOARD_LED2,
    BOARD_LED3,
    BOARD_LED4,
    BOARD_LED5
};

static const int rgbs[] = {
    RGB_REDLED,
    RGB_GREENLED,
    RGB_BLUELED
};

static const int buttons[] = {
    PUSH_BUTTON_1,
    PUSH_BUTTON_2
};

void board_init(void)
{
    bsp_init();
}

void led_on(int led)
{
    bsp_led_on(leds[led]);
}

void led_off(int led)
{
    bsp_led_off(leds[led]);
}

void led_toggle(int led)
{
    bsp_led_toggle(leds[led]);
}

void rgb_on(int led)
{
    bsp_RGB_on(rgbs[led]);
}

void rgb_off(int led)
{
    bsp_RGB_off(rgbs[led]);
}

void rgb_toggle(int led)
{
    bsp_RGB_led_toggle(rgbs[led]);
}

bool button_pressed(int button)
{
    return bsp_boton_presionado(buttons[button]);
}