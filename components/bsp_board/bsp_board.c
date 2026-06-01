#include <stdio.h>
#include "bsp_board.h"

//designated initializers technique
volatile uint32_t bsp_led_Vector_Gpio_Map [] = {
	[BSP_VECTOR_LED0]  = GPIO2,
	[BSP_VECTOR_LED1]  = GPIO4,
	[BSP_VECTOR_LED2]  = GPIO16,
	[BSP_VECTOR_LED3]  = GPIO17,
	[BSP_VECTOR_LED4]  = GPIO5
};

volatile uint32_t bsp_RGB_Vector_Gpio_Map [] = {
	[BSP_VECTOR_LEDRED]    = GPIO14,
	[BSP_VECTOR_LEDGREEN]  = GPIO13,
	[BSP_VECTOR_LEDBLUE]   = GPIO12
};

bsp_status_vector_leds_t bsp_board_leds_vector = {0};
bsp_status_RGB_vector_t  bsp_board_rgb_vector = {0};

void bsp_init(void){
	// ========== Configure Board leds as outputs ========== 
	gpio_config_out(BSP_LED0);
	gpio_config_out(BSP_LED1);
	gpio_config_out(BSP_LED2);
	gpio_config_out(BSP_LED3);
	gpio_config_out(BSP_LED4);
	
	// ========== Configure RGB leds as outputs ==========
	gpio_config_out(BSP_RGB_REDLED);
	gpio_config_out(BSP_RGB_GREENLED);
	gpio_config_out(BSP_RGB_BLUELED);
	
	// ========== Configure buttons as inputs ==========
	gpio_config_in(BSP_PUSH_BUTTON_0, PULL_UP);
	gpio_config_in(BSP_PUSH_BUTTON_1, PULL_UP);
	
	// initial state of each boardled
	gpio_write(BSP_LED0, false);
	gpio_write(BSP_LED1, false);
	gpio_write(BSP_LED2, false);
	gpio_write(BSP_LED3, false);
	gpio_write(BSP_LED4, false);
	
	// initial state of each RGB led
	gpio_write(BSP_RGB_REDLED,   true);
	gpio_write(BSP_RGB_GREENLED, true);
	gpio_write(BSP_RGB_BLUELED,  true);
}

void bsp_led_on(int led){
	gpio_write(led, true);
	bsp_board_leds_vector.bsp_led_vector |= (1<<led);
}

void bsp_led_off(int led){
	gpio_write(led, false);
	bsp_board_leds_vector.bsp_led_vector &= ~(1<<led);
}

void bsp_led_toggle(int led){
        gpio_write(led, !BSP_GET_BIT_VECTOR_LED(bsp_board_leds_vector, led));
        bsp_board_leds_vector.bsp_led_vector ^= (1<<led);
        //printf("%d\n", boardleds_vector.board_led_reg);
}

void bsp_RGB_on(int led){
	gpio_write(led, true);
	bsp_board_rgb_vector.bsp_rgb_vector |= (1<<led);
}

void bsp_RGB_off(int led){
	gpio_write(led, false);
	bsp_board_rgb_vector.bsp_rgb_vector &= ~(1<<led);
}

void bsp_RGB_led_toggle(int led){
	gpio_write(led,  !BSP_GET_BIT_VECTOR_RGB(bsp_board_rgb_vector, led));
	bsp_board_rgb_vector.bsp_rgb_vector ^= (1<<led);
}

bool bsp_boton_presionado(int button){
	return (gpio_read(button) == 1);
}