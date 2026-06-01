#include <stdio.h>
#include "gpio_2026.h"

//designated initializers technique
volatile uint32_t *IO_MUX_x_REG[] = {
	[GPIO0]  = IO_MUX_GPIO0_REG,
	[GPIO1]  = IO_MUX_GPIO1_REG,
	[GPIO2]  = IO_MUX_GPIO2_REG,
	[GPIO3]  = IO_MUX_GPIO3_REG,
	[GPIO4]  = IO_MUX_GPIO4_REG,
	[GPIO5]  = IO_MUX_GPIO5_REG,
	[GPIO12] = IO_MUX_GPIO12_REG,
	[GPIO13] = IO_MUX_GPIO13_REG,
	[GPIO14] = IO_MUX_GPIO14_REG,
	[GPIO15] = IO_MUX_GPIO15_REG,
	[GPIO16] = IO_MUX_GPIO16_REG,
	[GPIO17] = IO_MUX_GPIO17_REG,
	[GPIO18] = IO_MUX_GPIO18_REG,
	[GPIO19] = IO_MUX_GPIO19_REG,
	[GPIO21] = IO_MUX_GPIO21_REG,
	[GPIO22] = IO_MUX_GPIO22_REG,
	[GPIO23] = IO_MUX_GPIO23_REG,
	[GPIO25] = IO_MUX_GPIO25_REG,
	[GPIO26] = IO_MUX_GPIO26_REG,
	[GPIO27] = IO_MUX_GPIO27_REG,
	[GPIO32] = IO_MUX_GPIO32_REG,
	[GPIO33] = IO_MUX_GPIO33_REG,
	[GPIO34] = IO_MUX_GPIO34_REG,
	[GPIO35] = IO_MUX_GPIO35_REG,
	[GPIO36] = IO_MUX_GPIO36_REG,
	[GPIO37] = IO_MUX_GPIO37_REG,
	[GPIO38] = IO_MUX_GPIO38_REG,
	[GPIO39] = IO_MUX_GPIO39_REG,
};

bool gpio_read(gpio_t pin){
	if (pin < 32){
		return (READ_BIT_GPIO_IN_REG(pin) != 0); // Force to bool 0 or 1 value
	} else {
		return (READ_BIT_GPIO_IN1_REG(pin) != 0); // Force to bool 0 or 1 value
	}
}

void gpio_write(gpio_t pin, bool valor){
	if (valor){
		if(pin < 32){
			SET_BIT_GPIO_OUT_W1TS(pin);
		} else{
			SET_BIT_GPIO_OUT1_W1TS(pin);
		}
	}
	else{
		if(pin < 32){
			CLEAR_BIT_GPIO_OUT_W1TC(pin);
		} else{
			CLEAR_BIT_GPIO_OUT1_W1TC(pin);
		}
	}	
}

void enable_output (gpio_t pin, bool valor){
	if (valor){
		if(pin < 32){
			SET_BIT_GPIO_ENABLE_W1TS(pin);
		} else{
			SET_BIT_GPIO_ENABLE1_W1TS(pin);
		}
	}
	else{
		if(pin < 32){
			CLEAR_BIT_GPIO_ENABLE_W1TC(pin);
		} else{
			CLEAR_BIT_GPIO_ENABLE1_W1TC(pin);
		}
	}
}

void gpio_config_in (gpio_t pin, input_mode modo_pull){
	//disaable at first to stop GPIO conducing output
	enable_output(pin, false); //disable pin as output

	ENABLE_PAD(IO_MUX_x_REG[pin]); //Enable GPIO as input
	SET_MCU_SEL_FUN2(IO_MUX_x_REG[pin]); //set function 2 (GPIO mode)

	if (modo_pull == PULL_UP){
		ENABLE_PULLUP(IO_MUX_x_REG[pin]);
	} else if (modo_pull == PULL_DOWN){
		ENABLE_PULLDOWN(IO_MUX_x_REG[pin]);
	} else{
		FLOATING_GPIO(IO_MUX_x_REG[pin]);
	}
}

void gpio_config_out(gpio_t pin){
	SET_MCU_SEL_FUN2(IO_MUX_x_REG[pin]); //set function 2 (GPIO mode)
	gpio_write(pin, false); //GPIO starts with low value
	enable_output(pin, true); //enable pin as output
	//enable at end to start GPIO conducing
}

// ========= EXTRA =========
void gpio_config2026(gpio_t pin, input_mode modo, gpio_mode modo_gpio){
	if(modo_gpio == input){
		gpio_config_in(pin, modo);
	}
	else{
		gpio_config_out(pin);
	}
}