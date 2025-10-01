/**
 * @file main.c
 * @author yourname (bach.buispr@gmail.com)
 * @brief
 * @version: 1.0
 * @date: 20-09-2025
 * */
#include "S32K144.h"

#include <stdio.h>



/*Compiler-specific Macro ----------------------------------------------------------------------------------*/
#if defined (__ghs__)
    #define __INTERRUPT_SVC  __interrupt
    #define __NO_RETURN _Pragma("ghs nowarning 111")
#elif defined (__ICCARM__)
    #define __INTERRUPT_SVC  __svc
    #define __NO_RETURN _Pragma("diag_suppress=Pe111")
#elif defined (__GNUC__)
    #define __INTERRUPT_SVC  __attribute__ ((interrupt ("SVC")))
    #define __NO_RETURN
#else
    #define __INTERRUPT_SVC
    #define __NO_RETURN
#endif



/* ----------------------------------------------------------------------------
   -- DEFINE
   ---------------------------------------------------------------------------- */
/* BEGIN DEFINE */
// --- Core Define ---
#define GPIO_PIN_INPUT		1
#define GPIO_PIN_OUTPUT 	0
#define TICK_SYS          1000

// --- Application Define ---
#define LED_RED x
#define LED_GREEN x
#define LED_YELLOW x
/* END DEFINE */


/* ----------------------------------------------------------------------------
   -- MACRO
   ---------------------------------------------------------------------------- */
/* BEGIN MACRO */
/* END MACRO */


/* ----------------------------------------------------------------------------
   -- FUNCTION PROTOTIES
   ---------------------------------------------------------------------------- */
/* BEGIN FP */

// --- Hàm Hệ thống ---

// --- Hàm Liên quan đến GPIO ---
void GPIO_EnableClock(uint8_t index);
void GPIO_InitPin(PORT_Type *port, GPIO_Type *gpio_port, uint8_t pin_number, int gpio_mode);
void GPIO_LedToggle(GPIO_Type *gpio_port, uint8_t pin_number);
void GPIO_LedSet(GPIO_Type *gpio_port, uint8_t pin_number);
void GPIO_LedReset(GPIO_Type *gpio_port, uint8_t pin_number);

// --- Hàm Ứng dụng ---

/* END FP */




/**
 * @brief
 * @note
 * @param[in]
 */



/* ----------------------------------------------------------------------------
   -- MAIN FUNCTION
   ---------------------------------------------------------------------------- */
/* BEGIN MF */
int main(void)
{


    return 0;
}
/* END MF */


/* ----------------------------------------------------------------------------
   -- SYSTEM FUNCTION
   ---------------------------------------------------------------------------- */
/* BEGIN SF */
void delay_cycles(volatile uint32_t count) {
    while (count--)
    {
    	for(int i = TICK_SYS; i >= 0; i--)
    	{
        __asm("nop"); // No Operation (đảm bảo compiler không tối ưu mất)
        }
    }
}

/* END SF */


/* ----------------------------------------------------------------------------
   -- GPIO DEFINE FUNCTION
   ---------------------------------------------------------------------------- */
/* BEGIN GDF */
/**
 * @brief
 * @note
 * @param[in]
 */
void GPIO_InitPin(PORT_Type *port, GPIO_Type *gpio_port, uint8_t pin_number, int gpio_mode)
{
	// --1. Cấu hình MUX: để set chân pin của port thành 1 GPIO
	port->PCR[pin_number] = PORT_PCR_MUX(1);

	// --2. Cấu hình input/output cho GPIO được kích hoạt
	if(gpio_mode == GPIO_PIN_OUTPUT)
	{
		gpio_port->PDDR |= (1UL << pin_number);
	}
	else
	{
		gpio_port->PDDR = ~(1UL << pin_number);
	}
}


/**
 * @brief
 * @note
 * @param[in]
 */
void GPIO_EnableClock(uint8_t index)
{
	// --1. set clock for port
	IP_PCC->PCCn[index] |= PCC_PCCn_CGC_MASK;
}


/**
 * @brief
 * @note
 * @param[in]
 */
void GPIO_LedToggle(GPIO_Type *gpio_port, uint8_t pin_number)
{
	gpio_port->PTOR |= (1UL << pin_number);
}

/**
 * @brief
 * @note
 * @param[in]
 */
void GPIO_LedSet(GPIO_Type *gpio_port, uint8_t pin_number)
{
	gpio_port->PSOR |= (1UL << pin_number);
}
/**
 * @brief
 * @note
 * @param[in]
 */
void GPIO_LedReset(GPIO_Type *gpio_port, uint8_t pin_number)
{
	gpio_port->PCOR |= (1UL << pin_number);
}
/* END GDF */


/* ----------------------------------------------------------------------------
   -- TIMER DEFINE FUNCTION
   ---------------------------------------------------------------------------- */
/* BEGIN GDF */
void TIM_Init(void)
{

}


/* ----------------------------------------------------------------------------
   -- APPLICATION FUNCTION
   ---------------------------------------------------------------------------- */
/* BEGIN AF */

/* END AF */

