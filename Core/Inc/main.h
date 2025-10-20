/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
#define LEDMODE_TABLE                          \
  ENTRY(LEDMODE_ALL, LED_BlinkAll)             \
  ENTRY(LEDMODE_CHASE, LED_BlinkChase)         \
  ENTRY(LEDMODE_ALTERNATE, LED_BlinkAlternate) \
  ENTRY(LEDMODE_SCANNER, LED_BlinkScanner)     \
  ENTRY(LEDMODE_SPIN, LED_BlinkSpin)           \
  ENTRY(LEDMODE_PING_PONG, LED_BlinkPingPong)  \
  ENTRY(LEDMODE_TWINKLE, LED_BlinkTwinkle)

typedef enum {
#define ENTRY(LEDMODE, FUNCTION) LEDMODE,
  LEDMODE_TABLE
#undef ENTRY
      LEDMODE_NUMBER,
} LEDMODE;
/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void LED_ChangeMode(void);
void LED_Blink(const uint8_t led_state_bitmap, const uint32_t delay);
void LED_BlinkAll(void);
void LED_BlinkChase(void);
void LED_BlinkAlternate(void);
void LED_BlinkScanner(void);
void LED_BlinkSpin(void);
void LED_BlinkPingPong(void);
void LED_BlinkTwinkle(void);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BTN_CHANGE_MODE_Pin       GPIO_PIN_0
#define BTN_CHANGE_MODE_GPIO_Port GPIOA
#define BTN_CHANGE_MODE_EXTI_IRQn EXTI0_IRQn
#define LED2_Pin                  GPIO_PIN_12
#define LED2_GPIO_Port            GPIOD
#define LED1_Pin                  GPIO_PIN_13
#define LED1_GPIO_Port            GPIOD
#define LED3_Pin                  GPIO_PIN_14
#define LED3_GPIO_Port            GPIOD
#define LED4_Pin                  GPIO_PIN_15
#define LED4_GPIO_Port            GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
