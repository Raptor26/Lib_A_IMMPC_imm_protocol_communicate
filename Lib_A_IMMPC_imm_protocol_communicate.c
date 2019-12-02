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
static immpc_head_s*
IMMPC_GetTypeMessage(
	const uint8_t 	*pData,
	size_t 			buffSize);

static size_t
IMMPC_SetCalibMatrixMessageGeneric(
	immpc_calibmatrix_pack_generic_s 	*pOutputMessage,
	immpc_id_and_pack_requests_e 		idAndPackRequets,
	iscm_calibmatrix_generic_s 			*pCalibMatrix_s);
/*#### |End  | <-- Секция - "Прототипы локальных функций" ####################*/


/*#### |Begin| --> Секция - "Описание глобальных функций" ####################*/

size_t
IMMPC_EXTDEV_SetRequestMessageGeneric(
	immpc_request_cmd_s 			*pOutputData_s,
	immpc_id_and_pack_requests_e 	idAndPackRequests)
{
	pOutputData_s->startFrame 			= IMMPC_START_FRAME;
	pOutputData_s->idAndPackRequests 	= idAndPackRequests;
	pOutputData_s->crc =
		IMMPC_GetCRC_Generic(
			(uint8_t*) pOutputData_s,
			(uint16_t) sizeof(immpc_request_cmd_s));

	return (sizeof(immpc_request_cmd_s));
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
IMMPC_SetResponseMessage(
	immpc_response_cmd_s 	*pOutputMessage,
	immpc_message_id_e 		idResponse)
{
	pOutputMessage->startFrame 	= IMMPC_START_FRAME;
	pOutputMessage->messageID 	= idResponse;
	pOutputMessage->endFrame 	= IMMPC_RESPONCE_END_FRAME;

	return ((size_t) sizeof(immpc_response_cmd_s));
}

static size_t
IMMPC_SetCalibMatrixMessageGeneric(
	immpc_calibmatrix_pack_generic_s 	*pOutputMessage,
	immpc_id_and_pack_requests_e 		idAndPackRequets,
	iscm_calibmatrix_generic_s 			*pCalibMatrix_s)
{
	pOutputMessage->head_s.startFrame 			= IMMPC_START_FRAME;
	pOutputMessage->head_s.idAndPackRequests 	= idAndPackRequets;

	/* Копирование калибровочной матрицы */
	memcpy(
		(void*) &pOutputMessage->calib_s.matrix_a[0u][0u],
		(void*) &pCalibMatrix_s->matrix_a[0u][0u],
		sizeof(iscm_calibmatrix_generic_s));

	/* Вычисление и запись контрольной суммы */
	pOutputMessage->crc =
		IMMPC_GetCRC_Generic(
			(uint8_t*)pOutputMessage,
			(uint16_t) sizeof(immpc_calibmatrix_pack_generic_s));

	return (sizeof(immpc_calibmatrix_pack_generic_s));
}

/*-------------------------------------------------------------------------*//**
 * @author    Mickle Isaev
 * @date      29-ноя-2019
 *
 * @brief  	Функция выполняет разбор принятого от внешнего устройства пакета
 *    		данных и формирует пакет данных, который нужно отправить в качестве ответа
 *
 * @param        pRawSensMeas_s           Необработанный смысл измерения
 * @param        pInputBuff               Входной буфер
 * @param[in]    inputBuffSize            Размер входного буфера
 * @param        pOutBuff
 * @param        pOutBuffByteNumbForTx
 *
 * @return
 */
immpc_id_and_pack_requests_e
IMMPC_ParseInputMessageAndGenerateOutputMessage(
	immpc_meas_raw_data_s 	*pRawSensMeas_s,

	uint8_t 				*pInputBuff,
	uint16_t 				inputBuffSize,

	uint8_t 				*pOutBuff,
	uint16_t 				*pOutBuffByteNumbForTx)
{
	/* Сброс количества байт для передачи */
	*pOutBuffByteNumbForTx = 0u;

	immpc_head_s *pHeadMessage_s = NULL;
	pHeadMessage_s =
		IMMPC_GetTypeMessage(
			pInputBuff,
			inputBuffSize);

	if (pHeadMessage_s == NULL)
	{
		return (0u);
	}

	/* Указатель на сообщения запросов */
	immpc_request_cmd_s *pRequestCmd_s =
		(immpc_request_cmd_s*) pHeadMessage_s;

	switch (pRequestCmd_s->idAndPackRequests)
	{
	/* #### 9dof_main_raw_request_cmd -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
	case (IMMPC_ID_AND_PACK_REQUESTS_9dof_main_raw_request_cmd):
		if (pRequestCmd_s->crc == IMMPC_GetCRC_Generic((uint8_t*) pRequestCmd_s, (uint16_t) sizeof(immpc_request_cmd_s)))
		{
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_Generate_9dof_main_raw_pack(
					pRawSensMeas_s,
					(immpc_9dof_main_raw_pack_s*) pOutBuff);
		}
		else
		{
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetResponseMessage(
					(immpc_response_cmd_s*) pInputBuff,
					IMMPC_MESSAGE_ID_RESPONSE_CODE_INVALID_CRC);
		}
		break;
	/* #### 9dof_main_raw_request_cmd --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */


	/* #### 9dof_reserve_raw_request_cmd -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
	/* Команда на запрос данных "сырых" резервных измерителей */
	case (IMMPC_ID_AND_PACK_REQUESTS_9dof_reserve_raw_request_cmd_e):
		/* Если контрольная сумма верна */
		if (pRequestCmd_s->crc == IMMPC_GetCRC_Generic((uint8_t*) pRequestCmd_s, sizeof(immpc_request_cmd_s)))
		{
			/* Формирование ответного сообщения */
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_Generate_9dof_reserve_raw_pack(
					pRawSensMeas_s,
					(immpc_9dof_reserve_raw_pack_s*) pOutBuff);
		}
		else
		{
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetResponseMessage(
					(immpc_response_cmd_s*) pInputBuff,
					IMMPC_MESSAGE_ID_RESPONSE_CODE_INVALID_CRC);
		}
		break;
	/* #### 9dof_reserve_raw_request_cmd --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */


	default:
		break;
	}

	return (pRequestCmd_s->idAndPackRequests);
}

/*-------------------------------------------------------------------------*//**
 * @author		Dmitry Tanikeev
 * @date		27-ноя-2019
 *
 * @brief		Функция формирует пакет для отправки "сырых" данных основных
 * 				измерителей
 *
 * @param[in]	*pSourceData_s:	Указатель на область памяти, в которой храняться
 * 									"сырые" данные
 *
 * @param[out]	*pPackForTx_s: 	Указатель на область памяти, в которой будут
 * 							содержаться данные
 * 							@note 	Контрольная сумма записывается в конец
 * 									пакета данных
 *
 * @return		Длина пакета в байтах
 */
size_t
IMMPC_Generate_9dof_main_raw_pack(
	immpc_meas_raw_data_s 		*pSourceData_s,
	immpc_9dof_main_raw_pack_s	*pPackForTx_s)
{
	/* запись стартовых байт (Start frame) */
	pPackForTx_s->head_s.startFrame = IMMPC_START_FRAME;

	/* ID и Pack requests */
	pPackForTx_s->head_s.idAndPackRequests =
		IMMPC_ID_AND_PACK_REQUESTS_9dof_main_raw_pack_e;

	/* запись статусов сенсора (Sensors status) */
	__IMMPC_WRITE_REG(
		/* Переменная для записи битовых масок */
		pPackForTx_s->head_s.sensorsStatus,

		/* Битовые маски для записи в переменную */
		pSourceData_s->dataMainAccGyr.sensorStatus |
		pSourceData_s->dataMag.sensorStatus);

	/* сброс статусов сенсора */
	pSourceData_s->dataMainAccGyr.sensorStatus 	= 0u;
	pSourceData_s->dataMag.sensorStatus 		= 0u;

	/* Запись измерений акселерометра */
	pPackForTx_s->acc_a[0u] = pSourceData_s->dataMainAccGyr.rawMainAcc_a[0u];
	pPackForTx_s->acc_a[1u] = pSourceData_s->dataMainAccGyr.rawMainAcc_a[1u];
	pPackForTx_s->acc_a[2u] = pSourceData_s->dataMainAccGyr.rawMainAcc_a[2u];

	/* Запись измерений температуры акселерометра */
	pPackForTx_s->accTemp_a[0u] = pSourceData_s->dataMainAccGyr.rawMainTempAcc_a[0u];
	pPackForTx_s->accTemp_a[1u] = pSourceData_s->dataMainAccGyr.rawMainTempAcc_a[1u];
	pPackForTx_s->accTemp_a[2u] = pSourceData_s->dataMainAccGyr.rawMainTempAcc_a[2u];

	/* Запись измерений 3-х осей гироскопа (сырые данные) */
	pPackForTx_s->gyr_a[0u] = pSourceData_s->dataMainAccGyr.rawMainGyr_a[0u];
	pPackForTx_s->gyr_a[1u] = pSourceData_s->dataMainAccGyr.rawMainGyr_a[1u];
	pPackForTx_s->gyr_a[2u] = pSourceData_s->dataMainAccGyr.rawMainGyr_a[2u];

	/* Запись измерений температуры гироскопа */
	pPackForTx_s->gyrTemp_a[0u] = pSourceData_s->dataMainAccGyr.rawMainTempGyr_a[0u];
	pPackForTx_s->gyrTemp_a[1u] = pSourceData_s->dataMainAccGyr.rawMainTempGyr_a[1u];
	pPackForTx_s->gyrTemp_a[2u] = pSourceData_s->dataMainAccGyr.rawMainTempGyr_a[2u];

	/* Запись измерений 3-х осей магнитометра (сырые данные) */
	pPackForTx_s->mag_a[0u] = pSourceData_s->dataMag.rawMag_a[0u];
	pPackForTx_s->mag_a[1u] = pSourceData_s->dataMag.rawMag_a[1u];
	pPackForTx_s->mag_a[2u] = pSourceData_s->dataMag.rawMag_a[2u];

	/* Запись измерений температуры гироскопа */
	pPackForTx_s->magSelfTest_a[0u] = pSourceData_s->dataMag.rawMagSelfTest[0u];
	pPackForTx_s->magSelfTest_a[1u] = pSourceData_s->dataMag.rawMagSelfTest[1u];
	pPackForTx_s->magSelfTest_a[2u] = pSourceData_s->dataMag.rawMagSelfTest[2u];

	/* расчет CRC */
	pPackForTx_s->crc =
		(uint16_t) IMMPC_GetCRC_Generic(
			(uint8_t*) pPackForTx_s,
			(uint16_t) sizeof(immpc_9dof_main_raw_pack_s));

	return (sizeof(immpc_9dof_main_raw_pack_s));
}

/*-------------------------------------------------------------------------*//**
 * @author		Dmitry Tanikeev
 * @date		27-ноя-2019
 *
 * @brief		Функция формирует пакет для отправки "сырых" данных резервных
 * 				измерителей
 *
 * @param[in]	*pSourceData_s:	Указатель на область памяти, в которой храняться
 * 									"сырые" данные
 *
 * @param[out]	*pPackForTx_s: 	Указатель на область памяти, в которой будут
 * 							содержаться данные
 * 							@note 	Контрольная сумма записывается в конец
 * 									пакета данных
 *
 * @return		Длина пакета в байтах
 */
size_t
IMMPC_Generate_9dof_reserve_raw_pack(
	immpc_meas_raw_data_s 			*pSourceData_s,
	immpc_9dof_reserve_raw_pack_s	*pPackForTx_s)
{
	/* запись стартовых байт (Start frame) */
	pPackForTx_s->head_s.startFrame = IMMPC_START_FRAME;

	/* ID и Pack requests */
	pPackForTx_s->head_s.idAndPackRequests =
		IMMPC_ID_AND_PACK_REQUESTS_9dof_reserve_raw_pack_e;

	/* запись статусов сенсора (Sensors status) */
	__IMMPC_WRITE_REG(
		/* Переменная для записи битовых масок */
		pPackForTx_s->head_s.sensorsStatus,

		/* Битовые маски для записи в переменную */
		pSourceData_s->dataReserveAccGyr.sensorStatus |
		pSourceData_s->dataMag.sensorStatus);

	/* сброс статусов сенсора */
	pSourceData_s->dataReserveAccGyr.sensorStatus 	= 0u;
	pSourceData_s->dataMag.sensorStatus 			= 0u;

	/* Запись измерений акселерометра */
	pPackForTx_s->acc_a[0u] = pSourceData_s->dataReserveAccGyr.rawReserveAcc_a[0u];
	pPackForTx_s->acc_a[1u] = pSourceData_s->dataReserveAccGyr.rawReserveAcc_a[1u];
	pPackForTx_s->acc_a[2u] = pSourceData_s->dataReserveAccGyr.rawReserveAcc_a[2u];

	/* Запись измерений температуры акселерометра */
	pPackForTx_s->accTemp_a[0u] = pSourceData_s->dataReserveAccGyr.rawReserveTempAcc_a[0u];
	pPackForTx_s->accTemp_a[1u] = pSourceData_s->dataReserveAccGyr.rawReserveTempAcc_a[1u];
	pPackForTx_s->accTemp_a[2u] = pSourceData_s->dataReserveAccGyr.rawReserveTempAcc_a[2u];

	/* Запись измерений 3-х осей гироскопа (сырые данные) */
	pPackForTx_s->gyr_a[0u] = pSourceData_s->dataReserveAccGyr.rawReserveGyr_a[0u];
	pPackForTx_s->gyr_a[1u] = pSourceData_s->dataReserveAccGyr.rawReserveGyr_a[1u];
	pPackForTx_s->gyr_a[2u] = pSourceData_s->dataReserveAccGyr.rawReserveGyr_a[2u];

	/* Запись измерений температуры гироскопа */
	pPackForTx_s->gyrTemp_a[0u] = pSourceData_s->dataReserveAccGyr.rawReserveTempGyr_a[0u];
	pPackForTx_s->gyrTemp_a[1u] = pSourceData_s->dataReserveAccGyr.rawReserveTempGyr_a[1u];
	pPackForTx_s->gyrTemp_a[2u] = pSourceData_s->dataReserveAccGyr.rawReserveTempGyr_a[2u];

	/* Запись измерений 3-х осей магнитометра (сырые данные) */
	pPackForTx_s->mag_a[0u] = pSourceData_s->dataMag.rawMag_a[0u];
	pPackForTx_s->mag_a[1u] = pSourceData_s->dataMag.rawMag_a[1u];
	pPackForTx_s->mag_a[2u] = pSourceData_s->dataMag.rawMag_a[2u];

	/* Запись измерений температуры гироскопа */
	pPackForTx_s->magSelfTest_a[0u] = pSourceData_s->dataMag.rawMagSelfTest[0u];
	pPackForTx_s->magSelfTest_a[1u] = pSourceData_s->dataMag.rawMagSelfTest[1u];
	pPackForTx_s->magSelfTest_a[2u] = pSourceData_s->dataMag.rawMagSelfTest[2u];

	/* расчет CRC */
	pPackForTx_s->crc =
		(uint16_t) IMMPC_GetCRC_Generic(
			(uint8_t*) pPackForTx_s,
			(uint16_t) sizeof(immpc_9dof_reserve_raw_pack_s));

	return (sizeof(immpc_9dof_reserve_raw_pack_s));
}

/*-------------------------------------------------------------------------*//**
 * @author		Dmitry Tanikeev
 * @date		27-ноя-2019
 *
 * @brief		Функция формирует пакет для отправки "сырых" данных резервных
 * 				измерителей
 *
 * @param[in]	*pSourceData_s:	Указатель на область памяти, в которой храняться
 * 									"сырые" данные
 *
 * @param[out]	*pPackForTx_s: 	Указатель на область памяти, в которой будут
 * 							содержаться данные
 * 							@note 	Контрольная сумма записывается в конец
 * 									пакета данных
 *
 * @return		Длина пакета в байтах
 */
size_t
IMMPC_Generate_3dof_mag_raw_pack(
	immpc_meas_raw_data_s 		*pSourceData_s,
	immpc_mag3dof_raw_pack_s	*pPackForTx_s)
{
	/* запись стартовых байт (Start frame) */
	pPackForTx_s->head_s.startFrame = IMMPC_START_FRAME;

	/* запись типа сообщения (Message ID + Pack requests) */
	pPackForTx_s->head_s.messageID = IMMPC_MESSAGE_ID_MAG3DOF_PACK;

	__IMMPC_WRITE_REG(
		/* Переменная для записи битовых масок */
		pPackForTx_s->head_s.packRequests,

		/* Битовые маски для записи в переменную */
		0u);

	/* запись статусов сенсора (Sensors status) */
	__IMMPC_WRITE_REG(
		/* Переменная для записи битовых масок */
		pPackForTx_s->head_s.sensorsStatus,

		/* Битовые маски для записи в переменную */
		pSourceData_s->dataMag.sensorStatus);

	/* сброс статусов сенсора */
	pSourceData_s->dataMag.sensorStatus = 0u;

	/* Запись измерений 3-х осей магнитометра (сырые данные) */
	pPackForTx_s->mag_a[0u] = pSourceData_s->dataMag.rawMag_a[0u];
	pPackForTx_s->mag_a[1u] = pSourceData_s->dataMag.rawMag_a[1u];
	pPackForTx_s->mag_a[2u] = pSourceData_s->dataMag.rawMag_a[2u];

	/* Запись измерений температуры гироскопа */
	pPackForTx_s->magSelfTest_a[0u] = pSourceData_s->dataMag.rawMagSelfTest[0u];
	pPackForTx_s->magSelfTest_a[1u] = pSourceData_s->dataMag.rawMagSelfTest[1u];
	pPackForTx_s->magSelfTest_a[2u] = pSourceData_s->dataMag.rawMagSelfTest[2u];

	/* расчет CRC */
	pPackForTx_s->crc =
		(uint16_t) IMMPC_GetCRC_Generic(
			(uint8_t*) pPackForTx_s,
			(uint16_t) sizeof(immpc_mag3dof_raw_pack_s));

	return (sizeof(immpc_mag3dof_raw_pack_s));
}

/*#### |End  | <-- Секция - "Описание глобальных функций" ####################*/


/*#### |Begin| --> Секция - "Описание локальных функций" #####################*/
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
static immpc_head_s*
IMMPC_GetTypeMessage(
	const uint8_t 	*pData,
	size_t 			buffSize)
{
	/* присвоение стартовых значений */
	immpc_id_and_pack_requests_e messageType_e = IMMPC_ID_AND_PACK_REQUESTS_error_e;

	/* Установка адреса в NULL */
	immpc_head_s *pMessageHead = NULL;

	/* Минимальное количество данных необходимое для поиска */
	if (buffSize < ((size_t) 4u))
	{
		/* выход из функции */
		return (NULL);
	}

	size_t j;
	for (j = 0u; j < buffSize; j++)
	{
		/* Указатель на область памяти, в которой должны быть символы начала
		 * пакета данных и ID сообщения */
		uint16_t *pStartFrame 	= (uint16_t*) &pData[j];

		/* Если нашли символы начала пакета данных */
		if (*pStartFrame == IMMPC_START_FRAME)
		{
			/* Установка адреса "головы" сообщения */
			pMessageHead = (immpc_head_s*) pStartFrame;

			messageType_e = pMessageHead->idAndPackRequests;

			/* Выход из цикла for (Пакет нашли, разобрали его тип, не нужно
			 * тратить драгоценное время контроллера на попытку найти еще один) */
			break;
		}
	}

	/* выход */
	return (pMessageHead);
}
/*#### |End  | <-- Секция - "Описание локальных функций" #####################*/


/*#### |Begin| --> Секция - "Обработчики прерываний" #########################*/
/*#### |End  | <-- Секция - "Обработчики прерываний" #########################*/

/*############################################################################*/
/*############################ END OF FILE  ##################################*/
/*############################################################################*/
