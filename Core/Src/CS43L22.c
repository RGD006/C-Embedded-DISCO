#include "CS43L22.h"

/* Send register-value pair over I2C */
static HAL_StatusTypeDef CS43_WriteReg(I2C_HandleTypeDef *hi2c,
                                       uint8_t reg,
                                       uint8_t value)
{
  uint8_t data[2] = {reg, value};
  return HAL_I2C_Master_Transmit(hi2c, CS43L22_I2C_ADDR, data, 2, 100);
}

/* Init sequence (datasheet recommended startup) */
HAL_StatusTypeDef CS43L22_Init(I2C_HandleTypeDef *hi2c)
{
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);
  HAL_Delay(10);
  /* Step 1: Power-down (all on) */
  CS43_WriteReg(hi2c, CS43L22_REG_POWER_CTL1, 0x01);

  /* Step 2: Start magic sequence (required for correct startup) */
  CS43_WriteReg(hi2c, 0x00, 0x99);
  CS43_WriteReg(hi2c, 0x47, 0x80);

  CS43_WriteReg(hi2c, 0x32, 0x80);
  CS43_WriteReg(hi2c, 0x32, 0x00);

  CS43_WriteReg(hi2c, 0x00, 0x00);

  /* Step 3: Slave mode, I2S standard, 16-bit */
  CS43_WriteReg(hi2c, CS43L22_REG_INTERFACE_CTL1, 0x04);

  /* Clock auto detect */
  CS43_WriteReg(hi2c, CS43L22_REG_CLOCKING_CTL, 0x81);

  /* Headphone enable, speaker disable */
  CS43_WriteReg(hi2c, CS43L22_REG_POWER_CTL2, 0xAF);

  /* Volume default */
  CS43L22_SetVolume(hi2c, 200);

  return HAL_OK;
}

/* Power-up the audio path */
HAL_StatusTypeDef CS43L22_Start(I2C_HandleTypeDef *hi2c)
{
  /* Unmute HP left/right */
  CS43_WriteReg(hi2c, CS43L22_REG_PLAYBACK_CTL2, 0x00);

  /* Power-up (activate) */
  return CS43_WriteReg(hi2c, CS43L22_REG_POWER_CTL1, 0x9E);
}

/* Power down */
HAL_StatusTypeDef CS43L22_Stop(I2C_HandleTypeDef *hi2c)
{
  return CS43_WriteReg(hi2c, CS43L22_REG_POWER_CTL1, 0x01);
}

/* Volume: 0..255 (internally shifted to -102 to +12 dB) */
HAL_StatusTypeDef CS43L22_SetVolume(I2C_HandleTypeDef *hi2c, uint8_t vol)
{
  /* Volume range is inverted, 0 = loudest, 255 = muted */
  uint8_t hp_vol = 255 - vol;

  CS43_WriteReg(hi2c, CS43L22_REG_HEADPHONE_A_VOL, hp_vol);
  CS43_WriteReg(hi2c, CS43L22_REG_HEADPHONE_B_VOL, hp_vol);

  return HAL_OK;
}
