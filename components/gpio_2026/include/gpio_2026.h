/*
 * header files .h
 * Contain: Functions prototypes and constant definition
 */
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define LL_HWREG32(x)        (*((volatile uint32_t *)(x)))
/*
 * (volatile uint32_t *)(x)) 	==> Means that it's a pointer to the direction
 * *((volatile uint32_t *)(x)) 	==> Means that you're dereferencing that direction
 */

#define LL_HW_PTR_REG32(x)   ((volatile uint32_t *)(x))
/*
 * (volatile uint32_t *)(x)) 	==> Means that it's a pointer to the direction
 */

/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\MACROFUNCIONES PARA ACCESO A REGISTROS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\GPIO ENABLE 0-31 REGISTERS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
#define LL_GPIO_ENABLE 	(LL_HWREG32(0x3FF44020))
/*
 *     [x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x]
 * GPIO31 															  GPIO0
 *
 * GPIO_ENABLE_REG (0x3FF44020) with this register you can enable as output the GPIO 0 to 31
 * Page 63.
 */

#define LL_GPIO_ENABLE_W1TS 	(LL_HWREG32(0x3FF44024)) // Registro para encender (SET) GPIO 0-31 output
/*
 *     [x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x]
 * GPIO31 															  GPIO0
 *
 * GPIO 0-31 output enable set register
 * GPIO_OUT_W1TS_REG (0x3FF44024) it's kind of interface register.
 * Every bit 1 written here will be set 1 in GPIO_ENABLE_REG
 * Page 64.
 */
#define LL_SET_BIT_GPIO_ENABLE_W1TS(x)	 (LL_GPIO_ENABLE_W1TS = (1<<(x)))

#define LL_GPIO_ENABLE_W1TC 	(LL_HWREG32(0x3FF44028)) // Registro para encender (SET) GPIO 0-31 output
/*
 *     [x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x]
 * GPIO31 															  GPIO0
 *
 * GPIO 0-31 output clear register
 * GPIO_ENABLE_W1TC_REG (0x3FF44028) it's kind of interface register too.
 * For every bit 1 written here, will be cleared in GPIO_ENABLE_REG
 * Page 64.
 */
#define LL_CLEAR_BIT_GPIO_ENABLE_W1TC(x)	(LL_GPIO_ENABLE_W1TC = (1<<(x)))



/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\GPIO ENABLE 32-39 REGISTERS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
#define LL_GPIO_ENABLE1	(LL_HWREG32(0x3FF4402C)) // Registros para leer entradas en gios 32-39
/*
 *     [ (Reserved) x x x x x x x x]
 * 			   GPIO39			  GPIO32
 *
 * GPIO_ENABLE1_REG (0x3FF4402C) with this register you can enable as output the GPIO 32 to 39
 * Page 64.
 */

#define  LL_GPIO_ENABLE1_W1TS	(LL_HWREG32(0x3FF44030)) // Registros para leer entradas en gios 32-39
/*
 *     [ (Reserved) x x x x x x x x]
 * 			   GPIO39			  GPIO32
 *
 * GPIO 32-39 output enable register
 * GPIO_ENABLE1_W1TS_REG (0x3FF44030) it's kind of interface register.
 * Every bit 1 written here will be set 1 GPIO_ENABLE1_REG
 * Page 64.
 */
#define LL_SET_BIT_GPIO_ENABLE1_W1TS(x) (LL_GPIO_ENABLE1_W1TS = (1<<(x-32)))

#define LL_GPIO_ENABLE1_W1TC	(LL_HWREG32(0x3FF44034)) // Registros para leer entradas en gios 32-39
/*
 *     [ (Reserved) x x x x x x x x]
 * 			   GPIO39			  GPIO32
 *
 * GPIO 32-39 output clear register
 * GPIO_ENABLE1_W1TC_REG (0x3FF44034) it's kind of interface register.
 * For every bit 1 written here, will be cleared in GPIO_ENABLE1_REG
 * Page 65.
 */
#define LL_CLEAR_BIT_GPIO_ENABLE1_W1TC(x) (LL_GPIO_ENABLE1_W1TC = (1<<(x-32)))



/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\GPIO OUT 0-31 REGISTERS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
#define LL_GPIO_OUT_REG 	(LL_HWREG32(0x3FF44004))
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

#define LL_GPIO_OUT_W1TS 	(LL_HWREG32(0x3FF44008)) // Registro para encender (SET) GPIO 0-31 output
/*
 *     [x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x]
 * GPIO31 															  GPIO0
 *
 * GPIO 0-31 output set register
 * GPIO_OUT_W1TS_REG (0x3FF44008) it's kind of interface register.
 * Every bit 1 written here will be set 1 in GPIO_OUT_REG
 * Page 62.
 */
#define LL_SET_BIT_GPIO_OUT_W1TS(x)	 (LL_GPIO_OUT_W1TS = (1<<(x)))

#define LL_GPIO_OUT_W1TC	(LL_HWREG32(0x3FF4400C)) // Registro para apagar (CLEAR) GPIO 0-31
/*
 *     [x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x]
 * GPIO31														      GPIO0
 *
 * GPIO0-31 output clear register
 * GPIO_OUT_W1TC_REG (0x3FF4400C) it's kind of interface register too.
 * For every bit 1 written here, will be cleared in GPIO_OUT_REG
 * Page 62.
 */
#define LL_CLEAR_BIT_GPIO_OUT_W1TC(x)	 (LL_GPIO_OUT_W1TC = (1<<(x)))



/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\GPIO OUT 32-39 REGISTERS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
#define LL_GPIO_OUT1_REG 	(LL_HWREG32(0x3FF44010))
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

#define LL_GPIO_OUT1_W1TS	(LL_HWREG32(0x3FF44014)) // Registros para leer entradas en gios 32-39
/*
 *     [ (Reserved) x x x x x x x x]
 * 			   GPIO39			  GPIO32
 *
 * GPIO 32-39 output set register
 * GPIO_OUT1_W1TS_REG (0x3FF44014) it's kind of interface register.
 * Every bit 1 written here will be set 1 GPIO_OUT1_DATA
 * Page 63.
 */
#define LL_SET_BIT_GPIO_OUT1_W1TS(x) (LL_GPIO_OUT1_W1TS = (1<<(x-32)))

#define LL_GPIO_OUT1_W1TC	(LL_HWREG32(0x3FF44018)) // Registros para leer entradas en gios 32-39
/*
 *     [ (Reserved) x x x x x x x x]
 * 			   GPIO39			  GPIO32
 *
 * GPIO 32-39 output clear register
 * GPIO_OUT1_W1TC_REG (0x3FF44018) it's kind of interface register.
 * For every bit 1 written here, will be cleared in GPIO_OUT1_DATA
 * Page 63.
 */
#define LL_CLEAR_BIT_GPIO_OUT1_W1TC(x) (LL_GPIO_OUT1_W1TC = (1<<(x-32)))


/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\GPIO IN REGISTERS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
#define LL_GPIO_IN_REG		(LL_HWREG32(0x3FF4403C)) // Registro para leer entradas en gpios 0-31
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
#define LL_READ_BIT_GPIO_IN_REG(x)	 (LL_GPIO_IN_REG & (1<<(x)))

#define LL_GPIO_IN1_REG	(LL_HWREG32(0x3FF44040)) // Registros para leer entradas en gios 32-39
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
#define LL_READ_BIT_GPIO_IN1_REG(x) (LL_GPIO_IN1_REG & (1<<(x-32)))



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
#define LL_MCU_SEL_BIT0 (1<<12)
#define LL_MCU_SEL_BIT1 (1<<13)
#define LL_MCU_SEL_BIT2 (1<<14)
#define LL_FUN_IE  	    (1<<9)	//Input enable
#define LL_FUN_WPU 	    (1<<8)  //Pull-up enable
#define LL_FUN_WPD  	(1<<7)  //Pull-down enable


#define LL_ENABLE_PAD(x)  (*(x) |= LL_FUN_IE)
#define LL_DISABLE_PAD(x) (*(x) |= ~LL_FUN_IE)

#define LL_SET_MCU_SEL_FUN2(x) (*(x) = ((*(x) & ~((LL_MCU_SEL_BIT0)|(LL_MCU_SEL_BIT1)|(LL_MCU_SEL_BIT2))) | (LL_MCU_SEL_BIT1)))

#define LL_ENABLE_PULLUP(x)   (*(x) = ((*(x) & ~(LL_FUN_WPU|LL_FUN_WPD)) | (LL_FUN_WPU)))
#define LL_ENABLE_PULLDOWN(x) (*(x) = ((*(x) & ~(LL_FUN_WPU|LL_FUN_WPD)) | (LL_FUN_WPD)))
#define LL_FLOATING_GPIO(x)   (*(x) = (*(x) & ~(LL_FUN_WPU|LL_FUN_WPD)))


/* To identify each direction register with 
 * his respective GPIO you have to look at 
 * pages 60 & 57 from:
 * esp32_technical_reference_manual_v4.6.
 */
#define LL_IO_MUX_GPIO0_REG   LL_HW_PTR_REG32(0x3FF49044)
#define LL_IO_MUX_GPIO1_REG   LL_HW_PTR_REG32(0x3FF49088)
#define LL_IO_MUX_GPIO2_REG   LL_HW_PTR_REG32(0x3FF49040)
#define LL_IO_MUX_GPIO3_REG   LL_HW_PTR_REG32(0x3FF49084)
#define LL_IO_MUX_GPIO4_REG   LL_HW_PTR_REG32(0x3FF49048)
#define LL_IO_MUX_GPIO5_REG   LL_HW_PTR_REG32(0x3FF4906C) 
#define LL_IO_MUX_GPIO12_REG  LL_HW_PTR_REG32(0x3FF49034)
#define LL_IO_MUX_GPIO13_REG  LL_HW_PTR_REG32(0x3FF49038)
#define LL_IO_MUX_GPIO14_REG  LL_HW_PTR_REG32(0x3FF49030)
#define LL_IO_MUX_GPIO15_REG  LL_HW_PTR_REG32(0x3FF4903C)
#define LL_IO_MUX_GPIO16_REG  LL_HW_PTR_REG32(0x3FF4904C)
#define LL_IO_MUX_GPIO17_REG  LL_HW_PTR_REG32(0x3FF49050)
#define LL_IO_MUX_GPIO18_REG  LL_HW_PTR_REG32(0x3FF49070)
#define LL_IO_MUX_GPIO19_REG  LL_HW_PTR_REG32(0x3FF49074)
#define LL_IO_MUX_GPIO21_REG  LL_HW_PTR_REG32(0x3FF4907C)
#define LL_IO_MUX_GPIO22_REG  LL_HW_PTR_REG32(0x3FF49080)
#define LL_IO_MUX_GPIO23_REG  LL_HW_PTR_REG32(0x3FF4908C)
#define LL_IO_MUX_GPIO25_REG  LL_HW_PTR_REG32(0x3FF49024)
#define LL_IO_MUX_GPIO26_REG  LL_HW_PTR_REG32(0x3FF49028)
#define LL_IO_MUX_GPIO27_REG  LL_HW_PTR_REG32(0x3FF4902C)
#define LL_IO_MUX_GPIO32_REG  LL_HW_PTR_REG32(0x3FF4901C)
#define LL_IO_MUX_GPIO33_REG  LL_HW_PTR_REG32(0x3FF49020)
#define LL_IO_MUX_GPIO34_REG  LL_HW_PTR_REG32(0x3FF49014)
#define LL_IO_MUX_GPIO35_REG  LL_HW_PTR_REG32(0x3FF49018)
#define LL_IO_MUX_GPIO36_REG  LL_HW_PTR_REG32(0x3FF49004)
#define LL_IO_MUX_GPIO37_REG  LL_HW_PTR_REG32(0x3FF49008)
#define LL_IO_MUX_GPIO38_REG  LL_HW_PTR_REG32(0x3FF4900C)
#define LL_IO_MUX_GPIO39_REG  LL_HW_PTR_REG32(0x3FF49010)


typedef enum{
	LL_GPIO0 = 0,
	LL_GPIO1 = 1,
	LL_GPIO2 = 2,
	LL_GPIO3 = 3,
	LL_GPIO4 = 4,
	LL_GPIO5 = 5,
	LL_GPIO12 = 12,
	LL_GPIO13 = 13,
	LL_GPIO14 = 14,
	LL_GPIO15 = 15,
	LL_GPIO16 = 16,
	LL_GPIO17 = 17,
	LL_GPIO18 = 18,
	LL_GPIO19 = 19,
	LL_GPIO21 = 21,
	LL_GPIO22 = 22,
	LL_GPIO23 = 23,
	LL_GPIO25 = 25,
	LL_GPIO26 = 26,
	LL_GPIO27 = 27,
	LL_GPIO32 = 32,
	LL_GPIO33 = 33,
	LL_GPIO34 = 34,
	LL_GPIO35 = 35,
	LL_GPIO36 = 36,
	LL_GPIO37 = 37,
	LL_GPIO38 = 38,
	LL_GPIO39 = 39,
} ll_gpio_t;

// ========== Bit position GPIO in GPIO_ENABLE_REG (0x3FF44020) ========== 
/*
 * GPIO_ENABLE_REG (0x3FF44020): GPIO 0-31 output enable register
 * IMPORTANT: GPIO 6,7,8,9,10,11 MUST not be used due is connected to external SRAM
 * GPIO 20, 24, 28, 29, 30, 31 don´t exist. (pag 57. technical_reference_manual_v4.6)
 */
#define LL_PIN0  (1<<0)
#define LL_PIN1  (1<<1)
#define LL_PIN2  (1<<2)
#define LL_PIN3  (1<<3)
#define LL_PIN4  (1<<4)
#define LL_PIN5  (1<<5)
#define LL_PIN12 (1<<12)
#define LL_PIN13 (1<<13)
#define LL_PIN14 (1<<14)
#define LL_PIN15 (1<<15)
#define LL_PIN16 (1<<16)
#define LL_PIN17 (1<<17)
#define LL_PIN18 (1<<18)
#define LL_PIN19 (1<<19)
#define LL_PIN21 (1<<21)
#define LL_PIN22 (1<<22)
#define LL_PIN23 (1<<23)
#define LL_PIN25 (1<<25)
#define LL_PIN26 (1<<26)
#define LL_PIN27 (1<<27)

// ========== Bit position GPIO in GPIO_ENABLE1_REG (0x3FF4402C) ========== 
/*
 * GPIO_ENABLE1_REG (0x3FF4402C): GPIO 32-39 output enable register
 */
#define LL_PIN32 (1<<0)
#define LL_PIN33 (1<<1)
#define LL_PIN34 (1<<2)
#define LL_PIN35 (1<<3)
#define LL_PIN36 (1<<4)
#define LL_PIN37 (1<<5)
#define LL_PIN38 (1<<6)
#define LL_PIN39 (1<<7)

typedef enum pull_mode{
	LL_PULL_UP, 
	LL_PULL_DOWN, 
	LL_FLOATING
}ll_input_mode_t;

// =============================== FUNCTION PROTOTYPES =============================== 
bool ll_gpio_read(ll_gpio_t pin);
void ll_gpio_write(ll_gpio_t pin, bool valor);
void ll_enable_output (ll_gpio_t pin, bool valor);
void ll_gpio_config_in (ll_gpio_t pin, ll_input_mode_t modo_pull);
void ll_gpio_config_out(ll_gpio_t pin);


// ========= EXTRA =========
typedef enum modo{
	LL_INPUT,
	LL_OUTPUI
}ll_gpio_mode_t;

void ll_gpio_config2026(ll_gpio_t pin, ll_input_mode_t modo, ll_gpio_mode_t modo_gpio);



