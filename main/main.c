/**
 * @file main.c
 * @brief App program.
 *
 * @details
 * This file contains the App program which its a RGB 
 * control via buttons 16 and 17
 *
 * @author Hector Said Herrera Niño
 * @author José Francisco Padilla Torres
 * @date 2026-06-01
 */
#include "bsp_board.h"


/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
void app_main(void)
{
	bsp_init();

	/*gpio_config_in(GPIO18, PULL_UP);
	gpio_config_in(GPIO19, PULL_UP);

	gpio_config_out(GPIO2);
	gpio_config_out(GPIO4);
	gpio_config_out(GPIO5);
	gpio_config_out(GPIO16);
	gpio_config_out(GPIO17);
	gpio_config_out(GPIO12);
	gpio_config_out(GPIO13);
	gpio_config_out(GPIO14);*/
	
	bool led_state_18 [] = {false, true}; // ESTADOS DEL LED PARA APAGADO Y ENCENDIDO
	bool state_pin18 = true;
	bool state_pin18_old = true;

	bool led_state_19 [] = {false, true}; // ESTADOS DEL LED PARA APAGADO Y ENCENDIDO
	bool state_pin19 = true;
	bool state_pin19_old = true;
	
	while(true){
		//state_pin18 = gpio_read(GPIO18);
		//state_pin19 = gpio_read(GPIO19);
		//state_pin18 = ll_gpio_read(BSP_PUSH_BUTTON_0);
		//state_pin19 = ll_gpio_read(BSP_PUSH_BUTTON_1);
		state_pin18 = bsp_pressed_button(BSP_PUSH_BUTTON_0);
		state_pin19 = bsp_pressed_button(BSP_PUSH_BUTTON_1);

		if ((state_pin18 == false) && (state_pin18_old == true)){ //DETECCIÓN DE FALNCO DESCENDENTE EN PIN18
			printf("Boton 1 presionado lavos kayaaaaaa\n");
			led_state_18[0] = !led_state_18[0]; //CAMBIO DE ESTADO DEL LED1
			led_state_18[1] = !led_state_18[1]; //CAMBOI DE ESTADO DEL LED2
		}
		state_pin18_old = state_pin18;

		if ((state_pin19 == false) && (state_pin19_old == true)){ //DETECCIÓN DE FALNCO DESCENDENTE EN PIN18
			printf("Boton 2 presionado or is cravaaaaaa\n");
			led_state_19[0] = !led_state_19[0]; //CAMBIO DE ESTADO DEL LED1
			led_state_19[1] = !led_state_19[1]; //CAMBOI DE ESTADO DEL LED2
		}
		state_pin19_old = state_pin19;
		//sleep(1);

		// ===== CONTROL PRUEBA LEDS CHIDILLOS =====
		//APAGADO DE LED 
	    //vTaskDelay(1000 / portTICK_PERIOD_MS);  //RETRAZO DE 5 SEGUNDOS
	    
	    bsp_led_toggle(BSP_LED0);
	    bsp_led_toggle(BSP_LED1);
	    bsp_led_toggle(BSP_LED2);
	    bsp_led_toggle(BSP_LED3);
	    bsp_led_toggle(BSP_LED4);
	    
	    bsp_RGB_led_toggle(BSP_RGB_REDLED);
	    bsp_RGB_led_toggle(BSP_RGB_GREENLED);
	    bsp_RGB_led_toggle(BSP_RGB_BLUELED);
	    	    
	    
	    /*gpio_write(GPIO2, true);
	    gpio_write(GPIO4, true);
	    gpio_write(GPIO5, true);
	    gpio_write(GPIO16, true);
	    gpio_write(GPIO17, true);
	    gpio_write(GPIO12, true);
	    gpio_write(GPIO13, true);
	    gpio_write(GPIO14, true);*/
	    /*bsp_led_on(GPIO4);
	    bsp_led_on(GPIO5);
	    bsp_led_on(GPIO16);
	    bsp_led_on(GPIO17);
	    bsp_led_on(GPIO12);
	    bsp_led_on(GPIO13);
	    bsp_led_on(GPIO14);*/


	    //ENCENDIDO DE LED
	    vTaskDelay(1000 / portTICK_PERIOD_MS); //RETRAZO DE 5 SEGUNDOS
	    /*gpio_write(GPIO2, false);
	    gpio_write(GPIO4, false);
	    gpio_write(GPIO5, false);
	    gpio_write(GPIO16, false);
	    gpio_write(GPIO17, false);
	    gpio_write(GPIO12, false);
	    gpio_write(GPIO13, false);
	    gpio_write(GPIO14, false);*/
	    /*bsp_led_off(GPIO4);
	    bsp_led_off(GPIO5);
	    bsp_led_off(GPIO16);
	    bsp_led_off(GPIO17);
	    bsp_led_off(GPIO12);
	    bsp_led_off(GPIO13);
	    bsp_led_off(GPIO14);*/

		//vTaskDelay(pdMS_TO_TICKS(20)); //20 ms delay
	}
}