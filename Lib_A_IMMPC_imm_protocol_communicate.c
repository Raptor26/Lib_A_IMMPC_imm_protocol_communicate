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

static
immpc_pointer_data_s
IMMPC_pointerSetData_s;

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

/* Пакеты запросов и команд -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

static uint16_t
IMMPC_GetCRC_request_or_cmd(
	immpc_request_or_cmd_pack_s *pPack_s);

static void
IMMPC_WriteCRC_request_or_cmd(
	immpc_request_or_cmd_pack_s *pPack_s);

static size_t
IMMPC_IsPackValid_request_or_cmd(
	immpc_request_or_cmd_pack_s *pPack_s);

/* Пакет запросов и команд --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

static void
IMMPC_SetDataMessageToStruct(
	uint8_t *pData,
	void *pStruct,
	size_t structSize);

static size_t
IMMPC_GenerateResponseMessage(
	uint8_t *pData,
	immpc_message_id_e idResponse);

static size_t
IMMPC_GenerateDataMessageFromStruct(
	uint8_t *pData,
	void *pStruct,
	size_t structSize);

/*#### |End  | <-- Секция - "Прототипы локальных функций" ####################*/


/*#### |Begin| --> Секция - "Описание глобальных функций" ####################*/
/*-------------------------------------------------------------------------*//**
 * @author	Dmitry Tanikeev
 * @date	08-ноя-2019
 *
 * @brief	Функция выполняет сохранение указателей на структуры для ответных сообщений
 *
 * @param[in]	pointerSetData_s: Структура указателей на переменные
 */

/* Не правильно, в данном случае в функцию нужно передавать не структуру, а указатель
 * на структуру, т.к. в противном случае при выходе из функции IMMPC_PointerDataInit()
 * структура pointerSetData_s будет уничтожена */
void
IMMPC_PointerDataInit(
	immpc_pointer_data_s pointerSetData_s)
{
	/* сохранение структуры указателей */
	IMMPC_pointerSetData_s = pointerSetData_s;

	/* заполнение "шапки" пакетов */
	if (IMMPC_pointerSetData_s.pIMMPC_9DOF_main_raw_pack_s != NULL)
	{
		((*(IMMPC_pointerSetData_s.pIMMPC_9DOF_main_raw_pack_s)).headMessage_s).startFrame = IMMPC_START_FRAME;
		((*(IMMPC_pointerSetData_s.pIMMPC_9DOF_main_raw_pack_s)).headMessage_s).messageID = IMMPC_MESSAGE_ID_9DOF_PACK_MAIN;
		((*(IMMPC_pointerSetData_s.pIMMPC_9DOF_main_raw_pack_s)).headMessage_s).packRequests = (uint8_t) 0u;
	}

	if (IMMPC_pointerSetData_s.pIMMPC_9DOF_main_calib_pack_s != NULL)
	{
		((*(IMMPC_pointerSetData_s.pIMMPC_9DOF_main_calib_pack_s)).headMessage_s).startFrame = IMMPC_START_FRAME;
		((*(IMMPC_pointerSetData_s.pIMMPC_9DOF_main_calib_pack_s)).headMessage_s).messageID = IMMPC_MESSAGE_ID_9DOF_PACK_MAIN;
		((*(IMMPC_pointerSetData_s.pIMMPC_9DOF_main_calib_pack_s)).headMessage_s).packRequests = (uint8_t) IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS;
	}

	if (IMMPC_pointerSetData_s.pIMMPC_9DOF_reserve_raw_pack_s != NULL)
	{
		((*(IMMPC_pointerSetData_s.pIMMPC_9DOF_reserve_raw_pack_s)).headMessage_s).startFrame = IMMPC_START_FRAME;
		((*(IMMPC_pointerSetData_s.pIMMPC_9DOF_reserve_raw_pack_s)).headMessage_s).messageID = IMMPC_MESSAGE_ID_9DOF_PACK_RESERVE;
		((*(IMMPC_pointerSetData_s.pIMMPC_9DOF_reserve_raw_pack_s)).headMessage_s).packRequests = (uint8_t) IMMPC_PACK_REQUESTS_BITS_RESERVE_MEAS;
	}

	if (IMMPC_pointerSetData_s.pIMMPC_9DOF_reserve_calib_pack_s != NULL)
	{
		((*(IMMPC_pointerSetData_s.pIMMPC_9DOF_reserve_calib_pack_s)).headMessage_s).startFrame = IMMPC_START_FRAME;
		((*(IMMPC_pointerSetData_s.pIMMPC_9DOF_reserve_calib_pack_s)).headMessage_s).messageID = IMMPC_MESSAGE_ID_9DOF_PACK_RESERVE;
		((*(IMMPC_pointerSetData_s.pIMMPC_9DOF_reserve_calib_pack_s)).headMessage_s).packRequests =	(uint8_t) (
					IMMPC_PACK_REQUESTS_BITS_RESERVE_MEAS |
					IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS);
	}

	if (IMMPC_pointerSetData_s.pIMMPC_MAG3DOF_raw_pack_s != NULL)
	{
		((*(IMMPC_pointerSetData_s.pIMMPC_MAG3DOF_raw_pack_s)).headMessage_s).startFrame = IMMPC_START_FRAME;
		((*(IMMPC_pointerSetData_s.pIMMPC_MAG3DOF_raw_pack_s)).headMessage_s).messageID = IMMPC_MESSAGE_ID_MAG3DOF_PACK;
		((*(IMMPC_pointerSetData_s.pIMMPC_MAG3DOF_raw_pack_s)).headMessage_s).packRequests = (uint8_t) 0u;
	}

	if (IMMPC_pointerSetData_s.pIMMPC_MAG3DOF_calib_pack_s != NULL)
	{
		((*(IMMPC_pointerSetData_s.pIMMPC_MAG3DOF_calib_pack_s)).headMessage_s).startFrame = IMMPC_START_FRAME;
		((*(IMMPC_pointerSetData_s.pIMMPC_MAG3DOF_calib_pack_s)).headMessage_s).messageID = IMMPC_MESSAGE_ID_MAG3DOF_PACK;
		((*(IMMPC_pointerSetData_s.pIMMPC_MAG3DOF_calib_pack_s)).headMessage_s).packRequests = (uint8_t) IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS;
	}

	if (IMMPC_pointerSetData_s.pIMMPC_ACC3DOF_main_calibmatrix_pack_s != NULL)
	{
		((*(IMMPC_pointerSetData_s.pIMMPC_ACC3DOF_main_calibmatrix_pack_s)).headMessage_s).startFrame = IMMPC_START_FRAME;
		((*(IMMPC_pointerSetData_s.pIMMPC_ACC3DOF_main_calibmatrix_pack_s)).headMessage_s).messageID = IMMPC_MESSAGE_ID_ACC3DOF_CALIBMATRIX;
		((*(IMMPC_pointerSetData_s.pIMMPC_ACC3DOF_main_calibmatrix_pack_s)).headMessage_s).packRequests = (uint8_t) IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS;
	}

	if (IMMPC_pointerSetData_s.pIMMPC_ACC3DOF_reserve_calibmatrix_pack_s != NULL)
	{
		((*(IMMPC_pointerSetData_s.pIMMPC_ACC3DOF_reserve_calibmatrix_pack_s)).headMessage_s).startFrame = IMMPC_START_FRAME;
		((*(IMMPC_pointerSetData_s.pIMMPC_ACC3DOF_reserve_calibmatrix_pack_s)).headMessage_s).messageID = IMMPC_MESSAGE_ID_ACC3DOF_CALIBMATRIX;
		((*(IMMPC_pointerSetData_s.pIMMPC_ACC3DOF_reserve_calibmatrix_pack_s)).headMessage_s).packRequests =	(uint8_t) (
					IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS |
					IMMPC_PACK_REQUESTS_BITS_RESERVE_MEAS);
	}

	if (IMMPC_pointerSetData_s.pIMMPC_GYR3DOF_main_calibmatrix_pack_s != NULL)
	{
		((*(IMMPC_pointerSetData_s.pIMMPC_GYR3DOF_main_calibmatrix_pack_s)).headMessage_s).startFrame = IMMPC_START_FRAME;
		((*(IMMPC_pointerSetData_s.pIMMPC_GYR3DOF_main_calibmatrix_pack_s)).headMessage_s).messageID = IMMPC_MESSAGE_ID_GYR3DOF_CALIBMATRIX;
		((*(IMMPC_pointerSetData_s.pIMMPC_GYR3DOF_main_calibmatrix_pack_s)).headMessage_s).packRequests =	(uint8_t) IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS;
	}

	if (IMMPC_pointerSetData_s.pIMMPC_GYR3DOF_reserve_calibmatrix_pack_s != NULL)
	{
		((*(IMMPC_pointerSetData_s.pIMMPC_GYR3DOF_reserve_calibmatrix_pack_s)).headMessage_s).startFrame = IMMPC_START_FRAME;
		((*(IMMPC_pointerSetData_s.pIMMPC_GYR3DOF_reserve_calibmatrix_pack_s)).headMessage_s).messageID = IMMPC_MESSAGE_ID_GYR3DOF_CALIBMATRIX;
		((*(IMMPC_pointerSetData_s.pIMMPC_GYR3DOF_reserve_calibmatrix_pack_s)).headMessage_s).packRequests =	(uint8_t) (
					IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS |
					IMMPC_PACK_REQUESTS_BITS_RESERVE_MEAS);
	}

	if (IMMPC_pointerSetData_s.pIMMPC_MAG3DOF_calibmatrix_pack_s != NULL)
	{
		((*(IMMPC_pointerSetData_s.pIMMPC_MAG3DOF_calibmatrix_pack_s)).headMessage_s).startFrame = IMMPC_START_FRAME;
		((*(IMMPC_pointerSetData_s.pIMMPC_MAG3DOF_calibmatrix_pack_s)).headMessage_s).messageID = IMMPC_MESSAGE_ID_MAG3DOF_CALIBMATRIX;
		((*(IMMPC_pointerSetData_s.pIMMPC_MAG3DOF_calibmatrix_pack_s)).headMessage_s).packRequests =	(uint8_t) (
					IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS);
	}
}

/*-------------------------------------------------------------------------*//**
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция выполняет поиск типа сообщения
 *
 * @param[in]	*pData: 	Указатель на область памяти, в которой содержатся
 * 							данные
 *
 * @param[in]	buffSize: 	Количество данных
 *
 * @param[out]	pMessageHead: 	Адрес "головы" сообщения
 *
 * @return	Тип сообщения (см. immpc_message_pack_type_e)
 */
immpc_message_pack_type_e
IMMPC_GetTypeMessage(
	const uint8_t 	*pData,
	size_t 			buffSize,
	uint8_t 		*pMessageHead)
{
	/* присвоение стартовых значений */
	immpc_message_pack_type_e messageType_e = IMMPC_MESSAGE_PACK_UNKNOWN;

	/* Установка адреса в NULL */
	pMessageHead = NULL;

	/* Минимальное количество данных необходимое для поиска */
	if (buffSize < ((size_t) 4u))
	{
		/* выход из функции */
		return (messageType_e);
	}

	size_t j;
	for (j = 0u; j < buffSize; j++)
	{
		/* Указатель на область памяти, в которой должны быть символы начала
		 * пакета данных и ID сообщения */
		uint16_t *pStartFrame 	= (uint16_t*) &pData[j];
		// uint16_t *pIDAndPackReq = (uint16_t*) &pData[j + 2u];

		/* Если нашли символы начала пакета данных */
		if (*pStartFrame == IMMPC_START_FRAME)
		{
			messageType_e = (immpc_message_pack_type_e) pData[j + 2u];

			/* Установка адреса "головы" сообщения */
			pMessageHead = (uint8_t*) pStartFrame;

			/* Выход из цикла for (Пакет нашли, разобрали его тип, не нужно
			 * тратить драгоценное время контроллера на попытку найти еще один) */
			break;
		}
	}

	/* выход */
	return (messageType_e);
}

/*-------------------------------------------------------------------------*//**
 * @author	Mickle Isaev
 * @date	01-ноя-2019
 *
 * @brief	Функция вычисляет контрольную сумму
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
 * @author	Mickle Isaev
 * @date	01-ноя-2019
 *
 * @brief	Функция выполняет вычисление контрольной суммы пакета данных
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
 * @author	Mickle Isaev
 * @date	01-ноя-2019
 *
 * @brief	Функция выполняет запись контрольной суммы пакета данных
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
 * @author	Mickle Isaev
 * @date	01-ноя-2019
 *
 * @brief	Функция проверяет валидность пакета данных
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция выполняет вычисление контрольной суммы пакета данных (калиброванных)
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция выполняет запись контрольной суммы пакета данных (калиброванных)
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция проверяет валидность пакета данных (калиброванных)
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция выполняет вычисление контрольной суммы пакета данных
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция выполняет запись контрольной суммы пакета данных
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция проверяет валидность пакета данных
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция выполняет вычисление контрольной суммы пакета данных (калиброванных)
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция выполняет запись контрольной суммы пакета данных (калиброванных)
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция проверяет валидность пакета данных (калиброванных)
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция выполняет вычисление контрольной суммы пакета данных
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция выполняет запись контрольной суммы пакета данных
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция проверяет валидность пакета данных
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция выполняет вычисление контрольной суммы пакета данных (калиброванных)
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция выполняет запись контрольной суммы пакета данных (калиброванных)
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция проверяет валидность пакета данных (калиброванных)
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция выполняет вычисление контрольной суммы пакета данных (калиброванных)
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция выполняет запись контрольной суммы пакета данных (калиброванных)
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция проверяет валидность пакета данных (калиброванных)
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция выполняет вычисление контрольной суммы пакета данных (калиброванных)
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция выполняет запись контрольной суммы пакета данных (калиброванных)
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция проверяет валидность пакета данных (калиброванных)
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция выполняет вычисление контрольной суммы пакета данных (калиброванных)
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция выполняет запись контрольной суммы пакета данных (калиброванных)
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция проверяет валидность пакета данных (калиброванных)
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция выполняет вычисление контрольной суммы пакета данных (калиброванных)
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция выполняет запись контрольной суммы пакета данных (калиброванных)
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция проверяет валидность пакета данных (калиброванных)
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция выполняет вычисление контрольной суммы пакета данных (калиброванных)
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция выполняет запись контрольной суммы пакета данных (калиброванных)
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
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция проверяет валидность пакета данных (калиброванных)
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

/* Пакеты запросов и команд -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

/*-------------------------------------------------------------------------*//**
 * @author	Dmitry Tanikeev
 * @date	08-ноя-2019
 *
 * @brief	Функция выполняет вычисление контрольной суммы пакета данных (калиброванных)
 *
 * @param[in]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 							пакет данных
 *
 * @return 	Вычисленная сумма пакета данных
 */
static uint16_t
IMMPC_GetCRC_request_or_cmd(
	immpc_request_or_cmd_pack_s *pPack_s)
{
	return (IMMPC_GetCRC_Generic(
				(uint8_t*) pPack_s,
				(uint16_t) (sizeof(immpc_request_or_cmd_pack_s))));
}

/*-------------------------------------------------------------------------*//**
 * @author	Dmitry Tanikeev
 * @date	08-ноя-2019
 *
 * @brief	Функция выполняет запись контрольной суммы пакета данных (калиброванных)
 *
 * @param[in,out]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 								пакет данных.
 * 								@note 	Контрольная сумма записывается в конец
 * 										пакета данных
 */
static void
IMMPC_WriteCRC_request_or_cmd(
	immpc_request_or_cmd_pack_s *pPack_s)
{
	pPack_s->crc =
		IMMPC_GetCRC_Generic(
			(uint8_t*) pPack_s,
			(uint16_t) (sizeof(immpc_request_or_cmd_pack_s)));
}

/*-------------------------------------------------------------------------*//**
 * @author	Dmitry Tanikeev
 * @date	08-ноя-2019
 *
 * @brief	Функция проверяет валидность пакета данных (калиброванных)
 *
 * @param[in]	*pPack_s: 	Указатель на область памяти, в которой содержится
 * 							пакет данных.
 *
 * @return 	Если пакет данных валиден, то возвращает "1", иначе "0"
 */
static size_t
IMMPC_IsPackValid_request_or_cmd(
	immpc_request_or_cmd_pack_s *pPack_s)
{
	uint16_t crc =
		IMMPC_GetCRC_request_or_cmd(pPack_s);

	if (crc == pPack_s->crc)
	{
		return (1u);
	}
	else
	{
		return (0u);
	}
}


/* Пакет запросов и команд --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/*-------------------------------------------------------------------------*//**
 * @author	Dmitry Tanikeev
 * @date	07-ноя-2019
 *
 * @brief	Функция заполняет структуру
 *
 * @param[in]	*pData: 	Указатель на область памяти, в которой содержатся
 * 							данные
 *
 * @param[out]	*pStruct: 	Указатель на область памяти, в которой содержится
 * 							структура данных
 *
 * @param[in]	structSize: Размерность структуры
 */
static void
IMMPC_SetDataMessageToStruct(
	uint8_t *pData,
	void *pStruct,
	size_t structSize)
{
	uint8_t *pDataStruct = (uint8_t*) pStruct;

	/* сохранение данных */
	size_t i;
	for (i = 0; i < structSize; i++)
	{
		*pDataStruct++ = *pData++;
	}
}

/*-------------------------------------------------------------------------*//**
 * @author	Dmitry Tanikeev
 * @date	08-ноя-2019
 *
 * @brief	Функция формирует простой ответ (OK, ERROR. INVALID...)
 *
 * @param[out]	*pData: 	Указатель на область памяти, в которой будут содержаться
 * 							данные
 *
 * @param[out]	idResponse: Идентификатор сообщения
 *
 * @return Количество байт данных
 */
static size_t
IMMPC_GenerateResponseMessage(
	uint8_t *pData,
	immpc_message_id_e idResponse)
{
	*pData++ =	(uint8_t) ((IMMPC_START_FRAME & 0xFF00) >> 8u);
	*pData++ =	(uint8_t) (IMMPC_START_FRAME & 0x00FF);
	*pData++ =	(uint8_t) idResponse;
	*pData =	IMMPC_RESPONCE_END_FRAME;

	return ((size_t) 4u);
}

/*-------------------------------------------------------------------------*//**
 * @author	Dmitry Tanikeev
 * @date	08-ноя-2019
 *
 * @brief	Функция формирует ответ на запрос
 *
 * @param[out]	*pData: 	Указатель на область памяти, в которой будут содержаться
 * 							данные
 *
 * @param[in]	*pStruct: 	Указатель на область памяти, в которой содержится
 * 							структура данных
 *
 * @param[in]	structSize: Размерность структуры
 *
 * @return Количество байт данных
 */
static size_t
IMMPC_GenerateDataMessageFromStruct(
	uint8_t *pData,
	void *pStruct,
	size_t structSize)
{
	uint8_t *pDataStruct = (uint8_t*) pStruct;

	/* сохранение данных */
	size_t i;
	for (i = 0; i < structSize; i++)
	{
		*pData++ = *pDataStruct++;
	}

	return (structSize);
}

/*-------------------------------------------------------------------------*//**
 * @author	Dmitry Tanikeev
 * @date	05-ноя-2019
 *
 * @brief	Функция получает пакет данных,
 * 			если пакет данных содержит полезную часть, то данные записываются в соответствующую структуру,
 * 			если пакет содержит запрос или команду, то формируется ответ.
 * 			Ответ может быть как с полезными данными так и без них (т.е. OK, ERROR, INVALID).
 * 			Функция возвращет тип полученного пакета, который сформировани из двух полей пакета сообщения - Message ID и Pack requests.
 *
 * @param[in]	*pDataIn: 	Указатель на область памяти, в которой содержатся входной пакет данных.
 *
 * @param[in]	buffSize: 	Размер данных.
 *
 * @param[in]	*pIMMPC_Data_s:	Указатель на область памяти, в которой содержатся данные с датчиков.

 * @param[out]	*pDataOut:	Указатель на область памяти, в которой будут содержаться данные
 * 							для выходного пакета
 *
 * @param[out]	*pLengthOut:	Количество данных для выходного пакета
 *
 * @return	Тип сообщения (см. immpc_message_pack_type_e)
 */
immpc_message_pack_type_e
IMMPC_GetDataMessage(
	uint8_t *pDataIn,
	size_t 	buffSize,
	immpc_meas_data_tmp_s *pIMMPC_Data_s,
	uint8_t *pDataOut,
	size_t 	*pLengthOut)
{
	/* тип выходного ссобщения */
	immpc_message_pack_type_e messageTypeReturn_e;

	/* указатель на структуру  */
	uint8_t *pDataStruct;

	/* сброс длины выходного массива */
	*pLengthOut = (size_t) 0u;

	uint8_t *pMessHeadAddr;

	/* получение типа сообщения */
	messageTypeReturn_e =
		IMMPC_GetTypeMessage(
			pDataIn,
			buffSize,
			pMessHeadAddr);

	/* тип сообщения определен? */
	if (messageTypeReturn_e != IMMPC_MESSAGE_PACK_UNKNOWN)
	{
		return (messageTypeReturn_e);
	}

	/* обработка по типу сообщения */
	switch (messageTypeReturn_e)
	{
	case IMMPC_MESSAGE_PACK_9dof_main_raw_pack_s:
		/* проверка количества символов и правильности CRC */
		if (	(buffSize >= (size_t) (sizeof(immpc_9dof_main_raw_pack_s))) &&
				(IMMPC_IsPackValid_9dof_main_raw_pack((immpc_9dof_main_raw_pack_s*) pMessHeadAddr)))
		{
			/* запись новых данных в структуру */
			IMMPC_SetDataMessageToStruct(
				pMessHeadAddr,
				&IMMPC_9DOF_main_raw_pack_s,
				sizeof(immpc_9dof_main_raw_pack_s));
		}
		else
		{
			messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_9dof_main_calib_pack_s:
		/* проверка количества символов и правильности CRC */
		if (	(buffSize >= (size_t) (sizeof(immpc_9dof_main_calib_pack_s))) &&
				(IMMPC_IsPackValid_9dof_main_calib_pack((immpc_9dof_main_calib_pack_s*) pMessHeadAddr)))
		{
			/* запись новых данных в структуру */
			IMMPC_SetDataMessageToStruct(
				pMessHeadAddr,
				&IMMPC_9DOF_main_calib_pack_s,
				sizeof(immpc_9dof_main_calib_pack_s));
		}
		else
		{
			messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_9dof_reserve_raw_pack_s:
		/* проверка количества символов и правильности CRC */
		if (	(buffSize >= (size_t) (sizeof(immpc_9dof_reserve_raw_pack_s))) &&
				(IMMPC_IsPackValid_9dof_reserve_raw_pack((immpc_9dof_reserve_raw_pack_s*) pMessHeadAddr)))
		{
			/* запись новых данных в структуру */
			IMMPC_SetDataMessageToStruct(
				pMessHeadAddr,
				&IMMPC_9DOF_reserve_raw_pack_s,
				sizeof(immpc_9dof_reserve_raw_pack_s));
		}
		else
		{
			messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_9dof_reserve_calib_pack_s:
		/* проверка количества символов и правильности CRC */
		if (	(buffSize >= (size_t) (sizeof(immpc_9dof_reserve_calib_pack_s))) &&
				(IMMPC_IsPackValid_9dof_reserve_calib_pack((immpc_9dof_reserve_calib_pack_s*) pMessHeadAddr)))
		{
			/* запись новых данных в структуру */
			IMMPC_SetDataMessageToStruct(
				pMessHeadAddr,
				&IMMPC_9DOF_reserve_calib_pack_s,
				sizeof(immpc_9dof_reserve_calib_pack_s));
		}
		else
		{
			messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_mag3dof_raw_pack_s:
		/* проверка количества символов и правильности CRC */
		if (	(buffSize >= (size_t) (sizeof(immpc_mag3dof_raw_pack_s))) &&
				(IMMPC_IsPackValid_mag3dof_raw_pack((immpc_mag3dof_raw_pack_s*) pMessHeadAddr)))
		{
			/* запись новых данных в структуру */
			IMMPC_SetDataMessageToStruct(
				pMessHeadAddr,
				&IMMPC_MAG3DOF_raw_pack_s,
				sizeof(immpc_mag3dof_raw_pack_s));
		}
		else
		{
			messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_mag3dof_calib_pack_s:
		/* проверка количества символов и правильности CRC */
		if (	(buffSize >= (size_t) (sizeof(immpc_mag3dof_calib_pack_s))) &&
				(IMMPC_IsPackValid_mag3dof_calib_pack((immpc_mag3dof_calib_pack_s*) pMessHeadAddr)))
		{
			/* запись новых данных в структуру */
			IMMPC_SetDataMessageToStruct(
				pMessHeadAddr,
				&IMMPC_MAG3DOF_calib_pack_s,
				sizeof(immpc_mag3dof_calib_pack_s));
		}
		else
		{
			messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_acc3dof_main_calibmatrix_write_pack_s:
		/* проверка количества символов */
		if (buffSize >= (size_t) (sizeof(immpc_acc3dof_main_calibmatrix_pack_s)))
		{
			/* CRC правильный */
			if (IMMPC_IsPackValid_acc3dof_main_calibmatrix_pack((immpc_acc3dof_main_calibmatrix_pack_s*) pMessHeadAddr))
			{
				IMMPC_SetDataMessageToStruct(
					pMessHeadAddr,
					&IMMPC_ACC3DOF_main_calibmatrix_pack_s,
					sizeof(immpc_acc3dof_main_calibmatrix_pack_s));

				/* формироваие ответа - OK */
				*pLengthOut =
					IMMPC_GenerateResponseMessage(
						pDataOut,
						IMMPC_MESSAGE_ID_RESPONSE_CODE_OK);

			}
			else
			{
				/* формирование ответа - INVALID_CRC */
				*pLengthOut =
					IMMPC_GenerateResponseMessage(
						pDataOut,
						IMMPC_MESSAGE_ID_RESPONSE_CODE_INVALID_CRC);

				messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
			}
		}
		else
		{
			/* формироваие ответа - ERROR */
			*pLengthOut =
				IMMPC_GenerateResponseMessage(
					pDataOut,
					IMMPC_MESSAGE_ID_RESPONSE_CODE_ERROR);

			messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_acc3dof_main_calibmatrix_read_pack_s:
		/* */
		break;

	case IMMPC_MESSAGE_PACK_acc3dof_reserve_calibmatrix_write_pack_s:
		/* проверка количества символов */
		if (buffSize >= (size_t) (sizeof(immpc_acc3dof_reserve_calibmatrix_pack_s)))
		{
			/* CRC правильный */
			if (IMMPC_IsPackValid_acc3dof_reserve_calibmatrix_pack((immpc_acc3dof_reserve_calibmatrix_pack_s*) pMessHeadAddr))
			{
				IMMPC_SetDataMessageToStruct(
					pMessHeadAddr,
					&IMMPC_ACC3DOF_reserve_calibmatrix_pack_s,
					sizeof(immpc_acc3dof_reserve_calibmatrix_pack_s));

				/* формироваие ответа - OK */
				*pLengthOut =
					IMMPC_GenerateResponseMessage(
						pDataOut,
						IMMPC_MESSAGE_ID_RESPONSE_CODE_OK);

			}
			else
			{
				/* формирование ответа - INVALID_CRC */
				*pLengthOut =
					IMMPC_GenerateResponseMessage(
						pDataOut,
						IMMPC_MESSAGE_ID_RESPONSE_CODE_INVALID_CRC);

				messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
			}
		}
		else
		{
			/* формироваие ответа - ERROR */
			*pLengthOut =
				IMMPC_GenerateResponseMessage(
					pDataOut,
					IMMPC_MESSAGE_ID_RESPONSE_CODE_ERROR);

			messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_acc3dof_reserve_calibmatrix_read_pack_s:
		/* */
		break;

	case IMMPC_MESSAGE_PACK_gyr3dof_main_calibmatrix_write_pack_s:
		/* проверка количества символов */
		if (buffSize >= (size_t) (sizeof(immpc_gyr3dof_main_calibmatrix_pack_s)))
		{
			/* CRC правильный */
			if (IMMPC_IsPackValid_gyr3dof_main_calibmatrix_pack((immpc_gyr3dof_main_calibmatrix_pack_s*) pMessHeadAddr))
			{
				IMMPC_SetDataMessageToStruct(
					pMessHeadAddr,
					&IMMPC_GYR3DOF_main_calibmatrix_pack_s,
					sizeof(immpc_gyr3dof_main_calibmatrix_pack_s));

				/* формироваие ответа - OK */
				*pLengthOut =
					IMMPC_GenerateResponseMessage(
						pDataOut,
						IMMPC_MESSAGE_ID_RESPONSE_CODE_OK);

			}
			else
			{
				/* формирование ответа - INVALID_CRC */
				*pLengthOut =
					IMMPC_GenerateResponseMessage(
						pDataOut,
						IMMPC_MESSAGE_ID_RESPONSE_CODE_INVALID_CRC);

				messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
			}
		}
		else
		{
			/* формироваие ответа - ERROR */
			*pLengthOut =
				IMMPC_GenerateResponseMessage(
					pDataOut,
					IMMPC_MESSAGE_ID_RESPONSE_CODE_ERROR);

			messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_gyr3dof_main_calibmatrix_read_pack_s:
		/* */
		break;

	case IMMPC_MESSAGE_PACK_gyr3dof_reserve_calibmatrix_write_pack_s:
		/* проверка количества символов */
		if (buffSize >= (size_t) (sizeof(immpc_gyr3dof_reserve_calibmatrix_pack_s)))
		{
			/* CRC правильный */
			if (IMMPC_IsPackValid_gyr3dof_reserve_calibmatrix_pack((immpc_gyr3dof_reserve_calibmatrix_pack_s*) pMessHeadAddr))
			{
				IMMPC_SetDataMessageToStruct(
					pMessHeadAddr,
					&IMMPC_GYR3DOF_reserve_calibmatrix_pack_s,
					sizeof(immpc_gyr3dof_reserve_calibmatrix_pack_s));

				/* формироваие ответа - OK */
				*pLengthOut =
					IMMPC_GenerateResponseMessage(
						pDataOut,
						IMMPC_MESSAGE_ID_RESPONSE_CODE_OK);

			}
			else
			{
				/* формирование ответа - INVALID_CRC */
				*pLengthOut =
					IMMPC_GenerateResponseMessage(
						pDataOut,
						IMMPC_MESSAGE_ID_RESPONSE_CODE_INVALID_CRC);

				messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
			}
		}
		else
		{
			/* формироваие ответа - ERROR */
			*pLengthOut =
				IMMPC_GenerateResponseMessage(
					pDataOut,
					IMMPC_MESSAGE_ID_RESPONSE_CODE_ERROR);

			messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_gyr3dof_reserve_calibmatrix_read_pack_s:
		/* */
		break;

	case IMMPC_MESSAGE_PACK_mag3dof_calibmatrix_write_pack_s:
		/* проверка количества символов */
		if (buffSize >= (size_t) (sizeof(immpc_mag3dof_calibmatrix_pack_s)))
		{
			/* CRC правильный */
			if (IMMPC_IsPackValid_mag3dof_calibmatrix_pack((immpc_mag3dof_calibmatrix_pack_s*) pMessHeadAddr))
			{
				IMMPC_SetDataMessageToStruct(
					pMessHeadAddr,
					&IMMPC_MAG3DOF_calibmatrix_pack_s,
					sizeof(immpc_mag3dof_calibmatrix_pack_s));

				/* формироваие ответа - OK */
				*pLengthOut =
					IMMPC_GenerateResponseMessage(
						pDataOut,
						IMMPC_MESSAGE_ID_RESPONSE_CODE_OK);

			}
			else
			{
				/* формирование ответа - INVALID_CRC */
				*pLengthOut =
					IMMPC_GenerateResponseMessage(
						pDataOut,
						IMMPC_MESSAGE_ID_RESPONSE_CODE_INVALID_CRC);

				messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
			}
		}
		else
		{
			/* формироваие ответа - ERROR */
			*pLengthOut =
				IMMPC_GenerateResponseMessage(
					pDataOut,
					IMMPC_MESSAGE_ID_RESPONSE_CODE_ERROR);

			messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_mag3dof_calibmatrix_read_pack_s:
		/* */
		break;

	/* запросы */
	case IMMPC_MESSAGE_PACK_9dof_main_raw_request_cmd_s:
		/* формирование ответного сообщения ... */
		/* проверка количества символов */
		if (buffSize >= (size_t) (sizeof(immpc_request_or_cmd_pack_s)))
		{
			/* CRC правильный */
			if (IMMPC_IsPackValid_request_or_cmd((immpc_request_or_cmd_pack_s*) pMessHeadAddr))
			{
				/* формироваие ответа */
				*pLengthOut =
					IMMPC_GenerateDataMessageFromStruct(
						pDataOut,
						IMMPC_pointerSetData_s.pIMMPC_9DOF_main_raw_pack_s,
						sizeof (immpc_9dof_main_raw_pack_s));
			}
			else
			{
				/* формирование ответа - INVALID_CRC */
				*pLengthOut =
					IMMPC_GenerateResponseMessage(
						pDataOut,
						IMMPC_MESSAGE_ID_RESPONSE_CODE_INVALID_CRC);

				messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
			}
		}
		else
		{
			/* формироваие ответа - ERROR */
			*pLengthOut =
				IMMPC_GenerateResponseMessage(
					pDataOut,
					IMMPC_MESSAGE_ID_RESPONSE_CODE_ERROR);

			messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
		}
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

	/* ответ - IMMPC_MESSAGE_ID_RESPONSE_CODE_ERROR */
	case IMMPC_MESSAGE_PACK_response_code_error_s:
		/**/
		break;

	/* ответ - IMMPC_MESSAGE_ID_RESPONSE_CODE_INVALID_CRC */
	case IMMPC_MESSAGE_PACK_response_code_invalid_crc_s:
		/**/
		break;

	/* ответ - IMMPC_MESSAGE_ID_RESPONSE_CODE_INVALID_CALIBRATION_MATRIX_FROM_EEPROM */
	case IMMPC_MESSAGE_PACK_response_code_invalid_calibration_matrix_from_eeprom_s:
		/**/
		break;

	/* ответ - IMMPC_MESSAGE_ID_RESPONSE_CODE_OK */
	case IMMPC_MESSAGE_PACK_response_code_ok_s:
		/**/
		break;

	default:
		/* формирование ответа - INVALID_ID */
		messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
		break;
	}

	return (messageTypeReturn_e);
}

/*#### |End  | <-- Секция - "Описание глобальных функций" ####################*/


/*#### |Begin| --> Секция - "Описание локальных функций" #####################*/
/*#### |End  | <-- Секция - "Описание локальных функций" #####################*/


/*#### |Begin| --> Секция - "Обработчики прерываний" #########################*/
/*#### |End  | <-- Секция - "Обработчики прерываний" #########################*/

/*############################################################################*/
/*############################ END OF FILE  ##################################*/
/*############################################################################*/
