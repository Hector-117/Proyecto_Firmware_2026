/*
 * header files .h
 * Contain: Functions prototypes and constant definition
 */
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define HWREG32(x)        (*((volatile uint32_t *)(x)))
/*
 * (volatile uint32_t *)(x)) 	==> Means that it's a pointer to the direction
 * *((volatile uint32_t *)(x)) 	==> Means that you're dereferencing that direction
 */

#define HW_PTR_REG32(x)   ((volatile uint32_t *)(x))
/*
 * (volatile uint32_t *)(x)) 	==> Means that it's a pointer to the direction
 */

/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\MACROFUNCIONES PARA ACCESO A REGISTROS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\GPIO ENABLE 0-31 REGISTERS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
#define GPIO_ENABLE 	(HWREG32(0x3FF44020))
/*
 *     [x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x]
 * GPIO31 															  GPIO0
 *
 * GPIO_ENABLE_REG (0x3FF44020) with this register you can enable as output the GPIO 0 to 31
 * Page 63.
 */

#define GPIO_ENABLE_W1TS 	(HWREG32(0x3FF44024)) // Registro para encender (SET) GPIO 0-31 output
/*
 *     [x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x]
 * GPIO31 															  GPIO0
 *
 * GPIO 0-31 output enable set register
 * GPIO_OUT_W1TS_REG (0x3FF44024) it's kind of interface register.
 * Every bit 1 written here will be set 1 in GPIO_ENABLE_REG
 * Page 64.
 */
#define SET_BIT_GPIO_ENABLE_W1TS(x)	 (GPIO_ENABLE_W1TS = (1<<(x)))

#define GPIO_ENABLE_W1TC 	(HWREG32(0x3FF44028)) // Registro para encender (SET) GPIO 0-31 output
/*
 *     [x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x]
 * GPIO31 															  GPIO0
 *
 * GPIO 0-31 output clear register
 * GPIO_ENABLE_W1TC_REG (0x3FF44028) it's kind of interface register too.
 * For every bit 1 written here, will be cleared in GPIO_ENABLE_REG
 * Page 64.
 */
#define CLEAR_BIT_GPIO_ENABLE_W1TC(x)	(GPIO_ENABLE_W1TC = (1<<(x)))



/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\GPIO ENABLE 32-39 REGISTERS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
#define GPIO_ENABLE1	(HWREG32(0x3FF4402C)) // Registros para leer entradas en gios 32-39
/*
 *     [ (Reserved) x x x x x x x x]
 * 			   GPIO39			  GPIO32
 *
 * GPIO_ENABLE1_REG (0x3FF4402C) with this register you can enable as output the GPIO 32 to 39
 * Page 64.
 */

#define  GPIO_ENABLE1_W1TS	(HWREG32(0x3FF44030)) // Registros para leer entradas en gios 32-39
/*
 *     [ (Reserved) x x x x x x x x]
 * 			   GPIO39			  GPIO32
 *
 * GPIO 32-39 output enable register
 * GPIO_ENABLE1_W1TS_REG (0x3FF44030) it's kind of interface register.
 * Every bit 1 written here will be set 1 GPIO_ENABLE1_REG
 * Page 64.
 */
#define SET_BIT_GPIO_ENABLE1_W1TS(x) (GPIO_ENABLE1_W1TS = (1<<(x-32)))

#define GPIO_ENABLE1_W1TC	(HWREG32(0x3FF44034)) // Registros para leer entradas en gios 32-39
/*
 *     [ (Reserved) x x x x x x x x]
 * 			   GPIO39			  GPIO32
 *
 * GPIO 32-39 output clear register
 * GPIO_ENABLE1_W1TC_REG (0x3FF44034) it's kind of interface register.
 * For every bit 1 written here, will be cleared in GPIO_ENABLE1_REG
 * Page 65.
 */
#define CLEAR_BIT_GPIO_ENABLE1_W1TC(x) (GPIO_ENABLE1_W1TC = (1<<(x-32)))



/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\GPIO OUT 0-31 REGISTERS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
#define GPIO_OUT_REG 	(HWREG32(0x3FF44004))
/*
 *     [x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x]
 * GPIO31 															  GPIO0
 *
 * GPIO_OUT_REG (0x3FF44004) with this register you write the output value of each GPIO from 0 to 31
 * 
 * WARNING, using this register you overwrite all the bits. 
 * If you only want to change one bit without changin the other bits, better use GPIO_OUT_W1TS & GPIO_OUT_W1TC.
 * Page 62.
 */

#define GPIO_OUT_W1TS 	(HWREG32(0x3FF44008)) // Registro para encender (SET) GPIO 0-31 output
/*
 *     [x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x]
 * GPIO31 															  GPIO0
 *
 * GPIO 0-31 output set register
 * GPIO_OUT_W1TS_REG (0x3FF44008) it's kind of interface register.
 * Every bit 1 written here will be set 1 in GPIO_OUT_REG
 * Page 62.
 */
#define SET_BIT_GPIO_OUT_W1TS(x)	 (GPIO_OUT_W1TS = (1<<(x)))

#define GPIO_OUT_W1TC	(HWREG32(0x3FF4400C)) // Registro para apagar (CLEAR) GPIO 0-31
/*
 *     [x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x]
 * GPIO31														      GPIO0
 *
 * GPIO0-31 output clear register
 * GPIO_OUT_W1TC_REG (0x3FF4400C) it's kind of interface register too.
 * For every bit 1 written here, will be cleared in GPIO_OUT_REG
 * Page 62.
 */
#define CLEAR_BIT_GPIO_OUT_W1TC(x)	 (GPIO_OUT_W1TC = (1<<(x)))



/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\GPIO OUT 32-39 REGISTERS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
#define GPIO_OUT1_REG 	(HWREG32(0x3FF44010))
/*
 *     [ (Reserved) x x x x x x x x]
 * 			   GPIO39			  GPIO32 															  GPIO0
 *
 * GPIO_OUT1_REG (0x3FF44010) with this register you write the output value of each GPIO from 32 to 39.
 * 
 * WARNING, using this register you overwrite all the bits. 
 * If you only want to change one bit without changin the other bits, better use GPIO_OUT_W1TS & GPIO_OUT_W1TC.
 * Page 63.
 */

#define GPIO_OUT1_W1TS	(HWREG32(0x3FF44014)) // Registros para leer entradas en gios 32-39
/*
 *     [ (Reserved) x x x x x x x x]
 * 			   GPIO39			  GPIO32
 *
 * GPIO 32-39 output set register
 * GPIO_OUT1_W1TS_REG (0x3FF44014) it's kind of interface register.
 * Every bit 1 written here will be set 1 GPIO_OUT1_DATA
 * Page 63.
 */
#define SET_BIT_GPIO_OUT1_W1TS(x) (GPIO_OUT1_W1TS = (1<<(x-32)))

#define GPIO_OUT1_W1TC	(HWREG32(0x3FF44018)) // Registros para leer entradas en gios 32-39
/*
 *     [ (Reserved) x x x x x x x x]
 * 			   GPIO39			  GPIO32
 *
 * GPIO 32-39 output clear register
 * GPIO_OUT1_W1TC_REG (0x3FF44018) it's kind of interface register.
 * For every bit 1 written here, will be cleared in GPIO_OUT1_DATA
 * Page 63.
 */
#define CLEAR_BIT_GPIO_OUT1_W1TC(x) (GPIO_OUT1_W1TC = (1<<(x-32)))


/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\GPIO IN REGISTERS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
#define GPIO_IN_REG		(HWREG32(0x3FF4403C)) // Registro para leer entradas en gpios 0-31
/*
 *     [x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x]
 * GPIO31															  GPIO0
 * 
 * GPIO_IN_REG (0x3FF4403C) it's for 0 to 31 GPIOs. Each bit is the input value that receives
 * the each GPIO pad. 
 *	* High 1
 *	* Low  0
 * Page 65.
 */
//#define BIT_GPIO_IN_REG(x)	 (1<<(x))
#define READ_BIT_GPIO_IN_REG(x)	 (GPIO_IN_REG & (1<<(x)))

#define GPIO_IN1_REG	(HWREG32(0x3FF44040)) // Registros para leer entradas en gios 32-39
/*
 *     [ (Reserved) x x x x x x x x]
 * 			   GPIO39			  GPIO32
 * 
 * GPIO_IN1_REG (0x3FF44040) it's for 32 to 39 GPIOs. Each bit is the input value that receives
 * the each GPIO pad. 
 *	* High 1
 *	* Low  0
 * Page 65.
 */
//#define BIT_GPIO_IN1_REG(x)	 (1<<(x-32))
#define READ_BIT_GPIO_IN1_REG(x) (GPIO_IN1_REG & (1<<(x-32)))



//----------------------------------- Register IO_MUX_x_REG (x: GPIO0GPIO39) (0x10+4*x) -----------------------------------
/*
 * [		  (Reserved) 			 MCU_SEL FUN_DRV FUN_IE FUN_WPU FUN_WPD MCU_DRV MCU_IE MCU_WPU MCU_WPD SLP_SEL MCU_OE]
 * [31                           15  14   12  11 10    9       8       7      6  5    4      3        2       1       0  ]
 * [0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0  x  x  x   x x     x       x       x      x  x    x      x        x       x       x  ]
 * 
 * This is the Configuration register for pad GPIOX
 * BitField explanation:
 *	* MCU_SEL: Select the IO_MUX function for this signal. (see page 57 to see all functions can have each GPIO)
 *			   Function 2 will select GPIO mode. (see page 57)
 *	* FUN_IE:  Input enable of the pad: 1 input enabled, 0 input disabled
 *	* FUN_WPU: Internal pull-up enable of the pad: 1 enabled, 0 disabled
 *	* FUN_WPD: Internal pull-down enable of the pad: 1 enabled, 0 disabled
 * Page 73.
 */
#define MCU_SEL_BIT0 (1<<12)
#define MCU_SEL_BIT1 (1<<13)
#define MCU_SEL_BIT2 (1<<14)
#define FUN_IE  	 (1<<9)	//Input enable
#define FUN_WPU 	 (1<<8)  //Pull-up enable
#define FUN_WPD  	 (1<<7)  //Pull-down enable


#define ENABLE_PAD(x)  (*(x) |= FUN_IE)
#define DISABLE_PAD(x) (*(x) |= ~FUN_IE)

#define SET_MCU_SEL_FUN2(x) (*(x) = ((*(x) & ~((MCU_SEL_BIT0)|(MCU_SEL_BIT1)|(MCU_SEL_BIT2))) | (MCU_SEL_BIT1)))

#define ENABLE_PULLUP(x)   (*(x) = ((*(x) & ~(FUN_WPU|FUN_WPD)) | (FUN_WPU)))
#define ENABLE_PULLDOWN(x) (*(x) = ((*(x) & ~(FUN_WPU|FUN_WPD)) | (FUN_WPD)))
#define FLOATING_GPIO(x)   (*(x) = (*(x) & ~(FUN_WPU|FUN_WPD)))


/* To identify each direction register with 
 * his respective GPIO you have to look at 
 * pages 60 & 57 from:
 * esp32_technical_reference_manual_v4.6.
 */
#define IO_MUX_GPIO0_REG   HW_PTR_REG32(0x3FF49044)
#define IO_MUX_GPIO1_REG   HW_PTR_REG32(0x3FF49088)
#define IO_MUX_GPIO2_REG   HW_PTR_REG32(0x3FF49040)
#define IO_MUX_GPIO3_REG   HW_PTR_REG32(0x3FF49084)
#define IO_MUX_GPIO4_REG   HW_PTR_REG32(0x3FF49048)
#define IO_MUX_GPIO5_REG   HW_PTR_REG32(0x3FF4906C) 
#define IO_MUX_GPIO12_REG  HW_PTR_REG32(0x3FF49034)
#define IO_MUX_GPIO13_REG  HW_PTR_REG32(0x3FF49038)
#define IO_MUX_GPIO14_REG  HW_PTR_REG32(0x3FF49030)
#define IO_MUX_GPIO15_REG  HW_PTR_REG32(0x3FF4903C)
#define IO_MUX_GPIO16_REG  HW_PTR_REG32(0x3FF4904C)
#define IO_MUX_GPIO17_REG  HW_PTR_REG32(0x3FF49050)
#define IO_MUX_GPIO18_REG  HW_PTR_REG32(0x3FF49070)
#define IO_MUX_GPIO19_REG  HW_PTR_REG32(0x3FF49074)
#define IO_MUX_GPIO21_REG  HW_PTR_REG32(0x3FF4907C)
#define IO_MUX_GPIO22_REG  HW_PTR_REG32(0x3FF49080)
#define IO_MUX_GPIO23_REG  HW_PTR_REG32(0x3FF4908C)
#define IO_MUX_GPIO25_REG  HW_PTR_REG32(0x3FF49024)
#define IO_MUX_GPIO26_REG  HW_PTR_REG32(0x3FF49028)
#define IO_MUX_GPIO27_REG  HW_PTR_REG32(0x3FF4902C)
#define IO_MUX_GPIO32_REG  HW_PTR_REG32(0x3FF4901C)
#define IO_MUX_GPIO33_REG  HW_PTR_REG32(0x3FF49020)
#define IO_MUX_GPIO34_REG  HW_PTR_REG32(0x3FF49014)
#define IO_MUX_GPIO35_REG  HW_PTR_REG32(0x3FF49018)
#define IO_MUX_GPIO36_REG  HW_PTR_REG32(0x3FF49004)
#define IO_MUX_GPIO37_REG  HW_PTR_REG32(0x3FF49008)
#define IO_MUX_GPIO38_REG  HW_PTR_REG32(0x3FF4900C)
#define IO_MUX_GPIO39_REG  HW_PTR_REG32(0x3FF49010)


typedef enum{
	GPIO0 = 0,
	GPIO1 = 1,
	GPIO2 = 2,
	GPIO3 = 3,
	GPIO4 = 4,
	GPIO5 = 5,
	GPIO12 = 12,
	GPIO13 = 13,
	GPIO14 = 14,
	GPIO15 = 15,
	GPIO16 = 16,
	GPIO17 = 17,
	GPIO18 = 18,
	GPIO19 = 19,
	GPIO21 = 21,
	GPIO22 = 22,
	GPIO23 = 23,
	GPIO25 = 25,
	GPIO26 = 26,
	GPIO27 = 27,
	GPIO32 = 32,
	GPIO33 = 33,
	GPIO34 = 34,
	GPIO35 = 35,
	GPIO36 = 36,
	GPIO37 = 37,
	GPIO38 = 38,
	GPIO39 = 39,
} gpio_t;

// ========== Bit position GPIO in GPIO_ENABLE_REG (0x3FF44020) ========== 
/*
 * GPIO_ENABLE_REG (0x3FF44020): GPIO 0-31 output enable register
 * IMPORTANT: GPIO 6,7,8,9,10,11 MUST not be used due is connected to external SRAM
 * GPIO 20, 24, 28, 29, 30, 31 don´t exist. (pag 57. technical_reference_manual_v4.6)
 */
#define PIN0  (1<<0)
#define PIN1  (1<<1)
#define PIN2  (1<<2)
#define PIN3  (1<<3)
#define PIN4  (1<<4)
#define PIN5  (1<<5)
#define PIN12 (1<<12)
#define PIN13 (1<<13)
#define PIN14 (1<<14)
#define PIN15 (1<<15)
#define PIN16 (1<<16)
#define PIN17 (1<<17)
#define PIN18 (1<<18)
#define PIN19 (1<<19)
#define PIN21 (1<<21)
#define PIN22 (1<<22)
#define PIN23 (1<<23)
#define PIN25 (1<<25)
#define PIN26 (1<<26)
#define PIN27 (1<<27)

// ========== Bit position GPIO in GPIO_ENABLE1_REG (0x3FF4402C) ========== 
/*
 * GPIO_ENABLE1_REG (0x3FF4402C): GPIO 32-39 output enable register
 */
#define PIN32 (1<<0)
#define PIN33 (1<<1)
#define PIN34 (1<<2)
#define PIN35 (1<<3)
#define PIN36 (1<<4)
#define PIN37 (1<<5)
#define PIN38 (1<<6)
#define PIN39 (1<<7)

typedef enum pull_mode{
	PULL_UP, PULL_DOWN, FLOATING
}input_mode;

// =============================== FUNCTION PROTOTYPES =============================== 
bool gpio_read(gpio_t pin);
void gpio_write(gpio_t pin, bool valor);
void enable_output (gpio_t pin, bool valor);
void gpio_config_in (gpio_t pin, input_mode modo_pull);
void gpio_config_out(gpio_t pin);


// ========= EXTRA =========
typedef enum modo{
	input, output
}gpio_mode;
void gpio_config2026(gpio_t pin, input_mode modo, gpio_mode modo_gpio);



