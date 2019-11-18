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

//static void
//IMMPC_SetDataMessageToStruct(
//	uint8_t *pData,
//	void *pStruct,
//	size_t structSize);

immpc_message_pack_type_e
IMMPC_GetTypeMessage(
	const uint8_t *pData,
	size_t 	buffSize,
	uint8_t *pMessageHead);

static size_t
IMMPC_GenerateResponseMessage(
	uint8_t *pData,
	immpc_message_id_e idResponse);

static size_t
IMMPC_GenerateRawDataMessage(
	uint8_t *pData,
	immpc_message_pack_type_e setTypeMessage,
	uint16_t sensorStatus,
	int16_t *pDataMeas3dof,
	...);

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
/* Пакет immpc_gyr3dof_reserve_calibmatrix_read_pack_s --<<<<<<<<<<<<<<<<<<<<<</

/* Пакет immpc_mag3dof_calibmatrix_pack_s -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>/

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
	uint8_t *pData,
	immpc_message_id_e idResponse)
{
	*pData++ =	(uint8_t) ((IMMPC_START_FRAME & 0xFF00) >> 8u);
	*pData++ =	(uint8_t) (IMMPC_START_FRAME & 0x00FF);
	*pData++ =	(uint8_t) idResponse;
	*pData =	IMMPC_RESPONCE_END_FRAME;

	return ((size_t) 4u);
}

///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	08-ноя-2019
// *
// * @brief	Функция формирует ответ на запрос
// *
// * @param[out]	*pData: 	Указатель на область памяти, в которой будут содержаться
// * 							данные
// *
// * @param[in]	*pStruct: 	Указатель на область памяти, в которой содержится
// * 							структура данных
// *
// * @param[in]	structSize: Размерность структуры
// *
// * @return Количество байт данных
// */
//static size_t
//IMMPC_GenerateDataMessageFromStruct(
//	uint8_t *pData,
//	void *pStruct,
//	size_t structSize)
//{
//	uint8_t *pDataStruct = (uint8_t*) pStruct;
//
//	/* сохранение данных */
//	size_t i;
//	for (i = 0; i < structSize; i++)
//	{
//		*pData++ = *pDataStruct++;
//	}
//
//	return (structSize);
//}

/*-------------------------------------------------------------------------*//**
 * @author	Dmitry Tanikeev
 * @date	14-ноя-2019
 *
 * @brief	Функция формирует ответ на запрос
 *
 * @param[out]	*pData: 	Указатель на область памяти, в которой будут содержаться
 * 							данные
 *
 * @param[in]	setTypeMessage:	Тип пакета данных
 *
 * @param[in]	sensorStatus: Статус сенсора
 *
 * @param[in]	*pDataMeas3dof:	Указатель на область памяти, в которой храняться данные
 *
 * @param[in]   ...     Остальные указатели для копирования в структуру
 * 						типа "int16_t*"
 * @param[in]   NULL:	нулевой указатель, по которому функция определяет
 *                          		конец передаваемых в функцию параметров
 *
 * @return Количество байт данных
 */
static size_t
IMMPC_GenerateRawDataMessage(
	uint8_t *pData,
	immpc_message_pack_type_e setTypeMessage,
	uint16_t sensorStatus,
	int16_t *pDataMeas3dof,
	...)
{
	/* Объявление указателя на переменное число параметров функции */
	va_list pInParam;

	/* Инициализация указателя */
	va_start(
		pInParam,
		*pDataMeas3dof);

	/* сохранение указателя */
	int16_t *pData3dofTmp;
	pData3dofTmp = pDataMeas3dof;

	int16_t *pRawMeas = pData;

	/* запись стартовых байт (Start frame) */
	/* @todo проверить приведение типов */
	*pRawMeas++ = (int16_t) IMMPC_START_FRAME;
//	*pData[0u] =	(uint8_t) ((IMMPC_START_FRAME & 0xFF00) >> 8u);
//	*pData[1u] =	(uint8_t) (IMMPC_START_FRAME & 0x00FF);

	/* запись типа сообщения (Message ID + Pack requests) */
//	*pData[2u] =	(uint8_t) (((uint16_t) setTypeMessage >> 8u) & 0x00FF);
//	*pData[3u] =	(uint8_t) ((uint16_t) setTypeMessage & 0x00FF);
	/* @todo проверить приведение типов */
	*pRawMeas++ = (int16_t) setTypeMessage;

	/* запись статус сенсора (Sensors status) */
//	*pData[4u] =	(uint8_t) ((sensorStatus >> 8u) & 0x00FF);
//	*pData[5u] =	(uint8_t) (sensorStatus & 0x00FF);
	/* @todo проверить приведение типов */
	*pRawMeas++ = (int16_t) sensorStatus;



	/* Предварительный размер сообщения с учетом CRC */
	size_t messageSize = 8u;

	/* запись полезных данных (Payload) */
	while (pData3dofTmp != NULL)
	{
		for(size_t i = 0u; i < 3u; i++)
		{
//			*pData++ =	(uint8_t) (((*pData3dofTmp) >> 8u) & 0x00FF);
//			*pData++ =	(uint8_t) (*pData3dofTmp++ & 0x00FF);

			*pRawMeas++ = *pData3dofTmp++;
		}


		/* передача указателя */
		/* @todo проверить передачу указателя */
		pData3dofTmp =
			va_arg(
				pInParam,
				int16_t);

		messageSize += 6u;
	}

	/* "закрыть" указатель */
	va_end(pInParam);

	/* вычисление crc */
//	uint16_t *pCrc = (uint16_t*) pRawMeas;
//	*pCrc =
//		CRC_XOR_CCITT_Poly0x1021_Crc16(
//			(uint8_t*)&pData[2u],
//			messageSize - 2u);

	/* @todo проверить приведение типов */
	pRawMeas = (uint16_t*) pRawMeas;
	pRawMeas = IMMPC_GetCRC_Generic(
		(uint8_t*)&pData[2u],
		messageSize);

//	*pData++ =	(uint8_t) ((crc >> 8u) & 0x00FF);
//	*pData++ =	(uint8_t) (crc & 0x00FF);


	return (messageSize);
}

/*-------------------------------------------------------------------------*//**
 * @author	Dmitry Tanikeev
 * @date	18-ноя-2019
 *
 * @brief	Функция формирует ответ на запрос
 *
 * @param[out]	*pData: 	Указатель на область памяти, в которой будут содержаться
 * 							данные
 *
 * @param[in]	setTypeMessage:	Тип пакета данных

*
 * @param[in]	*pCalibMatrix3x4:	Указатель на область памяти, в которой храняться калибровочные матрицы
 *
 * @return Количество байт данных
 */
static size_t
IMMPC_GenerateCalibMatrixMessage(
	uint8_t *pData,
	immpc_message_pack_type_e setTypeMessage,
	double *pCalibMatrix3x4)
{
	/* сохранение указателя */
	int16_t *pCalibMatrixTmp;
	pCalibMatrixTmp = pCalibMatrix3x4;

	int16_t *pPacket = pData;

	/* запись стартовых байт (Start frame) */
	/* @todo проверить приведение типов */
	*pPacket++ = (int16_t) IMMPC_START_FRAME;

	/* запись типа сообщения (Message ID + Pack requests) */
	/* @todo проверить приведение типов */
	*pPacket++ = (int16_t) setTypeMessage;

	/* Предварительный размер сообщения с учетом CRC */
	size_t messageSize = 6u;

	/* прогнать 4x3x4 = 48 раз:
	 * 4 - двуйбайтных числа в типе double
	 * 3x4 - размерность матрицы
	 */
	for(size_t i = 0u; i < 48u; i++)
	{
		*pPacket++ = *pCalibMatrixTmp++;

		messageSize += 2u;
	}

	/* @todo проверить приведение типов */
	pPacket = (uint16_t*) pPacket;
	pPacket = IMMPC_GetCRC_Generic(
		(uint8_t*)&pData[2u],
		messageSize);

	return (messageSize);
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
 * @param[in]	*pIMMPC_RawData_s:	Указатель на область памяти, в которой содержатся данные с датчиков.
 *
 *
 * @param[in]	*pDataIn: 	Указатель на область памяти, в которой содержатся входной пакет данных.
 *
 * @param[in]	buffSizeIn:	Размер данных.
 * @param[out]	*pDataOut:	Указатель на область памяти, в которой будут содержаться данные
 * 							для выходного пакета
 *
 * @param[out]	*pLengthOut:	Количество данных для выходного пакета
 *
 * @return	Тип сообщения (см. immpc_message_pack_type_e)
 */
immpc_message_pack_type_e
IMMPC_GetDataMessage(
	immpc_meas_raw_data_s *pIMMPC_RawData_s,
	uint8_t *pDataIn,
	size_t 	buffSizeIn,
	uint8_t *pDataOut,
	size_t 	*pLengthOut)
{
	/* тип выходного ссобщения */
	immpc_message_pack_type_e messageTypeReturn_e;

	/* указатель на структуру  */
	uint8_t *pDataStruct;

	/* сброс длины выходного массива */
	*pLengthOut = (size_t) 0u;

	/* указатель на начало */
	uint8_t *pMessHeadAddr;

	/* получение типа сообщения */
	messageTypeReturn_e =
		IMMPC_GetTypeMessage(
			pDataIn,
			buffSizeIn,
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
		if (	(buffSizeIn >= (size_t) (sizeof(immpc_9dof_main_raw_pack_s))) &&
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
		if (	(buffSizeIn >= (size_t) (sizeof(immpc_9dof_main_calib_pack_s))) &&
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
		if (	(buffSizeIn >= (size_t) (sizeof(immpc_9dof_reserve_raw_pack_s))) &&
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
		if (	(buffSizeIn >= (size_t) (sizeof(immpc_9dof_reserve_calib_pack_s))) &&
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
		if (	(buffSizeIn >= (size_t) (sizeof(immpc_mag3dof_raw_pack_s))) &&
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
		if (	(buffSizeIn >= (size_t) (sizeof(immpc_mag3dof_calib_pack_s))) &&
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
		if (buffSizeIn >= (size_t) (sizeof(immpc_acc3dof_main_calibmatrix_pack_s)))
		{
			/* CRC правильный */
			if (IMMPC_IsPackValid_acc3dof_main_calibmatrix_pack((immpc_acc3dof_main_calibmatrix_pack_s*) pMessHeadAddr))
			{
				IMMPC_SetDataMessageToStruct(
					pMessHeadAddr,
					&IMMPC_ACC3DOF_main_calibmatrix_pack_s,
					sizeof(immpc_acc3dof_main_calibmatrix_pack_s));

				/* формирование ответа - OK */
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
			/* формирование ответа - ERROR */
			*pLengthOut =
				IMMPC_GenerateResponseMessage(
					pDataOut,
					IMMPC_MESSAGE_ID_RESPONSE_CODE_ERROR);

			messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_acc3dof_main_calibmatrix_read_pack_s:
		/* формирование ответного сообщения ... */
		/* проверка количества символов */
		if (buffSizeIn >= (size_t) (sizeof(immpc_request_or_cmd_pack_s)))
		{
			/* CRC правильный */
			if (IMMPC_IsPackValid_request_or_cmd((immpc_request_or_cmd_pack_s*) pMessHeadAddr))
			{
				/* формирование пакета для ответа */
				*pLengthOut = IMMPC_GenerateCalibMatrixMessage(
					pDataOut,
					IMMPC_MESSAGE_PACK_acc3dof_main_calibmatrix_write_pack_s,
					IMMPC_ACC3DOF_main_calibmatrix_pack_s.matrix);
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
			/* формирование ответа - ERROR */
			*pLengthOut =
				IMMPC_GenerateResponseMessage(
					pDataOut,
					IMMPC_MESSAGE_ID_RESPONSE_CODE_ERROR);

			messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_acc3dof_reserve_calibmatrix_write_pack_s:
		/* проверка количества символов */
		if (buffSizeIn >= (size_t) (sizeof(immpc_acc3dof_reserve_calibmatrix_pack_s)))
		{
			/* CRC правильный */
			if (IMMPC_IsPackValid_acc3dof_reserve_calibmatrix_pack((immpc_acc3dof_reserve_calibmatrix_pack_s*) pMessHeadAddr))
			{
				IMMPC_SetDataMessageToStruct(
					pMessHeadAddr,
					&IMMPC_ACC3DOF_reserve_calibmatrix_pack_s,
					sizeof(immpc_acc3dof_reserve_calibmatrix_pack_s));

				/* формирование ответа - OK */
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
			/* формирование ответа - ERROR */
			*pLengthOut =
				IMMPC_GenerateResponseMessage(
					pDataOut,
					IMMPC_MESSAGE_ID_RESPONSE_CODE_ERROR);

			messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_acc3dof_reserve_calibmatrix_read_pack_s:
		/* формирование ответного сообщения ... */
		/* проверка количества символов */
		if (buffSizeIn >= (size_t) (sizeof(immpc_request_or_cmd_pack_s)))
		{
			/* CRC правильный */
			if (IMMPC_IsPackValid_request_or_cmd((immpc_request_or_cmd_pack_s*) pMessHeadAddr))
			{
				/* формирование пакета для ответа */
				*pLengthOut = IMMPC_GenerateCalibMatrixMessage(
					pDataOut,
					IMMPC_MESSAGE_PACK_acc3dof_reserve_calibmatrix_write_pack_s,
					IMMPC_ACC3DOF_reserve_calibmatrix_pack_s.matrix);
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
			/* формирование ответа - ERROR */
			*pLengthOut =
				IMMPC_GenerateResponseMessage(
					pDataOut,
					IMMPC_MESSAGE_ID_RESPONSE_CODE_ERROR);

			messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_gyr3dof_main_calibmatrix_write_pack_s:
		/* проверка количества символов */
		if (buffSizeIn >= (size_t) (sizeof(immpc_gyr3dof_main_calibmatrix_pack_s)))
		{
			/* CRC правильный */
			if (IMMPC_IsPackValid_gyr3dof_main_calibmatrix_pack((immpc_gyr3dof_main_calibmatrix_pack_s*) pMessHeadAddr))
			{
				IMMPC_SetDataMessageToStruct(
					pMessHeadAddr,
					&IMMPC_GYR3DOF_main_calibmatrix_pack_s,
					sizeof(immpc_gyr3dof_main_calibmatrix_pack_s));

				/* формирование ответа - OK */
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
			/* формирование ответа - ERROR */
			*pLengthOut =
				IMMPC_GenerateResponseMessage(
					pDataOut,
					IMMPC_MESSAGE_ID_RESPONSE_CODE_ERROR);

			messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_gyr3dof_main_calibmatrix_read_pack_s:
		/* формирование ответного сообщения ... */
		/* проверка количества символов */
		if (buffSizeIn >= (size_t) (sizeof(immpc_request_or_cmd_pack_s)))
		{
			/* CRC правильный */
			if (IMMPC_IsPackValid_request_or_cmd((immpc_request_or_cmd_pack_s*) pMessHeadAddr))
			{
				/* формирование пакета для ответа */
				*pLengthOut = IMMPC_GenerateCalibMatrixMessage(
					pDataOut,
					IMMPC_MESSAGE_PACK_gyr3dof_main_calibmatrix_write_pack_s,
					IMMPC_GYR3DOF_main_calibmatrix_pack_s.matrix);
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
			/* формирование ответа - ERROR */
			*pLengthOut =
				IMMPC_GenerateResponseMessage(
					pDataOut,
					IMMPC_MESSAGE_ID_RESPONSE_CODE_ERROR);

			messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_gyr3dof_reserve_calibmatrix_write_pack_s:
		/* проверка количества символов */
		if (buffSizeIn >= (size_t) (sizeof(immpc_gyr3dof_reserve_calibmatrix_pack_s)))
		{
			/* CRC правильный */
			if (IMMPC_IsPackValid_gyr3dof_reserve_calibmatrix_pack((immpc_gyr3dof_reserve_calibmatrix_pack_s*) pMessHeadAddr))
			{
				IMMPC_SetDataMessageToStruct(
					pMessHeadAddr,
					&IMMPC_GYR3DOF_reserve_calibmatrix_pack_s,
					sizeof(immpc_gyr3dof_reserve_calibmatrix_pack_s));

				/* формирование ответа - OK */
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
			/* формирование ответа - ERROR */
			*pLengthOut =
				IMMPC_GenerateResponseMessage(
					pDataOut,
					IMMPC_MESSAGE_ID_RESPONSE_CODE_ERROR);

			messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_gyr3dof_reserve_calibmatrix_read_pack_s:
		/* формирование ответного сообщения ... */
		/* проверка количества символов */
		if (buffSizeIn >= (size_t) (sizeof(immpc_request_or_cmd_pack_s)))
		{
			/* CRC правильный */
			if (IMMPC_IsPackValid_request_or_cmd((immpc_request_or_cmd_pack_s*) pMessHeadAddr))
			{
				/* формирование пакета для ответа */
				*pLengthOut = IMMPC_GenerateCalibMatrixMessage(
					pDataOut,
					IMMPC_MESSAGE_PACK_gyr3dof_reserve_calibmatrix_write_pack_s,
					IMMPC_GYR3DOF_reserve_calibmatrix_pack_s.matrix);
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
			/* формирование ответа - ERROR */
			*pLengthOut =
				IMMPC_GenerateResponseMessage(
					pDataOut,
					IMMPC_MESSAGE_ID_RESPONSE_CODE_ERROR);

			messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_mag3dof_calibmatrix_write_pack_s:
		/* проверка количества символов */
		if (buffSizeIn >= (size_t) (sizeof(immpc_mag3dof_calibmatrix_pack_s)))
		{
			/* CRC правильный */
			if (IMMPC_IsPackValid_mag3dof_calibmatrix_pack((immpc_mag3dof_calibmatrix_pack_s*) pMessHeadAddr))
			{
				IMMPC_SetDataMessageToStruct(
					pMessHeadAddr,
					&IMMPC_MAG3DOF_calibmatrix_pack_s,
					sizeof(immpc_mag3dof_calibmatrix_pack_s));

				/* формирование ответа - OK */
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
			/* формирование ответа - ERROR */
			*pLengthOut =
				IMMPC_GenerateResponseMessage(
					pDataOut,
					IMMPC_MESSAGE_ID_RESPONSE_CODE_ERROR);

			messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_mag3dof_calibmatrix_read_pack_s:
		/* формирование ответного сообщения ... */
		/* проверка количества символов */
		if (buffSizeIn >= (size_t) (sizeof(immpc_request_or_cmd_pack_s)))
		{
			/* CRC правильный */
			if (IMMPC_IsPackValid_request_or_cmd((immpc_request_or_cmd_pack_s*) pMessHeadAddr))
			{
				/* формирование пакета для ответа */
				*pLengthOut = IMMPC_GenerateCalibMatrixMessage(
					pDataOut,
					IMMPC_MESSAGE_PACK_mag3dof_calibmatrix_write_pack_s,
					IMMPC_MAG3DOF_calibmatrix_pack_s.matrix);
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
			/* формирование ответа - ERROR */
			*pLengthOut =
				IMMPC_GenerateResponseMessage(
					pDataOut,
					IMMPC_MESSAGE_ID_RESPONSE_CODE_ERROR);

			messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	/* запросы */
	case IMMPC_MESSAGE_PACK_9dof_main_raw_request_cmd_s:
		/* формирование ответного сообщения ... */
		/* проверка количества символов */
		if (buffSizeIn >= (size_t) (sizeof(immpc_request_or_cmd_pack_s)))
		{
			/* CRC правильный */
			if (IMMPC_IsPackValid_request_or_cmd((immpc_request_or_cmd_pack_s*) pMessHeadAddr))
			{
				/* установка флага */
				__IMMPC_SET_BIT(
					(*pIMMPC_RawData_s).flagsUseData,
					IMMPC_FLAG_NEED_RAW_MAIN_ACC |
					IMMPC_FLAG_NEED_RAW_MAIN_GYR |
					IMMPC_FLAG_NEED_RAW_MAIN_TEMP_ACC |
					IMMPC_FLAG_NEED_RAW_MAIN_TEMP_GYR |
					IMMPC_FLAG_NEED_RAW_MAG |
					IMMPC_FLAG_NEED_RAW_MAG_SELF_TEST);

				/* сброс флагов */
				__IMMPC_CLEAR_BIT(
					(*pIMMPC_RawData_s).flagsUseData,
					IMMPC_FLAG_NEED_RAW_RESERVE_ACC |
					IMMPC_FLAG_NEED_RAW_RESERVE_GYR |
					IMMPC_FLAG_NEED_RAW_RESERVE_TEMP_ACC |
					IMMPC_FLAG_NEED_RAW_RESERVE_TEMP_GYR);

				/* формирование пакета для ответа */
				*pLengthOut = IMMPC_GenerateRawDataMessage(
					pDataOut,
					IMMPC_MESSAGE_PACK_9dof_main_raw_pack_s,
					(pIMMPC_RawData_s->dataMainAccGyr).sensorStatus,
					(pIMMPC_RawData_s->dataMainAccGyr).rawMainAcc_a,
					(pIMMPC_RawData_s->dataMainAccGyr).rawMainGyr_a,
					(pIMMPC_RawData_s->dataMag).rawMag_a,
					(pIMMPC_RawData_s->dataMainAccGyr).rawMainTempAcc_a,
					(pIMMPC_RawData_s->dataMainAccGyr).rawMainTempGyr_a,
					(pIMMPC_RawData_s->dataMag).rawMagSelfTest,
					NULL);
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
			/* формирование ответа - ERROR */
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
		/* проверка количества символов */
		if (buffSizeIn >= (size_t) (sizeof(immpc_request_or_cmd_pack_s)))
		{
			/* CRC правильный */
			if (IMMPC_IsPackValid_request_or_cmd((immpc_request_or_cmd_pack_s*) pMessHeadAddr))
			{
				/* установка флага */
				__IMMPC_SET_BIT(
					(*pIMMPC_RawData_s).flagsUseData,
					IMMPC_FLAG_NEED_RAW_RESERVE_ACC |
					IMMPC_FLAG_NEED_RAW_RESERVE_GYR |
					IMMPC_FLAG_NEED_RAW_RESERVE_TEMP_ACC |
					IMMPC_FLAG_NEED_RAW_RESERVE_TEMP_GYR |
					IMMPC_FLAG_NEED_RAW_MAG |
					IMMPC_FLAG_NEED_RAW_MAG_SELF_TEST);

				/* сброс флагов */
				__IMMPC_CLEAR_BIT(
					(*pIMMPC_RawData_s).flagsUseData,
					IMMPC_FLAG_NEED_RAW_MAIN_ACC |
					IMMPC_FLAG_NEED_RAW_MAIN_GYR |
					IMMPC_FLAG_NEED_RAW_MAIN_TEMP_ACC |
					IMMPC_FLAG_NEED_RAW_MAIN_TEMP_GYR);

				/* формирование пакета для ответа */
				*pLengthOut = IMMPC_GenerateRawDataMessage(
					pDataOut,
					IMMPC_MESSAGE_PACK_9dof_reserve_raw_pack_s,
					(pIMMPC_RawData_s->dataReserveAccGyr).sensorStatus,
					(pIMMPC_RawData_s->dataReserveAccGyr).rawReserveAcc_a,
					(pIMMPC_RawData_s->dataReserveAccGyr).rawReserveGyr_a,
					(pIMMPC_RawData_s->dataMag).rawMag_a,
					(pIMMPC_RawData_s->dataReserveAccGyr).rawReserveTempAcc_a,
					(pIMMPC_RawData_s->dataReserveAccGyr).rawReserveTempGyr_a,
					(pIMMPC_RawData_s->dataMag).rawMagSelfTest,
					NULL);
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
			/* формирование ответа - ERROR */
			*pLengthOut =
				IMMPC_GenerateResponseMessage(
					pDataOut,
					IMMPC_MESSAGE_ID_RESPONSE_CODE_ERROR);

			messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
		}
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
		/* проверка количества символов */
		if (buffSizeIn >= (size_t) (sizeof(immpc_request_or_cmd_pack_s)))
		{
			/* CRC правильный */
			if (IMMPC_IsPackValid_request_or_cmd((immpc_request_or_cmd_pack_s*) pMessHeadAddr))
			{
				/* установка флага */
				__IMMPC_SET_BIT(
					(*pIMMPC_RawData_s).flagsUseData,
					IMMPC_FLAG_NEED_SET_CALIB_MATRIX_TO_EEPROM);

				/* формирование ответа - OK */
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
			/* формирование ответа - ERROR */
			*pLengthOut =
				IMMPC_GenerateResponseMessage(
					pDataOut,
					IMMPC_MESSAGE_ID_RESPONSE_CODE_ERROR);

			messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
		}
		break;

	case IMMPC_MESSAGE_PACK_mag3dof_calib_request_cmd_s:
		/* формирование ответного сообщения ... */
		break;

	case IMMPC_MESSAGE_PACK_write_all_calibmatrix_in_eeprom_cmd_s:
		/* формирование ответного сообщения ... */
		/* проверка количества символов */
		if (buffSizeIn >= (size_t) (sizeof(immpc_request_or_cmd_pack_s)))
		{
			/* CRC правильный */
			if (IMMPC_IsPackValid_request_or_cmd((immpc_request_or_cmd_pack_s*) pMessHeadAddr))
			{
				/* установка флага */
				__IMMPC_SET_BIT(
					(*pIMMPC_RawData_s).flagsUseData,
					IMMPC_FLAG_NEED_RAW_MAG |
					IMMPC_FLAG_NEED_RAW_MAG_SELF_TEST);

				/* формирование пакета для ответа */
				*pLengthOut = IMMPC_GenerateRawDataMessage(
					pDataOut,
					IMMPC_MESSAGE_PACK_mag3dof_raw_pack_s,
					(pIMMPC_RawData_s->dataMag).rawMag_a,
					(pIMMPC_RawData_s->dataMag).rawMagSelfTest,
					NULL);
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
			/* формирование ответа - ERROR */
			*pLengthOut =
				IMMPC_GenerateResponseMessage(
					pDataOut,
					IMMPC_MESSAGE_ID_RESPONSE_CODE_ERROR);

			messageTypeReturn_e = IMMPC_MESSAGE_PACK_UNKNOWN;
		}
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
