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
   -- DEFINE AND MACRO
   ---------------------------------------------------------------------------- */
/**
 * @brief Định nghĩa cho hướng của chân GPIO.
 */
#define GPIO_PIN_INPUT      0
#define GPIO_PIN_OUTPUT     1

/**
 * @brief Định nghĩa các thông số cho đèn LED xanh.
 */
#define BLUE_LED_PIN        	0U
#define RED_LED_PIN        		15U
#define GREEN_LED_PIN        	16U

#define BLUE_LED_PORT       	IP_PORTD
#define RED_LED_PORT       		IP_PORTD
#define GREEN_LED_PORT       	IP_PORTD

#define BLUE_LED_GPIO       	IP_PTD
#define RED_LED_GPIO       		IP_PTD
#define GREEN_LED_GPIO       	IP_PTD


/* ----------------------------------------------------------------------------
   -- FUNCTION PROTOTIES
   ---------------------------------------------------------------------------- */
/**
 * @brief Cấp clock cho một Port GPIO.
 */
void GPIO_EnableClock(uint8_t index);

/**
 * @brief Cấu hình một chân GPIO là Input hoặc Output.
 */
void GPIO_InitPin(PORT_Type *port, GPIO_Type *gpio_port, uint8_t pin_number, int gpio_mode);

/**
 * @brief Đảo trạng thái một chân GPIO.
 */
void GPIO_LedToggle(GPIO_Type *gpio_port, uint8_t pin_number);

/**
 * @brief Bật một chân GPIO lên mức cao.
 */
void GPIO_LedSet(GPIO_Type *gpio_port, uint8_t pin_number);

/**
 * @brief Bật một chân GPIO lên mức thấp.
 */
void GPIO_LedReset(GPIO_Type *gpio_port, uint8_t pin_number);

/**
 * @brief Khởi tạo và chuyển đổi clock hệ thống sang SPLL.
 */
void Clock_Init_System_SPLL(void);

/**
 * @brief Chương trình ứng dụng
 */
void App_ControlLedADC(void);


/* ----------------------------------------------------------------------------
   -- MAIN FUNCTION
   ---------------------------------------------------------------------------- */
int main(void)
{


    return 0;
}


/* ----------------------------------------------------------------------------
   -- SYSTEM FUNCTION
   ---------------------------------------------------------------------------- */
void Clock_Init_System_SPLL(void)
{

}


/* ----------------------------------------------------------------------------
   -- GPIO DEFINE FUNCTION
   ---------------------------------------------------------------------------- */
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

void GPIO_EnableClock(uint8_t index)
{
	// --1. set clock for port
	IP_PCC->PCCn[index] |= PCC_PCCn_CGC_MASK;
}

void GPIO_LedToggle(GPIO_Type *gpio_port, uint8_t pin_number)
{
	gpio_port->PTOR |= (1UL << pin_number);
}

void GPIO_LedSet(GPIO_Type *gpio_port, uint8_t pin_number)
{
	gpio_port->PSOR |= (1UL << pin_number);
}

void GPIO_LedReset(GPIO_Type *gpio_port, uint8_t pin_number)
{
	gpio_port->PCOR |= (1UL << pin_number);
}


/* ----------------------------------------------------------------------------
   -- APPLICATION FUNCTION
   ---------------------------------------------------------------------------- */
void App_ControlLedADC(void)
{

}
