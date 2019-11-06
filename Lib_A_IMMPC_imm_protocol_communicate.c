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
static
immpc_9dof_main_raw_pack_s
IMMPC_9DOF_main_raw_pack_s;

static
immpc_9dof_main_calib_pack_s
IMMPC_9DOF_main_calib_pack_s;

static
immpc_9dof_reserve_raw_pack_s
IMMPC_9DOF_reserve_raw_pack_s;

static
immpc_9dof_reserve_calib_pack_s
IMMPC_9DOF_reserve_calib_pack_s;

static
immpc_mag3dof_raw_pack_s
IMMPC_MAG3DOF_raw_pack_s;

static
immpc_mag3dof_calib_pack_s
IMMPC_MAG3DOF_calib_pack_s;

static
immpc_acc3dof_main_calibmatrix_pack_s
IMMPC_ACC3DOF_main_calibmatrix_pack_s;

static
immpc_acc3dof_reserve_calibmatrix_pack_s
IMMPC_ACC3DOF_reserve_calibmatrix_pack_s;

static
immpc_gyr3dof_main_calibmatrix_pack_s
IMMPC_GYR3DOF_main_calibmatrix_pack_s;

static
immpc_gyr3dof_reserve_calibmatrix_pack_s
IMMPC_GYR3DOF_reserve_calibmatrix_pack_s;

static
immpc_mag3dof_calibmatrix_pack_s
IMMPC_MAG3DOF_calibmatrix_pack_s;

/*#### |End  | <-- Секция - "Локальные переменные" ###########################*/


/*#### |Begin| --> Секция - "Прототипы локальных функций" ####################*/
static uint16_t
IMMPC_GetCRC_Generic(
	uint8_t *pData,
	uint16_t len);

/* Пакет 9dof_main_raw_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

static uint16_t
IMMPC_GetCRC_9dof_main_raw_pack(
	immpc_9dof_main_raw_pack_s *pPack_s);

static void
IMMPC_WriteCRC_9dof_main_raw_pack(
	immpc_9dof_main_raw_pack_s *pPack_s);

static size_t
IMMPC_IsPackValid_9dof_main_raw_pack(
	immpc_9dof_main_raw_pack_s *pPack_s);

/* Пакет 9dof_main_raw_pack_s --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* Пакет 9dof_main_calib_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

static uint16_t
IMMPC_GetCRC_9dof_main_calib_pack(
	immpc_9dof_main_calib_pack_s *pPack_s);

static void
IMMPC_WriteCRC_9dof_main_calib_pack(
	immpc_9dof_main_calib_pack_s *pPack_s);

static size_t
IMMPC_IsPackValid_9dof_main_calib_pack(
	immpc_9dof_main_calib_pack_s *pPack_s);

/* Пакет 9dof_main_calib_pack_s --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* Пакет 9dof_reserve_raw_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

static uint16_t
IMMPC_GetCRC_9dof_reserve_raw_pack(
	immpc_9dof_reserve_raw_pack_s *pPack_s);

static void
IMMPC_WriteCRC_9dof_reserve_raw_pack(
	immpc_9dof_reserve_raw_pack_s *pPack_s);

static size_t
IMMPC_IsPackValid_9dof_reserve_raw_pack(
	immpc_9dof_reserve_raw_pack_s *pPack_s);

/* Пакет 9dof_reserve_raw_pack_s --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* Пакет 9dof_reserve_calib_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

static uint16_t
IMMPC_GetCRC_9dof_reserve_calib_pack(
	immpc_9dof_reserve_calib_pack_s *pPack_s);

static void
IMMPC_WriteCRC_9dof_reserve_calib_pack(
	immpc_9dof_reserve_calib_pack_s *pPack_s);

static size_t
IMMPC_IsPackValid_9dof_reserve_calib_pack(
	immpc_9dof_reserve_calib_pack_s *pPack_s);

/* Пакет 9dof_reserve_calib_pack_s --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* Пакет mag3dof_raw_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

static uint16_t
IMMPC_GetCRC_mag3dof_raw_pack(
	immpc_mag3dof_raw_pack_s *pPack_s);

static void
IMMPC_WriteCRC_mag3dof_raw_pack(
	immpc_mag3dof_raw_pack_s *pPack_s);

static size_t
IMMPC_IsPackValid_mag3dof_raw_pack(
	immpc_mag3dof_raw_pack_s *pPack_s);

/* Пакет mag3dof_raw_pack_s --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* Пакет mag3dof_calib_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

static uint16_t
IMMPC_GetCRC_mag3dof_calib_pack(
	immpc_mag3dof_calib_pack_s *pPack_s);

static void
IMMPC_WriteCRC_mag3dof_calib_pack(
	immpc_mag3dof_calib_pack_s *pPack_s);

static size_t
IMMPC_IsPackValid_mag3dof_calib_pack(
	immpc_mag3dof_calib_pack_s *pPack_s);

/* Пакет mag3dof_calib_pack_s --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* Пакет immpc_acc3dof_main_calibmatrix_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

static uint16_t
IMMPC_GetCRC_acc3dof_main_calibmatrix_pack(
	immpc_acc3dof_main_calibmatrix_pack_s *pPack_s);

static void
IMMPC_WriteCRC_acc3dof_main_calibmatrix_pack(
	immpc_acc3dof_main_calibmatrix_pack_s *pPack_s);

static size_t
IMMPC_IsPackValid_acc3dof_main_calibmatrix_pack(
	immpc_acc3dof_main_calibmatrix_pack_s *pPack_s);

/* Пакет immpc_acc3dof_main_calibmatrix_read_pack_s --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* Пакет immpc_acc3dof_reserve_calibmatrix_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

static uint16_t
IMMPC_GetCRC_acc3dof_reserve_calibmatrix_pack(
	immpc_acc3dof_reserve_calibmatrix_pack_s *pPack_s);

static void
IMMPC_WriteCRC_acc3dof_reserve_calibmatrix_pack(
	immpc_acc3dof_reserve_calibmatrix_pack_s *pPack_s);

static size_t
IMMPC_IsPackValid_acc3dof_reserve_calibmatrix_pack(
	immpc_acc3dof_reserve_calibmatrix_pack_s *pPack_s);

/* Пакет immpc_acc3dof_reserve_calibmatrix_read_pack_s --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* Пакет immpc_gyr3dof_main_calibmatrix_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

static uint16_t
IMMPC_GetCRC_gyr3dof_main_calibmatrix_pack(
	immpc_gyr3dof_main_calibmatrix_pack_s *pPack_s);

static void
IMMPC_WriteCRC_gyr3dof_main_calibmatrix_pack(
	immpc_gyr3dof_main_calibmatrix_pack_s *pPack_s);

static size_t
IMMPC_IsPackValid_gyr3dof_main_calibmatrix_pack(
	immpc_gyr3dof_main_calibmatrix_pack_s *pPack_s);

/* Пакет immpc_gyr3dof_main_calibmatrix_read_pack_s --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* Пакет immpc_gyr3dof_reserve_calibmatrix_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

static uint16_t
IMMPC_GetCRC_gyr3dof_reserve_calibmatrix_pack(
	immpc_gyr3dof_reserve_calibmatrix_pack_s *pPack_s);

static void
IMMPC_WriteCRC_gyr3dof_reserve_calibmatrix_pack(
	immpc_gyr3dof_reserve_calibmatrix_pack_s *pPack_s);

static size_t
IMMPC_IsPackValid_gyr3dof_reserve_calibmatrix_pack(
	immpc_gyr3dof_reserve_calibmatrix_pack_s *pPack_s);

/* Пакет immpc_gyr3dof_reserve_calibmatrix_read_pack_s --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* Пакет immpc_mag3dof_calibmatrix_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

static uint16_t
IMMPC_GetCRC_mag3dof_calibmatrix_pack(
	immpc_mag3dof_calibmatrix_pack_s *pPack_s);

static void
IMMPC_WriteCRC_mag3dof_calibmatrix_pack(
	immpc_mag3dof_calibmatrix_pack_s *pPack_s);

static size_t
IMMPC_IsPackValid_mag3dof_calibmatrix_pack(
	immpc_mag3dof_calibmatrix_pack_s *pPack_s);

/* Пакет immpc_mag3dof_calibmatrix_read_pack_s --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/*#### |End  | <-- Секция - "Прототипы локальных функций" ####################*/


/*#### |Begin| --> Секция - "Описание глобальных функций" ####################*/
/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief    Функция выполняет поиск типа сообщения
 *
 * @param[in]	*pData: 	Указатель на область памяти, в которой содержатся
 * 							данные
 *
 * @param[in]	buffSize: 	Количество данных
 *
 * @param[out]	*pMessageIDReturn: 	Указатель на область памяти, в которой содержится
 * 									идентификатор сообщения
 *
 * @param[out]	*pMessagePackReturn: 	Указатель на область памяти, в которой содержится
 * 										тип сообщения
 */
immpc_message_struct_e
IMMPC_GetTypeMessage(
	const uint8_t *pData,
	size_t 	buffSize,
	uint8_t *pMessageIDReturn,
	uint8_t *pMessagePackReturn)
{
	/* присвоение стартовых значений */
	*pMessageIDReturn = IMMPC_MESSAGE_ID_UNKNOWN;
	*pMessagePackReturn = IMMPC_MESSAGE_PACK_UNKNOWN;

	immpc_message_struct_e messageFormat_e = IMMPC_MESSAGE_PACK_UNKNOWN;

	/* Минимальное количество данных необходимое для поиска */
	if (buffSize < 4u)
	{
		/* выход из функции */
		return (messageFormat_e);
	}

	size_t j;
	for (j = 0u; j < ((size_t) buffSize); j++)
	{
		/* Указатель на область памяти, в которой должны быть символы начала
		 * пакета данных и ID сообщения */
		uint16_t *pStartFrame 	= (uint16_t*) &pData[j];
//		uint8_t  *pMessageID 	= (uint8_t*)  &pData[j + 2u];
//		uint8_t  *pPackRequest 	= (uint8_t*)  &pData[j + 3u];
//
		uint16_t *pIDAndPackReq = (uint16_t*) &pData[j + 2u];
//
//		uint8_t packReq = 0u;

		/* Если нашли символы начала пакета данных */
		if (*pStartFrame == IIMPC_START_FRAME)
		{
			messageFormat_e = (immpc_message_struct_e) *pIDAndPackReq;

//			/* Получить ID пакета данных */
//			switch (*pMessageID)
//			{
//			case IMMPC_MESSAGE_ID_9DOF_PACK_MAIN:
//				if (__IIMPC_PACK_REQUESTS_BITS_IsSetCalibMeas(*pPackRequest) == 1u)
//				{
//					packReq = IIMPC_PACK_REQUESTS_BITS_SET_CALIB_MEAS(packReq);
//				}
//
//				if (__IIMPC_PACK_REQUESTS_BITS_IsSetReservMeas(*pPackRequest) == 1u)
//				{
//					packReq = IIMPC_PACK_REQUESTS_BITS_SET_RESERV_MEAS(packReq);
//				}
//
//				if (__IIMPC_PACK_REQUESTS_BITS_IsSetReadFlag(*pPackRequest) == 1u)
//				{
//					packReq = IIMPC_PACK_REQUESTS_BITS_SET_READ_MEAS(packReq);
//				}
//
//				if (__IIMPC_PACK_REQUESTS_BITS_IsSetDataRequest(*pPackRequest))
//				{
//					packReq = IIMPC_PACK_REQUESTS_BITS_SET_REQUEST(packReq);
//				}
//
//				break;
//
//			default:
//				break;
//			}

			/* Выход из цикла for (Пакет нашли, разобрали, не нужно
			 * тратить драгоценное время контроллера на попытку найти еще один)*/
			break;
		}
	}

	/* Поиск */
	for (uint16_t i = 0; i < (uint16_t) buffSize - 2u; i++)
	{

		/* Поиск в потоке данных символы StartFrame */
		if (	(*(pData + i) == (uint8_t) ((IIMPC_START_FRAME >> 8) & 0xFF)) &&
				(*(pData + i + 1) == (uint8_t) (IIMPC_START_FRAME & 0xFF)))
		{

			/* Посмотреть какой ID сообщения */
			switch (*(pData + i + 2))
			{
			case IMMPC_MESSAGE_ID_9DOF_PACK_MAIN:
				/* не резервные т.е. основыне */
				if ((*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_RESERV_MEAS) != IIMPC_PACK_REQUESTS_BITS_RESERV_MEAS)
				{
					/* запрос на получение данных */
					if ((*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST) == IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST)
					{
						/* калиброванные */
						if ((*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS) == IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS)
						{
							*pMessagePackReturn = IMMPC_MESSAGE_PACK_9dof_main_calib_pack_s;
						}
						else
						{
							*pMessagePackReturn = IMMPC_MESSAGE_PACK_9dof_main_raw_pack_s;
						}
					}
					/* ответ на запрос с данными */
					else
					{
						/* калиброванные */
						if ((*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS) == IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS)
						{
							*pMessagePackReturn = IMMPC_MESSAGE_PACK_9dof_main_calib_request_cmd_s;
						}
						else
						{
							*pMessagePackReturn = IMMPC_MESSAGE_PACK_9dof_main_raw_request_cmd_s;
						}
					}
				}
				break;

			case IMMPC_MESSAGE_ID_9DOF_PACK_RESERVE:
				/* резервные */
				if ((*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_RESERV_MEAS) == IIMPC_PACK_REQUESTS_BITS_RESERV_MEAS)
				{
					/* запрос на получение данных */
					if ((*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST) == IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST)
					{
						/* калиброванные */
						if ((*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS) == IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS)
						{
							*pMessagePackReturn = IMMPC_MESSAGE_PACK_9dof_reserve_calib_pack_s;
						}
						else
						{
							*pMessagePackReturn = IMMPC_MESSAGE_PACK_9dof_reserve_raw_pack_s;
						}
					}
					/* ответ на запрос с данными */
					else
					{
						/* калиброванные */
						if ((*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS) == IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS)
						{
							*pMessagePackReturn = IMMPC_MESSAGE_PACK_9dof_reserve_calib_request_cmd_s;
						}
						else
						{
							*pMessagePackReturn =  IMMPC_MESSAGE_PACK_9dof_reserve_raw_request_cmd_s;
						}
					}
				}
				break;

			case IMMPC_MESSAGE_ID_ACC3DOF_CALIBMATRIX:
				/* запрос калиброванных данных */
				if ((*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS) == IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS)
				{
					/* запрос на получение данных */
					if ((*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST) == IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST)
					{
						/* резервные */
						if ((*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_RESERV_MEAS) == IIMPC_PACK_REQUESTS_BITS_RESERV_MEAS)
						{
							*pMessagePackReturn = IMMPC_MESSAGE_PACK_acc3dof_reserve_calibmatrix_request_cmd_s;
						}
						else
						{
							*pMessagePackReturn =  IMMPC_MESSAGE_PACK_acc3dof_main_calibmatrix_request_cmd_s;
						}
					}
					/* с полезными данными */
					else {
						/* запрос на запись данных */
						if ((*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_READ_MEAS) == IIMPC_PACK_REQUESTS_BITS_READ_MEAS)
						{
							/* резервные */
							if ((*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_RESERV_MEAS) == IIMPC_PACK_REQUESTS_BITS_RESERV_MEAS)
							{
								*pMessagePackReturn = IMMPC_MESSAGE_PACK_acc3dof_reserve_calibmatrix_write_pack_s;
							}
							else
							{
								*pMessagePackReturn =  IMMPC_MESSAGE_PACK_acc3dof_main_calibmatrix_write_pack_s;
							}
						}
						else
						{
							/* резервные */
							if ((*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_RESERV_MEAS) == IIMPC_PACK_REQUESTS_BITS_RESERV_MEAS)
							{
								*pMessagePackReturn = IMMPC_MESSAGE_PACK_acc3dof_reserve_calibmatrix_read_pack_s;
							}
							else
							{
								*pMessagePackReturn =  IMMPC_MESSAGE_PACK_acc3dof_main_calibmatrix_read_pack_s;
							}
						}
					}
				}
				break;

			case IMMPC_MESSAGE_ID_GYR3DOF_CALIBMATRIX:
				/* запрос калиброванных данных */
				if ((*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS) == IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS)
				{
					/* запрос на получение данных */
					if ((*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST) == IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST)
					{
						/* резервные */
						if ((*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_RESERV_MEAS) == IIMPC_PACK_REQUESTS_BITS_RESERV_MEAS)
						{
							*pMessagePackReturn = IMMPC_MESSAGE_PACK_gyr3dof_reserve_calibmatrix_request_cmd_s;
						}
						else
						{
							*pMessagePackReturn =  IMMPC_MESSAGE_PACK_gyr3dof_main_calibmatrix_request_cmd_s;
						}
					}
					/* с полезными данными */
					else {
						/* запрос на запись данных */
						if ((*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_READ_MEAS) == IIMPC_PACK_REQUESTS_BITS_READ_MEAS)
						{
							/* резервные */
							if ((*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_RESERV_MEAS) == IIMPC_PACK_REQUESTS_BITS_RESERV_MEAS)
							{
								*pMessagePackReturn = IMMPC_MESSAGE_PACK_gyr3dof_reserve_calibmatrix_write_pack_s;
							}
							else
							{
								*pMessagePackReturn =  IMMPC_MESSAGE_PACK_gyr3dof_main_calibmatrix_write_pack_s;
							}
						}
						else
						{
							/* резервные */
							if ((*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_RESERV_MEAS) == IIMPC_PACK_REQUESTS_BITS_RESERV_MEAS)
							{
								*pMessagePackReturn = IMMPC_MESSAGE_PACK_gyr3dof_reserve_calibmatrix_read_pack_s;
							}
							else
							{
								*pMessagePackReturn =  IMMPC_MESSAGE_PACK_gyr3dof_main_calibmatrix_read_pack_s;
							}
						}
					}
				}
				break;

			case IMMPC_MESSAGE_ID_MAG3DOF_CALIBMATRIX:
				/* запрос калиброванных данных */
				if ((*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS) == IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS)
				{
					/* запрос на получение данных */
					if ((*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST) == IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST)
					{
						*pMessagePackReturn = IMMPC_MESSAGE_PACK_mag3dof_calibmatrix_request_cmd_s;
					}
					else {
						/* запрос на запись данных */
						if ((*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_READ_MEAS) == IIMPC_PACK_REQUESTS_BITS_READ_MEAS)
						{
							*pMessagePackReturn = IMMPC_MESSAGE_PACK_mag3dof_calibmatrix_write_pack_s;
						}
						else
						{
							*pMessagePackReturn = IMMPC_MESSAGE_PACK_mag3dof_calibmatrix_read_pack_s;
						}
					}
				}
				break;

			case IMMPC_MESSAGE_ID_3DOF_PACK_MAIN:
				/* запрос калиброванных данных
				 * запись */
				if (	((*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS) == IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS) &&
						((*(pData + i + 3) & IIMPC_PACK_REQUESTS_BITS_READ_MEAS) == IIMPC_PACK_REQUESTS_BITS_READ_MEAS))
				{
					*pMessagePackReturn = IMMPC_MESSAGE_PACK_write_all_calibmatrix_in_eeprom_cmd_s;
				}
				break;

			default:
				/* выход из функции */
				return (messageFormat_e);
			}

			/* запись идентификатора пакета */
			*pMessageIDReturn = *(pData + i + 2);

			/* выход */
			return (messageFormat_e);
		}
	}
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
		IMMPC_GetCRC_9dof_main_raw_pack(pPack_s);

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

/* Пакет 9dof_main_calib_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief    Функция выполняет вычисление контрольной суммы пакета данных (калиброванных)
 *
 * @param[in]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 							пакет данных
 *
 * @return 	Вычисленная сумма пакета данных
 */
static uint16_t
IMMPC_GetCRC_9dof_main_calib_pack(
	immpc_9dof_main_calib_pack_s *pPack_s)
{
	return (IMMPC_GetCRC_Generic(
				(uint8_t*) pPack_s,
				(uint16_t) (sizeof(immpc_9dof_main_calib_pack_s))));
}

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief 	Функция выполняет запись контрольной суммы пакета данных (калиброванных)
 *
 * @param[in,out]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 								пакет данных.
 * 								@note 	Контрольная сумма записывается в конец
 * 										пакета данных
 */
static void
IMMPC_WriteCRC_9dof_main_calib_pack(
	immpc_9dof_main_calib_pack_s *pPack_s)
{
	pPack_s->crc =
		IMMPC_GetCRC_Generic(
			(uint8_t*) pPack_s,
			(uint16_t) (sizeof(immpc_9dof_main_calib_pack_s)));
}

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief Функция проверяет валидность пакета данных (калиброванных)
 *
 * @param[in]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 							пакет данных.
 *
 * @return 	Если пакет данных валиден, то возвращает "1", иначе "0"
 */
static size_t
IMMPC_IsPackValid_9dof_main_calib_pack(
	immpc_9dof_main_calib_pack_s *pPack_s)
{
	uint16_t crc =
		IMMPC_GetCRC_9dof_main_calib_pack_s(pPack_s);

	if (crc == pPack_s->crc)
	{
		return (1u);
	}
	else
	{
		return (0u);
	}
}
/* Пакет 9dof_main_calib_pack_s --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* Пакет 9dof_reserve_raw_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief    Функция выполняет вычисление контрольной суммы пакета данных
 *
 * @param[in]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 							пакет данных
 *
 * @return 	Вычисленная сумма пакета данных
 */
static uint16_t
IMMPC_GetCRC_9dof_reserve_raw_pack(
	immpc_9dof_reserve_raw_pack_s *pPack_s)
{
	return (IMMPC_GetCRC_Generic(
				(uint8_t*) pPack_s,
				(uint16_t) (sizeof(immpc_9dof_reserve_raw_pack_s))));
}

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief 	Функция выполняет запись контрольной суммы пакета данных
 *
 * @param[in,out]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 								пакет данных.
 * 								@note 	Контрольная сумма записывается в конец
 * 										пакета данных
 */
static void
IMMPC_WriteCRC_9dof_reserve_raw_pack(
	immpc_9dof_reserve_raw_pack_s *pPack_s)
{
	pPack_s->crc =
		IMMPC_GetCRC_Generic(
			(uint8_t*) pPack_s,
			(uint16_t) (sizeof(immpc_9dof_reserve_raw_pack_s)));
}

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief Функция проверяет валидность пакета данных
 *
 * @param[in]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 							пакет данных.
 *
 * @return 	Если пакет данных валиден, то возвращает "1", иначе "0"
 */
static size_t
IMMPC_IsPackValid_9dof_reserve_raw_pack(
	immpc_9dof_reserve_raw_pack_s *pPack_s)
{
	uint16_t crc =
		IMMPC_GetCRC_9dof_reserve_raw_pack_s(pPack_s);

	if (crc == pPack_s->crc)
	{
		return (1u);
	}
	else
	{
		return (0u);
	}
}
/* Пакет 9dof_reserve_raw_pack_s --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* Пакет 9dof_reserve_calib_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief    Функция выполняет вычисление контрольной суммы пакета данных (калиброванных)
 *
 * @param[in]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 							пакет данных
 *
 * @return 	Вычисленная сумма пакета данных
 */
static uint16_t
IMMPC_GetCRC_9dof_reserve_calib_pack(
	immpc_9dof_reserve_calib_pack_s *pPack_s)
{
	return (IMMPC_GetCRC_Generic(
				(uint8_t*) pPack_s,
				(uint16_t) (sizeof(immpc_9dof_reserve_calib_pack_s))));
}

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief 	Функция выполняет запись контрольной суммы пакета данных (калиброванных)
 *
 * @param[in,out]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 								пакет данных.
 * 								@note 	Контрольная сумма записывается в конец
 * 										пакета данных
 */
static void
IMMPC_WriteCRC_9dof_reserve_calib_pack(
	immpc_9dof_reserve_calib_pack_s *pPack_s)
{
	pPack_s->crc =
		IMMPC_GetCRC_Generic(
			(uint8_t*) pPack_s,
			(uint16_t) (sizeof(immpc_9dof_reserve_calib_pack_s)));
}

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief Функция проверяет валидность пакета данных (калиброванных)
 *
 * @param[in]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 							пакет данных.
 *
 * @return 	Если пакет данных валиден, то возвращает "1", иначе "0"
 */
static size_t
IMMPC_IsPackValid_9dof_reserve_calib_pack(
	immpc_9dof_reserve_calib_pack_s *pPack_s)
{
	uint16_t crc =
		IMMPC_GetCRC_9dof_reserve_calib_pack_s(pPack_s);

	if (crc == pPack_s->crc)
	{
		return (1u);
	}
	else
	{
		return (0u);
	}
}
/* Пакет 9dof_reserve_calib_pack_s --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* Пакет mag3dof_raw_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief    Функция выполняет вычисление контрольной суммы пакета данных
 *
 * @param[in]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 							пакет данных
 *
 * @return 	Вычисленная сумма пакета данных
 */
static uint16_t
IMMPC_GetCRC_mag3dof_raw_pack(
	immpc_mag3dof_raw_pack_s *pPack_s)
{
	return (IMMPC_GetCRC_Generic(
				(uint8_t*) pPack_s,
				(uint16_t) (sizeof(immpc_mag3dof_raw_pack_s))));
}

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief 	Функция выполняет запись контрольной суммы пакета данных
 *
 * @param[in,out]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 								пакет данных.
 * 								@note 	Контрольная сумма записывается в конец
 * 										пакета данных
 */
static void
IMMPC_WriteCRC_mag3dof_raw_pack(
	immpc_mag3dof_raw_pack_s *pPack_s)
{
	pPack_s->crc =
		IMMPC_GetCRC_Generic(
			(uint8_t*) pPack_s,
			(uint16_t) (sizeof(immpc_mag3dof_raw_pack_s)));
}

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief Функция проверяет валидность пакета данных
 *
 * @param[in]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 							пакет данных.
 *
 * @return 	Если пакет данных валиден, то возвращает "1", иначе "0"
 */
static size_t
IMMPC_IsPackValid_mag3dof_raw_pack(
	immpc_mag3dof_raw_pack_s *pPack_s)
{
	uint16_t crc =
		IMMPC_GetCRC_mag3dof_raw_pack_s(pPack_s);

	if (crc == pPack_s->crc)
	{
		return (1u);
	}
	else
	{
		return (0u);
	}
}
/* Пакет mag3dof_raw_pack_s --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* Пакет mag3dof_calib_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief    Функция выполняет вычисление контрольной суммы пакета данных (калиброванных)
 *
 * @param[in]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 							пакет данных
 *
 * @return 	Вычисленная сумма пакета данных
 */
static uint16_t
IMMPC_GetCRC_mag3dof_calib_pack(
	immpc_mag3dof_calib_pack_s *pPack_s)
{
	return (IMMPC_GetCRC_Generic(
				(uint8_t*) pPack_s,
				(uint16_t) (sizeof(immpc_mag3dof_calib_pack_s))));
}

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief 	Функция выполняет запись контрольной суммы пакета данных (калиброванных)
 *
 * @param[in,out]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 								пакет данных.
 * 								@note 	Контрольная сумма записывается в конец
 * 										пакета данных
 */
static void
IMMPC_WriteCRC_mag3dof_calib_pack(
	immpc_mag3dof_calib_pack_s *pPack_s)
{
	pPack_s->crc =
		IMMPC_GetCRC_Generic(
			(uint8_t*) pPack_s,
			(uint16_t) (sizeof(immpc_mag3dof_calib_pack_s)));
}

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief Функция проверяет валидность пакета данных (калиброванных)
 *
 * @param[in]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 							пакет данных.
 *
 * @return 	Если пакет данных валиден, то возвращает "1", иначе "0"
 */
static size_t
IMMPC_IsPackValid_mag3dof_calib_pack(
	immpc_mag3dof_calib_pack_s *pPack_s)
{
	uint16_t crc =
		IMMPC_GetCRC_mag3dof_calib_pack_s(pPack_s);

	if (crc == pPack_s->crc)
	{
		return (1u);
	}
	else
	{
		return (0u);
	}
}
/* Пакет mag3dof_calib_pack_s --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* Пакет immpc_acc3dof_main_calibmatrix_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief    Функция выполняет вычисление контрольной суммы пакета данных (калиброванных)
 *
 * @param[in]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 							пакет данных
 *
 * @return 	Вычисленная сумма пакета данных
 */
static uint16_t
IMMPC_GetCRC_acc3dof_main_calibmatrix_pack(
	immpc_acc3dof_main_calibmatrix_pack_s *pPack_s)
{
	return (IMMPC_GetCRC_Generic(
				(uint8_t*) pPack_s,
				(uint16_t) (sizeof(immpc_acc3dof_main_calibmatrix_pack_s))));
}

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief 	Функция выполняет запись контрольной суммы пакета данных (калиброванных)
 *
 * @param[in,out]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 								пакет данных.
 * 								@note 	Контрольная сумма записывается в конец
 * 										пакета данных
 */
static void
IMMPC_WriteCRC_acc3dof_main_calibmatrix_pack(
	immpc_acc3dof_main_calibmatrix_pack_s *pPack_s)
{
	pPack_s->crc =
		IMMPC_GetCRC_Generic(
			(uint8_t*) pPack_s,
			(uint16_t) (sizeof(immpc_acc3dof_main_calibmatrix_pack_s)));
}

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief Функция проверяет валидность пакета данных (калиброванных)
 *
 * @param[in]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 							пакет данных.
 *
 * @return 	Если пакет данных валиден, то возвращает "1", иначе "0"
 */
static size_t
IMMPC_IsPackValid_acc3dof_main_calibmatrix_pack(
	immpc_acc3dof_main_calibmatrix_pack_s *pPack_s)
{
	uint16_t crc =
		IMMPC_GetCRC_acc3dof_main_calibmatrix_pack_s(pPack_s);

	if (crc == pPack_s->crc)
	{
		return (1u);
	}
	else
	{
		return (0u);
	}
}
/* Пакет immpc_acc3dof_main_calibmatrix_read_pack_s --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* Пакет immpc_acc3dof_reserve_calibmatrix_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief    Функция выполняет вычисление контрольной суммы пакета данных (калиброванных)
 *
 * @param[in]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 							пакет данных
 *
 * @return 	Вычисленная сумма пакета данных
 */
static uint16_t
IMMPC_GetCRC_acc3dof_reserve_calibmatrix_pack(
	immpc_acc3dof_reserve_calibmatrix_pack_s *pPack_s)
{
	return (IMMPC_GetCRC_Generic(
				(uint8_t*) pPack_s,
				(uint16_t) (sizeof(immpc_acc3dof_reserve_calibmatrix_pack_s))));
}

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief 	Функция выполняет запись контрольной суммы пакета данных (калиброванных)
 *
 * @param[in,out]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 								пакет данных.
 * 								@note 	Контрольная сумма записывается в конец
 * 										пакета данных
 */
static void
IMMPC_WriteCRC_acc3dof_reserve_calibmatrix_pack(
	immpc_acc3dof_reserve_calibmatrix_pack_s *pPack_s)
{
	pPack_s->crc =
		IMMPC_GetCRC_Generic(
			(uint8_t*) pPack_s,
			(uint16_t) (sizeof(immpc_acc3dof_reserve_calibmatrix_pack_s)));
}

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief Функция проверяет валидность пакета данных (калиброванных)
 *
 * @param[in]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 							пакет данных.
 *
 * @return 	Если пакет данных валиден, то возвращает "1", иначе "0"
 */
static size_t
IMMPC_IsPackValid_acc3dof_reserve_calibmatrix_pack(
	immpc_acc3dof_reserve_calibmatrix_pack_s *pPack_s)
{
	uint16_t crc =
		IMMPC_GetCRC_acc3dof_reserve_calibmatrix_pack_s(pPack_s);

	if (crc == pPack_s->crc)
	{
		return (1u);
	}
	else
	{
		return (0u);
	}
}
/* Пакет immpc_acc3dof_reserve_calibmatrix_read_pack_s --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* Пакет immpc_gyr3dof_main_calibmatrix_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief    Функция выполняет вычисление контрольной суммы пакета данных (калиброванных)
 *
 * @param[in]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 							пакет данных
 *
 * @return 	Вычисленная сумма пакета данных
 */
static uint16_t
IMMPC_GetCRC_gyr3dof_main_calibmatrix_pack(
	immpc_gyr3dof_main_calibmatrix_pack_s *pPack_s)
{
	return (IMMPC_GetCRC_Generic(
				(uint8_t*) pPack_s,
				(uint16_t) (sizeof(immpc_gyr3dof_main_calibmatrix_pack_s))));
}

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief 	Функция выполняет запись контрольной суммы пакета данных (калиброванных)
 *
 * @param[in,out]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 								пакет данных.
 * 								@note 	Контрольная сумма записывается в конец
 * 										пакета данных
 */
static void
IMMPC_WriteCRC_gyr3dof_main_calibmatrix_pack(
	immpc_gyr3dof_main_calibmatrix_pack_s *pPack_s)
{
	pPack_s->crc =
		IMMPC_GetCRC_Generic(
			(uint8_t*) pPack_s,
			(uint16_t) (sizeof(immpc_gyr3dof_main_calibmatrix_pack_s)));
}

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief Функция проверяет валидность пакета данных (калиброванных)
 *
 * @param[in]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 							пакет данных.
 *
 * @return 	Если пакет данных валиден, то возвращает "1", иначе "0"
 */
static size_t
IMMPC_IsPackValid_gyr3dof_main_calibmatrix_pack(
	immpc_gyr3dof_main_calibmatrix_pack_s *pPack_s)
{
	uint16_t crc =
		IMMPC_GetCRC_gyr3dof_main_calibmatrix_pack_s(pPack_s);

	if (crc == pPack_s->crc)
	{
		return (1u);
	}
	else
	{
		return (0u);
	}
}
/* Пакет immpc_gyr3dof_main_calibmatrix_read_pack_s --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* Пакет immpc_gyr3dof_reserve_calibmatrix_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief    Функция выполняет вычисление контрольной суммы пакета данных (калиброванных)
 *
 * @param[in]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 							пакет данных
 *
 * @return 	Вычисленная сумма пакета данных
 */
static uint16_t
IMMPC_GetCRC_gyr3dof_reserve_calibmatrix_pack(
	immpc_gyr3dof_reserve_calibmatrix_pack_s *pPack_s)
{
	return (IMMPC_GetCRC_Generic(
				(uint8_t*) pPack_s,
				(uint16_t) (sizeof(immpc_gyr3dof_reserve_calibmatrix_pack_s))));
}

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief 	Функция выполняет запись контрольной суммы пакета данных (калиброванных)
 *
 * @param[in,out]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 								пакет данных.
 * 								@note 	Контрольная сумма записывается в конец
 * 										пакета данных
 */
static void
IMMPC_WriteCRC_gyr3dof_reserve_calibmatrix_pack(
	immpc_gyr3dof_reserve_calibmatrix_pack_s *pPack_s)
{
	pPack_s->crc =
		IMMPC_GetCRC_Generic(
			(uint8_t*) pPack_s,
			(uint16_t) (sizeof(immpc_gyr3dof_reserve_calibmatrix_pack_s)));
}

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief Функция проверяет валидность пакета данных (калиброванных)
 *
 * @param[in]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 							пакет данных.
 *
 * @return 	Если пакет данных валиден, то возвращает "1", иначе "0"
 */
static size_t
IMMPC_IsPackValid_gyr3dof_reserve_calibmatrix_pack(
	immpc_gyr3dof_reserve_calibmatrix_pack_s *pPack_s)
{
	uint16_t crc =
		IMMPC_GetCRC_gyr3dof_reserve_calibmatrix_pack_s(pPack_s);

	if (crc == pPack_s->crc)
	{
		return (1u);
	}
	else
	{
		return (0u);
	}
}
/* Пакет immpc_gyr3dof_reserve_calibmatrix_read_pack_s --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* Пакет immpc_mag3dof_calibmatrix_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief    Функция выполняет вычисление контрольной суммы пакета данных (калиброванных)
 *
 * @param[in]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 							пакет данных
 *
 * @return 	Вычисленная сумма пакета данных
 */
static uint16_t
IMMPC_GetCRC_mag3dof_calibmatrix_pack(
	immpc_mag3dof_calibmatrix_pack_s *pPack_s)
{
	return (IMMPC_GetCRC_Generic(
				(uint8_t*) pPack_s,
				(uint16_t) (sizeof(immpc_mag3dof_calibmatrix_pack_s))));
}

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief 	Функция выполняет запись контрольной суммы пакета данных (калиброванных)
 *
 * @param[in,out]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 								пакет данных.
 * 								@note 	Контрольная сумма записывается в конец
 * 										пакета данных
 */
static void
IMMPC_WriteCRC_mag3dof_calibmatrix_pack(
	immpc_mag3dof_calibmatrix_pack_s *pPack_s)
{
	pPack_s->crc =
		IMMPC_GetCRC_Generic(
			(uint8_t*) pPack_s,
			(uint16_t) (sizeof(immpc_mag3dof_calibmatrix_pack_s)));
}

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief Функция проверяет валидность пакета данных (калиброванных)
 *
 * @param[in]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 							пакет данных.
 *
 * @return 	Если пакет данных валиден, то возвращает "1", иначе "0"
 */
static size_t
IMMPC_IsPackValid_mag3dof_calibmatrix_pack(
	immpc_mag3dof_calibmatrix_pack_s *pPack_s)
{
	uint16_t crc =
		IMMPC_GetCRC_mag3dof_calibmatrixx_pack_s(pPack_s);

	if (crc == pPack_s->crc)
	{
		return (1u);
	}
	else
	{
		return (0u);
	}
}
/* Пакет immpc_mag3dof_calibmatrix_read_pack_s --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date      05-ноя-2019
 *
 * @brief    Функция выполняет поиск типа сообщения
 *
 * @param[in]	*pData: 	Указатель на область памяти, в которой содержатся
 * 							данные
 *
 * @param[in]	buffSize: 	Количество данных
 *
 * @param[out]	*pMessagePackReturn: 	Указатель на область памяти, в которой содержится
 * 										тип сообщения
 */
void
IMMPC_GetDataMessage(
	uint8_t *pData,
	size_t 	buffSize,
	uint8_t *pMessagePackReturn)
{
	uint8_t messageIDReturn;
	uint32_t i;
	uint8_t *pDataStruct;

	/* получение типа сообщения */
	IMMPC_GetTypeMessage(
		pData,
		buffSize,
		&messageIDReturn,
		pMessagePackReturn);

	/* идентификатор и тип пакета определены? */
	if (	(messageIDReturn != IMMPC_MESSAGE_ID_UNKNOWN) &&
			(*pMessagePackReturn != IMMPC_MESSAGE_PACK_UNKNOWN))
	{
		return;
	}

	/* обработка по типу сообщения */
	switch (*pMessagePackReturn)
	{
	case IMMPC_MESSAGE_PACK_9dof_main_raw_pack_s:
		/* проверка количества символов и правильности CRC */
		if (	(buffSize == (size_t) (sizeof(immpc_9dof_main_raw_pack_s))) &&
				(IMMPC_IsPackValid_9dof_main_raw_pack((immpc_9dof_main_raw_pack_s*) pData)))
		{
			/* сохранение адреса структуры */
			pDataStruct = (uint8_t*) &IMMPC_9DOF_main_raw_pack_s;

			/* сохранение данных */
			for (i = 0; i < sizeof(immpc_9dof_main_raw_pack_s); i++)
			{
				*pDataStruct++ = *pData++;
			}
		}
		else
		{
			*pMessagePackReturn == IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_9dof_main_calib_pack_s:
		/* проверка количества символов и правильности CRC */
		if (	(buffSize == (size_t) (sizeof(immpc_9dof_main_calib_pack_s))) &&
				(IMMPC_IsPackValid_9dof_main_calib_pack((immpc_9dof_main_calib_pack_s*) pData)))
		{
			/* сохранение адреса структуры */
			pDataStruct = (uint8_t*) &IMMPC_9DOF_main_calib_pack_s;

			/* сохранение данных */
			for (i = 0; i < sizeof(immpc_9dof_main_calib_pack_s); i++)
			{
				*pDataStruct++ = *pData++;
			}
		}
		else
		{
			*pMessagePackReturn == IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_9dof_reserve_raw_pack_s:
		/* проверка количества символов и правильности CRC */
		if (	(buffSize == (size_t) (sizeof(immpc_9dof_reserve_raw_pack_s))) &&
				(IMMPC_IsPackValid_9dof_reserve_raw_pack((immpc_9dof_reserve_raw_pack_s*) pData)))
		{
			/* сохранение адреса структуры */
			pDataStruct = (uint8_t*) &IMMPC_9DOF_reserve_raw_pack_s;

			/* сохранение данных */
			for (i = 0; i < sizeof(immpc_9dof_reserve_raw_pack_s); i++)
			{
				*pDataStruct++ = *pData++;
			}
		}
		else
		{
			*pMessagePackReturn == IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_9dof_reserve_calib_pack_s:
		/* проверка количества символов и правильности CRC */
		if (	(buffSize == (size_t) (sizeof(immpc_9dof_reserve_calib_pack_s))) &&
				(IMMPC_IsPackValid_9dof_reserve_calib_pack((immpc_9dof_reserve_calib_pack_s*) pData)))
		{
			/* сохранение адреса структуры */
			pDataStruct = (uint8_t*) &IMMPC_9DOF_reserve_calib_pack_s;

			/* сохранение данных */
			for (i = 0; i < sizeof(immpc_9dof_reserve_calib_pack_s); i++)
			{
				*pDataStruct++ = *pData++;
			}
		}
		else
		{
			*pMessagePackReturn == IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_mag3dof_raw_pack_s:
		/* проверка количества символов и правильности CRC */
		if (	(buffSize == (size_t) (sizeof(immpc_mag3dof_raw_pack_s))) &&
				(IMMPC_IsPackValid_mag3dof_raw_pack((immpc_mag3dof_raw_pack_s*) pData)))
		{
			/* сохранение адреса структуры */
			pDataStruct = (uint8_t*) &IMMPC_MAG3DOF_raw_pack_s;

			/* сохранение данных */
			for (i = 0; i < sizeof(immpc_mag3dof_raw_pack_s); i++)
			{
				*pDataStruct++ = *pData++;
			}
		}
		else
		{
			*pMessagePackReturn == IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_mag3dof_calib_pack_s:
		/* проверка количества символов и правильности CRC */
		if (	(buffSize == (size_t) (sizeof(immpc_mag3dof_calib_pack_s))) &&
				(IMMPC_IsPackValid_mag3dof_calib_pack((immpc_mag3dof_calib_pack_s*) pData)))
		{
			/* сохранение адреса структуры */
			pDataStruct = (uint8_t*) &IMMPC_MAG3DOF_calib_pack_s;

			/* сохранение данных */
			for (i = 0; i < sizeof(immpc_mag3dof_calib_pack_s); i++)
			{
				*pDataStruct++ = *pData++;
			}
		}
		break;

	case IMMPC_MESSAGE_PACK_acc3dof_main_calibmatrix_read_pack_s:
		/* проверка количества символов и правильности CRC */
		if (	(buffSize == (size_t) (sizeof(immpc_acc3dof_main_calibmatrix_pack_s))) &&
				(IMMPC_IsPackValid_acc3dof_main_calibmatrix_pack((immpc_acc3dof_main_calibmatrix_pack_s*) pData)))
		{
			/* сохранение адреса структуры */
			pDataStruct = (uint8_t*) &IMMPC_ACC3DOF_main_calibmatrix_pack_s;

			/* сохранение данных */
			for (i = 0; i < sizeof(immpc_acc3dof_main_calibmatrix_pack_s); i++)
			{
				*pDataStruct++ = *pData++;
			}
		}
		else
		{
			*pMessagePackReturn == IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_acc3dof_main_calibmatrix_write_pack_s:
		/* формирование ответного сообщения ... */
		break;

	case IMMPC_MESSAGE_PACK_acc3dof_reserve_calibmatrix_read_pack_s:
		/* проверка количества символов и правильности CRC */
		if (	(buffSize == (size_t) (sizeof(immpc_acc3dof_reserve_calibmatrix_pack_s))) &&
				(IMMPC_IsPackValid_acc3dof_reserve_calibmatrix_pack((immpc_acc3dof_reserve_calibmatrix_pack_s*) pData)))
		{
			/* сохранение адреса структуры */
			pDataStruct = (uint8_t*) &IMMPC_ACC3DOF_reserve_calibmatrix_pack_s;

			/* сохранение данных */
			for (i = 0; i < sizeof(immpc_acc3dof_reserve_calibmatrix_pack_s); i++)
			{
				*pDataStruct++ = *pData++;
			}
		}
		else
		{
			*pMessagePackReturn == IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_acc3dof_reserve_calibmatrix_write_pack_s:
		/* формирование ответного сообщения ... */
		break;

	case IMMPC_MESSAGE_PACK_gyr3dof_main_calibmatrix_read_pack_s:
		/* проверка количества символов и правильности CRC */
		if (	(buffSize == (size_t) (sizeof(immpc_gyr3dof_main_calibmatrix_pack_s))) &&
				(IMMPC_IsPackValid_gyr3dof_main_calibmatrix_pack((immpc_gyr3dof_main_calibmatrix_pack_s*) pData)))
		{
			/* сохранение адреса структуры */
			pDataStruct = (uint8_t*) &IMMPC_GYR3DOF_main_calibmatrix_pack_s;

			/* сохранение данных */
			for (i = 0; i < sizeof(immpc_gyr3dof_main_calibmatrix_pack_s); i++)
			{
				*pDataStruct++ = *pData++;
			}
		}
		else
		{
			*pMessagePackReturn == IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_gyr3dof_main_calibmatrix_write_pack_s:
		/* формирование ответного сообщения ... */
		break;

	case IMMPC_MESSAGE_PACK_gyr3dof_reserve_calibmatrix_read_pack_s:
		/* проверка количества символов и правильности CRC */
		if (	(buffSize == (size_t) (sizeof(immpc_gyr3dof_reserve_calibmatrix_pack_s))) &&
				(IMMPC_IsPackValid_gyr3dof_reserve_calibmatrix_pack((immpc_gyr3dof_reserve_calibmatrix_pack_s*) pData)))
		{
			/* сохранение адреса структуры */
			pDataStruct = (uint8_t*) &IMMPC_GYR3DOF_reserve_calibmatrix_pack_s;

			/* сохранение данных */
			for (i = 0; i < sizeof(immpc_gyr3dof_reserve_calibmatrix_pack_s); i++)
			{
				*pDataStruct++ = *pData++;
			}
		}
		else
		{
			*pMessagePackReturn == IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_gyr3dof_reserve_calibmatrix_write_pack_s:
		/* формирование ответного сообщения ... */
		break;

	case IMMPC_MESSAGE_PACK_mag3dof_calibmatrix_read_pack_s:
		/* проверка количества символов и правильности CRC */
		if (	(buffSize == (size_t) (sizeof(immpc_mag3dof_calibmatrix_pack_s))) &&
				(IMMPC_IsPackValid_mag3dof_calibmatrix_pack((immpc_mag3dof_calibmatrix_pack_s*) pData)))
		{
			/* сохранение адреса структуры */
			pDataStruct = (uint8_t*) &IMMPC_MAG3DOF_calibmatrix_pack_s;

			/* сохранение данных */
			for (i = 0; i < sizeof(immpc_mag3dof_calibmatrix_pack_s); i++)
			{
				*pDataStruct++ = *pData++;
			}
		}
		else
		{
			*pMessagePackReturn == IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_mag3dof_calibmatrix_write_pack_s:
		/* формирование ответного сообщения ... */
		break;

	case IMMPC_MESSAGE_PACK_9dof_main_raw_request_cmd_s:
		/* формирование ответного сообщения ... */
		break;

	case IMMPC_MESSAGE_PACK_9dof_main_calib_request_cmd_s:
		/* формирование ответного сообщения ... */
		break;

	case IMMPC_MESSAGE_PACK_9dof_reserve_raw_request_cmd_s:
		/* формирование ответного сообщения ... */
		break;

	case IMMPC_MESSAGE_PACK_9dof_reserve_calib_request_cmd_s:
		/* формирование ответного сообщения ... */
		break;

	case IMMPC_MESSAGE_PACK_acc3dof_main_calibmatrix_request_cmd_s:
		/* формирование ответного сообщения ... */
		break;

	case IMMPC_MESSAGE_PACK_acc3dof_reserve_calibmatrix_request_cmd_s:
		/* формирование ответного сообщения ... */
		break;

	case IMMPC_MESSAGE_PACK_gyr3dof_main_calibmatrix_request_cmd_s:
		/* формирование ответного сообщения ... */
		break;

	case IMMPC_MESSAGE_PACK_gyr3dof_reserve_calibmatrix_request_cmd_s:
		/* формирование ответного сообщения ... */
		break;

	case IMMPC_MESSAGE_PACK_mag3dof_calibmatrix_request_cmd_s:
		/* формирование ответного сообщения ... */
		break;

	case IMMPC_MESSAGE_PACK_mag3dof_raw_request_cmd_s:
		/* формирование ответного сообщения ... */
		break;

	case IMMPC_MESSAGE_PACK_mag3dof_calib_request_cmd_s:
		/* формирование ответного сообщения ... */
		break;

	case IMMPC_MESSAGE_PACK_write_all_calibmatrix_in_eeprom_cmd_s:
		/* формирование ответного сообщения ... */
		/* установка события для записи в EEPROM ... */
		break;
	}
}


/*#### |End  | <-- Секция - "Описание глобальных функций" ####################*/


/*#### |Begin| --> Секция - "Описание локальных функций" #####################*/
/*#### |End  | <-- Секция - "Описание локальных функций" #####################*/


/*#### |Begin| --> Секция - "Обработчики прерываний" #########################*/
/*#### |End  | <-- Секция - "Обработчики прерываний" #########################*/

/*############################################################################*/
/*############################ END OF FILE  ##################################*/
/*############################################################################*/
