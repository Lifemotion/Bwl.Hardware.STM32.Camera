
#include "stm32f4xx_hal.h"
#include "usb_device.h"
#include "usbd_cdc_if.h"
#define OV9655_DEVICE_WRITE_ADDRESS 0x61
#define Delay HAL_Delay
#define TIMEOUT 2


DCMI_HandleTypeDef hdcmi;
DMA_HandleTypeDef hdma_dcmi;

I2C_HandleTypeDef hi2c1;
TIM_HandleTypeDef htim3;
UART_HandleTypeDef huart1;

void SystemClock_Config(void);
void Error_Handler(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_DCMI_Init(void);
static void MX_I2C1_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_TIM3_Init(void);
void write_SCCB(uint16_t MemAddress, uint8_t pData);
void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

void OV2640_config(void)
{
write_SCCB(0xff, 0x01);
write_SCCB(0x12, 0x80);
HAL_Delay(1);
write_SCCB(0xff, 0x00);
write_SCCB(0x2c, 0xff);
write_SCCB(0x2e, 0xdf);
write_SCCB(0xff, 0x01);
write_SCCB(0x3c, 0x32);
//
write_SCCB(0x11, 0x01);
write_SCCB(0x09, 0x02);
write_SCCB(0x04, 0x28);
write_SCCB(0x13, 0xe5);
write_SCCB(0x14, 0x48);
write_SCCB(0x2c, 0x0c);
write_SCCB(0x33, 0x78);
write_SCCB(0x3a, 0x33);
write_SCCB(0x3b, 0xfB);
//
write_SCCB(0x3e, 0x00);
write_SCCB(0x43, 0x11);
write_SCCB(0x16, 0x10);
//
write_SCCB(0x39, 0x92);
//
write_SCCB(0x35, 0xda);
write_SCCB(0x22, 0x1a);
write_SCCB(0x37, 0xc3);
write_SCCB(0x23, 0x00);
write_SCCB(0x34, 0xc0);
write_SCCB(0x36, 0x1a);
write_SCCB(0x06, 0x88);
write_SCCB(0x07, 0xc0);
write_SCCB(0x0d, 0x87);
write_SCCB(0x0e, 0x41);
write_SCCB(0x4c, 0x00);
write_SCCB(0x48, 0x00);
write_SCCB(0x5B, 0x00);
write_SCCB(0x42, 0x03);
//
write_SCCB(0x4a, 0x81);
write_SCCB(0x21, 0x99);
//
write_SCCB(0x24, 0x40);
write_SCCB(0x25, 0x38);
write_SCCB(0x26, 0x82);
write_SCCB(0x5c, 0x00);
write_SCCB(0x63, 0x00);
write_SCCB(0x61, 0x70);
write_SCCB(0x62, 0x80);
write_SCCB(0x7c, 0x05);
//
write_SCCB(0x20, 0x80);
write_SCCB(0x28, 0x30);
write_SCCB(0x6c, 0x00);
write_SCCB(0x6d, 0x80);
write_SCCB(0x6e, 0x00);
write_SCCB(0x70, 0x02);
write_SCCB(0x71, 0x94);
write_SCCB(0x73, 0xc1);
//
write_SCCB(0x12, 0x40);
write_SCCB(0x17, 0x11);
write_SCCB(0x18, 0x43);
write_SCCB(0x19, 0x00);
write_SCCB(0x1a, 0x4b);
write_SCCB(0x32, 0x09);
write_SCCB(0x37, 0xc0);
write_SCCB(0x4f, 0x60);
write_SCCB(0x50, 0xa8);
write_SCCB(0x6d, 0x00);
write_SCCB(0x3d, 0x38);
//
write_SCCB(0x46, 0x3f);
write_SCCB(0x4f, 0x60);
write_SCCB(0x0c, 0x3c);
//
write_SCCB(0xff, 0x00);
write_SCCB(0xe5, 0x7f);
write_SCCB(0xf9, 0xc0);
write_SCCB(0x41, 0x24);
write_SCCB(0xe0, 0x14);
write_SCCB(0x76, 0xff);
write_SCCB(0x33, 0xa0);
write_SCCB(0x42, 0x20);
write_SCCB(0x43, 0x18);
write_SCCB(0x4c, 0x00);
write_SCCB(0x87, 0xd5);
write_SCCB(0x88, 0x3f);
write_SCCB(0xd7, 0x03);
write_SCCB(0xd9, 0x10);
write_SCCB(0xd3, 0x82);
//
write_SCCB(0xc8, 0x08);
write_SCCB(0xc9, 0x80);
//
write_SCCB(0x7c, 0x00);
write_SCCB(0x7d, 0x00);
write_SCCB(0x7c, 0x03);
write_SCCB(0x7d, 0x48);
write_SCCB(0x7d, 0x48);
write_SCCB(0x7c, 0x08);
write_SCCB(0x7d, 0x20);
write_SCCB(0x7d, 0x10);
write_SCCB(0x7d, 0x0e);
//
write_SCCB(0x90, 0x00);
write_SCCB(0x91, 0x0e);
write_SCCB(0x91, 0x1a);
write_SCCB(0x91, 0x31);
write_SCCB(0x91, 0x5a);
write_SCCB(0x91, 0x69);
write_SCCB(0x91, 0x75);
write_SCCB(0x91, 0x7e);
write_SCCB(0x91, 0x88);
write_SCCB(0x91, 0x8f);
write_SCCB(0x91, 0x96);
write_SCCB(0x91, 0xa3);
write_SCCB(0x91, 0xaf);
write_SCCB(0x91, 0xc4);
write_SCCB(0x91, 0xd7);
write_SCCB(0x91, 0xe8);
write_SCCB(0x91, 0x20);
//
write_SCCB(0x92, 0x00);
write_SCCB(0x93, 0x06);
write_SCCB(0x93, 0xe3);
write_SCCB(0x93, 0x05);
write_SCCB(0x93, 0x05);
write_SCCB(0x93, 0x00);
write_SCCB(0x93, 0x04);
write_SCCB(0x93, 0x00);
write_SCCB(0x93, 0x00);
write_SCCB(0x93, 0x00);
write_SCCB(0x93, 0x00);
write_SCCB(0x93, 0x00);
write_SCCB(0x93, 0x00);
write_SCCB(0x93, 0x00);
//
write_SCCB(0x96, 0x00);
write_SCCB(0x97, 0x08);
write_SCCB(0x97, 0x19);
write_SCCB(0x97, 0x02);
write_SCCB(0x97, 0x0c);
write_SCCB(0x97, 0x24);
write_SCCB(0x97, 0x30);
write_SCCB(0x97, 0x28);
write_SCCB(0x97, 0x26);
write_SCCB(0x97, 0x02);
write_SCCB(0x97, 0x98);
write_SCCB(0x97, 0x80);
write_SCCB(0x97, 0x00);
write_SCCB(0x97, 0x00);
//
write_SCCB(0xc3, 0xed);
write_SCCB(0xa4, 0x00);
write_SCCB(0xa8, 0x00);
write_SCCB(0xc5, 0x11);
write_SCCB(0xc6, 0x51);
write_SCCB(0xbf, 0x80);
write_SCCB(0xc7, 0x10);
write_SCCB(0xb6, 0x66);
write_SCCB(0xb8, 0xA5);
write_SCCB(0xb7, 0x64);
write_SCCB(0xb9, 0x7C);
write_SCCB(0xb3, 0xaf);
write_SCCB(0xb4, 0x97);
write_SCCB(0xb5, 0xFF);
write_SCCB(0xb0, 0xC5);
write_SCCB(0xb1, 0x94);
write_SCCB(0xb2, 0x0f);
write_SCCB(0xc4, 0x5c);
//
write_SCCB(0xc0, 0x64);
write_SCCB(0xc1, 0x4B);
write_SCCB(0x8c, 0x00);
write_SCCB(0x86, 0x3D);
write_SCCB(0x50, 0x00);
write_SCCB(0x51, 0xC8);
write_SCCB(0x52, 0x96);
write_SCCB(0x53, 0x00);
write_SCCB(0x54, 0x00);
write_SCCB(0x55, 0x00);
write_SCCB(0x5a, 0xC8);
write_SCCB(0x5b, 0x96);
write_SCCB(0x5c, 0x00);
write_SCCB(0xd3, 0x82);
//
write_SCCB(0xc3, 0xed);
write_SCCB(0x7f, 0x00);
//
write_SCCB(0xda, 0x10);
//
write_SCCB(0xe5, 0x1f);
write_SCCB(0xe1, 0x67);
write_SCCB(0xe0, 0x00);
write_SCCB(0xdd, 0x7f);
write_SCCB(0x05, 0x00);	
}

void write_SCCB(uint16_t MemAddress, uint8_t pData)
{
	HAL_I2C_Mem_Write(&hi2c1, 0x60, MemAddress, I2C_MEMADD_SIZE_8BIT, &pData, 1, 1);
}

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_DCMI_Init();
  MX_I2C1_Init();
  MX_USART1_UART_Init();
  MX_USB_DEVICE_Init();
  MX_TIM3_Init();
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
	HAL_Delay(100);	
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
	OV2640_config();
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
  while (1)
  {									
			HAL_Delay(1000);
		}
}





void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 144;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 6;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }

  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}


/* DCMI init function */
static void MX_DCMI_Init(void)
{

  hdcmi.Instance = DCMI;
  hdcmi.Init.SynchroMode = DCMI_SYNCHRO_HARDWARE;
  hdcmi.Init.PCKPolarity = DCMI_PCKPOLARITY_RISING;
  hdcmi.Init.VSPolarity = DCMI_VSPOLARITY_LOW;
  hdcmi.Init.HSPolarity = DCMI_HSPOLARITY_LOW;
  hdcmi.Init.CaptureRate = DCMI_CR_ALL_FRAME;
  hdcmi.Init.ExtendedDataMode = DCMI_EXTEND_DATA_8B;
  hdcmi.Init.JPEGMode = DCMI_JPEG_ENABLE;
  if (HAL_DCMI_Init(&hdcmi) != HAL_OK)
  {
    Error_Handler();
  }
}

static void MX_I2C1_Init(void)
{

  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
	
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }

}

/* TIM3 init function */
static void MX_TIM3_Init(void)
{

  TIM_ClockConfigTypeDef sClockSourceConfig;
  TIM_MasterConfigTypeDef sMasterConfig;
  TIM_OC_InitTypeDef sConfigOC;

  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 0;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 6;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }

  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 3;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }

  HAL_TIM_MspPostInit(&htim3);

}

/* USART1 init function */
static void MX_USART1_UART_Init(void)
{

  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }

}

/** 
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void) 
{
  /* DMA controller clock enable */
  __HAL_RCC_DMA2_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA2_Stream1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream1_IRQn);

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);

  /*Configure GPIO pins : PD13 PD14 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : PA8 */
  GPIO_InitStruct.Pin = GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
