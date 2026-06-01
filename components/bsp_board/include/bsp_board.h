#ifndef BSP_BOARD_H
#define BSP_BOARD_H

#include "../../gpio_2026/include/gpio_2026.h"

// =============== Name abstraction for board =============== 
#define BSP_LED0 GPIO2
#define BSP_LED1 GPIO4
#define BSP_LED2 GPIO16
#define BSP_LED3 GPIO17
#define BSP_LED4 GPIO5

#define BSP_RGB_REDLED   GPIO14
#define BSP_RGB_GREENLED GPIO13
#define BSP_RGB_BLUELED  GPIO12

#define BSP_PUSH_BUTTON_0 GPIO18
#define BSP_PUSH_BUTTON_1 GPIO19

typedef enum{
	BSP_VECTOR_LED0 = 0,
	BSP_VECTOR_LED1 = 1,
	BSP_VECTOR_LED2 = 2,
	BSP_VECTOR_LED3 = 3,
	BSP_VECTOR_LED4 = 4,
} bsp_ivector_led_t;

typedef enum{
	BSP_VECTOR_LEDRED = 0,
	BSP_VECTOR_LEDGREEN = 1,
	BSP_VECTOR_LEDBLUE = 2,
} bsp_ivector_rgb_t;

//  =============== Vector state of board leds =============== 
bool bsp_get_bit_vector_led(uint8_t bit);

//  =============== Vector state of RGB vector =============== 
bool bsp_get_bit_vector_RGB(uint8_t bit);

// =============== Function prototypes for BSP =============== 
// Initialize the boards components
void bsp_init(void);

// Abstraction for board leds
void bsp_led_on(int led);
void bsp_led_off(int led);
void bsp_led_toggle(int led);

// Abstraction for RGB leds
void bsp_RGB_on(int led);
void bsp_RGB_off(int led);
void bsp_RGB_led_toggle(int led);


// Abstraction for board buttons
bool bsp_pressed_button(int button);



#endif
