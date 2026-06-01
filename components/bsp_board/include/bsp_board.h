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


// ======================Enums=====================
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

//  =============== Union of structs to handle Board leds =============== 
typedef union
{
    struct
    {
        uint8_t bsp_vector_led0_state : 1;
        uint8_t bsp_vector_led1_state : 1;
        uint8_t bsp_vector_led2_state : 1;
        uint8_t bsp_vector_led3_state : 1;
        uint8_t bsp_vector_led4_state : 1;
    };

    uint8_t bsp_led_vector;

} bsp_status_vector_leds_t; 
#define BSP_GET_BIT_VECTOR_LED(x, y) ((x.bsp_led_vector & (1<<y)) != 0)

//  =============== Union of structs to handle RGB leds =============== 
typedef union
{
    struct
    {
        uint8_t bsp_rgb_vector_red_state   : 1;
        uint8_t bsp_rgb_vector_green_state : 1;
        uint8_t bsp_rgb_vector_blue_state  : 1;
    };

    uint8_t bsp_rgb_vector;

} bsp_status_RGB_vector_t;
#define BSP_GET_BIT_VECTOR_RGB(x, y) ((x.bsp_rgb_vector & (1<<y)) != 0)

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
