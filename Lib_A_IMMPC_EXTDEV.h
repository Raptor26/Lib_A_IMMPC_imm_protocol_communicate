/** 
 * @file   	%<%NAME%>%.%<%EXTENSION%>%
 * @author 	%<%USER%>%
 * @version	
 * @date 	%<%DATE%>%, %<%TIME%>%
 * @brief
 */


#ifndef LIB_A_IMMPC_EXTDEV_H_
#define LIB_A_IMMPC_EXTDEV_H_


/*#### |Begin| --> Секция - "Include" ########################################*/
/*==== |Begin| --> Секция - "C libraries" ====================================*/
/*==== |End  | <-- Секция - "C libraries" ====================================*/

/*==== |Begin| --> Секция - "RTOS libraries ==================================*/
/*==== |End  | <-- Секция - "RTOS libraries ==================================*/

/*==== |Begin| --> Секция - "MK peripheral libraries" ========================*/
/*==== |End  | <-- Секция - "MK peripheral libraries" ========================*/

/*==== |Begin| --> Секция - "Extern libraries" ===============================*/
#include "Lib_A_IMMPC_imm_protocol_communicate.h"
/*==== |End  | <-- Секция - "Extern libraries" ===============================*/
/*#### |End  | <-- Секция - "Include" ########################################*/


/*#### |Begin| --> Секция - "Определение констант" ###########################*/
/*#### |End  | <-- Секция - "Определение констант" ###########################*/


/*#### |Begin| --> Секция - "Определение типов" ##############################*/
/*#### |End  | <-- Секция - "Определение типов" ##############################*/


/*#### |Begin| --> Секция - "Определение глобальных переменных" ##############*/
/*#### |End  | <-- Секция - "Определение глобальных переменных" ##############*/


/*#### |Begin| --> Секция - "Прототипы глобальных функций" ###################*/

/* #### Копирвоание данных в "Generic IMM" #### >>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

/* #### ---- Копирование измерений акселерометра в "Generic IMM" #### >>>>>>> */
/* #### ---- >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> ############ */
__IMMPC_ALWAYS_INLINE void
IMMPC_EXTDEV_Main9dof_SetInertMeasAcc_Int16(
	immpc_inert_meas_all_data_s *pRawData_s,
	int16_t 					*pRawAcc)
{
	pRawData_s->main9dof.acc_a[0u] = *pRawAcc++;
	pRawData_s->main9dof.acc_a[1u] = *pRawAcc++;
	pRawData_s->main9dof.acc_a[2u] = *pRawAcc;
}
/* -------------------------------------------------------------------------- */
__IMMPC_ALWAYS_INLINE void
IMMPC_EXTDEV_Main9dof_SetInertMeasAccTemperature_Int16(
	immpc_inert_meas_all_data_s *pRawData_s,
	int16_t 					*pAccTemperature)
{
	pRawData_s->main9dof.accTemp_a[0u] = *pAccTemperature++;
	pRawData_s->main9dof.accTemp_a[1u] = *pAccTemperature++;
	pRawData_s->main9dof.accTemp_a[2u] = *pAccTemperature;
}
/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
__IMMPC_ALWAYS_INLINE void
IMMPC_EXTDEV_Reserve9dof_SetInertMeasAcc_Int16(
	immpc_inert_meas_all_data_s *pRawData_s,
	int16_t 					*pRawAcc)
{
	pRawData_s->reserve6dof.acc_a[0u] = *pRawAcc++;
	pRawData_s->reserve6dof.acc_a[1u] = *pRawAcc++;
	pRawData_s->reserve6dof.acc_a[2u] = *pRawAcc;
}
/* -------------------------------------------------------------------------- */
__IMMPC_ALWAYS_INLINE void
IMMPC_EXTDEV_Reserve9dof_SetInertMeasAccTemperature_Int16(
	immpc_inert_meas_all_data_s *pRawData_s,
	int16_t *pAccTemperature)
{
	pRawData_s->reserve6dof.acc_a[0u] = *pAccTemperature++;
	pRawData_s->reserve6dof.acc_a[1u] = *pAccTemperature++;
	pRawData_s->reserve6dof.acc_a[2u] = *pAccTemperature;
}
/* #### ---- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ############ */
/* #### ---- Копирование измерений акселерометра в "Generic IMM" #### <<<<<<< */


/* #### ---- Копирование измерений гироскопа в "Generic IMM" #### >>>>>>>>>>> */
/* #### ---- >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> ################ */
__IMMPC_ALWAYS_INLINE void
IMMPC_EXTDEV_Main9dof_SetInertMeasGyr_Int16(
	immpc_inert_meas_all_data_s *pRawData_s,
	int16_t 					*pRawGyr)
{
	pRawData_s->main9dof.gyr_a[0u] = *pRawGyr++;
	pRawData_s->main9dof.gyr_a[1u] = *pRawGyr++;
	pRawData_s->main9dof.gyr_a[2u] = *pRawGyr;
}
/* -------------------------------------------------------------------------- */
__IMMPC_ALWAYS_INLINE void
IMMPC_EXTDEV_Main9dof_SetInertMeasGyrTemperature_Int16(
	immpc_inert_meas_all_data_s *pRawData_s,
	int16_t *pGyrTemperature)
{
	pRawData_s->main9dof.gyrTemp_a[0u] = *pGyrTemperature++;
	pRawData_s->main9dof.gyrTemp_a[1u] = *pGyrTemperature++;
	pRawData_s->main9dof.gyrTemp_a[2u] = *pGyrTemperature;
}
/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
__IMMPC_ALWAYS_INLINE void
IMMPC_EXTDEV_Reserve9dof_SetInertMeasGyr_Int16(
	immpc_inert_meas_all_data_s *pRawData_s,
	int16_t *pRawGyr)
{
	pRawData_s->reserve6dof.gyr_a[0u] = *pRawGyr++;
	pRawData_s->reserve6dof.gyr_a[1u] = *pRawGyr++;
	pRawData_s->reserve6dof.gyr_a[2u] = *pRawGyr;
}
/* -------------------------------------------------------------------------- */
__IMMPC_ALWAYS_INLINE void
IMMPC_EXTDEV_Reserve9dof_SetInertMeasGyrTemperature_Int16(
	immpc_inert_meas_all_data_s *pRawData_s,
	int16_t *pGyrTemperature)
{
	pRawData_s->reserve6dof.gyr_a[0u] = *pGyrTemperature++;
	pRawData_s->reserve6dof.gyr_a[1u] = *pGyrTemperature++;
	pRawData_s->reserve6dof.gyr_a[2u] = *pGyrTemperature;
}
/* #### ---- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ################ */
/* #### ---- Копирование измерений гироскопа в "Generic IMM" #### <<<<<<<<<<< */


/* #### ---- Копирование измерений магнитометра в "Generic IMM" #### >>>>>>>> */
/* #### ---- >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> ############# */
__IMMPC_ALWAYS_INLINE void
IMMPC_EXTDEV_Main9dof_SetInertMeasMag_Int16(
	immpc_inert_meas_all_data_s *pRawData_s,
	int16_t *pRawMag)
{
	pRawData_s->main9dof.mag_a[0u] = *pRawMag++;
	pRawData_s->main9dof.mag_a[1u] = *pRawMag++;
	pRawData_s->main9dof.mag_a[2u] = *pRawMag;
}
/* -------------------------------------------------------------------------- */
__IMMPC_ALWAYS_INLINE void
IMMPC_EXTDEV_Main9dof_SetInertMeasMagSelfTest_Int16(
	immpc_inert_meas_all_data_s *pRawData_s,
	int16_t *pRawMagSelfTest)
{
	pRawData_s->main9dof.magSelfTest_a[0u] = *pRawMagSelfTest++;
	pRawData_s->main9dof.magSelfTest_a[1u] = *pRawMagSelfTest++;
	pRawData_s->main9dof.magSelfTest_a[2u] = *pRawMagSelfTest;
}
/* #### ---- Копирование измерений магнитометра в "Generic IMM" #### <<<<<<<< */
/* #### ---- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ############# */


extern immpc_message_id_e
IMMPC_EXTDEV_ParseMain9dofRawPack(
	immpc_inert_meas_all_data_s *pInertMeas_s,
	immpc_9dof_main_raw_pack_s 	*pInputBuff_s);
/* -------------------------------------------------------------------------- */
extern immpc_message_id_e
IMMPC_EXTDEV_ParseReserve9dofRawPack(
	immpc_inert_meas_all_data_s 	*pInertMeas_s,
	immpc_9dof_reserve_raw_pack_s 	*pInputBuff_s);
/*#### |End  | <-- Секция - "Прототипы глобальных функций" ###################*/


/*#### |Begin| --> Секция - "Определение макросов" ###########################*/
/*#### |End  | <-- Секция - "Определение макросов" ###########################*/


/*#### |Begin| --> Секция - "Include - подмодули" ############################*/
/*#### |End  | <-- Секция - "Include - подмодули" ############################*/

#endif	/* LIB_A_IMMPC_IMM_PROTOCOL_COMMUNICATE_LIB_A_IMMPC_EXTDEV_H_ */

/*############################################################################*/
/*################################ END OF FILE ###############################*/
/*############################################################################*/
