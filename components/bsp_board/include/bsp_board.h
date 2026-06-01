#ifndef BSP_BOARD_H
#define BSP_BOARD_H

#include "../../gpio_2026/include/gpio_2026.h"

// =============== Name abstraction for board =============== 
#define BSP_LED0 LL_GPIO2
#define BSP_LED1 LL_GPIO4
#define BSP_LED2 LL_GPIO16
#define BSP_LED3 LL_GPIO17
#define BSP_LED4 LL_GPIO5

#define BSP_RGB_REDLED   LL_GPIO14
#define BSP_RGB_GREENLED LL_GPIO13
#define BSP_RGB_BLUELED  LL_GPIO12

#define BSP_PUSH_BUTTON_0 LL_GPIO18
#define BSP_PUSH_BUTTON_1 LL_GPIO19

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
