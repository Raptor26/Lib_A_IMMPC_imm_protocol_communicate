/**
 * @file   	%<%NAME%>%.%<%EXTENSION%>%
 * @author 	%<%USER%>%
 * @version
 * @date 	%<%DATE%>%, %<%TIME%>%
 * @brief
 */


/*#### |Begin| --> Секция - "Include" ########################################*/
#include "Lib_A_IMMPC_imm_protocol_communicate.h"
/*#### |End  | <-- Секция - "Include" ########################################*/


/*#### |Begin| --> Секция - "Глобальные переменные" ##########################*/
/*#### |End  | <-- Секция - "Глобальные переменные" ##########################*/


/*#### |Begin| --> Секция - "Локальные переменные" ###########################*/
/*#### |End  | <-- Секция - "Локальные переменные" ###########################*/


/*#### |Begin| --> Секция - "Прототипы локальных функций" ####################*/
static uint16_t
IMMPC_GetCRC_Generic(
	uint8_t *pData,
	uint16_t len);

static uint16_t
IMMPC_GetCRC_9dof_main_raw_pack(
	immpc_9dof_main_raw_pack_s *pPack_s);

static size_t
IMMPC_IsPackValid_9dof_main_raw_pack(
	immpc_9dof_main_raw_pack_s *pPack_s);
/*#### |End  | <-- Секция - "Прототипы локальных функций" ####################*/


/*#### |Begin| --> Секция - "Описание глобальных функций" ####################*/
void
IMMPC_GetTypeMessage(
	uint8_t *pData,
	size_t 	buffSize,
	uint8_t *pMessageIDReturn,
	uint8_t *pMessagePackReturn)
{
	*pMessageIDReturn = IMMPC_MESSAGE_ID_UNKNOWN;
	*pMessagePackReturn = IMMPC_MESSAGE_PACK_9dof_main_raw_pack_s;

	/* Минимальное количество данных необходимое для поиска */
	if (buffSize < 4u)
	{
		/* выход из функции */
		return;
	}

	/* Поиск */
	for (uint16_t i = 0; i < (uint16_t) buffSize - 2u; i++)
	{

		/* Поиск в потоке данных символы StartFrame */
		if(	(*(pData + i) == (uint8_t) ((IIMPC_START_FRAME >> 8) & 0xFF)) &&
			(*(pData + i + 1) == (uint8_t) (IIMPC_START_FRAME & 0xFF)))
		{

			/* Посмотреть какой ID сообщения */
			switch(*(pData + i + 2))
			{
				case IMMPC_MESSAGE_ID_9DOF_PACK_MAIN:
					/* запрос на получение данных */
					if(*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST == IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST)
					{
						if(*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS == IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS)
						{
							*pMessagePackReturn = IMMPC_MESSAGE_PACK_9dof_main_calib_pack_s;
						}
						else
						{
							*pMessagePackReturn = IMMPC_MESSAGE_PACK_9dof_main_raw_pack_s;
						}
					}
					/* ответ на запрос */
					else
					{
						if(*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS == IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS)
						{
							*pMessagePackReturn = IMMPC_MESSAGE_PACK_9dof_main_calib_request_cmd_s;
						}
						else
						{
							*pMessagePackReturn = IMMPC_MESSAGE_PACK_9dof_main_raw_request_cmd_s;
						}
					}
					break;

				case IMMPC_MESSAGE_ID_9DOF_PACK_RESERVE:
					/* запрос на получение данных */
					if(*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST == IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST)
					{
						if(*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS == IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS)
						{
							*pMessagePackReturn = IMMPC_MESSAGE_PACK_9dof_reserve_calib_pack_s;
						}
						else
						{
							*pMessagePackReturn = IMMPC_MESSAGE_PACK_9dof_reserve_raw_pack_s;
						}
					}
					/* ответ на запрос */
					else
					{
						if(*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS == IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS)
						{
							*pMessagePackReturn = IMMPC_MESSAGE_PACK_9dof_reserve_calib_request_cmd_s;
						}
						else
						{
							*pMessagePackReturn =  IMMPC_MESSAGE_PACK_9dof_reserve_raw_request_cmd_s;
						}
					}
					break;

				case IMMPC_MESSAGE_ID_ACC3DOF_CALIBMATRIX:
					/* запрос на получение данных */
					if(*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST == IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST)
					{

					}
					/* ответ на запрос */
					else
					{

					}
					break;

				case IMMPC_MESSAGE_ID_GYR3DOF_CALIBMATRIX:
					break;

				case IMMPC_MESSAGE_ID_MAG3DOF_CALIBMATRIX:
					break;

				case IMMPC_MESSAGE_ID_3DOF_PACK_MAIN:
					break;

				default:
					/* выход из функции */
					return;
			}

			/* запись идентификатора пакета */
			*pMessageIDReturn = *(pData + i + 2);

			return;
		}
	}



	/* Найти в потоке данных символы StartFrame */
	if

	/* Посмотреть какой ID сообщения */

	/* Записать в pMessagePackReturn номер, который соответствует структуре данных */
}

/*-------------------------------------------------------------------------*//**
 * @author    Mickle Isaev
 * @date      01-ноя-2019
 *
 * @brief    Функция вычисляет контрольную сумму
 *
 * @param[in] 	*pData: 	Указатель на область памяти, в которой содержится 
 * 							пакет данных
 * @param[in]   len:	Количество байт пакета данных
 *
 * @return    { description_of_the_return_value }
 */
static uint16_t
IMMPC_GetCRC_Generic(
	uint8_t *pData,
	uint16_t len)
{
	return (CRC_XOR_CCITT_Poly0x1021_Crc16(
				(uint8_t*)&pData[2u],
				len - 4u));
}

/* Пакет 9dof_main_raw_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

/*-------------------------------------------------------------------------*//**
 * @author    Mickle Isaev
 * @date      01-ноя-2019
 *
 * @brief    Функция выполняет вычисление контрольной суммы пакета данных 
 *
 * @param[in]	*pPack_s: 	Указатель на область памяти, в которой содержится 
 * 							пакет данных 
 *
 * @return 	Вычисленная сумма пакета данных
 */
static uint16_t
IMMPC_GetCRC_9dof_main_raw_pack(
	immpc_9dof_main_raw_pack_s *pPack_s)
{
	return (IMMPC_GetCRC_Generic(
				(uint8_t*) pPack_s,
				(uint16_t) (sizeof(immpc_9dof_main_raw_pack_s))));
}

/*-------------------------------------------------------------------------*//**
 * @author    Mickle Isaev
 * @date      01-ноя-2019
 *
 * @brief 	Функция выполняет запись контрольной суммы пакета данных 
 *
 * @param[in,out]	*pPack_s: 	Указатель на область памяти, в которой содержится 
 * 								пакет данных.
 * 								@note 	Контрольная сумма записывается в конец 
 * 										пакета данных
 */
static void
IMMPC_WriteCRC_9dof_main_raw_pack(
	immpc_9dof_main_raw_pack_s *pPack_s)
{
	pPack_s->crc =
		IMMPC_GetCRC_Generic(
			(uint8_t*) pPack_s,
			(uint16_t) (sizeof(immpc_9dof_main_raw_pack_s)));
}

/*-------------------------------------------------------------------------*//**
 * @author    Mickle Isaev
 * @date      01-ноя-2019
 *
 * @brief Функция проверяет валидность пакета данных 
 *
 * @param[in]	*pPack_s: 	Указатель на область памяти, в которой содержится 
 * 							пакет данных.
 *
 * @return 	Если пакет данных валиден, то возвращает "1", иначе "0"
 */
static size_t
IMMPC_IsPackValid_9dof_main_raw_pack(
	immpc_9dof_main_raw_pack_s *pPack_s)
{
	uint16_t crc =
		IMMPC_GetCRC_9dof_main_raw_pack_s(pPack_s);

	if (crc == pPack_s->crc)
	{
		return (1u);
	}
	else
	{
		return (0u);
	}
}
/* Пакет 9dof_main_raw_pack_s --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */
/*#### |End  | <-- Секция - "Описание глобальных функций" ####################*/


/*#### |Begin| --> Секция - "Описание локальных функций" #####################*/
/*#### |End  | <-- Секция - "Описание локальных функций" #####################*/


/*#### |Begin| --> Секция - "Обработчики прерываний" #########################*/
/*#### |End  | <-- Секция - "Обработчики прерываний" #########################*/

/*############################################################################*/
/*############################ END OF FILE  ##################################*/
/*############################################################################*/
