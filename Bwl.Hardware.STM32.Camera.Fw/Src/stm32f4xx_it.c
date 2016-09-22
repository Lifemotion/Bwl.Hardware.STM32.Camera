#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "stm32f4xx_it.h"
#include "usbd_cdc_if.h"

extern PCD_HandleTypeDef hpcd_USB_OTG_FS;
extern DMA_HandleTypeDef hdma_dcmi;
extern DCMI_HandleTypeDef hdcmi;


void SVC_Handler(void)
{

}

void start_capture(void){
	//HAL_DCMI_Start_DMA(&hdcmi, DCMI_MODE_SNAPSHOT,(uint32_t)&buffer, 120*160/4);
}

void PendSV_Handler(void)
{

}

void SysTick_Handler(void)
{
  HAL_IncTick();
  HAL_SYSTICK_IRQHandler();
}


void DMA2_Stream1_IRQHandler(void)
{
	
	HAL_NVIC_ClearPendingIRQ(DMA2_Stream1_IRQn);
  HAL_DMA_IRQHandler(&hdma_dcmi);
}


void OTG_FS_IRQHandler(void)
{
  HAL_PCD_IRQHandler(&hpcd_USB_OTG_FS);

}


void DCMI_IRQHandler(void)
{
	//HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
  HAL_DCMI_IRQHandler(&hdcmi);
}

