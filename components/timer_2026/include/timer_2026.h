

//#define LLT_HWREG32(x)        (*((volatile uint32_t *)(x)))
//#define LLT_HW_PTR_REG32(x)   ((volatile uint32_t *)(x))

//#define TIMG0_T0CONFIG_REG (LLT_HWREG32(0x3FF5F000))
/*
 * Timer 0 configuration register
 * TIMG0 0x3FF5F000
 * Page 495
 */
 
//TIMG0_T0CONFIG_REG |=  ((1<<31)|(1<<30)|()) 

//---------------------------------------------------
 

//#define TIMG0_T0_EN 		  (1<<31)
/**
 * Enables or disables timer COUNTER
*/

//#define TIMG0_T0_INCREASE     (1<<30)
/**
 * Defines if count is increasing or decreasing
 */
 
//#define TIMG0_T0_AUTORELOAD   (1<<29)
/**
 * Reset counter when alarm happens
 */

//#define TIMG0_T0_DIVIDER (x)  (x<<13)
/**
 * Frequency divider
 * APB_CLK = 80 MHz (page 494)
 *
 * Example:
 * Freq_Divider 80
 * 80 MHz / Freq_Divider = 1MHz :. Timer increases each 1us
 */
 
//#define TIMG0_T0_EDGE_INT_EN  (1<<12)
/**
 * Interruption signal is in edge mode
 */
 
//#define TIMG0_T0_LEVEL_INT_EN (1<<11)
/**
 * Interruption signal is in level mode
 */
 
//#define TIMG0_T0_ALARM_EN	  (1<<10)
/**
 * Enable alarm, to notify when the timer has reach the alarm value
 */
 

