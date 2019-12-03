/**
 * @file    %<%NAME%>%.%<%EXTENSION%>%
 * @author  %<%USER%>%
 * @version
 * @date    %<%DATE%>%, %<%TIME%>%
 * @brief
 */


#ifndef LIB_A_IMMPC_IIM_PROTOCOL_COMMUNICATE_
#define LIB_A_IMMPC_IIM_PROTOCOL_COMMUNICATE_


/*#### |Begin| --> Секция - "Include" ########################################*/
/*==== |Begin| --> Секция - "C libraries" ====================================*/
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
/*==== |End  | <-- Секция - "C libraries" ====================================*/

/*==== |Begin| --> Секция - "RTOS libraries ==================================*/
/*==== |End  | <-- Секция - "RTOS libraries ==================================*/

/*==== |Begin| --> Секция - "MK peripheral libraries" ========================*/
/*==== |End  | <-- Секция - "MK peripheral libraries" ========================*/

/*==== |Begin| --> Секция - "Extern libraries" ===============================*/
#include "Lib_A_CRC_cyclic_redundancy_check.h"
#include "Lib_A_ISCM_inert_sens_calib_matrix.h"
/*==== |End  | <-- Секция - "Extern libraries" ===============================*/
/*#### |End  | <-- Секция - "Include" ########################################*/


/*#### |Begin| --> Секция - "Определение констант" ###########################*/
#if defined (__IMMPC_EXTERN_MODE_ENABLE__)
	#include "macros_definitions.h"
#endif

/*==== |Begin| --> Секция определения типа числа с плавающей точкой ==========*/
#if !defined (__IMMPC_FPT__)
	#error "Please, set __IMMPC_FPT__ float or double in macros list"
#endif

#if !defined (__IMMPC_FPT_SIZE__)
	#error "Please, set __IMMPC_FPT_SIZE__ 4 (that mean float) or 8 (that mean double) in macros list"
#endif

#if     __IMMPC_FPT_SIZE__ == 4

#elif   __IMMPC_FPT_SIZE__ == 8

#else
	#error "Your compiler uses a non-standard floating point size"
#endif
/*==== |End  | <-- Секция определения типа числа с плавающей точкой ==========*/

/*==== |Begin| --> Секция - Макросы для встраиваемых функций =================*/
#if defined (__GNUC__)

	/* inline*/
	#ifndef __IMMPC_INLINE
		#define __IMMPC_INLINE             inline
	#endif

	/* static inline */
	#ifndef __IMMPC_STATIC_INLINE
		#define __IMMPC_STATIC_INLINE      static inline
	#endif

	/* always inline */
	#ifndef __IMMPC_ALWAYS_INLINE
		#define __IMMPC_ALWAYS_INLINE      inline __attribute__((always_inline)) static
	#endif

	/* force inline */
	#ifndef __IMMPC_FORCE_INLINE
		#define __IMMPC_FORCE_INLINE       inline __attribute__((always_inline))
	#endif

#else
	#define __IMMPC_INLINE
	#define __IMMPC_STATIC_INLINE   static
	#define __IMMPC_ALWAYS_INLINE
#endif
/*==== |End  | <-- Секция - Макросы для встраиваемых функций =================*/

/*==== |Begin| --> Секция - Расположение функций библиотеки в специальной
 *                          области памяти ===================================*/
#if defined (__IMMPC_FNC_ONCE_MEMORY_LOCATION_NAME__)
	#if defined (__GNUC__)
		#define __IMMPC_FNC_ONCE_MEMORY_LOCATION  __attribute__ ((section(__IMMPC_FNC_ONCE_MEMORY_LOCATION_NAME__)))
	#else
		#error "You defined the name of the memory area for the function location, but the type of your compiler is not supported by the library. You can delete the macro definition __IMMPC_FNC_ONCE_MEMORY_LOCATION_NAME__ or extend the macro definition __IMMPC_FNC_ONCE_MEMORY_LOCATION for your compiler type"
	#endif
#else
	#define __IMMPC_FNC_ONCE_MEMORY_LOCATION
#endif

#if defined (__IMMPC_FNC_LOOP_MEMORY_LOCATION_NAME__)
	#if defined (__GNUC__)
		#define __IMMPC_FNC_LOOP_MEMORY_LOCATION  __attribute__ ((section(__IMMPC_FNC_LOOP_MEMORY_LOCATION_NAME__)))
	#else
		#error "You defined the name of the memory area for the function location, but the type of your compiler is not supported by the library. You can delete the macro definition __IMMPC_FNC_LOOP_MEMORY_LOCATION_NAME__ or extend the macro definition __IMMPC_FNC_LOOP_MEMORY_LOCATION for your compiler type"
	#endif
#else
	#define __IMMPC_FNC_LOOP_MEMORY_LOCATION
#endif
/*==== |End  | <-- Секция - Расположение функций библиотеки в специальной
 *                          области памяти ===================================*/


/*==== |Begin| --> Секция - Расположение констант библиотеки в специальной
 *                          области памяти ===================================*/
#if defined (__IMMPC_CONST_MEMORY_LOCATION_NAME__)
	#if defined (__GNUC__)
		#define __IMMPC_CONST_MEMORY_LOCATION  __attribute__ ((section(__IMMPC_CONST_MEMORY_LOCATION_NAME__)))
	#else
		#error "You defined the name of the memory area for the function location, but the type of your compiler is not supported by the library. You can delete the macro definition __IMMPC_CONST_LOOP_MEMORY_LOCATION_NAME__ or extend the macro definition __IMMPC_CONST_MEMORY_LOCATION for your compiler type"
	#endif
#else
	#define __IMMPC_CONST_MEMORY_LOCATION
#endif
/*==== |End  | <-- Секция - Расположение констант библиотеки в специальной
 *                          области памяти ===================================*/

/*==== |Begin| --> Секция - Локальная оптимизация функций ====================*/
#if defined (__GNUC__)
	#ifndef __IMMPC_FNC_ONCE_OPTIMIZE_MODE
		#define __IMMPC_FNC_ONCE_OPTIMIZE_MODE
	#endif
#endif

#if defined (__GNUC__)
	#ifndef __IMMPC_FNC_LOOP_OPTIMIZE_MODE
		#define __IMMPC_FNC_LOOP_OPTIMIZE_MODE
	#endif
#endif
/*==== |End| --> Секция - Локальная оптимизация функций ======================*/

/* @todo добавить макроопределение для выбора big endian и little endian */
#define __IMMPC_RemapTwoBytes(IMMPC_macrosByte)	((uint16_t)((((IMMPC_macrosByte) << 8) & 0xFF00) | (((IMMPC_macrosByte) >> 8) & 0x00FF)))

#define __IMMPC_SET_BIT(REG, BIT)   	((REG) |= (BIT))
#define __IMMPC_CLEAR_BIT(REG, BIT) 	((REG) &= ~(BIT))
#define __IMMPC_READ_BIT(REG, BIT)  	((REG) & (BIT))
#define __IMMPC_CLEAR_REG(REG)     		((REG) = (0x0))
#define __IMMPC_WRITE_REG(REG, VAL) 	((REG) = (VAL))
#define __IMMPC_READ_REG(REG)      		((REG))
#define __IMMPC_IS_SET_BIT(REG, BIT)	(((REG) & (BIT)) == (BIT))
#define __IMMPC_MODIFY_REG(REG, CLEARMASK, SETMASK)  __IMMPC_WRITE_REG((REG), (((__IMMPC_READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

#define IMMPC_START_FRAME									((uint16_t)	0xAAAA)
#define IMMPC_RESPONCE_END_FRAME							((uint8_t)	0x55)





/* #### PACK_REQUESTS_BITS #### */
/* #### Raw or Calibration measurements macros #### -->>>>>>>>>>>>>>>>>>>>>>> */
/* #### >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> ############################## */
#define IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS 				(0b10000000) ///< Если бит установлен, то запрос калиброванных данны
#define __IMMPC_PACK_REQUESTS_BITS_SetCalibMeas(var)    	__IMMPC_SET_BIT(var, 	IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS)
#define __IMMPC_PACK_REQUESTS_BITS_SetRawMeas(var)      	__IMMPC_CLEAR_BIT(var, 	IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS)
#define __IMMPC_PACK_REQUESTS_BITS_IsSetCalibMeas(var)		__IMMPC_IS_SET_BIT(var, IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS)
#define __IMMPC_PACK_REQUESTS_BITS_IsSetRawMeas(var)		(!(__IMMPC_PACK_REQUESTS_BITS_IsSetCalibMeas(var)))
/* #### Raw or Calibration measurements macros #### --<<<<<<<<<<<<<<<<<<<<<<  */
/* #### <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ############################## */


/* #### Main or Reserve measurements macros #### -->>>>>>>>>>>>>>>>>>>>>>>>>> */
/* #### >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> ################################# */
#define IMMPC_PACK_REQUESTS_BITS_RESERVE_MEAS        	(0b01000000) ///< Если бит установлен, то запрос резервных измерителей
#define __IMMPC_PACK_REQUESTS_BITS_SetReserveMeas(var)	__IMMPC_SET_BIT(var, 	IMMPC_PACK_REQUESTS_BITS_RESERVE_MEAS)
#define __IMMPC_PACK_REQUESTS_BITS_SetMainMeas(var)    	__IMMPC_CLEAR_BIT(var, 	IMMPC_PACK_REQUESTS_BITS_RESERVE_MEAS)
#define __IIMPC_PACK_REQUESTS_BITS_IsSetReservMeas(var) __IMMPC_IS_SET_BIT(var, IMMPC_PACK_REQUESTS_BITS_RESERVE_MEAS)
#define __IIMPC_PACK_REQUESTS_BITS_IsSetMainMeas(var)	(!(__IIMPC_PACK_REQUESTS_BITS_IsSetReservMeas(var)))
/* #### Main or Reserve measurements macros #### --<<<<<<<<<<<<<<<<<<<<<<<<<< */
/* #### <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ################################# */


/* #### Read or Write macros #### -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
/* #### >>>>>>>>>>>>>>>>>>>> ################################################ */
#define IMMPC_PACK_REQUESTS_BITS_READ_MEAS            	(0b00100000) ///< Если бит установлен, то ИИМ необходимо разобрать пакет данных и записать его payload в свою ОЗУ
#define __IMMPC_PACK_REQUESTS_BITS_SetReadMeas(var)		__IMMPC_SET_BIT(var, 	IMMPC_PACK_REQUESTS_BITS_READ_MEAS)
#define __IMMPC_PACK_REQUESTS_BITS_SetWriteMeas(var)	__IMMPC_CLEAR_BIT(var, 	IMMPC_PACK_REQUESTS_BITS_READ_MEAS)
#define __IIMPC_PACK_REQUESTS_BITS_IsSetReadFlag(var)	__IMMPC_IS_SET_BIT(var, IMMPC_PACK_REQUESTS_BITS_READ_MEAS)
#define __IIMPC_PACK_REQUESTS_BITS_IsSetWriteFlag(var)	(!(__IIMPC_PACK_REQUESTS_BITS_IsSetReadFlag(var)))
/* #### Read or Write macros #### --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */
/* #### <<<<<<<<<<<<<<<<<<<< ################################################ */


/* #### Request data or Payload Data #### -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
/* #### >>>>>>>>>>>>>>>>>>>>>>>>>>>> ######################################## */
#define IMMPC_PACK_REQUESTS_BITS_DATA_REQUEST        		(0b00010000) ///< Если бит установлен, то внешнее устройство запрашивает данные
#define __IMMPC_PACK_REQUESTS_BITS_SetRequestData(var)		__IMMPC_SET_BIT(var, 	IMMPC_PACK_REQUESTS_BITS_DATA_REQUEST)
#define __IMMPC_PACK_REQUESTS_BITS_SetPayloadData(var)		__IMMPC_CLEAR_BIT(var, 	IMMPC_PACK_REQUESTS_BITS_DATA_REQUEST)
#define __IMMPC_PACK_REQUESTS_BITS_IsSetRequestData(var)	__IMMPC_IS_SET_BIT(var, IMMPC_PACK_REQUESTS_BITS_DATA_REQUEST)
#define __IMMPC_PACK_REQUESTS_BITS_IsSetPayloadData(var)	(!(__IMMPC_PACK_REQUESTS_BITS_IsSetRequestData(var)))
/* #### Request data or Payload Data #### --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */
/* #### <<<<<<<<<<<<<<<<<<<<<<<<<<<< ######################################## */


/* флаги необходимости "сырых" данных */
// #define IMMPC_FLAG_NEED_RAW_MAIN_ACC						(((uint32_t)(0b10000000) << 24) & 0xFF000000)
#define IMMPC_FLAG_NEED_RAW_MAIN_ACC_Pos					(31u)
#define IMMPC_FLAG_NEED_RAW_MAIN_ACC_Msk					(0x1u << IMMPC_FLAG_NEED_RAW_MAIN_ACC_Pos)
#define IMMPC_FLAG_NEED_RAW_MAIN_ACC 						((uint32_t)(IMMPC_FLAG_NEED_RAW_MAIN_ACC_Msk))
//#define IMMPC_FLAG_NEED_RAW_MAIN_GYR						(((uint32_t)(0b01000000) << 24) & 0xFF000000)
#define IMMPC_FLAG_NEED_RAW_MAIN_GYR_Pos					(30u)
#define IMMPC_FLAG_NEED_RAW_MAIN_GYR_Msk					(0x1u << IMMPC_FLAG_NEED_RAW_MAIN_GYR_Pos)
#define IMMPC_FLAG_NEED_RAW_MAIN_GYR 						((uint32_t)(IMMPC_FLAG_NEED_RAW_MAIN_GYR_Msk))
//#define IMMPC_FLAG_NEED_RAW_MAIN_TEMP_ACC					(((uint32_t)(0b00100000) << 24) & 0xFF000000)
#define IMMPC_FLAG_NEED_RAW_MAIN_TEMP_ACC_Pos				(29u)
#define IMMPC_FLAG_NEED_RAW_MAIN_TEMP_ACC_Msk				(0x1u << IMMPC_FLAG_NEED_RAW_MAIN_TEMP_ACC_Pos)
#define IMMPC_FLAG_NEED_RAW_MAIN_TEMP_ACC 					((uint32_t)(IMMPC_FLAG_NEED_RAW_MAIN_TEMP_ACC_Msk))
//#define IMMPC_FLAG_NEED_RAW_MAIN_TEMP_GYR					(((uint32_t)(0b00010000) << 24) & 0xFF000000)
#define IMMPC_FLAG_NEED_RAW_MAIN_TEMP_GYR_Pos				(28u)
#define IMMPC_FLAG_NEED_RAW_MAIN_TEMP_GYR_Msk				(0x1u << IMMPC_FLAG_NEED_RAW_MAIN_TEMP_GYR_Pos)
#define IMMPC_FLAG_NEED_RAW_MAIN_TEMP_GYR 					((uint32_t)(IMMPC_FLAG_NEED_RAW_MAIN_TEMP_GYR_Msk))
//#define IMMPC_FLAG_NEED_RAW_MAG							(((uint32_t)(0b00001000) << 24) & 0xFF000000)
#define IMMPC_FLAG_NEED_RAW_MAG_Pos							(27u)
#define IMMPC_FLAG_NEED_RAW_MAG_Msk							(0x1u << IMMPC_FLAG_NEED_RAW_MAG_Pos)
#define IMMPC_FLAG_NEED_RAW_MAG 							((uint32_t)(IMMPC_FLAG_NEED_RAW_MAG_Msk))
//#define IMMPC_FLAG_NEED_RAW_MAG_SELF_TEST					(((uint32_t)(0b00000100) << 24) & 0xFF000000)
#define IMMPC_FLAG_NEED_RAW_MAG_SELF_TEST_Pos				(26u)
#define IMMPC_FLAG_NEED_RAW_MAG_SELF_TEST_Msk				(0x1u << IMMPC_FLAG_NEED_RAW_MAG_SELF_TEST_Pos)
#define IMMPC_FLAG_NEED_RAW_MAG_SELF_TEST					((uint32_t)(IMMPC_FLAG_NEED_RAW_MAG_SELF_TEST_Msk))
//#define IMMPC_FLAG_NEED_RAW_RESERVE_ACC					(((uint32_t)(0b00000010) << 24) & 0xFF000000)
#define IMMPC_FLAG_NEED_RAW_RESERVE_ACC_Pos					(25u)
#define IMMPC_FLAG_NEED_RAW_RESERVE_ACC_Msk					(0x1u << IMMPC_FLAG_NEED_RAW_RESERVE_ACC_Pos)
#define IMMPC_FLAG_NEED_RAW_RESERVE_ACC 					((uint32_t)(IMMPC_FLAG_NEED_RAW_RESERVE_ACC_Msk))
//#define IMMPC_FLAG_NEED_RAW_RESERVE_GYR					(((uint32_t)(0b00000001) << 24) & 0xFF000000)
#define IMMPC_FLAG_NEED_RAW_RESERVE_GYR_Pos					(24u)
#define IMMPC_FLAG_NEED_RAW_RESERVE_GYR_Msk					(0x1u << IMMPC_FLAG_NEED_RAW_RESERVE_GYR_Pos)
#define IMMPC_FLAG_NEED_RAW_RESERVE_GYR 					((uint32_t)(IMMPC_FLAG_NEED_RAW_RESERVE_GYR_Msk))
//#define IMMPC_FLAG_NEED_RAW_RESERVE_TEMP_ACC				(((uint32_t)(0b10000000) << 16) & 0x00FF0000)
#define IMMPC_FLAG_NEED_RAW_RESERVE_TEMP_ACC_Pos			(23u)
#define IMMPC_FLAG_NEED_RAW_RESERVE_TEMP_ACC_Msk			(0x1u << IMMPC_FLAG_NEED_RAW_RESERVE_TEMP_ACC_Pos)
#define IMMPC_FLAG_NEED_RAW_RESERVE_TEMP_ACC 				((uint32_t)(IMMPC_FLAG_NEED_RAW_RESERVE_TEMP_ACC_Msk))
//#define IMMPC_FLAG_NEED_RAW_RESERVE_TEMP_GYR				(((uint32_t)(0b01000000) << 16) & 0x00FF0000)
#define IMMPC_FLAG_NEED_RAW_RESERVE_TEMP_GYR_Pos			(22u)
#define IMMPC_FLAG_NEED_RAW_RESERVE_TEMP_GYR_Msk			(0x1u << IMMPC_FLAG_NEED_RAW_RESERVE_TEMP_GYR_Pos)
#define IMMPC_FLAG_NEED_RAW_RESERVE_TEMP_GYR 				((uint32_t)(IMMPC_FLAG_NEED_RAW_RESERVE_TEMP_GYR_Msk))
//#define IMMPC_FLAG_NEED_SET_CALIB_MATRIX_TO_EEPROM		(((uint32_t)(0b00100000) << 16) & 0x00FF0000)
#define IMMPC_FLAG_NEED_SET_CALIB_MATRIX_TO_EEPROM_Pos		(21u)
#define IMMPC_FLAG_NEED_SET_CALIB_MATRIX_TO_EEPROM_Msk		(0x1u << IMMPC_FLAG_NEED_SET_CALIB_MATRIX_TO_EEPROM_Pos)
#define IMMPC_FLAG_NEED_SET_CALIB_MATRIX_TO_EEPROM 			((uint32_t)(IMMPC_FLAG_NEED_SET_CALIB_MATRIX_TO_EEPROM_Msk))
// next 													(20u)

/* Sensors_status */
#define IMMPC_ACC_X_SELF_TEST								(((uint16_t)(0b10000000) << 8) & 0xFF00)
#define IMMPC_ACC_Y_SELF_TEST								(((uint16_t)(0b01000000) << 8) & 0xFF00)
#define IMMPC_ACC_Z_SELF_TEST								(((uint16_t)(0b00100000) << 8) & 0xFF00)
#define IMMPC_GYR_X_SELF_TEST								(((uint16_t)(0b00010000) << 8) & 0xFF00)
#define IMMPC_GYR_Y_SELF_TEST								(((uint16_t)(0b00001000) << 8) & 0xFF00)
#define IMMPC_GYR_Z_SELF_TEST								(((uint16_t)(0b00000100) << 8) & 0xFF00)
#define IMMPC_MAG_X_SELF_TEST								(((uint16_t)(0b00000010) << 8) & 0xFF00)
#define IMMPC_MAG_Y_SELF_TEST								(((uint16_t)(0b00000001) << 8) & 0xFF00)
#define IMMPC_MAG_Z_SELF_TEST								((uint16_t)(0b10000000) & 0x00FF)
#define IMMPC_ACC_XYZ_DATA_WAS_UPDATE						((uint16_t)(0b01000000) & 0x00FF)
#define IMMPC_GYR_XYZ_DATA_WAS_UPDATE						((uint16_t)(0b00100000) & 0x00FF)
#define IMMPC_MAG_XYZ_DATA_WAS_UPDATE						((uint16_t)(0b00010000) & 0x00FF)

/* скорости передачи данных при использовании USART */
#define IMMPC_USART_BAUDRATE_LOW							(57600U)
#define IMMPC_USART_BAUDRATE_MEDIUM							(115200U)
#define IMMPC_USART_BAUDRATE_FAST							(460800U)
#define IMMPC_USART_BAUDRATE_VERY_FAST						(921600U)
#define IMMPC_USART_BAUDRATE_DEFAULT						(IMMPC_USART_BAUDRATE_LOW)

/* Message ID */
typedef enum
{
	/**/
	IMMPC_MESSAGE_ID_UNKNOWN = 0u,

	/**
	 * @brief 	Идентификатор основных измерителей
	 */
	IMMPC_ID_9dof_main,

	/**
	 * @brief 	Идентификатор резервных измерителей
	 */
	IMMPC_ID_9dof_reserve,

	/**
	 * @brief 	Идентификатор калибровочной матрицы акселерометра
	 */
	IMMPC_MESSAGE_ID_ACC3DOF_CALIBMATRIX,

	/**
	 * @brief 	Идентификатор калибровочной матрицы гироскопов
	 */
	IMMPC_MESSAGE_ID_GYR3DOF_CALIBMATRIX,

	/**
	 * @brief 	Идентификаторы калибровочной матрицы магнитометров
	 */
	IMMPC_MESSAGE_ID_MAG3DOF_CALIBMATRIX,

	/**
	 * @brief 	Идентификатор измерений магнитометра
	 * @note 	Для магнитометра нет деления на основной и резервный
	 */
	IMMPC_MESSAGE_ID_MAG3DOF_PACK,

	/**
	 * @brief 	Идентификатор для записи всех калибровочных матриц из
	 * 			оперативной памяти контроллера в EEPROM
	 */
	IMMPC_MESSAGE_ID_WRITE_ALL_CALIBMATRIX,

	/* Коды ответных сообщений */
	IMMPC_MESSAGE_ID_RESPONSE_CODE_ERROR 		= 200u,
	IMMPC_MESSAGE_ID_RESPONSE_CODE_INVALID_CRC,
	IMMPC_MESSAGE_ID_RESPONSE_CODE_INVALID_CALIBRATION_MATRIX_FROM_EEPROM,
	IMMPC_MESSAGE_ID_RESPONSE_CODE_INVALID_MESSAGE_FORMATE,
	IMMPC_MESSAGE_ID_RESPONSE_CODE_OK,
} immpc_message_id_e;


#define __IMMPC_SetMessageTypeHelper_SetID(bitsInID) 				(((((uint16_t) 	((bitsInID))) << 8u) & 0xFF00))
#define __IMMPC_SetMessageTypeHelper_SetPackRequest(bitsInPackReq)	(((uint16_t) 	(bitsInPackReq)) & 0x00fFF)

#define __IMMPC_SetIDandPackRequests(bitsInID, bitsInPackReq)			\
	__IMMPC_RemapTwoBytes(												\
		((__IMMPC_SetMessageTypeHelper_SetID(bitsInID)) | 				\
		 (__IMMPC_SetMessageTypeHelper_SetPackRequest(bitsInPackReq))))

#define __IMMPC_GetIDFromIdAndPackRequest(idAndPackRequest)()

typedef enum
{
	IMMPC_MESSAGE_PACK_UNKNOWN = 0u,

	/* #### Пакеты с данными от основных измерителей #### -->>>>>>>>>>>>>>>>> */
	/* #### <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ######################## */
	IMMPC_ID_AND_PACK_REQUESTS_9dof_main_raw_pack_e =
		__IMMPC_SetIDandPackRequests(
			IMMPC_ID_9dof_main,
			0u),
	IMMPC_ID_AND_PACK_REQUESTS_9dof_main_calib_pack_e =
		__IMMPC_SetIDandPackRequests(
			IMMPC_ID_9dof_main,
			IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS),
	/* #### Пакеты с данными от основных измерителей #### --<<<<<<<<<<<<<<<<< */
	/* #### <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ######################## */


	/* #### Пакеты с данными от резервных измерителей #### -->>>>>>>>>>>>>>>> */
	/* #### <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ####################### */
	IMMPC_ID_AND_PACK_REQUESTS_9dof_reserve_raw_pack_e =
		__IMMPC_SetIDandPackRequests(
			IMMPC_ID_9dof_reserve,
			0u),
	IMMPC_ID_AND_PACK_REQUESTS_9dof_reserve_calib_pack_e =
		__IMMPC_SetIDandPackRequests(
			IMMPC_ID_9dof_reserve,
			IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS),
	/* #### Пакеты с данными от резервных измерителей #### --<<<<<<<<<<<<<<<< */
	/* #### <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ####################### */

	/* #### Запросы от внешнего устройства #### -->>>>>>>>>>>>>>>>>>>>>>>>>>> */
	IMMPC_ID_AND_PACK_REQUESTS_9dof_main_raw_request_cmd =
		__IMMPC_SetIDandPackRequests(
			IMMPC_ID_9dof_main,
			IMMPC_PACK_REQUESTS_BITS_DATA_REQUEST),
	/* ---------------------------------------------------------------------- */
	IMMPC_ID_AND_PACK_REQUESTS_9dof_reserve_raw_request_cmd_e =
		__IMMPC_SetIDandPackRequests(
			IMMPC_ID_9dof_reserve,
			IMMPC_PACK_REQUESTS_BITS_DATA_REQUEST),
	/* #### Запросы от внешнего устройства #### --<<<<<<<<<<<<<<<<<<<<<<<<<<< */


	/* #### Пакеты с калибровочными матрицами #### -->>>>>>>>>>>>>>>>>>>>>>>> */
	/* #### >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> ############################### */
	/* #### ---- Пакет с калибровочными матрицами акселерометров #### -->>>>> */
	/* #### ---- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ############ */
	IMMPC_ID_AND_PACK_REQUESTS_acc3dof_main_calibmatrix_read_pack_e =
		__IMMPC_SetIDandPackRequests(
			IMMPC_MESSAGE_ID_ACC3DOF_CALIBMATRIX,
			IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS),
	/* ---------------------------------------------------------------------- */
	IMMPC_ID_AND_PACK_REQUESTS_acc3dof_main_calibmatrix_write_pack_e =
		__IMMPC_SetIDandPackRequests(
			IMMPC_MESSAGE_ID_ACC3DOF_CALIBMATRIX,
			IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS | IMMPC_PACK_REQUESTS_BITS_READ_MEAS),
	/* ---------------------------------------------------------------------- */
	/* ---------------------------------------------------------------------- */
	IMMPC_ID_AND_PACK_REQUESTS_acc3dof_reserve_calibmatrix_read_pack_e =
		__IMMPC_SetIDandPackRequests(
			IMMPC_MESSAGE_ID_ACC3DOF_CALIBMATRIX,
			IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS | IMMPC_PACK_REQUESTS_BITS_RESERVE_MEAS),
	/* ---------------------------------------------------------------------- */
	IMMPC_ID_AND_PACK_REQUESTS_acc3dof_reserve_calibmatrix_write_pack_e =
		__IMMPC_SetIDandPackRequests(
			IMMPC_MESSAGE_ID_ACC3DOF_CALIBMATRIX,
			IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS | IMMPC_PACK_REQUESTS_BITS_READ_MEAS | IMMPC_PACK_REQUESTS_BITS_RESERVE_MEAS),
	/* #### ---- Пакет с калибровочными матрицами акселерометров #### --<<<<< */
	/* #### ---- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ############ */



	/* Коды ответный сообщений  */
	IMMPC_ID_AND_PACK_REQUESTS_error_e =
		__IMMPC_SetIDandPackRequests(IMMPC_MESSAGE_ID_RESPONSE_CODE_ERROR, 0u),

	IMMPC_ID_AND_PACK_REQUESTS_invalid_crc_e =
		__IMMPC_SetIDandPackRequests(IMMPC_MESSAGE_ID_RESPONSE_CODE_INVALID_CRC, 0u),
} immpc_id_and_pack_requests_e;

/**
 * @brief Заголовок пакета данных
 */
typedef struct
{
	uint16_t 	startFrame;

	union
	{
		uint16_t idAndPackRequests;
		struct
		{
			uint8_t messageID;
			uint8_t packRequests;
		};
	};

	uint16_t 	sensorsStatus;
}
#if defined (__GNUC__)
	__attribute__((__packed__))
#else
	#error "Please, define compiler"
#endif
immpc_head_s;

typedef struct
{
	uint16_t 	startFrame;

	union
	{
		uint16_t idAndPackRequests;
		struct
		{
			uint8_t messageID;
			uint8_t packRequests;
		};
	};
}
#if defined (__GNUC__)
	__attribute__((__packed__))
#else
	#error "Please, define compiler"
#endif
immpc_head_calib_matrix_s;

typedef struct
{
	uint16_t startFrame;

	union
	{
		uint16_t idAndPackRequests;
		struct
		{
			uint8_t messageID;
			uint8_t packRequests;
		};
	};

	uint16_t crc;
}
#if defined (__GNUC__)
	__attribute__((__packed__))
#else
	#error "Please, define compiler"
#endif
immpc_request_cmd_s;

typedef struct
{
	/**
	 * @brief Заголовок пакета данных
	 */
	immpc_head_s head_s;

	int16_t acc_a[3u];
	int16_t gyr_a[3u];
	int16_t mag_a[3u];

	int16_t accTemp_a[3u];
	int16_t gyrTemp_a[3u];
	int16_t magSelfTest_a[3u];

	uint16_t crc;
}
#if defined (__GNUC__)
	__attribute__((__packed__))
#else
	#error "Please, define compiler"
#endif
immpc_9dof_generic_raw_pack_s;

/* пакет "сырых" данных основных измерителей */
typedef struct
{
	/**
	 * @brief Заголовок пакета данных
	 */
	immpc_head_s head_s;

	int16_t acc_a[3u];
	int16_t gyr_a[3u];
	int16_t mag_a[3u];

	int16_t accTemp_a[3u];
	int16_t gyrTemp_a[3u];
	int16_t magSelfTest_a[3u];

	uint16_t crc;
}
#if defined (__GNUC__)
	__attribute__((__packed__))
#else
	#error "Please, define compiler"
#endif
immpc_9dof_main_raw_pack_s;

/* пакет калиброванных данных основных измерителей */
typedef struct
{
	/**
	 * @brief Заголовок пакета данных
	 */
	immpc_head_s head_s;

	__IMMPC_FPT__ acc[3u];
	__IMMPC_FPT__ gyr[3u];
	__IMMPC_FPT__ mag[3u];

	__IMMPC_FPT__ accTemp[3u];
	__IMMPC_FPT__ gyrTemp[3u];
	int16_t magSelfTest_a[3u];

	uint16_t crc;
}
#if defined (__GNUC__)
	__attribute__((__packed__))
#else
	#error "Please, define compiler"
#endif
immpc_9dof_main_calib_pack_s;

/* пакет "сырых" данных резервных измерителей */
typedef struct
{
	/**
	 * @brief Заголовок пакета данных
	 */
	immpc_head_s head_s;

	int16_t acc_a[3u];
	int16_t gyr_a[3u];
	int16_t mag_a[3u];

	int16_t accTemp_a[3u];
	int16_t gyrTemp_a[3u];
	int16_t magSelfTest_a[3u];

	uint16_t crc;
}
#if defined (__GNUC__)
	__attribute__((__packed__))
#else
	#error "Please, define compiler"
#endif
immpc_9dof_reserve_raw_pack_s;

/* пакет калиброванных данных резервных измерителей */
typedef struct
{
	/**
	 * @brief Заголовок пакета данных
	 */
	immpc_head_s head_s;

	__IMMPC_FPT__ acc[3u];
	__IMMPC_FPT__ gyr[3u];
	__IMMPC_FPT__ mag[3u];

	__IMMPC_FPT__ accTemp[3u];
	__IMMPC_FPT__ gyrTemp[3u];
	int16_t magSelfTest_a[3u];

	uint16_t crc;
}
#if defined (__GNUC__)
	__attribute__((__packed__))
#else
	#error "Please, define compiler"
#endif
immpc_9dof_reserve_calib_pack_s;

/* пакет "сырых" данных магнитометра */
typedef struct
{
	/**
	 * @brief Заголовок пакета данных
	 */
	immpc_head_s head_s;

	int16_t mag_a[3u];
	int16_t magSelfTest_a[3u];

	uint16_t crc;
}
#if defined (__GNUC__)
	__attribute__((__packed__))
#else
	#error "Please, define compiler"
#endif
immpc_mag3dof_raw_pack_s;

/* пакет калиброванных данных магнитометра */
typedef struct
{
	immpc_head_s head_s;
	int16_t mag[3u];
	int16_t magSelfTest[3u];

	uint16_t crc;
}
#if defined (__GNUC__)
	__attribute__((__packed__))
#else
	#error "Please, define compiler"
#endif
immpc_mag3dof_calib_pack_s;

/* пакет запросов или команд */
typedef struct
{
	uint16_t 	startFrame;
	uint8_t 	messageID;
	uint8_t 	packRequests;;

	uint16_t	crc;
}
#if defined (__GNUC__)
	__attribute__((__packed__))
#else
	#error "Please, define compiler"
#endif
immpc_request_or_cmd_pack_s;

typedef struct
{
	uint16_t 	startFrame;
	uint8_t 	messageID;
	uint8_t 	endFrame;
}
#if defined (__GNUC__)
	__attribute__((__packed__))
#else
	#error "Please, define compiler"
#endif
immpc_response_cmd_s;

typedef struct
{
	immpc_head_calib_matrix_s head_s;
	iscm_3dof_acc_calib_matrix_s calib_s;
	uint16_t crc;
}
#if defined (__GNUC__)
	__attribute__((__packed__))
#else
	#error "Please, define compiler"
#endif
immpc_calibmatrix_pack_generic_s;

/* структура "сырых" данных акселерометра и гироскопа
 * основных датчиков
 */
typedef struct
{
	int16_t acc_a[3u];
	int16_t gyr_a[3u];
	int16_t mag_a[3u];

	int16_t accTemp_a[3u];
	int16_t gyrTemp_a[3u];
	int16_t magSelfTest_a[3u];

	uint16_t sensorStatus;
} immpc_main9dof_raw_data_s;

/* структура "сырых" данных магнитометра */
typedef struct
{
	int16_t rawMag_a[3u];
	int16_t rawMagSelfTest[3u];

	uint16_t sensorStatus;
} immpc_raw_mag_data_s;

/* структура "сырых" данных акселерометра и гироскопа
 * резервных датчиков
 */
typedef struct
{
	int16_t acc_a[3u];
	int16_t gyr_a[3u];

	int16_t accTemp_a[3u];
	int16_t gyrTemp_a[3u];

	uint16_t sensorStatus;
} immpc_reserve6dof_raw_data_s;

/* структура данных */
typedef struct
{
	/* "сырые" данные */
	immpc_main9dof_raw_data_s 		main9dof;
	immpc_reserve6dof_raw_data_s 	reserve6dof;
//	immpc_raw_mag_data_s 				dataMag;

	/* флаги (см. выше #define IMMPC_FLAG_NEED...) */
	immpc_id_and_pack_requests_e whatPackageIsNeeded;
} immpc_inert_meas_all_data_s;

/*#### |End  | <-- Секция - "Определение констант" ###########################*/


/*#### |Begin| --> Секция - "Определение типов" ##############################*/
/*#### |End  | <-- Секция - "Определение типов" ##############################*/


/*#### |Begin| --> Секция - "Определение глобальных переменных" ##############*/
/*#### |End  | <-- Секция - "Определение глобальных переменных" ##############*/


/*#### |Begin| --> Секция - "Прототипы глобальных функций" ###################*/
__IMMPC_ALWAYS_INLINE uint8_t
IMMPC_GetMessageIDFromIDandPackRequests(
	uint16_t messageIDAndPackRequests)
{
	return ((uint8_t)(messageIDAndPackRequests << 8u));
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
__IMMPC_ALWAYS_INLINE uint16_t
IMMPC_GetCRC_Generic(
	uint8_t *pData,
	uint16_t len)
{
	return __IMMPC_RemapTwoBytes(
			   (CRC_XOR_CCITT_Poly0x1021_Crc16(
					(uint8_t*)&pData[2u],
					len - 4u)));
}


/* Запись данных в структуру -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

__IMMPC_ALWAYS_INLINE void
IMMPC_Main9dof_SetInertMeasAcc_Int16(
	immpc_inert_meas_all_data_s *pRawData_s,
	int16_t *pRawAcc)
{
	pRawData_s->main9dof.acc_a[0u] = *pRawAcc++;
	pRawData_s->main9dof.acc_a[1u] = *pRawAcc++;
	pRawData_s->main9dof.acc_a[2u] = *pRawAcc;

	/* Установить бит обновления данных гироскопа */
	__IMMPC_SET_BIT(
		pRawData_s->main9dof.sensorStatus,
		IMMPC_ACC_XYZ_DATA_WAS_UPDATE);
}

__IMMPC_ALWAYS_INLINE void
IMMPC_Main9dof_SetInertMeasGyr_Int16(
	immpc_inert_meas_all_data_s *pRawData_s,
	int16_t *pRawGyr)
{
	pRawData_s->main9dof.gyr_a[0u] = *pRawGyr++;
	pRawData_s->main9dof.gyr_a[1u] = *pRawGyr++;
	pRawData_s->main9dof.gyr_a[2u] = *pRawGyr;

	/* Установить бит обновления данных акселерометра */
	__IMMPC_SET_BIT(
		pRawData_s->main9dof.sensorStatus,
		IMMPC_GYR_XYZ_DATA_WAS_UPDATE);
}

__IMMPC_ALWAYS_INLINE void
IMMPC_Main9dof_SetInertMeasGyrTemperature_Int16(
	immpc_inert_meas_all_data_s *pRawData_s,
	int16_t *pGyrTemperature)
{
	pRawData_s->main9dof.gyrTemp_a[0u] = *pGyrTemperature++;
	pRawData_s->main9dof.gyrTemp_a[1u] = *pGyrTemperature++;
	pRawData_s->main9dof.gyrTemp_a[2u] = *pGyrTemperature;
}

__IMMPC_ALWAYS_INLINE void
IMMPC_Main9dof_SetInertMeasAccTemperature_Int16(
	immpc_inert_meas_all_data_s *pRawData_s,
	int16_t *pAccTemperature)
{
	pRawData_s->main9dof.accTemp_a[0u] = *pAccTemperature++;
	pRawData_s->main9dof.accTemp_a[1u] = *pAccTemperature++;
	pRawData_s->main9dof.accTemp_a[2u] = *pAccTemperature;
}

__IMMPC_ALWAYS_INLINE void
IMMPC_Main9dof_SetInertMeasMag_Int16(
	immpc_inert_meas_all_data_s *pRawData_s,
	int16_t *pRawMag)
{
	pRawData_s->main9dof.mag_a[0u] = *pRawMag++;
	pRawData_s->main9dof.mag_a[1u] = *pRawMag++;
	pRawData_s->main9dof.mag_a[2u] = *pRawMag;

	/* Установить бит обновления данных гироскопа */
	__IMMPC_SET_BIT(
		pRawData_s->main9dof.sensorStatus,
		IMMPC_MAG_XYZ_DATA_WAS_UPDATE);

	__IMMPC_SET_BIT(
		pRawData_s->reserve6dof.sensorStatus,
		IMMPC_MAG_XYZ_DATA_WAS_UPDATE);
}

__IMMPC_ALWAYS_INLINE void
IMMPC_Main9dof_SetInertMeasMagSelfTest_Int16(
	immpc_inert_meas_all_data_s *pRawData_s,
	int16_t *pRawMagSelfTest)
{
	pRawData_s->main9dof.magSelfTest_a[0u] = *pRawMagSelfTest++;
	pRawData_s->main9dof.magSelfTest_a[1u] = *pRawMagSelfTest++;
	pRawData_s->main9dof.magSelfTest_a[2u] = *pRawMagSelfTest;
}

__IMMPC_ALWAYS_INLINE void
IMMPC_Reserve9dof_SetInertMeasAcc_Int16(
	immpc_inert_meas_all_data_s *pRawData_s,
	int16_t *pRawAcc)
{
	pRawData_s->reserve6dof.acc_a[0u] = *pRawAcc++;
	pRawData_s->reserve6dof.acc_a[1u] = *pRawAcc++;
	pRawData_s->reserve6dof.acc_a[2u] = *pRawAcc;

	/* @todo Установить бит обновления данных гироскопа */
	__IMMPC_SET_BIT(
		pRawData_s->reserve6dof.sensorStatus,
		IMMPC_ACC_XYZ_DATA_WAS_UPDATE);
}

__IMMPC_ALWAYS_INLINE void
IMMPC_Reserve9dof_SetInertMeasGyr_Int16(
	immpc_inert_meas_all_data_s *pRawData_s,
	int16_t *pRawGyr)
{
	pRawData_s->reserve6dof.gyr_a[0u] = *pRawGyr++;
	pRawData_s->reserve6dof.gyr_a[1u] = *pRawGyr++;
	pRawData_s->reserve6dof.gyr_a[2u] = *pRawGyr;

	/* @todo Установить бит обновления данных акселерометра */
	__IMMPC_SET_BIT(
		pRawData_s->reserve6dof.sensorStatus,
		IMMPC_GYR_XYZ_DATA_WAS_UPDATE);
}

__IMMPC_ALWAYS_INLINE void
IMMPC_Reserve9dof_SetInertMeasGyrTemperature_Int16(
	immpc_inert_meas_all_data_s *pRawData_s,
	int16_t *pGyrTemperature)
{
	pRawData_s->reserve6dof.gyr_a[0u] = *pGyrTemperature++;
	pRawData_s->reserve6dof.gyr_a[1u] = *pGyrTemperature++;
	pRawData_s->reserve6dof.gyr_a[2u] = *pGyrTemperature;
}

__IMMPC_ALWAYS_INLINE void
IMMPC_Reserve9dof_SetInertMeasAccTemperature_Int16(
	immpc_inert_meas_all_data_s *pRawData_s,
	int16_t *pAccTemperature)
{
	pRawData_s->reserve6dof.acc_a[0u] = *pAccTemperature++;
	pRawData_s->reserve6dof.acc_a[1u] = *pAccTemperature++;
	pRawData_s->reserve6dof.acc_a[2u] = *pAccTemperature;
}

/* Запись данных в структуру --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* Работа с флагами -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

__IMMPC_ALWAYS_INLINE size_t
IMMPC_IsMain6DofNeedByVar(
	uint32_t flags)
{
	/* Возвращает 1 если нужны данные от резервного измерителя */
	return (__IMMPC_IS_SET_BIT(
				flags,
				(IMMPC_FLAG_NEED_RAW_MAIN_ACC |
				 IMMPC_FLAG_NEED_RAW_MAIN_GYR)));
}

__IMMPC_ALWAYS_INLINE size_t
IMMPC_IsMain6DofNeed(
	immpc_inert_meas_all_data_s *pMeasRawData_s)
{
	/* Возвращает 1 если нужны данные от резервного измерителя */
	return (IMMPC_IsMain6DofNeedByVar(pMeasRawData_s->whatPackageIsNeeded));
}

__IMMPC_ALWAYS_INLINE void
IMMPC_SetMain6DofNeedFlag(
	immpc_inert_meas_all_data_s *pMeasRawData_s)
{
	__IMMPC_SET_BIT(
		pMeasRawData_s->whatPackageIsNeeded,
		(IMMPC_FLAG_NEED_RAW_MAIN_ACC | IMMPC_FLAG_NEED_RAW_MAIN_GYR));
}

__IMMPC_ALWAYS_INLINE size_t
IMMPC_IsReserve6DofNeedByVar(
	uint32_t flags)
{
	/* Возвращает 1 если нужны данные от резервного измерителя */
	return (__IMMPC_IS_SET_BIT(
				flags,
				(IMMPC_FLAG_NEED_RAW_RESERVE_ACC |
				 IMMPC_FLAG_NEED_RAW_RESERVE_GYR)));
}

__IMMPC_ALWAYS_INLINE size_t
IMMPC_IsReserve6DofNeed(
	immpc_inert_meas_all_data_s *pMeasRawData_s)
{
	/* Возвращает 1 если нужны данные от резервного измерителя */
	return (IMMPC_IsReserve6DofNeedByVar(pMeasRawData_s->whatPackageIsNeeded));
}

__IMMPC_ALWAYS_INLINE void
IMMPC_SetReserve6DofNeedFlag(
	immpc_inert_meas_all_data_s *pMeasRawData_s)
{
	__IMMPC_SET_BIT(
		pMeasRawData_s->whatPackageIsNeeded,
		(IMMPC_FLAG_NEED_RAW_RESERVE_ACC | IMMPC_FLAG_NEED_RAW_RESERVE_GYR));
}

__IMMPC_ALWAYS_INLINE size_t
IMMPC_IsNeedReserve6dofRawPack(
	immpc_inert_meas_all_data_s *pMeasRawData_s)
{
	/* @todo добавить проверку */
	return (1u);
}

__IMMPC_ALWAYS_INLINE size_t
IMMPC_IsMag3DofNeedByVar(
	size_t flags)
{
	/* Возвращает 1 если нужны данные от резервного измерителя */
	return (__IMMPC_IS_SET_BIT(
				flags,
				(IMMPC_FLAG_NEED_RAW_MAG)));
}

__IMMPC_ALWAYS_INLINE size_t
IMMPC_IsMag3DofNeed(
	immpc_inert_meas_all_data_s *pMeasRawData_s)
{
	/* Возвращает 1 если нужны данные от резервного измерителя */
	return (IMMPC_IsMag3DofNeedByVar(pMeasRawData_s->whatPackageIsNeeded));
}

__IMMPC_ALWAYS_INLINE void
IMMPC_SetMag3DofNeedFlag(
	immpc_inert_meas_all_data_s *pMeasRawData_s)
{
	__IMMPC_SET_BIT(
		pMeasRawData_s->whatPackageIsNeeded,
		(IMMPC_FLAG_NEED_RAW_MAG));
}

/* Работа с флагами --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

extern size_t
IMMPC_EXTDEV_SetRequestMessageGeneric(
	immpc_request_cmd_s 			*pOutputData_s,
	immpc_id_and_pack_requests_e 	idAndPackRequests);

extern immpc_id_and_pack_requests_e
IMMPC_ParseInputMessageAndGenerateOutputMessage(
	immpc_inert_meas_all_data_s 	*pRawSensMeas_s,

	uint8_t 				*pInputBuff,
	uint16_t 				inputBuffSize,

	uint8_t 				*pOutBuff,
	uint16_t 				*pOutBuffByteNumbForTx);

extern size_t
IMMPC_SetMain9dofRawDataPack(
	immpc_inert_meas_all_data_s 		*pSourceData_s,
	immpc_9dof_main_raw_pack_s	*pPackForTx_s)
__IMMPC_FNC_LOOP_OPTIMIZE_MODE;

extern size_t
IMMPC_SetReserve9dofRawDataPack(
	immpc_inert_meas_all_data_s 			*pSourceData_s,
	immpc_9dof_reserve_raw_pack_s	*pPackForTx_s)
__IMMPC_FNC_LOOP_OPTIMIZE_MODE;

extern size_t
IMMPC_SetMain3dofMagRawDataPack(
	immpc_inert_meas_all_data_s 		*pSourceData_s,
	immpc_mag3dof_raw_pack_s	*pPackForTx_s)
__IMMPC_FNC_LOOP_OPTIMIZE_MODE;

extern immpc_head_s*
IMMPC_GetTypeMessage(
	const uint8_t 	*pData,
	size_t 			buffSize);
/*#### |End  | <-- Секция - "Прототипы глобальных функций" ###################*/


/*#### |Begin| --> Секция - "Определение макросов" ###########################*/
/*#### |End  | <-- Секция - "Определение макросов" ###########################*/


/*#### |Begin| --> Секция - "Include - подмодули" ############################*/
/*#### |End  | <-- Секция - "Include - подмодули" ############################*/

#endif  /* LIB_A_IMMPC_IIM_PROTOCOL_COMMUNICATE_ */

/*############################################################################*/
/*################################ END OF FILE ###############################*/
/*############################################################################*/
