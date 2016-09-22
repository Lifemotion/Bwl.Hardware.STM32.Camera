#include "stm32f4xx_hal.h"
#ifndef __STM32F4xx_IT_H
#define __STM32F4xx_IT_H

#ifdef __cplusplus
 extern "C" {
#endif 
void SVC_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
void DMA2_Stream1_IRQHandler(void);
void OTG_FS_IRQHandler(void);
void DCMI_IRQHandler(void);
void start_capture(void);
	 
#ifdef __cplusplus
}
#endif

#endif /* __STM32F4xx_IT_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
