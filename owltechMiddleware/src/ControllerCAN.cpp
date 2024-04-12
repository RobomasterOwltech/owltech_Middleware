
#include "ControllerCAN.hpp"


ControllerCAN::ControllerCAN(CAN_HandleTypeDef handler, int id){


}



// CAN
FDCAN_RxHeaderTypeDef RxHeader;
uint8_t RxData[8];
FDCAN_TxHeaderTypeDef TxHeader; // manda posicion
FDCAN_TxHeaderTypeDef TxHeader2; // manda distancia

//uint8_t TxData[8] = {'J', ' ', 'D', 'E', 'E', 'R', 'E', '.'};
FDCAN_FilterTypeDef sFilterConfig;

uint8_t TxData[4];
FDCAN_HandleTypeDef hfdcan1;
static void MX_FDCAN1_Init(void);


// CAN TRANMITION FUNCTIONS

void transmitDistance(){
	HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_14);

	TxData[0] = currentDistance;
	TxData[1] = 0;
	TxData[2] = 0;


    if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, TxData) != HAL_OK)
    {
        //uart_buf_len = sprintf(uart_buf, "Error");
        //HAL_UART_Transmit(&huart3, (uint8_t *)uart_buf, uart_buf_len, HAL_MAX_DELAY);
        Error_Handler();


    }
}

static void MX_FDCAN1_Init(void)
{

  /* USER CODE BEGIN FDCAN1_Init 0 */

  /* USER CODE END FDCAN1_Init 0 */

  /* USER CODE BEGIN FDCAN1_Init 1 */

  /* USER CODE END FDCAN1_Init 1 */
  hfdcan1.Instance = FDCAN1;
  hfdcan1.Init.FrameFormat = FDCAN_FRAME_CLASSIC;
  hfdcan1.Init.Mode = FDCAN_MODE_NORMAL;
  hfdcan1.Init.AutoRetransmission = ENABLE;
  hfdcan1.Init.TransmitPause = ENABLE;
  hfdcan1.Init.ProtocolException = ENABLE;
  hfdcan1.Init.NominalPrescaler = 5;
  hfdcan1.Init.NominalSyncJumpWidth = 8;
  hfdcan1.Init.NominalTimeSeg1 = 0x1f;
  hfdcan1.Init.NominalTimeSeg2 = 8;
  hfdcan1.Init.DataPrescaler = 1;
  hfdcan1.Init.DataSyncJumpWidth = 1;
  hfdcan1.Init.DataTimeSeg1 = 1;
  hfdcan1.Init.DataTimeSeg2 = 1;
  hfdcan1.Init.MessageRAMOffset = 0;
  hfdcan1.Init.StdFiltersNbr = 0;
  hfdcan1.Init.ExtFiltersNbr = 0;
  hfdcan1.Init.RxFifo0ElmtsNbr = 1;
  hfdcan1.Init.RxFifo0ElmtSize = FDCAN_DATA_BYTES_8;
  hfdcan1.Init.RxFifo1ElmtsNbr = 0;
  hfdcan1.Init.RxFifo1ElmtSize = FDCAN_DATA_BYTES_8;
  hfdcan1.Init.RxBuffersNbr = 0;
  hfdcan1.Init.RxBufferSize = FDCAN_DATA_BYTES_8;
  hfdcan1.Init.TxEventsNbr = 0;
  hfdcan1.Init.TxBuffersNbr = 0;
  hfdcan1.Init.TxFifoQueueElmtsNbr = 1;
  hfdcan1.Init.TxFifoQueueMode = FDCAN_TX_FIFO_OPERATION;
  hfdcan1.Init.TxElmtSize = FDCAN_DATA_BYTES_8;
  if (HAL_FDCAN_Init(&hfdcan1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN FDCAN1_Init 2 */
  sFilterConfig.IdType = FDCAN_STANDARD_ID;
  sFilterConfig.FilterIndex = 0;
  sFilterConfig.FilterID1 = 0x321;
  sFilterConfig.FilterID2 = 0x7FF;
  sFilterConfig.FilterType = FDCAN_FILTER_MASK;
  sFilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;

  if (HAL_FDCAN_ConfigFilter(&hfdcan1, &sFilterConfig) != HAL_OK)
  {
  Error_Handler();
  }



  if (  HAL_FDCAN_Start(&hfdcan1) != HAL_OK)
  {
  Error_Handler();
  }



  if(HAL_FDCAN_ActivateNotification(&hfdcan1, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK)
  {
  Error_Handler();
  }

  TxHeader.Identifier =  0x0F;
  TxHeader.IdType = FDCAN_STANDARD_ID;
  TxHeader.DataLength = FDCAN_DLC_BYTES_8;
  TxHeader.TxFrameType = FDCAN_DATA_FRAME;
  TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
  TxHeader.BitRateSwitch = FDCAN_BRS_OFF;
  TxHeader.FDFormat = FDCAN_CLASSIC_CAN;
  TxHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
  TxHeader.MessageMarker = 0;



  TxHeader2.Identifier = 0xFF;
  TxHeader2.IdType = FDCAN_STANDARD_ID;
  TxHeader2.DataLength = FDCAN_DLC_BYTES_8;
  TxHeader2.TxFrameType = FDCAN_DATA_FRAME;
  TxHeader2.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
  TxHeader2.BitRateSwitch = FDCAN_BRS_OFF;
  TxHeader2.FDFormat = FDCAN_CLASSIC_CAN;
  TxHeader2.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
  TxHeader2.MessageMarker = 0;

  /* USER CODE END FDCAN1_Init 2 */

}

#ifdef __cplusplus
}
#endif

#endif 