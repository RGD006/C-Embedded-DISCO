#ifndef CS43L22_H
#define CS43L22_H

#include "stm32f4xx_hal.h"

/* I2C device address (8-bit shifted) */
#define CS43L22_I2C_ADDR   (0x94)

/* CS43L22 Register Map */
#define CS43L22_REG_ID                    0x01
#define CS43L22_REG_POWER_CTL1            0x02
#define CS43L22_REG_POWER_CTL2            0x04
#define CS43L22_REG_CLOCKING_CTL          0x05
#define CS43L22_REG_INTERFACE_CTL1        0x06
#define CS43L22_REG_INTERFACE_CTL2        0x07
#define CS43L22_REG_PASSTHR_A_SELECT      0x08
#define CS43L22_REG_PASSTHR_B_SELECT      0x09
#define CS43L22_REG_PLAYBACK_CTL1         0x0D
#define CS43L22_REG_MISC_CTL              0x0E
#define CS43L22_REG_PLAYBACK_CTL2         0x0F
#define CS43L22_REG_PASSTHR_GAIN_A        0x14
#define CS43L22_REG_PASSTHR_GAIN_B        0x15
#define CS43L22_REG_PCMA_VOL              0x1A
#define CS43L22_REG_PCMB_VOL              0x1B
#define CS43L22_REG_TONE_CTL              0x1F
#define CS43L22_REG_MASTER_A_VOL          0x20
#define CS43L22_REG_MASTER_B_VOL          0x21
#define CS43L22_REG_HEADPHONE_A_VOL       0x22
#define CS43L22_REG_HEADPHONE_B_VOL       0x23
#define CS43L22_REG_SPEAKER_A_VOL         0x24
#define CS43L22_REG_SPEAKER_B_VOL         0x25

/* Prototypes */
HAL_StatusTypeDef CS43L22_Init(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef CS43L22_Start(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef CS43L22_Stop(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef CS43L22_SetVolume(I2C_HandleTypeDef *hi2c, uint8_t vol);

#endif