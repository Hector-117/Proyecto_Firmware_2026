#ifndef HAL_BOARD_H
#define HAL_BOARD_H

#include <stdbool.h>

/* LEDs */
#define LED_1 0
#define LED_2 1
#define LED_3 2
#define LED_4 3
#define LED_5 4

/* RGB */
#define RED_LED   0
#define GREEN_LED 1
#define BLUE_LED  2

/* Buttons */
#define BUTTON_1 0
#define BUTTON_2 1

void board_init(void);

void led_on(int led);
void led_off(int led);
void led_toggle(int led);

void rgb_on(int led);
void rgb_off(int led);
void rgb_toggle(int led);

bool button_pressed(int button);

#endif