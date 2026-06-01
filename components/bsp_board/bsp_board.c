#include <stdio.h>
#include "bsp_board.h"

//designated initializers technique
volatile uint32_t Pin_Gpio_Map [] = {
	[LED1]  = GPIO2,
	[LED2]  = GPIO4,
	[LED3]  = GPIO16,
	[LED4]  = GPIO17,
	[LED5]  = GPIO5
};

volatile uint32_t RGB_Gpio_Map [] = {
	[LEDRED]  = GPIO14,
	[LEDGREEN]  = GPIO13,
	[LEDBLUE]  = GPIO12
};


STATUS_BOARD_LEDS_t boardleds_vector = {0};
STATUS_RGB_t rgb_vector = {0};

void bsp_init(void){
	// ========== Configure Board leds as outputs ========== 
	gpio_config_out(BOARD_LED1);
	gpio_config_out(BOARD_LED2);
	gpio_config_out(BOARD_LED3);
	gpio_config_out(BOARD_LED4);
	gpio_config_out(BOARD_LED5);
	
	// ========== Configure RGB leds as outputs ==========
	gpio_config_out(RGB_REDLED);
	gpio_config_out(RGB_GREENLED);
	gpio_config_out(RGB_BLUELED);
	
	// ========== Configure buttons as inputs ==========
	gpio_config_in(PUSH_BUTTON_1, PULL_UP);
	gpio_config_in(PUSH_BUTTON_2, PULL_UP);
	
	// initial state of each boardled
	gpio_write(BOARD_LED1, false);
	gpio_write(BOARD_LED2, false);
	gpio_write(BOARD_LED3, false);
	gpio_write(BOARD_LED4, false);
	gpio_write(BOARD_LED5, false);
	
	// initial state of each RGB led
	gpio_write(RGB_REDLED, true);
	gpio_write(RGB_GREENLED, true);
	gpio_write(RGB_BLUELED, true);
}

void bsp_led_on(int led){
	gpio_write(led, true);
	boardleds_vector.board_led_reg |= (1<<led);
}

void bsp_led_off(int led){
	gpio_write(led, false);
	boardleds_vector.board_led_reg &= ~(1<<led);
}

void bsp_led_toggle(board_led_t led){
        gpio_write(Pin_Gpio_Map[led], !GET_BIT_VECTOR_BOARD_LED_REG(boardleds_vector, led));
        boardleds_vector.board_led_reg ^= (1<<led);
        //printf("%d\n", boardleds_vector.board_led_reg);
}

void bsp_RGB_on(int led){
	gpio_write(led, true);
	rgb_vector.rgb_reg |= (1<<led);
}

void bsp_RGB_off(int led){
	gpio_write(led, false);
	rgb_vector.rgb_reg &= ~(1<<led);
}

void bsp_RGB_led_toggle(board_rgb_t led){
	gpio_write(RGB_Gpio_Map[led],  !GET_BIT_VECTOR_RGB(rgb_vector, led));
	rgb_vector.rgb_reg ^= (1<<led);
}

bool bsp_boton_presionado(int button){
	return (gpio_read(button) == 1);
}