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

///* указатель на структуру
// * !!! необходимо проинициализировать
// *
// */
//immpc_meas_data_s *pIMMPC_MeasData_s;

//static
//immpc_pointer_data_s
//IMMPC_pointerSetData_s;

/*#### |End  | <-- Секция - "Локальные переменные" ###########################*/


/*#### |Begin| --> Секция - "Прототипы локальных функций" ####################*/
//static uint16_t
//IMMPC_GetCRC_Generic(
//	uint8_t *pData,
//	uint16_t len);

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

//static void
//IMMPC_SetDataMessageToStruct(
//	uint8_t *pData,
//	void *pStruct,
//	size_t structSize);

immpc_id_and_pack_requests_e
IMMPC_GetTypeMessage(
	const uint8_t 	*pData,
	size_t 			buffSize,
	immpc_head_s 	*pMessageHead);

static size_t
IMMPC_GenerateResponseMessage(
	immpc_response_cmd_s 	*pResponseCmd,
	immpc_message_id_e 		idResponse);

static size_t
IMMPC_GenerateCalibMatrixMessage(
	uint8_t *pData,
	immpc_id_and_pack_requests_e setTypeMessage,
	double *pCalibMatrix3x4);

//__IMMPC_ALWAYS_INLINE void
//IMMPC_CopyMeasData_FPT(
//	__IMMPC_FPT__ *pDataSet,
//	__IMMPC_FPT__ *pDataGet);

//__IMMPC_ALWAYS_INLINE void
//IMMPC_CopyMeasData_int16(
//	int16_t *pDataSet,
//	int16_t *pDataGet);

////#define IMMPC_SetRawMainAcc(pVar)			IMMPC_CopyMeasData_int16(&(pIMMPC_MeasData_s->rawMainAcc_a[0u]), pVar)
////#define IMMPC_GetRawMainAcc(pVarArray, dataMeasStruct)		IMMPC_CopyMeasData_int16(pVarArray, &(dataMeasStruct.
////
////&(pIMMPC_MeasData_s->rawMainAcc_a[0u]), pVar)
//#define IMMPC_SetRawMainGyr(pVar)			IMMPC_CopyMeasData_int16(&(pIMMPC_MeasData_s->rawMainGyr_a[0u]), pVar)
//#define IMMPC_GetRawMainGyr(pVar)			IMMPC_CopyMeasData_int16(pVar, &(pIMMPC_MeasData_s->rawMainGyr_a[0u]))
//
//#define IMMPC_SetRawReserveAcc(pVar)		IMMPC_CopyMeasData_int16(&(pIMMPC_MeasData_s->rawReserveAcc_a[0u]), pVar)
//#define IMMPC_GetRawReserveAcc(pVar)		IMMPC_CopyMeasData_int16(pVar, &(pIMMPC_MeasData_s->rawReserveAcc_a[0u]))
//#define IMMPC_SetRawReserveGyr(pVar)		IMMPC_CopyMeasData_int16(&(pIMMPC_MeasData_s->rawReserveGyr_a[0u]), pVar)
//#define IMMPC_GetRawReserveGyr(pVar)		IMMPC_CopyMeasData_int16(pVar, &(pIMMPC_MeasData_s->rawReserveGyr_a[0u]))
//
//#define IMMPC_SetRawMainTempAcc(pVar)		IMMPC_CopyMeasData_int16(&(pIMMPC_MeasData_s->rawMainTempAcc_a[0u]), pVar)
//#define IMMPC_GetRawMainTempAcc(pVar)		IMMPC_CopyMeasData_int16(pVar, &(pIMMPC_MeasData_s->rawMainTempAcc_a[0u]))
//#define IMMPC_SetRawMainTempGyr(pVar)		IMMPC_CopyMeasData_int16(&(pIMMPC_MeasData_s->rawMainTempGyr_a[0u]), pVar)
//#define IMMPC_GetRawMainTempGyr(pVar)		IMMPC_CopyMeasData_int16(pVar, &(pIMMPC_MeasData_s->rawMainTempGyr_a[0u]))
//
//#define IMMPC_SetRawReserveTempAcc(pVar)	IMMPC_CopyMeasData_int16(&(pIMMPC_MeasData_s->rawReserveTempAcc_a[0u]), pVar)
//#define IMMPC_GetRawReserveTempAcc(pVar)	IMMPC_CopyMeasData_int16(pVar, &(pIMMPC_MeasData_s->rawReserveTempAcc_a[0u]))
//#define IMMPC_SetRawReserveTempGyr(pVar)	IMMPC_CopyMeasData_int16(&(pIMMPC_MeasData_s->rawReserveTempGyr_a[0u]), pVar)
//#define IMMPC_GetRawReserveTempGyr(pVar)	IMMPC_CopyMeasData_int16(pVar, &(pIMMPC_MeasData_s->rawReserveTempGyr_a[0u]))
//
//#define IMMPC_SetRawMag(pVar)				IMMPC_CopyMeasData_int16(&(pIMMPC_MeasData_s->rawMag_a[0u]), pVar)
//#define IMMPC_GetRawMag(pVar)				IMMPC_CopyMeasData_int16(pVar, &(pIMMPC_MeasData_s->rawMag_a[0u]))
//
//#define IMMPC_SetRawMagSelfTest(pVar)		IMMPC_CopyMeasData_int16(&(pIMMPC_MeasData_s->rawMagSelfTest_a[0u]), pVar)
//#define IMMPC_GetRawMagSelfTest(pVar)		IMMPC_CopyMeasData_int16(pVar, &(pIMMPC_MeasData_s->rawMagSelfTest_a[0u]))

//#define IMMPC_SetCalibMainAcc(pVar)			IMMPC_CopyMeasData_FPT(&(pIMMPC_MeasData_s->calibMainAcc[0u]),	pVar)
//#define IMMPC_GetCalibMainAcc(pVar)			IMMPC_CopyMeasData_FPT(pVar, &(pIMMPC_MeasData_s->calibMainAcc[0u]))
//#define IMMPC_SetCalibMainGyr(pVar)			IMMPC_CopyMeasData_FPT(&(pIMMPC_MeasData_s->calibMainGyr[0u]),	pVar)
//#define IMMPC_GetCalibMainGyr(pVar)			IMMPC_CopyMeasData_FPT(pVar, &(pIMMPC_MeasData_s->calibMainGyr[0u]))
//
//#define IMMPC_SetCalibReserveAcc(pVar)		IMMPC_CopyMeasData_FPT(&(pIMMPC_MeasData_s->calibReserveAcc[0u]),	pVar)
//#define IMMPC_GetCalibReserveAcc(pVar)		IMMPC_CopyMeasData_FPT(pVar, &(pIMMPC_MeasData_s->calibMainAcc[0u]))
//#define IMMPC_SetCalibReserveGyr(pVar)		IMMPC_CopyMeasData_FPT(&(pIMMPC_MeasData_s->calibMainGyr[0u]),	pVar)
//#define IMMPC_GetCalibReserveGyr(pVar)		IMMPC_CopyMeasData_FPT(pVar, &(pIMMPC_MeasData_s->calibMainGyr[0u]))
//
//#define IMMPC_SetNormMainTempAcc(pVar)		IMMPC_CopyMeasData_FPT(&(pIMMPC_MeasData_s->normMainTempAcc[0u]),	pVar)
//#define IMMPC_GetNormMainTempAcc(pVar)		IMMPC_CopyMeasData_FPT(pVar, &(pIMMPC_MeasData_s->normMainTempAcc[0u]))
//#define IMMPC_SetNormMainTempGyr(pVar)		IMMPC_CopyMeasData_FPT(&(pIMMPC_MeasData_s->normMainTempGyr[0u]),	pVar)
//#define IMMPC_GetNormMainTempGyr(pVar)		IMMPC_CopyMeasData_FPT(pVar, &(pIMMPC_MeasData_s->normMainTempGyr[0u]))
//
//#define IMMPC_SetNormReserveTempAcc(pVar)	IMMPC_CopyMeasData_FPT(&(pIMMPC_MeasData_s->normReserveTempAcc_a[0u]),	pVar)
//#define IMMPC_GetNormReserveTempAcc(pVar)	IMMPC_CopyMeasData_FPT(pVar, &(pIMMPC_MeasData_s->normReserveTempAcc[0u]))
//#define IMMPC_SetNormReserveTempGyr(pVar)	IMMPC_CopyMeasData_FPT(&(pIMMPC_MeasData_s->normReserveTempGyr_a[0u]),	pVar)
//#define IMMPC_GetNormReserveTempGyr(pVar)	IMMPC_CopyMeasData_FPT(pVar, &(pIMMPC_MeasData_s->normReserveTempGyr[0u]))
//
//#define IMMPC_SetCalibMag(pVar)				IMMPC_CopyMeasData_FPT(&(pIMMPC_MeasData_s->calibMag_a[0u]), pVar)
//#define IMMPC_GetCalibMag(pVar)				IMMPC_CopyMeasData_FPT(pVar, &(pIMMPC_MeasData_s->calibMag_a[0u]))


/*#### |End  | <-- Секция - "Прототипы локальных функций" ####################*/


/*#### |Begin| --> Секция - "Описание глобальных функций" ####################*/
/*-------------------------------------------------------------------------*//**
 * @author	Dmitry Tanikeev
 * @date	08-ноя-2019
 *
 * @brief	Функция выполняет сохранение указателей на структуры для ответных сообщений
 *
 * @param[in]	pDataMeas_s: Указатель на область данных, в которой будут храниться данные полученные из датчика.
 */

///* Не правильно, в данном случае в функцию нужно передавать не структуру, а указатель
// * на структуру, т.к. в противном случае при выходе из функции IMMPC_PointerDataInit()
// * структура pointerSetData_s будет уничтожена */
//void
//IMMPC_PointerDataInit(
//	immpc_meas_data_s *pDataMeas_s)
//{
//	pIMMPC_MeasData_s = pDataMeas_s;
//
////	/* сохранение структуры указателей */
////	IMMPC_pointerSetData_s = pointerSetData_s;
////
////	/* заполнение "шапки" пакетов */
////	if (IMMPC_pointerSetData_s.pIMMPC_9DOF_main_raw_pack_s != NULL)
////	{
////		((*(IMMPC_pointerSetData_s.pIMMPC_9DOF_main_raw_pack_s)).headMessage_s).startFrame = IMMPC_START_FRAME;
////		((*(IMMPC_pointerSetData_s.pIMMPC_9DOF_main_raw_pack_s)).headMessage_s).messageID = IMMPC_MESSAGE_ID_9DOF_PACK_MAIN;
////		((*(IMMPC_pointerSetData_s.pIMMPC_9DOF_main_raw_pack_s)).headMessage_s).packRequests = (uint8_t) 0u;
////	}
////
////	if (IMMPC_pointerSetData_s.pIMMPC_9DOF_main_calib_pack_s != NULL)
////	{
////		((*(IMMPC_pointerSetData_s.pIMMPC_9DOF_main_calib_pack_s)).headMessage_s).startFrame = IMMPC_START_FRAME;
////		((*(IMMPC_pointerSetData_s.pIMMPC_9DOF_main_calib_pack_s)).headMessage_s).messageID = IMMPC_MESSAGE_ID_9DOF_PACK_MAIN;
////		((*(IMMPC_pointerSetData_s.pIMMPC_9DOF_main_calib_pack_s)).headMessage_s).packRequests = (uint8_t) IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS;
////	}
////
////	if (IMMPC_pointerSetData_s.pIMMPC_9DOF_reserve_raw_pack_s != NULL)
////	{
////		((*(IMMPC_pointerSetData_s.pIMMPC_9DOF_reserve_raw_pack_s)).headMessage_s).startFrame = IMMPC_START_FRAME;
////		((*(IMMPC_pointerSetData_s.pIMMPC_9DOF_reserve_raw_pack_s)).headMessage_s).messageID = IMMPC_MESSAGE_ID_9DOF_PACK_RESERVE;
////		((*(IMMPC_pointerSetData_s.pIMMPC_9DOF_reserve_raw_pack_s)).headMessage_s).packRequests = (uint8_t) IMMPC_PACK_REQUESTS_BITS_RESERVE_MEAS;
////	}
////
////	if (IMMPC_pointerSetData_s.pIMMPC_9DOF_reserve_calib_pack_s != NULL)
////	{
////		((*(IMMPC_pointerSetData_s.pIMMPC_9DOF_reserve_calib_pack_s)).headMessage_s).startFrame = IMMPC_START_FRAME;
////		((*(IMMPC_pointerSetData_s.pIMMPC_9DOF_reserve_calib_pack_s)).headMessage_s).messageID = IMMPC_MESSAGE_ID_9DOF_PACK_RESERVE;
////		((*(IMMPC_pointerSetData_s.pIMMPC_9DOF_reserve_calib_pack_s)).headMessage_s).packRequests =	(uint8_t) (
////					IMMPC_PACK_REQUESTS_BITS_RESERVE_MEAS |
////					IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS);
////	}
////
////	if (IMMPC_pointerSetData_s.pIMMPC_MAG3DOF_raw_pack_s != NULL)
////	{
////		((*(IMMPC_pointerSetData_s.pIMMPC_MAG3DOF_raw_pack_s)).headMessage_s).startFrame = IMMPC_START_FRAME;
////		((*(IMMPC_pointerSetData_s.pIMMPC_MAG3DOF_raw_pack_s)).headMessage_s).messageID = IMMPC_MESSAGE_ID_MAG3DOF_PACK;
////		((*(IMMPC_pointerSetData_s.pIMMPC_MAG3DOF_raw_pack_s)).headMessage_s).packRequests = (uint8_t) 0u;
////	}
////
////	if (IMMPC_pointerSetData_s.pIMMPC_MAG3DOF_calib_pack_s != NULL)
////	{
////		((*(IMMPC_pointerSetData_s.pIMMPC_MAG3DOF_calib_pack_s)).headMessage_s).startFrame = IMMPC_START_FRAME;
////		((*(IMMPC_pointerSetData_s.pIMMPC_MAG3DOF_calib_pack_s)).headMessage_s).messageID = IMMPC_MESSAGE_ID_MAG3DOF_PACK;
////		((*(IMMPC_pointerSetData_s.pIMMPC_MAG3DOF_calib_pack_s)).headMessage_s).packRequests = (uint8_t) IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS;
////	}
////
////	if (IMMPC_pointerSetData_s.pIMMPC_ACC3DOF_main_calibmatrix_pack_s != NULL)
////	{
////		((*(IMMPC_pointerSetData_s.pIMMPC_ACC3DOF_main_calibmatrix_pack_s)).headMessage_s).startFrame = IMMPC_START_FRAME;
////		((*(IMMPC_pointerSetData_s.pIMMPC_ACC3DOF_main_calibmatrix_pack_s)).headMessage_s).messageID = IMMPC_MESSAGE_ID_ACC3DOF_CALIBMATRIX;
////		((*(IMMPC_pointerSetData_s.pIMMPC_ACC3DOF_main_calibmatrix_pack_s)).headMessage_s).packRequests = (uint8_t) IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS;
////	}
////
////	if (IMMPC_pointerSetData_s.pIMMPC_ACC3DOF_reserve_calibmatrix_pack_s != NULL)
////	{
////		((*(IMMPC_pointerSetData_s.pIMMPC_ACC3DOF_reserve_calibmatrix_pack_s)).headMessage_s).startFrame = IMMPC_START_FRAME;
////		((*(IMMPC_pointerSetData_s.pIMMPC_ACC3DOF_reserve_calibmatrix_pack_s)).headMessage_s).messageID = IMMPC_MESSAGE_ID_ACC3DOF_CALIBMATRIX;
////		((*(IMMPC_pointerSetData_s.pIMMPC_ACC3DOF_reserve_calibmatrix_pack_s)).headMessage_s).packRequests =	(uint8_t) (
////					IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS |
////					IMMPC_PACK_REQUESTS_BITS_RESERVE_MEAS);
////	}
////
////	if (IMMPC_pointerSetData_s.pIMMPC_GYR3DOF_main_calibmatrix_pack_s != NULL)
////	{
////		((*(IMMPC_pointerSetData_s.pIMMPC_GYR3DOF_main_calibmatrix_pack_s)).headMessage_s).startFrame = IMMPC_START_FRAME;
////		((*(IMMPC_pointerSetData_s.pIMMPC_GYR3DOF_main_calibmatrix_pack_s)).headMessage_s).messageID = IMMPC_MESSAGE_ID_GYR3DOF_CALIBMATRIX;
////		((*(IMMPC_pointerSetData_s.pIMMPC_GYR3DOF_main_calibmatrix_pack_s)).headMessage_s).packRequests =	(uint8_t) IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS;
////	}
////
////	if (IMMPC_pointerSetData_s.pIMMPC_GYR3DOF_reserve_calibmatrix_pack_s != NULL)
////	{
////		((*(IMMPC_pointerSetData_s.pIMMPC_GYR3DOF_reserve_calibmatrix_pack_s)).headMessage_s).startFrame = IMMPC_START_FRAME;
////		((*(IMMPC_pointerSetData_s.pIMMPC_GYR3DOF_reserve_calibmatrix_pack_s)).headMessage_s).messageID = IMMPC_MESSAGE_ID_GYR3DOF_CALIBMATRIX;
////		((*(IMMPC_pointerSetData_s.pIMMPC_GYR3DOF_reserve_calibmatrix_pack_s)).headMessage_s).packRequests =	(uint8_t) (
////					IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS |
////					IMMPC_PACK_REQUESTS_BITS_RESERVE_MEAS);
////	}
////
////	if (IMMPC_pointerSetData_s.pIMMPC_MAG3DOF_calibmatrix_pack_s != NULL)
////	{
////		((*(IMMPC_pointerSetData_s.pIMMPC_MAG3DOF_calibmatrix_pack_s)).headMessage_s).startFrame = IMMPC_START_FRAME;
////		((*(IMMPC_pointerSetData_s.pIMMPC_MAG3DOF_calibmatrix_pack_s)).headMessage_s).messageID = IMMPC_MESSAGE_ID_MAG3DOF_CALIBMATRIX;
////		((*(IMMPC_pointerSetData_s.pIMMPC_MAG3DOF_calibmatrix_pack_s)).headMessage_s).packRequests =	(uint8_t) (
////					IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS);
////	}
//}

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
immpc_id_and_pack_requests_e
IMMPC_GetTypeMessage(
	const uint8_t 	*pData,
	size_t 			buffSize,
	immpc_head_s 	*pMessageHead)
{
	/* присвоение стартовых значений */
	immpc_id_and_pack_requests_e messageType_e = IMMPC_ID_AND_PACK_REQUESTS_error_e;

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
	return (messageType_e);
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

/* Пакет 9dof_main_calib_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

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
		IMMPC_GetCRC_9dof_main_calib_pack(pPack_s);

	if (crc == pPack_s->crc)
	{
		return (1u);
	}
	else
	{
		return (0u);
	}
}
/* Пакет 9dof_main_calib_pack_s --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* Пакет 9dof_reserve_raw_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

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
		IMMPC_GetCRC_9dof_reserve_raw_pack(pPack_s);

	if (crc == pPack_s->crc)
	{
		return (1u);
	}
	else
	{
		return (0u);
	}
}
/* Пакет 9dof_reserve_raw_pack_s --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* Пакет 9dof_reserve_calib_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

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
		IMMPC_GetCRC_9dof_reserve_calib_pack(pPack_s);

	if (crc == pPack_s->crc)
	{
		return (1u);
	}
	else
	{
		return (0u);
	}
}
/* Пакет 9dof_reserve_calib_pack_s --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* Пакет mag3dof_raw_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

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
		IMMPC_GetCRC_mag3dof_raw_pack(pPack_s);

	if (crc == pPack_s->crc)
	{
		return (1u);
	}
	else
	{
		return (0u);
	}
}
/* Пакет mag3dof_raw_pack_s --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

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
		IMMPC_GetCRC_mag3dof_calib_pack(pPack_s);

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

/* Пакет immpc_acc3dof_main_calibmatrix_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>> */

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
		IMMPC_GetCRC_acc3dof_main_calibmatrix_pack(pPack_s);

	if (crc == pPack_s->crc)
	{
		return (1u);
	}
	else
	{
		return (0u);
	}
}
/* Пакет immpc_acc3dof_main_calibmatrix_read_pack_s --<<<<<<<<<<<<<<<<<<<<<<< */

/* Пакет immpc_acc3dof_reserve_calibmatrix_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>> */

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
		IMMPC_GetCRC_acc3dof_reserve_calibmatrix_pack(pPack_s);

	if (crc == pPack_s->crc)
	{
		return (1u);
	}
	else
	{
		return (0u);
	}
}
/* Пакет immpc_acc3dof_reserve_calibmatrix_read_pack_s --<<<<<<<<<<<<<<<<<<<< */

/* Пакет immpc_gyr3dof_main_calibmatrix_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>> */

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
		IMMPC_GetCRC_gyr3dof_main_calibmatrix_pack(pPack_s);

	if (crc == pPack_s->crc)
	{
		return (1u);
	}
	else
	{
		return (0u);
	}
}
/* Пакет immpc_gyr3dof_main_calibmatrix_read_pack_s --<<<<<<<<<<<<<<<<<<<<<<<<*/

/* Пакет immpc_gyr3dof_reserve_calibmatrix_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>*/

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
		IMMPC_GetCRC_gyr3dof_reserve_calibmatrix_pack(pPack_s);

	if (crc == pPack_s->crc)
	{
		return (1u);
	}
	else
	{
		return (0u);
	}
}
/* Пакет immpc_gyr3dof_reserve_calibmatrix_read_pack_s --<<<<<<<<<<<<<<<<<<<<<<*/

/* Пакет immpc_mag3dof_calibmatrix_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

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
		IMMPC_GetCRC_mag3dof_calibmatrix_pack(pPack_s);

	if (crc == pPack_s->crc)
	{
		return (1u);
	}
	else
	{
		return (0u);
	}
}
/* Пакет immpc_mag3dof_calibmatrix_read_pack_s --<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* Пакеты запросов и команд -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

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


/* Пакет запросов и команд --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

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
	immpc_response_cmd_s 	*pResponseCmd,
	immpc_message_id_e 		idResponse)
{
	pResponseCmd->startFrame 	= IMMPC_START_FRAME;
	pResponseCmd->messageID 	= idResponse;
	pResponseCmd->endFrame 		= IMMPC_RESPONCE_END_FRAME;

	return ((size_t) sizeof(immpc_response_cmd_s));
}

/*-------------------------------------------------------------------------*//**
 * @author    Dmitry Tanikeev
 * @date    18-ноя-2019
 *
 * @brief    Функция формирует ответ на запрос
 *
 * @param[out]    *pData:     Указатель на область памяти, в которой будут содержаться
 *                             данные
 *
 * @param[in]    setTypeMessage:    Тип пакета данных

*
 * @param[in]    *pCalibMatrix3x4:    Указатель на область памяти, в которой храняться калибровочные матрицы
 *
 * @return Количество байт данных
 */
static size_t
IMMPC_GenerateCalibMatrixMessage(
	uint8_t *pData,
	immpc_id_and_pack_requests_e setTypeMessage,
	double *pCalibMatrix3x4)
{

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
	immpc_id_and_pack_requests_e messageType_e =
		IMMPC_GetTypeMessage(
			pInputBuff,
			inputBuffSize,
			pHeadMessage_s);

	/* Использовать конструкцию switc-case */

	/* Если пришла команда на запрос данных */
//	if (__IMMPC_PACK_REQUESTS_BITS_IsSetRequestData(pHeadMessage_s->packRequests))
//	{
//		/* Проверить контрольную сумму */
//		immpc_request_cmd_s *pRequestCmd_s =
//			(immpc_request_cmd_s*) pHeadMessage_s;
//		if (pRequestCmd_s->crc == IMMPC_GetCRC_Generic((uint8_t*) pRequestCmd_s, (uint16_t) sizeof(pRequestCmd_s)))
//		{
//			/* Если запрос "сырых" данных резервных измерителей */
//			if (__IIMPC_PACK_REQUESTS_BITS_IsSetReservMeas(pHeadMessage_s->packRequests))
//			{
//				/* Генерация пакета данных */
//				*pOutBuffByteNumbForTx =
//					IMMPC_Generate_9dof_reserve_raw_pack(
//						pRawSensMeas_s,
//						(immpc_9dof_reserve_raw_pack_s*) pOutBuff);
//			}
//		}
//		/* Контрольная сумма не верна */
//		else
//		{
//			/* Генерация пакета данных */
//			*pOutBuffByteNumbForTx =
//				IMMPC_GenerateResponseMessage(
//					(immpc_response_cmd_s*) pOutBuff,
//					IMMPC_MESSAGE_ID_RESPONSE_CODE_INVALID_CRC);
//
//			messageType_e = IMMPC_ID_AND_PACK_REQUESTS_invalid_crc_e;
//		}
//	}
//	/* Если пришла команда и содержит payload */
//	else
//	{
//		/* Если необходимо разобрать пакет, содержащий payload и записать эту payload в оперативную память ИИМ */
//		if (!(__IIMPC_PACK_REQUESTS_BITS_IsSetReadFlag(pHeadMessage_s->idAndPackRequests)))
//		{
//
//		}
//	}

	return (messageType_e);
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

	/* запись типа сообщения (Message ID + Pack requests) */
	pPackForTx_s->head_s.messageID = IMMPC_ID_9dof_main;

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
		pSourceData_s->dataMainAccGyr.sensorStatus |
		pSourceData_s->dataMag.sensorStatus);

	/* сброс статусов сенсора */
	pSourceData_s->dataMainAccGyr.sensorStatus 	= 0;
	pSourceData_s->dataMag.sensorStatus 			= 0;

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

	/* запись типа сообщения (Message ID + Pack requests) */
	pPackForTx_s->head_s.messageID = IMMPC_ID_9dof_raw;

	__IMMPC_WRITE_REG(
		/* Переменная для записи битовых масок */
		pPackForTx_s->head_s.packRequests,

		/* Битовые маски для записи в переменную */
		IMMPC_PACK_REQUESTS_BITS_RESERVE_MEAS);

	/* запись статусов сенсора (Sensors status) */
	__IMMPC_WRITE_REG(
		/* Переменная для записи битовых масок */
		pPackForTx_s->head_s.sensorsStatus,

		/* Битовые маски для записи в переменную */
		pSourceData_s->dataReserveAccGyr.sensorStatus |
		pSourceData_s->dataMag.sensorStatus);

	/* сброс статусов сенсора */
	pSourceData_s->dataReserveAccGyr.sensorStatus 	= 0;
	pSourceData_s->dataMag.sensorStatus 			= 0;

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
	pSourceData_s->dataMag.sensorStatus = 0;

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
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Перезапись данных типа __IMMPC_FPT__.
// *
// * @param[out]	*pDataSet: 	Указатель на область памяти структуры, в которой будут содержаться
// * 							данные
// *
// * @param[in]	*pDataSet:	Указатель на область памяти, из которой будут считываться данные
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_CopyMeasData_FPT(
//	__IMMPC_FPT__ *pDataSet,
//	__IMMPC_FPT__ *pDataGet)
//{
//	*pDataSet++ = *pDataGet++;
//	*pDataSet++ = *pDataGet++;
//	*pDataSet = *pDataGet;
//}

///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Перезапись данных типа int16_t.
// *
// * @param[out]	*pDataSet: 	Указатель на область памяти структуры, в которой будут содержаться
// * 							данные
// *
// * @param[in]	*pDataSet:	Указатель на область памяти, из которой будут считываться данные
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_CopyMeasData_int16(
//	int16_t *pDataSet,
//	int16_t *pDataGet)
//{
//	*pDataSet++ = *pDataGet++;
//	*pDataSet++ = *pDataGet++;
//	*pDataSet = *pDataGet;
//}
/*#### |End  | <-- Секция - "Описание локальных функций" #####################*/


/*#### |Begin| --> Секция - "Обработчики прерываний" #########################*/
/*#### |End  | <-- Секция - "Обработчики прерываний" #########################*/

/*############################################################################*/
/*############################ END OF FILE  ##################################*/
/*############################################################################*/
