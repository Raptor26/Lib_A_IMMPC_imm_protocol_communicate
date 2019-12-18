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
static size_t
IMMPC_SetCalibMatrixMessageGeneric(
	immpc_calibmatrix_pack_generic_s 	*pOutputMessage,
	immpc_id_and_pack_requests_e 		idAndPackRequets,
	iscm_calibmatrix_generic_s 			*pCalibMatrix_s);

static void
IMMPc_GetCalibMatrixFromMessageGeneric(
	iscm_calibmatrix_generic_s			*pCalibMatInRAM,
	immpc_calibmatrix_pack_generic_s 	*pInputMessagePack);
/*#### |End  | <-- Секция - "Прототипы локальных функций" ####################*/


/*#### |Begin| --> Секция - "Описание глобальных функций" ####################*/



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


/*-------------------------------------------------------------------------*//**
 * @author
 * @date	08-ноя-2019
 *
 * @brief	Функция формирует ответ с калибровочными матрицами
 *
 * @return Количество байт данных
 */
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

static void
IMMPc_GetCalibMatrixFromMessageGeneric(
	iscm_calibmatrix_generic_s			*pCalibMatInRAM,
	immpc_calibmatrix_pack_generic_s 	*pInputMessagePack)
{
	memcpy(
		(void*) &pCalibMatInRAM->matrix_a[0u][0u],
		(void*) &pInputMessagePack->calib_s.matrix_a[0u][0u],
		sizeof(iscm_calibmatrix_generic_s));
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
	immpc_inert_meas_all_data_s 	*pRawSensMeas_s,

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
		*pOutBuffByteNumbForTx =
			(uint16_t) IMMPC_SetResponseMessage(
				(immpc_response_cmd_s*) pOutBuff,
				IMMPC_ID_response_code_invalid_message_format);

		return (IMMPC_ID_AND_PACK_UNKNOWN_e);
	}

	/* Указатель на сообщения запросов */
	immpc_request_cmd_s *pRequestCmd_s =
		(immpc_request_cmd_s*) pHeadMessage_s;

	immpc_calibmatrix_pack_generic_s *pCalibMatPackGeneric_s =
		(immpc_calibmatrix_pack_generic_s*) pHeadMessage_s;

	switch (pRequestCmd_s->idAndPackRequests)
	{
	/* #### 9dof_main_raw_request_cmd -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
	/* Команда на запрос данных "сырых" основных измерителей */
	case (IMMPC_ID_AND_PACK_REQUESTS_9dof_main_raw_request_cmd_e):
		if (pRequestCmd_s->crc == IMMPC_GetCRC_Generic((uint8_t*) pRequestCmd_s, (uint16_t) sizeof(immpc_request_cmd_s)))
		{
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetMain9dofRawDataPack(
					pRawSensMeas_s,
					(immpc_9dof_main_raw_pack_s*) pOutBuff);
		}
		else
		{
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetResponseMessage(
					(immpc_response_cmd_s*) pOutBuff,
					IMMPC_ID_response_code_invalid_crc);
		}
		break;
	/* #### 9dof_main_raw_request_cmd --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */


	/* #### 9dof_main_calib_request_cmd -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
	/* Команда на запрос данных калиброванных основных измерителей */
	case (IMMPC_ID_AND_PACK_REQUESTS_9dof_main_calib_request_cmd_e):
		if (pRequestCmd_s->crc == IMMPC_GetCRC_Generic((uint8_t*) pRequestCmd_s, (uint16_t) sizeof(immpc_request_cmd_s)))
		{
			/* @todo ормирование пакета с калиброванными данными основных измерителей */
			/* .... */
		}
		else
		{
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetResponseMessage(
					(immpc_response_cmd_s*) pOutBuff,
					IMMPC_ID_response_code_invalid_crc);
		}
		break;
	/* #### 9dof_main_calib_request_cmd --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */


	/* #### 9dof_reserve_raw_request_cmd -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
	/* Команда на запрос данных "сырых" резервных измерителей */
	case (IMMPC_ID_AND_PACK_REQUESTS_9dof_reserve_raw_request_cmd_e):
		/* Если контрольная сумма верна */
		if (pRequestCmd_s->crc == IMMPC_GetCRC_Generic((uint8_t*) pRequestCmd_s, sizeof(immpc_request_cmd_s)))
		{
			/* Формирование ответного сообщения */
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetReserve9dofRawDataPack(
					pRawSensMeas_s,
					(immpc_9dof_reserve_raw_pack_s*) pOutBuff);
		}
		else
		{
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetResponseMessage(
					(immpc_response_cmd_s*) pOutBuff,
					IMMPC_ID_response_code_invalid_crc);
		}
		break;
	/* #### 9dof_reserve_raw_request_cmd --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */


	/* #### 9dof_reserve_calib_request_cmd -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
	/* Команда на запрос данных калиброванных резервных измерителей */
	case (IMMPC_ID_AND_PACK_REQUESTS_9dof_reserve_calib_request_cmd_e):
		if (pRequestCmd_s->crc == IMMPC_GetCRC_Generic((uint8_t*) pRequestCmd_s, (uint16_t) sizeof(immpc_request_cmd_s)))
		{
			/* Формирование сообщения калиброванных данных резервных измерителей */
			IMMPC_SetReserve9dofCalibDataPack(
				pRawSensMeas_s,
				(immpc_9dof_reserve_calib_pack_s*) pOutBuff);
		}
		else
		{
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetResponseMessage(
					(immpc_response_cmd_s*) pOutBuff,
					IMMPC_ID_response_code_invalid_crc);
		}
		break;
	/* #### 9dof_reserve_calib_request_cmd --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */


	/* #### 3dof_mag_raw_request_cmd -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
	/* Команда на запрос данных "сырых" магнитометра */
	case (IMMPC_ID_AND_PACK_REQUESTS_3dof_mag_raw_request_cmd_e):
		/* Если контрольная сумма верна */
		if (pRequestCmd_s->crc == IMMPC_GetCRC_Generic((uint8_t*) pRequestCmd_s, sizeof(immpc_request_cmd_s)))
		{
			/* Формирование ответного сообщения */
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetMain3dofMagRawDataPack(
					pRawSensMeas_s,
					(immpc_mag3dof_raw_pack_s*) pOutBuff);
		}
		else
		{
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetResponseMessage(
					(immpc_response_cmd_s*) pOutBuff,
					IMMPC_ID_response_code_invalid_crc);
		}
		break;
	/* #### 3dof_mag_raw_request_cmd --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */


	/* #### 3dof_mag_calib_request_cmd -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
	/* Команда на запрос данных калиброванных магнитометра */
	case (IMMPC_ID_AND_PACK_REQUESTS_3dof_mag_calib_request_cmd_e):
		/* Если контрольная сумма верна */
		if (pRequestCmd_s->crc == IMMPC_GetCRC_Generic((uint8_t*) pRequestCmd_s, sizeof(immpc_request_cmd_s)))
		{
			/* @todo формирование пакета с калиброванными данными магнитометра */
			/* .... */
		}
		else
		{
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetResponseMessage(
					(immpc_response_cmd_s*) pOutBuff,
					IMMPC_ID_response_code_invalid_crc);
		}
		break;
	/* #### 3dof_mag_calib_request_cmd --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */


	/* #### 3dof_acc_main_calibmatrix_request_cmd -->>>>>>>>>>>>>>>>>>>>>>>>> */
	/* Команда на запрос калибровочных матриц основного акселерометра */
	case (IMMPC_ID_AND_PACK_REQUESTS_3dof_acc_main_calibmatrix_request_cmd_e):
		/* Если контрольная сумма верна */
		if (pRequestCmd_s->crc == IMMPC_GetCRC_Generic((uint8_t*) pRequestCmd_s, sizeof(immpc_request_cmd_s)))
		{
			/* Формирование ответного сообщения */
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetCalibMatrixMessageGeneric(
					(immpc_calibmatrix_pack_generic_s*) pOutBuff,
					IMMPC_ID_AND_PACK_REQUESTS_acc3dof_main_calibmatrix_read_pack_e,
					(iscm_calibmatrix_generic_s*) &pRawSensMeas_s->calibMat_s.mainAccCalibMatrix);
					//&tmpMainAccCalibMatrix);
		}
		else
		{
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetResponseMessage(
					(immpc_response_cmd_s*) pOutBuff,
					IMMPC_ID_response_code_invalid_crc);
		}
		break;
	/* #### 3dof_acc_main_calibmatrix_request_cmd --<<<<<<<<<<<<<<<<<<<<<<<<< */


	/* #### 3dof_acc_reserve_calibmatrix_request_cmd -->>>>>>>>>>>>>>>>>>>>>> */
	/* Команда на запрос калибровочных матриц резервного акселерометра */
	case (IMMPC_ID_AND_PACK_REQUESTS_3dof_acc_reserve_calibmatrix_request_cmd_e):
		/* Если контрольная сумма верна */
		if (pRequestCmd_s->crc == IMMPC_GetCRC_Generic((uint8_t*) pRequestCmd_s, sizeof(immpc_request_cmd_s)))
		{
			/* Формирование ответного сообщения */
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetCalibMatrixMessageGeneric(
					(immpc_calibmatrix_pack_generic_s*) pOutBuff,
					IMMPC_ID_AND_PACK_REQUESTS_acc3dof_reserve_calibmatrix_read_pack_e,
					(iscm_calibmatrix_generic_s*) & ((pRawSensMeas_s->calibMat_s).reserveAccCalibMatrix));

//			immpc_calibmatrix_pack_generic_s *pTest_s = (immpc_calibmatrix_pack_generic_s*) pOutBuff;
//			pTest_s->crc = 0x00;
		}
		else
		{
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetResponseMessage(
					(immpc_response_cmd_s*) pOutBuff,
					IMMPC_ID_response_code_invalid_crc);
		}
		break;
	/* #### 3dof_acc_reserve_calibmatrix_request_cmd --<<<<<<<<<<<<<<<<<<<<<< */


	/* #### 3dof_gyr_main_calibmatrix_request_cmd -->>>>>>>>>>>>>>>>>>>>>>>>> */
	/* Команда на запрос калибровочных матриц основного гироскопа */
	case (IMMPC_ID_AND_PACK_REQUESTS_3dof_gyr_main_calibmatrix_request_cmd_e):
		/* Если контрольная сумма верна */
		if (pRequestCmd_s->crc == IMMPC_GetCRC_Generic((uint8_t*) pRequestCmd_s, sizeof(immpc_request_cmd_s)))
		{
			/* Формирование ответного сообщения */
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetCalibMatrixMessageGeneric(
					(immpc_calibmatrix_pack_generic_s*) pOutBuff,
					IMMPC_ID_AND_PACK_REQUESTS_gyr3dof_main_calibmatrix_read_pack_e,
					(iscm_calibmatrix_generic_s*) & ((pRawSensMeas_s->calibMat_s).mainGyrCalibMatrix));
		}
		else
		{
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetResponseMessage(
					(immpc_response_cmd_s*) pOutBuff,
					IMMPC_ID_response_code_invalid_crc);
		}
		break;
	/* #### 3dof_gyr_main_calibmatrix_request_cmd --<<<<<<<<<<<<<<<<<<<<<<<<< */


	/* #### 3dof_gyr_reserve_calibmatrix_request_cmd -->>>>>>>>>>>>>>>>>>>>>> */
	/* Команда на запрос калибровочных матриц резервного гироскопа */
	case (IMMPC_ID_AND_PACK_REQUESTS_3dof_gyr_reserve_calibmatrix_request_cmd_e):
		/* Если контрольная сумма верна */
		if (pRequestCmd_s->crc == IMMPC_GetCRC_Generic((uint8_t*) pRequestCmd_s, sizeof(immpc_request_cmd_s)))
		{
			/* Формирование ответного сообщения */
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetCalibMatrixMessageGeneric(
					(immpc_calibmatrix_pack_generic_s*) pOutBuff,
					IMMPC_ID_AND_PACK_REQUESTS_gyr3dof_reserve_calibmatrix_read_pack_e,
					(iscm_calibmatrix_generic_s*) & ((pRawSensMeas_s->calibMat_s).reserveGyrCalibMatrix));
		}
		else
		{
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetResponseMessage(
					(immpc_response_cmd_s*) pOutBuff,
					IMMPC_ID_response_code_invalid_crc);
		}
		break;
	/* #### 3dof_gyr_reserve_calibmatrix_request_cmd --<<<<<<<<<<<<<<<<<<<<<< */


	/* #### 3dof_mag_calibmatrix_request_cmd -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
	/* Команда на запрос калибровочных матриц магнитометра */
	case (IMMPC_ID_AND_PACK_REQUESTS_3dof_mag_calibmatrix_request_cmd_e):
		/* Если контрольная сумма верна */
		if (pRequestCmd_s->crc == IMMPC_GetCRC_Generic((uint8_t*) pRequestCmd_s, sizeof(immpc_request_cmd_s)))
		{
			/* Формирование ответного сообщения */
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetCalibMatrixMessageGeneric(
					(immpc_calibmatrix_pack_generic_s*) pOutBuff,
					IMMPC_ID_AND_PACK_REQUESTS_mag3dof_calibmatrix_read_pack_e,
					(iscm_calibmatrix_generic_s*) & ((pRawSensMeas_s->calibMat_s).magCalibMatrix));
		}
		else
		{
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetResponseMessage(
					(immpc_response_cmd_s*) pOutBuff,
					IMMPC_ID_response_code_invalid_crc);
		}
		break;
	/* #### 3dof_mag_calibmatrix_request_cmd --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */


	/* #### 3dof_acc_main_calibmatrix_write_pack -->>>>>>>>>>>>>>>>>>>>>>>>>> */
	/* Пакет, содержащий калибровочную матрицу основного акселерометра */
	case (IMMPC_ID_AND_PACK_REQUESTS_acc3dof_main_calibmatrix_write_pack_e):
		/* Если контрольная сумма верна */
		if (pCalibMatPackGeneric_s->crc == IMMPC_GetCRC_Generic((uint8_t*) pCalibMatPackGeneric_s, sizeof(immpc_calibmatrix_pack_generic_s)))
		{
			/* Записать в общую структуру данных инерциальных измерителей */
			IMMPc_GetCalibMatrixFromMessageGeneric(
				(iscm_calibmatrix_generic_s*) &pRawSensMeas_s->calibMat_s.mainAccCalibMatrix,
				pCalibMatPackGeneric_s);

			/* Отправить ответ */
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetResponseMessage(
					(immpc_response_cmd_s*) pOutBuff,
					IMMPC_ID_response_code_ok);
		}
		else
		{
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetResponseMessage(
					(immpc_response_cmd_s*) pOutBuff,
					IMMPC_ID_response_code_invalid_crc);
		}

		break;
	/* #### 3dof_acc_main_calibmatrix_write_pack --<<<<<<<<<<<<<<<<<<<<<<<<<< */


	/* #### 3dof_acc_reserve_calibmatrix_write_pack -->>>>>>>>>>>>>>>>>>>>>>> */
	/* Пакет, содержащий калибровочную матрицу резервного акселерометра */
	case (IMMPC_ID_AND_PACK_REQUESTS_acc3dof_reserve_calibmatrix_write_pack_e):
		/* Если контрольная сумма верна */
		if (pCalibMatPackGeneric_s->crc == IMMPC_GetCRC_Generic((uint8_t*) pCalibMatPackGeneric_s, sizeof(immpc_calibmatrix_pack_generic_s)))
		{
			/* Записать в общую структуру данных инерциальных измерителей */
			IMMPc_GetCalibMatrixFromMessageGeneric(
				(iscm_calibmatrix_generic_s*) &pRawSensMeas_s->calibMat_s.reserveAccCalibMatrix,
				pCalibMatPackGeneric_s);

			/* Отправить ответ */
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetResponseMessage(
					(immpc_response_cmd_s*) pOutBuff,
					IMMPC_ID_response_code_ok);
		}
		else
		{
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetResponseMessage(
					(immpc_response_cmd_s*) pOutBuff,
					IMMPC_ID_response_code_invalid_crc);
		}

		break;
	/* #### 3dof_acc_reserve_calibmatrix_write_pack --<<<<<<<<<<<<<<<<<<<<<<< */


	/* #### 3dof_gyr_main_calibmatrix_write_pack -->>>>>>>>>>>>>>>>>>>>>>>>>> */
	/* Пакет, содержащий калибровочную матрицу основного гироскопа */
	case (IMMPC_ID_AND_PACK_REQUESTS_gyr3dof_main_calibmatrix_write_pack_e):
		/* Если контрольная сумма верна */
		if (pCalibMatPackGeneric_s->crc == IMMPC_GetCRC_Generic((uint8_t*) pCalibMatPackGeneric_s, sizeof(immpc_calibmatrix_pack_generic_s)))
		{
			/* Записать в общую структуру данных инерциальных измерителей */
			IMMPc_GetCalibMatrixFromMessageGeneric(
				(iscm_calibmatrix_generic_s*) &pRawSensMeas_s->calibMat_s.mainGyrCalibMatrix,
				pCalibMatPackGeneric_s);

			/* Отправить ответ */
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetResponseMessage(
					(immpc_response_cmd_s*) pOutBuff,
					IMMPC_ID_response_code_ok);
		}
		else
		{
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetResponseMessage(
					(immpc_response_cmd_s*) pOutBuff,
					IMMPC_ID_response_code_invalid_crc);
		}

		break;
	/* #### 3dof_gyr_main_calibmatrix_write_pack --<<<<<<<<<<<<<<<<<<<<<<<<<< */


	/* #### 3dof_gyr_reserve_calibmatrix_write_pack -->>>>>>>>>>>>>>>>>>>>>>> */
	/* Пакет, содержащий калибровочную матрицу резервного гироскопа */
	case (IMMPC_ID_AND_PACK_REQUESTS_gyr3dof_reserve_calibmatrix_write_pack_e):
		/* Если контрольная сумма верна */
		if (pCalibMatPackGeneric_s->crc == IMMPC_GetCRC_Generic((uint8_t*) pCalibMatPackGeneric_s, sizeof(immpc_calibmatrix_pack_generic_s)))
		{
			/* Записать в общую структуру данных инерциальных измерителей */
			IMMPc_GetCalibMatrixFromMessageGeneric(
				(iscm_calibmatrix_generic_s*) &pRawSensMeas_s->calibMat_s.reserveGyrCalibMatrix,
				pCalibMatPackGeneric_s);

			/* Отправить ответ */
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetResponseMessage(
					(immpc_response_cmd_s*) pOutBuff,
					IMMPC_ID_response_code_ok);
		}
		else
		{
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetResponseMessage(
					(immpc_response_cmd_s*) pOutBuff,
					IMMPC_ID_response_code_invalid_crc);
		}

		break;
	/* #### 3dof_gyr_reserve_calibmatrix_write_pack --<<<<<<<<<<<<<<<<<<<<<<< */


	/* #### 3dof_mag_calibmatrix_write_pack -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
	/* Пакет, содержащий калибровочную матрицу магнитометра */
	case (IMMPC_ID_AND_PACK_REQUESTS_mag3dof_calibmatrix_write_pack_e):
		/* Если контрольная сумма верна */
		if (pCalibMatPackGeneric_s->crc == IMMPC_GetCRC_Generic((uint8_t*) pCalibMatPackGeneric_s, sizeof(immpc_calibmatrix_pack_generic_s)))
		{
			/* Записать в общую структуру данных инерциальных измерителей */
			IMMPc_GetCalibMatrixFromMessageGeneric(
				(iscm_calibmatrix_generic_s*) &pRawSensMeas_s->calibMat_s.magCalibMatrix,
				pCalibMatPackGeneric_s);

			/* Отправить ответ */
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetResponseMessage(
					(immpc_response_cmd_s*) pOutBuff,
					IMMPC_ID_response_code_ok);
		}
		else
		{
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetResponseMessage(
					(immpc_response_cmd_s*) pOutBuff,
					IMMPC_ID_response_code_invalid_crc);
		}

		break;
	/* #### 3dof_mag_calibmatrix_write_pack --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */


	/* #### write_all_calibmatrix_cmd -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
	/* Команда для записи всех калибровочных матриц из ОЗУ в EEPROM */
	case (IMMPC_ID_AND_PACK_REQUESTS_write_all_calibmatrix_in_eeprom_cmd_e):
		/* Если контрольная сумма верна */
		if (pRequestCmd_s->crc == IMMPC_GetCRC_Generic((uint8_t*) pRequestCmd_s, sizeof(immpc_request_cmd_s)))
		//if (pCalibMatPackGeneric_s->crc == IMMPC_GetCRC_Generic((uint8_t*) pCalibMatPackGeneric_s, sizeof(immpc_calibmatrix_pack_generic_s)))
		{
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetResponseMessage(
					(immpc_response_cmd_s*) pOutBuff,
					IMMPC_ID_response_code_ok);
		}
		else
		{
			*pOutBuffByteNumbForTx =
				(uint16_t) IMMPC_SetResponseMessage(
					(immpc_response_cmd_s*) pOutBuff,
					IMMPC_ID_response_code_invalid_crc);

			pRequestCmd_s->idAndPackRequests = IMMPC_ID_AND_PACK_UNKNOWN_e;
		}
		break;
	/* #### write_all_calibmatrix_cmd --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */


	default:
		*pOutBuffByteNumbForTx =
			(uint16_t) IMMPC_SetResponseMessage(
				(immpc_response_cmd_s*) pOutBuff,
				IMMPC_ID_response_code_invalid_message_format);

		pRequestCmd_s->idAndPackRequests = IMMPC_ID_AND_PACK_UNKNOWN_e;
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
IMMPC_SetMain9dofRawDataPack(
	immpc_inert_meas_all_data_s 	*pInertMeas_s,
	immpc_9dof_main_raw_pack_s		*pPackForTx_s)
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
		pInertMeas_s->main9dof.sensorStatus);

	/* сброс статусов сенсора */
	__IMMPC_CLEAR_BIT(
		pInertMeas_s->main9dof.sensorStatus,
		IMMPC_ACC_XYZ_DATA_WAS_UPDATE |
		IMMPC_GYR_XYZ_DATA_WAS_UPDATE |
		IMMPC_MAG_XYZ_DATA_WAS_UPDATE);

	/* Запись измерений акселерометра */
	pPackForTx_s->acc_a[0u] = pInertMeas_s->main9dof.acc_a[0u];
	pPackForTx_s->acc_a[1u] = pInertMeas_s->main9dof.acc_a[1u];
	pPackForTx_s->acc_a[2u] = pInertMeas_s->main9dof.acc_a[2u];

	/* Запись измерений температуры акселерометра */
	pPackForTx_s->accTemp_a[0u] = pInertMeas_s->main9dof.accTemp_a[0u];
	pPackForTx_s->accTemp_a[1u] = pInertMeas_s->main9dof.accTemp_a[1u];
	pPackForTx_s->accTemp_a[2u] = pInertMeas_s->main9dof.accTemp_a[2u];

	/* Запись измерений 3-х осей гироскопа (сырые данные) */
	pPackForTx_s->gyr_a[0u] = pInertMeas_s->main9dof.gyr_a[0u];
	pPackForTx_s->gyr_a[1u] = pInertMeas_s->main9dof.gyr_a[1u];
	pPackForTx_s->gyr_a[2u] = pInertMeas_s->main9dof.gyr_a[2u];

	/* Запись измерений температуры гироскопа */
	pPackForTx_s->gyrTemp_a[0u] = pInertMeas_s->main9dof.gyrTemp_a[0u];
	pPackForTx_s->gyrTemp_a[1u] = pInertMeas_s->main9dof.gyrTemp_a[1u];
	pPackForTx_s->gyrTemp_a[2u] = pInertMeas_s->main9dof.gyrTemp_a[2u];

	/* Запись измерений 3-х осей магнитометра (сырые данные) */
	pPackForTx_s->mag_a[0u] = pInertMeas_s->main9dof.mag_a[0u];
	pPackForTx_s->mag_a[1u] = pInertMeas_s->main9dof.mag_a[1u];
	pPackForTx_s->mag_a[2u] = pInertMeas_s->main9dof.mag_a[2u];

	/* Запись измерений температуры гироскопа */
	pPackForTx_s->magSelfTest_a[0u] = pInertMeas_s->main9dof.magSelfTest_a[0u];
	pPackForTx_s->magSelfTest_a[1u] = pInertMeas_s->main9dof.magSelfTest_a[1u];
	pPackForTx_s->magSelfTest_a[2u] = pInertMeas_s->main9dof.magSelfTest_a[2u];

	/* расчет CRC */
	pPackForTx_s->crc =
		(uint16_t) IMMPC_GetCRC_Generic(
			(uint8_t*) pPackForTx_s,
			(uint16_t) sizeof(immpc_9dof_main_raw_pack_s));

	return (sizeof(immpc_9dof_main_raw_pack_s));
}

/* @todo написать функцию */
size_t
IMMPC_SetMain9dofCalibDataPack(
	immpc_inert_meas_all_data_s 	*pInertMeas_s,
	immpc_9dof_main_calib_pack_s	*pPackForTx_s)
{

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
IMMPC_SetReserve9dofRawDataPack(
	immpc_inert_meas_all_data_s 	*pInertMeas_s,
	immpc_9dof_reserve_raw_pack_s	*pPackForTx_s)
{
	/* запись стартовых байт (Start frame) */
	pPackForTx_s->head_s.startFrame = IMMPC_START_FRAME;

	/* ID и Pack requests */
	pPackForTx_s->head_s.idAndPackRequests =
		IMMPC_ID_AND_PACK_REQUESTS_9dof_reserve_raw_pack_e;


	pPackForTx_s->head_s.sensorsStatus = 0u;

	/* запись статусов сенсора (Sensors status) */
	__IMMPC_WRITE_REG(
		pPackForTx_s->head_s.sensorsStatus,

		__IMMPC_CLEAR_BIT(
			pInertMeas_s->main9dof.sensorStatus,
			(!(IMMPC_MAG_X_SELF_TEST 				|
			   IMMPC_MAG_Y_SELF_TEST 				|
			   IMMPC_MAG_Z_SELF_TEST  				|
			   IMMPC_MAG_XYZ_DATA_WAS_UPDATE))) 	|

		__IMMPC_CLEAR_BIT(
			pInertMeas_s->reserve6dof.sensorStatus,
			(!(IMMPC_ACC_X_SELF_TEST 			|
			   IMMPC_ACC_Y_SELF_TEST 			|
			   IMMPC_ACC_Z_SELF_TEST			|
			   IMMPC_GYR_X_SELF_TEST 			|
			   IMMPC_GYR_Y_SELF_TEST 			|
			   IMMPC_GYR_Z_SELF_TEST			|
			   IMMPC_ACC_XYZ_DATA_WAS_UPDATE 	|
			   IMMPC_GYR_XYZ_DATA_WAS_UPDATE)))
	);

	/* сброс статусов сенсора */
	__IMMPC_CLEAR_BIT(
		/* Статусы резервных измерителей */
		pInertMeas_s->reserve6dof.sensorStatus,

		/* Сброс флагов обновления данных: acc, gyr, mag */
		IMMPC_ACC_XYZ_DATA_WAS_UPDATE |
		IMMPC_GYR_XYZ_DATA_WAS_UPDATE |
		IMMPC_MAG_XYZ_DATA_WAS_UPDATE);

	__IMMPC_CLEAR_BIT(
		/* Статусы основных измерителей */
		pInertMeas_s->main9dof.sensorStatus,

		/* Сброс флагов обновления данных: mag */
		IMMPC_MAG_XYZ_DATA_WAS_UPDATE);

	/* Запись измерений акселерометра */
	pPackForTx_s->acc_a[0u] = pInertMeas_s->reserve6dof.acc_a[0u];
	pPackForTx_s->acc_a[1u] = pInertMeas_s->reserve6dof.acc_a[1u];
	pPackForTx_s->acc_a[2u] = pInertMeas_s->reserve6dof.acc_a[2u];

	/* Запись измерений температуры акселерометра */
	pPackForTx_s->accTemp_a[0u] = pInertMeas_s->reserve6dof.accTemp_a[0u];
	pPackForTx_s->accTemp_a[1u] = pInertMeas_s->reserve6dof.accTemp_a[1u];
	pPackForTx_s->accTemp_a[2u] = pInertMeas_s->reserve6dof.accTemp_a[2u];

	/* Запись измерений 3-х осей гироскопа (сырые данные) */
	pPackForTx_s->gyr_a[0u] = pInertMeas_s->reserve6dof.gyr_a[0u];
	pPackForTx_s->gyr_a[1u] = pInertMeas_s->reserve6dof.gyr_a[1u];
	pPackForTx_s->gyr_a[2u] = pInertMeas_s->reserve6dof.gyr_a[2u];

	/* Запись измерений температуры гироскопа */
	pPackForTx_s->gyrTemp_a[0u] = pInertMeas_s->reserve6dof.gyrTemp_a[0u];
	pPackForTx_s->gyrTemp_a[1u] = pInertMeas_s->reserve6dof.gyrTemp_a[1u];
	pPackForTx_s->gyrTemp_a[2u] = pInertMeas_s->reserve6dof.gyrTemp_a[2u];

	/* Запись измерений 3-х осей магнитометра (сырые данные) */
	pPackForTx_s->mag_a[0u] = pInertMeas_s->main9dof.mag_a[0u];
	pPackForTx_s->mag_a[1u] = pInertMeas_s->main9dof.mag_a[1u];
	pPackForTx_s->mag_a[2u] = pInertMeas_s->main9dof.mag_a[2u];

	/* Запись измерений selfTest магнитометра (вместо температуры) */
	pPackForTx_s->magSelfTest_a[0u] = pInertMeas_s->main9dof.magSelfTest_a[0u];
	pPackForTx_s->magSelfTest_a[1u] = pInertMeas_s->main9dof.magSelfTest_a[1u];
	pPackForTx_s->magSelfTest_a[2u] = pInertMeas_s->main9dof.magSelfTest_a[2u];

	/* расчет CRC */
	pPackForTx_s->crc =
		(uint16_t) IMMPC_GetCRC_Generic(
			(uint8_t*) pPackForTx_s,
			(uint16_t) sizeof(immpc_9dof_reserve_raw_pack_s));

	return (sizeof(immpc_9dof_reserve_raw_pack_s));
}

size_t
IMMPC_SetReserve9dofCalibDataPack(
	immpc_inert_meas_all_data_s 	*pInertMeas_s,
	immpc_9dof_reserve_calib_pack_s	*pPackForTx_s)
{
	/* запись стартовых байт (Start frame) */
	pPackForTx_s->head_s.startFrame = IMMPC_START_FRAME;

	/* ID и Pack requests */
	pPackForTx_s->head_s.idAndPackRequests =
		IMMPC_ID_AND_PACK_REQUESTS_9dof_reserve_calib_pack_e;

	pPackForTx_s->head_s.sensorsStatus = 0u;

	/* запись статусов сенсора (Sensors status) */
	__IMMPC_WRITE_REG(
		pPackForTx_s->head_s.sensorsStatus,

		__IMMPC_CLEAR_BIT(
			pInertMeas_s->main9dof.sensorStatus,
			(!(IMMPC_MAG_X_SELF_TEST 				|
			   IMMPC_MAG_Y_SELF_TEST 				|
			   IMMPC_MAG_Z_SELF_TEST  				|
			   IMMPC_MAG_XYZ_DATA_WAS_UPDATE))) 	|

		__IMMPC_CLEAR_BIT(
			pInertMeas_s->reserve6dof.sensorStatus,
			(!(IMMPC_ACC_X_SELF_TEST 			|
			   IMMPC_ACC_Y_SELF_TEST 			|
			   IMMPC_ACC_Z_SELF_TEST			|
			   IMMPC_GYR_X_SELF_TEST 			|
			   IMMPC_GYR_Y_SELF_TEST 			|
			   IMMPC_GYR_Z_SELF_TEST			|
			   IMMPC_ACC_XYZ_DATA_WAS_UPDATE 	|
			   IMMPC_GYR_XYZ_DATA_WAS_UPDATE)))
	);

	/* сброс статусов сенсора */
	__IMMPC_CLEAR_BIT(
		/* Статусы резервных измерителей */
		pInertMeas_s->reserve6dof.sensorStatus,

		/* Сброс флагов обновления данных: acc, gyr, mag */
		IMMPC_ACC_XYZ_DATA_WAS_UPDATE |
		IMMPC_GYR_XYZ_DATA_WAS_UPDATE |
		IMMPC_MAG_XYZ_DATA_WAS_UPDATE);

	__IMMPC_CLEAR_BIT(
		/* Статусы основных измерителей */
		pInertMeas_s->main9dof.sensorStatus,

		/* Сброс флагов обновления данных: mag */
		IMMPC_MAG_XYZ_DATA_WAS_UPDATE);

	/* Запись измерений акселерометра */
	ISCM_GetCalibDataFromRawGeneric(
		pInertMeas_s->reserve6dof.acc_a,
		(iscm_calibmatrix_generic_s*) &pInertMeas_s->calibMat_s.reserveAccCalibMatrix,
		pPackForTx_s->acc);

	/* Запись измерений температуры акселерометра */
	IMMPC_RawToFptReserveAccTemperature(&pInertMeas_s->reserve6dof.accTemp_a[0u], &pPackForTx_s->accTemp[0u]);
	pInertMeas_s->reserve6dof.accTemp_a[1u] = pInertMeas_s->reserve6dof.accTemp_a[0u];
	pInertMeas_s->reserve6dof.accTemp_a[2u] = pInertMeas_s->reserve6dof.accTemp_a[0u];

	/* Запись измерений 3-х осей гироскопа (калиброванные данные) */
	ISCM_GetCalibDataFromRawGeneric(
		pInertMeas_s->reserve6dof.gyr_a,
		(iscm_calibmatrix_generic_s*) &pInertMeas_s->calibMat_s.reserveAccCalibMatrix,
		pPackForTx_s->gyr);

	/* Запись измерений температуры гироскопа */
	IMMPC_RawToFptReserveGyrTemperature(&pInertMeas_s->reserve6dof.gyrTemp_a[0u], &pPackForTx_s->gyrTemp[0u]);
	pInertMeas_s->reserve6dof.gyrTemp_a[1u] = pPackForTx_s->gyrTemp[0u];
	pInertMeas_s->reserve6dof.gyrTemp_a[2u] = pPackForTx_s->gyrTemp[0u];

	/* Запись измерений 3-х осей магнитометра (калиброванные данные) */
	ISCM_GetCalibDataFromRawGeneric(
		pInertMeas_s->main9dof.mag_a,
		(iscm_calibmatrix_generic_s*) &pInertMeas_s->calibMat_s.magCalibMatrix,
		pPackForTx_s->mag);

	/* @todo написать номрирование self test магнитометра */

	/* расчет CRC */
	pPackForTx_s->crc =
		(uint16_t) IMMPC_GetCRC_Generic(
			(uint8_t*) pPackForTx_s,
			(uint16_t) sizeof(immpc_9dof_reserve_calib_pack_s));

	return (sizeof(immpc_9dof_reserve_calib_pack_s));
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
IMMPC_SetMain3dofMagRawDataPack(
	immpc_inert_meas_all_data_s 	*pInertMeas_s,
	immpc_mag3dof_raw_pack_s		*pPackForTx_s)
{
	/* запись стартовых байт (Start frame) */
	pPackForTx_s->head_s.startFrame = IMMPC_START_FRAME;

	/* запись типа сообщения (Message ID + Pack requests) */
	pPackForTx_s->head_s.messageID =
		IMMPC_ID_AND_PACK_REQUESTS_3dof_mag_raw_pack_e;

	__IMMPC_WRITE_REG(
		/* Переменная для записи битовых масок */
		pPackForTx_s->head_s.packRequests,

		/* Битовые маски для записи в переменную */
		__IMMPC_CLEAR_BIT(
			pInertMeas_s->main9dof.sensorStatus,
			(!(IMMPC_MAG_X_SELF_TEST |
			   IMMPC_MAG_Y_SELF_TEST |
			   IMMPC_MAG_Z_SELF_TEST |
			   IMMPC_MAG_XYZ_DATA_WAS_UPDATE)))
	);

	/* Сброс статусов магнитометра */
	__IMMPC_CLEAR_BIT(
		pInertMeas_s->main9dof.sensorStatus,
		(IMMPC_MAG_X_SELF_TEST |
		 IMMPC_MAG_Y_SELF_TEST |
		 IMMPC_MAG_Z_SELF_TEST |
		 IMMPC_MAG_XYZ_DATA_WAS_UPDATE));

	/* Запись измерений 3-х осей магнитометра (сырые данные) */
	pPackForTx_s->mag_a[0u] = pInertMeas_s->main9dof.mag_a[0u];
	pPackForTx_s->mag_a[1u] = pInertMeas_s->main9dof.mag_a[1u];
	pPackForTx_s->mag_a[2u] = pInertMeas_s->main9dof.mag_a[2u];

	/* Запись измерений температуры гироскопа */
	pPackForTx_s->magSelfTest_a[0u] = pInertMeas_s->main9dof.magSelfTest_a[0u];
	pPackForTx_s->magSelfTest_a[1u] = pInertMeas_s->main9dof.magSelfTest_a[1u];
	pPackForTx_s->magSelfTest_a[2u] = pInertMeas_s->main9dof.magSelfTest_a[2u];

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
immpc_head_s*
IMMPC_GetTypeMessage(
	const uint8_t 	*pData,
	size_t 			buffSize)
{
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

			/* Выход из цикла for (Пакет нашли, разобрали его тип, не нужно
			 * тратить драгоценное время контроллера на попытку найти еще один) */
			break;
		}
	}

	/* выход */
	return (pMessageHead);
}

uint32_t
IMMPC_ConvertIDandPackRequest2FlagNeed(
	immpc_id_and_pack_requests_e idAndPackRequest)
{

}
/*#### |End  | <-- Секция - "Описание локальных функций" #####################*/


/*#### |Begin| --> Секция - "Обработчики прерываний" #########################*/
/*#### |End  | <-- Секция - "Обработчики прерываний" #########################*/

/*############################################################################*/
/*############################ END OF FILE  ##################################*/
/*############################################################################*/
