/**
 * @file   	%<%NAME%>%.%<%EXTENSION%>%
 * @author 	%<%USER%>%
 * @version
 * @date 	%<%DATE%>%, %<%TIME%>%
 * @brief
 */


/*#### |Begin| --> Секция - "Include" ########################################*/
#include "Lib_A_IMMPC_EXTDEV.h"
/*#### |End  | <-- Секция - "Include" ########################################*/


/*#### |Begin| --> Секция - "Глобальные переменные" ##########################*/
/*#### |End  | <-- Секция - "Глобальные переменные" ##########################*/


/*#### |Begin| --> Секция - "Локальные переменные" ###########################*/
/*#### |End  | <-- Секция - "Локальные переменные" ###########################*/


/*#### |Begin| --> Секция - "Прототипы локальных функций" ####################*/
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

immpc_message_id_e
IMMPC_EXTDEV_ParseMain9dofRawPack(
	immpc_inert_meas_all_data_s *pInertMeas_s,
	immpc_9dof_main_raw_pack_s 	*pInputBuff_s)
{
	/* Если верна контрольная сумма данных */
	if (IMMPC_GetCRC_Generic(
			(uint8_t*) pInputBuff_s,
			(uint16_t) sizeof(immpc_9dof_main_raw_pack_s)) == pInputBuff_s->crc)
	{
		/* __________________________________________________________________ */
		/* Установка битов, относящихся к акселерометрам */
		__IMMPC_SET_BIT(
			pInertMeas_s->main9dof.sensorStatus,
			__IMMPC_CLEAR_BIT(
				pInputBuff_s->head_s.sensorsStatus,
				!(IMMPC_ACC_XYZ_DATA_WAS_UPDATE |
				  IMMPC_ACC_X_SELF_TEST 		|
				  IMMPC_ACC_Y_SELF_TEST 		|
				  IMMPC_ACC_Z_SELF_TEST)));
		IMMPC_EXTDEV_Main9dof_SetInertMeasAcc_Int16(
			pInertMeas_s,
			pInputBuff_s->acc_a);
		IMMPC_EXTDEV_Main9dof_SetInertMeasAccTemperature_Int16(
			pInertMeas_s,
			pInputBuff_s->accTemp_a);
		/* __________________________________________________________________ */
		/* Установка битов, относящихся к гироскопам */
		__IMMPC_SET_BIT(
			pInertMeas_s->main9dof.sensorStatus,
			__IMMPC_CLEAR_BIT(
				pInputBuff_s->head_s.sensorsStatus,
				!(IMMPC_GYR_XYZ_DATA_WAS_UPDATE |
				  IMMPC_GYR_X_SELF_TEST 		|
				  IMMPC_GYR_Y_SELF_TEST 		|
				  IMMPC_GYR_Z_SELF_TEST)));
		IMMPC_EXTDEV_Main9dof_SetInertMeasGyr_Int16(
			pInertMeas_s,
			pInputBuff_s->gyr_a);
		IMMPC_EXTDEV_Main9dof_SetInertMeasGyrTemperature_Int16(
			pInertMeas_s,
			pInputBuff_s->gyrTemp_a);
		/* __________________________________________________________________ */
		/* Установка битов, относящихся к магнитометрам */
		__IMMPC_SET_BIT(
			pInertMeas_s->main9dof.sensorStatus,
			__IMMPC_CLEAR_BIT(
				pInputBuff_s->head_s.sensorsStatus,
				!(IMMPC_MAG_XYZ_DATA_WAS_UPDATE |
				  IMMPC_MAG_X_SELF_TEST 		|
				  IMMPC_MAG_Y_SELF_TEST 		|
				  IMMPC_MAG_Z_SELF_TEST)));
		IMMPC_EXTDEV_Main9dof_SetInertMeasMag_Int16(
			pInertMeas_s,
			pInputBuff_s->mag_a);
		IMMPC_EXTDEV_Main9dof_SetInertMeasMagSelfTest_Int16(
			pInertMeas_s,
			pInputBuff_s->magSelfTest_a);
	}
	else
	{
		/* Контрольная сумма не верна */
		return (IMMPC_ID_response_code_invalid_crc);
	}

	return (IMMPC_ID_response_code_ok);
}

immpc_message_id_e
IMMPC_EXTDEV_ParseReserve9dofRawPack(
	immpc_inert_meas_all_data_s 	*pInertMeas_s,
	immpc_9dof_reserve_raw_pack_s 	*pInputBuff_s)
{
	if (IMMPC_GetCRC_Generic(
			(uint8_t*) pInputBuff_s,
			(uint16_t) sizeof(immpc_9dof_reserve_raw_pack_s)) == pInputBuff_s->crc)
	{
		/* __________________________________________________________________ */
		/* Установка битов, относящихся к акселерометрам */
		__IMMPC_SET_BIT(
			pInertMeas_s->main9dof.sensorStatus,
			__IMMPC_CLEAR_BIT(
				pInputBuff_s->head_s.sensorsStatus,
				!(IMMPC_ACC_XYZ_DATA_WAS_UPDATE |
				  IMMPC_ACC_X_SELF_TEST 		|
				  IMMPC_ACC_Y_SELF_TEST 		|
				  IMMPC_ACC_Z_SELF_TEST)));
		IMMPC_EXTDEV_Reserve9dof_SetInertMeasAcc_Int16(
			pInertMeas_s,
			pInputBuff_s->acc_a);
		IMMPC_EXTDEV_Reserve9dof_SetInertMeasAccTemperature_Int16(
			pInertMeas_s,
			pInputBuff_s->accTemp_a);
		/* __________________________________________________________________ */
		/* Установка битов, относящихся к гироскопам */
		__IMMPC_SET_BIT(
			pInertMeas_s->main9dof.sensorStatus,
			__IMMPC_CLEAR_BIT(
				pInputBuff_s->head_s.sensorsStatus,
				!(IMMPC_GYR_XYZ_DATA_WAS_UPDATE |
				  IMMPC_GYR_X_SELF_TEST 		|
				  IMMPC_GYR_Y_SELF_TEST 		|
				  IMMPC_GYR_Z_SELF_TEST)));
		IMMPC_EXTDEV_Reserve9dof_SetInertMeasGyr_Int16(
			pInertMeas_s,
			pInputBuff_s->gyr_a);
		IMMPC_EXTDEV_Reserve9dof_SetInertMeasGyrTemperature_Int16(
			pInertMeas_s,
			pInputBuff_s->gyrTemp_a);
		/* __________________________________________________________________ */
		/* Установка битов, относящихся к магнитометрам */
		__IMMPC_SET_BIT(
			pInertMeas_s->main9dof.sensorStatus,
			__IMMPC_CLEAR_BIT(
				pInputBuff_s->head_s.sensorsStatus,
				!(IMMPC_MAG_XYZ_DATA_WAS_UPDATE |
				  IMMPC_MAG_X_SELF_TEST 		|
				  IMMPC_MAG_Y_SELF_TEST 		|
				  IMMPC_MAG_Z_SELF_TEST)));
		IMMPC_EXTDEV_Main9dof_SetInertMeasMag_Int16(
			pInertMeas_s,
			pInputBuff_s->mag_a);
		IMMPC_EXTDEV_Main9dof_SetInertMeasMagSelfTest_Int16(
			pInertMeas_s,
			pInputBuff_s->magSelfTest_a);
	}
	else
	{
		/* Контрольная сумма не верна */
		return (IMMPC_ID_response_code_invalid_crc);
	}

	return (IMMPC_ID_response_code_ok);
}
/*#### |End  | <-- Секция - "Описание глобальных функций" ####################*/


/*#### |Begin| --> Секция - "Описание локальных функций" #####################*/
/*#### |End  | <-- Секция - "Описание локальных функций" #####################*/


/*#### |Begin| --> Секция - "Обработчики прерываний" #########################*/
/*#### |End  | <-- Секция - "Обработчики прерываний" #########################*/

/*############################################################################*/
/*############################ END OF FILE  ##################################*/
/*############################################################################*/
