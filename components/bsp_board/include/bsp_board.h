#ifndef BSP_BOARD_H
#define BSP_BOARD_H

#include "../../gpio_2026/include/gpio_2026.h"

// =============== Name abstraction for board =============== 
#define BOARD_LED1 GPIO2
#define BOARD_LED2 GPIO4
#define BOARD_LED3 GPIO16
#define BOARD_LED4 GPIO17
#define BOARD_LED5 GPIO5

#define RGB_REDLED   GPIO14
#define RGB_GREENLED GPIO13
#define RGB_BLUELED  GPIO12

#define PUSH_BUTTON_1 GPIO18
#define PUSH_BUTTON_2 GPIO19


// ======================Enums=====================
typedef enum{
	LED1 = 0,
	LED2 = 1,
	LED3 = 2,
	LED4 = 3,
	LED5 = 4,
} board_led_t;

typedef enum{
	LEDRED = 0,
	LEDGREEN = 1,
	LEDBLUE = 2,
} board_rgb_t;

// ========map enum leds with real GPIO value ========


//  =============== Union of structs to handle Board leds =============== 
typedef union
{
    struct
    {
        uint8_t board_led1_state : 1;
        uint8_t board_led2_state : 1;
        uint8_t board_led3_state : 1;
        uint8_t board_led4_state : 1;
        uint8_t board_led5_state : 1;
    };

    uint8_t board_led_reg;

} STATUS_BOARD_LEDS_t;
#define GET_BIT_VECTOR_BOARD_LED_REG(x, y) ((x.board_led_reg & (1<<y)) != 0)

//  =============== Union of structs to handle RGB leds =============== 
typedef union
{
    struct
    {
        uint8_t rgb_red_state   : 1;
        uint8_t rgb_green_state : 1;
        uint8_t rgb_blue_state  : 1;
    };

    uint8_t rgb_reg;

} STATUS_RGB_t;
#define GET_BIT_VECTOR_RGB(x, y) ((x.rgb_reg & (1<<y)) != 0)

// =============== Function prototypes for BSP =============== 
// Initialize the boards components
void bsp_init(void);

// Abstraction for board leds
void bsp_led_on(int led);
void bsp_led_off(int led);
void bsp_led_toggle(board_led_t led);

// Abstraction for RGB leds
void bsp_RGB_on(int led);
void bsp_RGB_off(int led);
void bsp_RGB_led_toggle(board_rgb_t led);


// Abstraction for board buttons
bool bsp_pressed_button(int button);



#endif
