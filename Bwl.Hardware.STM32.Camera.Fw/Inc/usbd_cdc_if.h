
#ifndef __USBD_CDC_IF_H
#define __USBD_CDC_IF_H

#ifdef __cplusplus
 extern "C" {
#endif
/* Includes ------------------------------------------------------------------*/
#include "usbd_cdc.h"
/* USER CODE BEGIN INCLUDE */
/* USER CODE END INCLUDE */

/** @addtogroup STM32_USB_OTG_DEVICE_LIBRARY
  * @{
  */
  
/** @defgroup USBD_CDC_IF
  * @brief header 
  * @{
  */ 

/** @defgroup USBD_CDC_IF_Exported_Defines
  * @{
  */ 
/* USER CODE BEGIN EXPORTED_DEFINES */
/* USER CODE END EXPORTED_DEFINES */

/**
  * @}
  */ 

/** @defgroup USBD_CDC_IF_Exported_Types
  * @{
  */  
/* USER CODE BEGIN EXPORTED_TYPES */
/* USER CODE END EXPORTED_TYPES */

/**
  * @}
  */ 

/** @defgroup USBD_CDC_IF_Exported_Macros
  * @{
  */ 
/* USER CODE BEGIN EXPORTED_MACRO */
/* USER CODE END EXPORTED_MACRO */

/**
  * @}
  */ 

/** @defgroup USBD_AUDIO_IF_Exported_Variables
  * @{
  */ 
extern USBD_CDC_ItfTypeDef  USBD_Interface_fops_FS;

/* USER CODE BEGIN EXPORTED_VARIABLES */
/* USER CODE END EXPORTED_VARIABLES */

/**
  * @}
  */ 

/** @defgroup USBD_CDC_IF_Exported_FunctionsPrototype
  * @{
  */ 
uint8_t CDC_Transmit_FS(uint8_t* Buf, uint16_t Len);

/* USER CODE BEGIN EXPORTED_FUNCTIONS */
/* USER CODE END EXPORTED_FUNCTIONS */
/**
  * @}
  */ 

/**
  * @}
  */ 

/**
  * @}
  */ 
  
#ifdef __cplusplus
}
#endif
  
#endif /* __USBD_CDC_IF_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
