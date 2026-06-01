#include <stdio.h>
#include "bsp_board.h"

static uint8_t bsp_led_vector = 0;
static uint8_t bsp_rgb_vector = 0;

uint32_t bsp_led_Vector_Gpio_Map [] = {
	[GPIO2]  = BSP_VECTOR_LED0,
	[GPIO4]  = BSP_VECTOR_LED1,
	[GPIO16] = BSP_VECTOR_LED2,
	[GPIO17] = BSP_VECTOR_LED3,
	[GPIO5]  = BSP_VECTOR_LED4
};

uint32_t bsp_RGB_Vector_Gpio_Map [] = {
	[GPIO14] = BSP_VECTOR_LEDRED,
	[GPIO13] = BSP_VECTOR_LEDGREEN,
	[GPIO12] = BSP_VECTOR_LEDBLUE
};

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

bool bsp_get_bit_vector_led(uint8_t bit){
	return ((bsp_led_vector & (1<<bit)) != 0);
}

bool bsp_get_bit_vector_RGB(uint8_t bit){
	return ((bsp_rgb_vector & (1<<bit)) != 0);
}

void bsp_led_on(int led){
	gpio_write(led, true);
	bsp_led_vector |= (1<<led);
}

void bsp_led_off(int led){
	gpio_write(led, false);
	bsp_led_vector &= ~(1<<led);
}

void bsp_led_toggle(int led){
        gpio_write(led, !bsp_get_bit_vector_led(bsp_led_Vector_Gpio_Map[led]));
        bsp_led_vector ^= (1<<bsp_led_Vector_Gpio_Map[led]);
}

void bsp_RGB_on(int led){
	gpio_write(led, true);
	bsp_rgb_vector |= (1<<led);
}

void bsp_RGB_off(int led){
	gpio_write(led, false);
	bsp_rgb_vector &= ~(1<<led);
}

void bsp_RGB_led_toggle(int led){
	gpio_write(led,  !bsp_get_bit_vector_RGB(bsp_RGB_Vector_Gpio_Map[led]));
	bsp_rgb_vector ^= (1<<bsp_RGB_Vector_Gpio_Map[led]);
}

bool bsp_boton_presionado(int button){
	return (gpio_read(button) == 1);
}