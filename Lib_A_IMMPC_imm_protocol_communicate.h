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
/*==== |End  | <-- Секция - "Extern libraries" ===============================*/
/*#### |End  | <-- Секция - "Include" ########################################*/


/*#### |Begin| --> Секция - "Определение констант" ###########################*/

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
#if defined (__IMMPC_USE_9DOF)
	#pragma message ("Use 9dof")
#else
	#pragma message ("Not use 9dof")
#endif

#if defined (__IMMPC_USE_3DOFACC)
	#pragma message ("Use 3dof ACC")
#else
	#pragma message ("Not use 3dof ACC")
#endif

#if defined (__IMMPC_USE_3DOFGYR)
	#pragma message ("Use 3dof GYR")
#else
	#pragma message ("Not use 3dof GYR")
#endif

#if defined (__IMMPC_USE_3DOFMAG)
	#pragma message ("Use 3dof MAG")
#else
	#pragma message ("Not use 3dof MAG")
#endif

#define __IMMPC_SET_BIT(REG, BIT)   	((REG) |= (BIT))

#define __IMMPC_CLEAR_BIT(REG, BIT) 	((REG) &= ~(BIT))

#define __IMMPC_READ_BIT(REG, BIT)  	((REG) & (BIT))

#define __IMMPC_CLEAR_REG(REG)     		((REG) = (0x0))

#define __IMMPC_WRITE_REG(REG, VAL) 	((REG) = (VAL))

#define __IMMPC_READ_REG(REG)      		((REG))

#define __IMMPC_IS_SET_BIT(REG, BIT)	(((REG) & (BIT)) == (BIT))

#define IMMPC_START_FRAME									((uint16_t)	0xAAAA)
#define IMMPC_RESPONCE_END_FRAME							((uint8_t)	0x55)

#define IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS             	(0b10000000) /* калиброванный */
#define IMMPC_PACK_REQUESTS_BITS_RESERVE_MEAS            	(0b01000000) /* резервный */
#define IMMPC_PACK_REQUESTS_BITS_READ_MEAS              	(0b00100000) /* чтение данных с пакета с последующей записью */
#define IMMPC_PACK_REQUESTS_BITS_DATA_REQUEST        		(0b00010000) /* запрос или команда */

#define __IMMPC_PACK_REQUESTS_BITS_SET_CALIB_MEAS(var)    	__IMMPC_SET_BIT(var, 	IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS)
#define __IMMPC_PACK_REQUESTS_BITS_SET_RAW_MEAS(var)      	__IMMPC_CLEAR_BIT(var, 	IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS)
#define __IMMPC_PACK_REQUESTS_BITS_IsSetCalibMeas(var)		__IMMPC_IS_SET_BIT(var, IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS);

#define __IMMPC_PACK_REQUESTS_BITS_SET_RESERV_MEAS(var)		__IMMPC_SET_BIT(var, 	IIMPC_PACK_REQUESTS_BITS_RESERV_MEAS)
#define __IMMPC_PACK_REQUESTS_BITS_SET_MAIN_MEAS(var)    	__IMMPC_CLEAR_BIT(var, 	IIMPC_PACK_REQUESTS_BITS_RESERV_MEAS)
#define __IIMPC_PACK_REQUESTS_BITS_IsSetReservMeas(var) 	__IMMPC_IS_SET_BIT(var, IIMPC_PACK_REQUESTS_BITS_RESERV_MEAS)

#define __IMMPC_PACK_REQUESTS_BITS_SET_READ_MEAS(var)		__IMMPC_SET_BIT(var, 	IMMPC_PACK_REQUESTS_BITS_READ_MEAS)
#define __IMMPC_PACK_REQUESTS_BITS_SET_NOT_READ_MEAS(var)	__IMMPC_CLEAR_BIT(var, 	IMMPC_PACK_REQUESTS_BITS_READ_MEAS)
#define __IIMPC_PACK_REQUESTS_BITS_IsSetReadFlag(var)		__IMMPC_IS_SET_BIT(var, IMMPC_PACK_REQUESTS_BITS_READ_MEAS)

#define __IMPC_PACK_REQUESTS_BITS_SET_REQUEST(var)			__IMMPC_SET_BIT(var, 	IMMPC_PACK_REQUESTS_BITS_DATA_REQUEST)
#define __IMMPC_PACK_REQUESTS_BITS_SET_DATA_PAYLOAD(var)	__IMMPC_CLEAR_BIT(var, 	IMMPC_PACK_REQUESTS_BITS_DATA_REQUEST)
#define __IMMPC_PACK_REQUESTS_BITS_IsSetDataRequest(var)	__IMMPC_IS_SET_BIT(var, IMMPC_PACK_REQUESTS_BITS_DATA_REQUEST)

#define __IMMPC_GetOffssetID(pMem)							((uint8_t)pMem[2u])

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

/* биты Sensor status */
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

/* идентификаторы */
typedef enum
{
	/**/
	IMMPC_MESSAGE_ID_UNKNOWN = 0u,
	/**/
	IMMPC_MESSAGE_ID_9DOF_PACK_MAIN,
	IMMPC_MESSAGE_ID_9DOF_PACK_RESERVE,
	/**/
	IMMPC_MESSAGE_ID_ACC3DOF_CALIBMATRIX,
	IMMPC_MESSAGE_ID_GYR3DOF_CALIBMATRIX,
	IMMPC_MESSAGE_ID_MAG3DOF_CALIBMATRIX,
	/**/
	IMMPC_MESSAGE_ID_MAG3DOF_PACK,
	/**/
	IMMPC_MESSAGE_ID_WRITE_ALL_CALIBMATRIX,
	/* коды ответных сообщений */
	IMMPC_MESSAGE_ID_RESPONSE_CODE_ERROR = 200u,
	IMMPC_MESSAGE_ID_RESPONSE_CODE_INVALID_CRC,
	IMMPC_MESSAGE_ID_RESPONSE_CODE_INVALID_CALIBRATION_MATRIX_FROM_EEPROM,
	IMMPC_MESSAGE_ID_RESPONSE_CODE_OK,
} immpc_message_id_e;


#define __IMMPC_SetMessageTypeHelper_SetID(bitsInID) 				(((((uint16_t) 	(0u | (bitsInID))) << 8u) & 0xFF00))
#define __IMMPC_SetMessageTypeHelper_SetPackRequest(bitsInPackReq)	(((uint16_t) 	(0u | bitsInPackReq)) & 0x00fFF)

#define __IMMPC_SetMessageType(bitsInID, bitsInPackReq)					\
	((__IMMPC_SetMessageTypeHelper_SetID(bitsInID)) 					\
	 | (__IMMPC_SetMessageTypeHelper_SetPackRequest(bitsInPackReq)))

typedef enum
{
	IMMPC_MESSAGE_PACK_UNKNOWN = 0u,

	/* пакеты с данными */
	IMMPC_MESSAGE_PACK_9dof_main_raw_pack_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_9DOF_PACK_MAIN,
			0u),

	IMMPC_MESSAGE_PACK_9dof_main_calib_pack_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_9DOF_PACK_MAIN,
			IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS),

	IMMPC_MESSAGE_PACK_9dof_reserve_raw_pack_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_9DOF_PACK_RESERVE,
			IMMPC_PACK_REQUESTS_BITS_RESERVE_MEAS),

	IMMPC_MESSAGE_PACK_9dof_reserve_calib_pack_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_9DOF_PACK_RESERVE,
			IMMPC_PACK_REQUESTS_BITS_RESERVE_MEAS |
			IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS),

	IMMPC_MESSAGE_PACK_mag3dof_raw_pack_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_MAG3DOF_PACK,
			0u),
	IMMPC_MESSAGE_PACK_mag3dof_calib_pack_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_MAG3DOF_PACK,
			IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS),
	IMMPC_MESSAGE_PACK_acc3dof_main_calibmatrix_read_pack_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_ACC3DOF_CALIBMATRIX,
			IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS),
	IMMPC_MESSAGE_PACK_acc3dof_main_calibmatrix_write_pack_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_ACC3DOF_CALIBMATRIX,
			IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS |
			IMMPC_PACK_REQUESTS_BITS_READ_MEAS),

	IMMPC_MESSAGE_PACK_acc3dof_reserve_calibmatrix_read_pack_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_ACC3DOF_CALIBMATRIX,
			IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS |
			IMMPC_PACK_REQUESTS_BITS_RESERVE_MEAS),

	IMMPC_MESSAGE_PACK_acc3dof_reserve_calibmatrix_write_pack_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_ACC3DOF_CALIBMATRIX,
			IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS |
			IMMPC_PACK_REQUESTS_BITS_READ_MEAS |
			IMMPC_PACK_REQUESTS_BITS_RESERVE_MEAS),
	IMMPC_MESSAGE_PACK_gyr3dof_main_calibmatrix_read_pack_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_GYR3DOF_CALIBMATRIX,
			IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS),

	IMMPC_MESSAGE_PACK_gyr3dof_main_calibmatrix_write_pack_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_GYR3DOF_CALIBMATRIX,
			IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS |
			IMMPC_PACK_REQUESTS_BITS_READ_MEAS),

	IMMPC_MESSAGE_PACK_gyr3dof_reserve_calibmatrix_read_pack_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_GYR3DOF_CALIBMATRIX,
			IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS |
			IMMPC_PACK_REQUESTS_BITS_RESERVE_MEAS),

	IMMPC_MESSAGE_PACK_gyr3dof_reserve_calibmatrix_write_pack_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_GYR3DOF_CALIBMATRIX,
			IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS |
			IMMPC_PACK_REQUESTS_BITS_READ_MEAS |
			IMMPC_PACK_REQUESTS_BITS_RESERVE_MEAS),

	IMMPC_MESSAGE_PACK_mag3dof_calibmatrix_read_pack_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_MAG3DOF_CALIBMATRIX,
			IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS),

	IMMPC_MESSAGE_PACK_mag3dof_calibmatrix_write_pack_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_MAG3DOF_CALIBMATRIX,
			IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS |
			IMMPC_PACK_REQUESTS_BITS_READ_MEAS),

	/* запросы */
	IMMPC_MESSAGE_PACK_9dof_main_raw_request_cmd_s =
		__IMMPC_SetMessageType(	IMMPC_MESSAGE_ID_9DOF_PACK_MAIN,
								IMMPC_PACK_REQUESTS_BITS_DATA_REQUEST),

	IMMPC_MESSAGE_PACK_9dof_main_calib_request_cmd_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_9DOF_PACK_MAIN,
			IMMPC_PACK_REQUESTS_BITS_DATA_REQUEST |
			IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS),

	IMMPC_MESSAGE_PACK_9dof_reserve_raw_request_cmd_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_9DOF_PACK_RESERVE,
			IMMPC_PACK_REQUESTS_BITS_DATA_REQUEST |
			IMMPC_PACK_REQUESTS_BITS_RESERVE_MEAS),

	IMMPC_MESSAGE_PACK_9dof_reserve_calib_request_cmd_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_9DOF_PACK_RESERVE,
			IMMPC_PACK_REQUESTS_BITS_DATA_REQUEST |
			IMMPC_PACK_REQUESTS_BITS_RESERVE_MEAS |
			IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS),

	IMMPC_MESSAGE_PACK_acc3dof_main_calibmatrix_request_cmd_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_ACC3DOF_CALIBMATRIX,
			IMMPC_PACK_REQUESTS_BITS_DATA_REQUEST |
			IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS),

	IMMPC_MESSAGE_PACK_acc3dof_reserve_calibmatrix_request_cmd_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_ACC3DOF_CALIBMATRIX,
			IMMPC_PACK_REQUESTS_BITS_DATA_REQUEST |
			IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS |
			IMMPC_PACK_REQUESTS_BITS_RESERVE_MEAS),

	IMMPC_MESSAGE_PACK_gyr3dof_main_calibmatrix_request_cmd_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_GYR3DOF_CALIBMATRIX,
			IMMPC_PACK_REQUESTS_BITS_DATA_REQUEST |
			IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS),
	IMMPC_MESSAGE_PACK_gyr3dof_reserve_calibmatrix_request_cmd_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_GYR3DOF_CALIBMATRIX,
			IMMPC_PACK_REQUESTS_BITS_DATA_REQUEST |
			IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS |
			IMMPC_PACK_REQUESTS_BITS_RESERVE_MEAS),

	IMMPC_MESSAGE_PACK_mag3dof_calibmatrix_request_cmd_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_MAG3DOF_CALIBMATRIX,
			IMMPC_PACK_REQUESTS_BITS_DATA_REQUEST |
			IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS),

	IMMPC_MESSAGE_PACK_mag3dof_raw_request_cmd_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_MAG3DOF_PACK,
			IMMPC_PACK_REQUESTS_BITS_DATA_REQUEST),

	IMMPC_MESSAGE_PACK_mag3dof_calib_request_cmd_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_MAG3DOF_PACK,
			IMMPC_PACK_REQUESTS_BITS_DATA_REQUEST |
			IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS),
	/* команды */
	IMMPC_MESSAGE_PACK_write_all_calibmatrix_in_eeprom_cmd_s = /* запись данных в EEPROM ИИМ */
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_WRITE_ALL_CALIBMATRIX,
			IMMPC_PACK_REQUESTS_BITS_CALIB_MEAS |
			IMMPC_PACK_REQUESTS_BITS_READ_MEAS |
			IMMPC_PACK_REQUESTS_BITS_DATA_REQUEST),

	/* коды ответных сообщений */
	IMMPC_MESSAGE_PACK_response_code_error_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_RESPONSE_CODE_ERROR,
			IMMPC_RESPONCE_END_FRAME),

	IMMPC_MESSAGE_PACK_response_code_invalid_crc_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_RESPONSE_CODE_INVALID_CRC,
			IMMPC_RESPONCE_END_FRAME),

	IMMPC_MESSAGE_PACK_response_code_invalid_calibration_matrix_from_eeprom_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_RESPONSE_CODE_INVALID_CALIBRATION_MATRIX_FROM_EEPROM,
			IMMPC_RESPONCE_END_FRAME),

	IMMPC_MESSAGE_PACK_response_code_ok_s =
		__IMMPC_SetMessageType(
			IMMPC_MESSAGE_ID_RESPONSE_CODE_OK,
			IMMPC_RESPONCE_END_FRAME),
} immpc_message_pack_type_e;

typedef enum
{
	IMMPC_PACK_REQUESTS_9dof_main_calib_pack,
} immpcs_pack_requests_e;

/* заголовок пакета */
typedef struct
{
	uint16_t 	startFrame;
	uint8_t 	messageID;
	uint8_t 	packRequests;
	uint16_t 	sensorsStatus;
}
#if defined (__GNUC__)
	__attribute__((__packed__))
#else
	#error "Please, define compiler"
#endif
immpc_head_s;

/* пакет "сырых" данных основных измерителей */
typedef struct
{
	immpc_head_s headMessage_s;
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
	immpc_head_s headMessage_s;
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
	immpc_head_s headMessage_s;
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
	immpc_head_s headMessage_s;
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
	immpc_head_s headMessage_s;
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
	immpc_head_s headMessage_s;
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

/* пакет калибровочной матрицы основных акселерометров */
typedef struct
{
	immpc_head_s headMessage_s;
	double matrix[3u][4u];

	uint16_t crc;
}
#if defined (__GNUC__)
	__attribute__((__packed__))
#else
	#error "Please, define compiler"
#endif
immpc_acc3dof_main_calibmatrix_pack_s;

/* пакет калибровочной матрицы резервных акселерометров */
typedef struct
{
	immpc_head_s headMessage_s;
	double matrix[3u][4u];

	uint16_t crc;
}
#if defined (__GNUC__)
	__attribute__((__packed__))
#else
	#error "Please, define compiler"
#endif
immpc_acc3dof_reserve_calibmatrix_pack_s;

/* пакет калибровочной матрицы основных гироскопов */
typedef struct
{
	immpc_head_s headMessage_s;
	double matrix[3u][4u];

	uint16_t crc;
}
#if defined (__GNUC__)
	__attribute__((__packed__))
#else
	#error "Please, define compiler"
#endif
immpc_gyr3dof_main_calibmatrix_pack_s;

/* пакет калибровочной матрицы резервных гироскопов */
typedef struct
{
	immpc_head_s headMessage_s;
	double matrix[3u][4u];

	uint16_t crc;
}
#if defined (__GNUC__)
	__attribute__((__packed__))
#else
	#error "Please, define compiler"
#endif
immpc_gyr3dof_reserve_calibmatrix_pack_s;

/* пакет калибровочной матрицы магнитометров */
typedef struct
{
	immpc_head_s headMessage_s;
	double matrix[3u][4u];

	uint16_t crc;
}
#if defined (__GNUC__)
	__attribute__((__packed__))
#else
	#error "Please, define compiler"
#endif
immpc_mag3dof_calibmatrix_pack_s;


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

/* структура "сырых" данных акселерометра и гироскопа
 * основных датчиков
 */
typedef struct
{
	int16_t rawMainAcc_a[3u];
	int16_t rawMainGyr_a[3u];

	int16_t rawMainTempAcc_a[3u];
	int16_t rawMainTempGyr_a[3u];

	uint16_t sensorStatus;
} immpc_raw_main_acc_gyr_data_s;

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
	int16_t rawReserveAcc_a[3u];
	int16_t rawReserveGyr_a[3u];

	int16_t rawReserveTempAcc_a[3u];
	int16_t rawReserveTempGyr_a[3u];

	uint16_t sensorStatus;
} immpc_raw_reserve_acc_gyr_data_s;

/* структура данных */
typedef struct
{
	/* "сырые" данные */
	immpc_raw_main_acc_gyr_data_s dataMainAccGyr;
	immpc_raw_reserve_acc_gyr_data_s dataReserveAccGyr;
	immpc_raw_mag_data_s dataMag;

	/* флаги (см. выше #define IMMPC_FLAG_NEED...) */
	uint32_t flagsUseData;
} immpc_meas_raw_data_s;

/*#### |End  | <-- Секция - "Определение констант" ###########################*/


/*#### |Begin| --> Секция - "Определение типов" ##############################*/
/*#### |End  | <-- Секция - "Определение типов" ##############################*/


/*#### |Begin| --> Секция - "Определение глобальных переменных" ##############*/
/*#### |End  | <-- Секция - "Определение глобальных переменных" ##############*/


/*#### |Begin| --> Секция - "Прототипы глобальных функций" ###################*/

/* Запись данных в структуру -->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

__IMMPC_ALWAYS_INLINE void
IMMPC_SetMainRawAcc(
	immpc_meas_raw_data_s *pRawData_s,
	int16_t *pRawAcc)
{
	pRawData_s->dataMainAccGyr.rawMainAcc_a[0u] = *pRawAcc++;
	pRawData_s->dataMainAccGyr.rawMainAcc_a[1u] = *pRawAcc++;
	pRawData_s->dataMainAccGyr.rawMainAcc_a[2u] = *pRawAcc;

	/* @todo Установить бит обновления данных гироскопа */
	__IMMPC_SET_BIT(
		pRawData_s->dataMainAccGyr.sensorStatus,
		IMMPC_ACC_XYZ_DATA_WAS_UPDATE);
}

__IMMPC_ALWAYS_INLINE void
IMMPC_SetMainRawGyr(
	immpc_meas_raw_data_s *pRawData_s,
	int16_t *pRawGyr)
{
	pRawData_s->dataMainAccGyr.rawMainGyr_a[0u] = *pRawGyr++;
	pRawData_s->dataMainAccGyr.rawMainGyr_a[1u] = *pRawGyr++;
	pRawData_s->dataMainAccGyr.rawMainGyr_a[2u] = *pRawGyr;

	/* @todo Установить бит обновления данных акселерометра */
	__IMMPC_SET_BIT(
		pRawData_s->dataMainAccGyr.sensorStatus,
		IMMPC_GYR_XYZ_DATA_WAS_UPDATE);
}

__IMMPC_ALWAYS_INLINE void
IMMPC_SetMainRawGyrTemperature(
	immpc_meas_raw_data_s *pRawData_s,
	int16_t *pGyrTemperature)
{
	pRawData_s->dataMainAccGyr.rawMainTempGyr_a[0u] = *pGyrTemperature++;
	pRawData_s->dataMainAccGyr.rawMainTempGyr_a[1u] = *pGyrTemperature++;
	pRawData_s->dataMainAccGyr.rawMainTempGyr_a[2u] = *pGyrTemperature;
}

__IMMPC_ALWAYS_INLINE void
IMMPC_SetMainRawAccTemperature(
	immpc_meas_raw_data_s *pRawData_s,
	int16_t *pAccTemperature)
{
	pRawData_s->dataMainAccGyr.rawMainTempAcc_a[0u] = *pAccTemperature++;
	pRawData_s->dataMainAccGyr.rawMainTempAcc_a[1u] = *pAccTemperature++;
	pRawData_s->dataMainAccGyr.rawMainTempAcc_a[2u] = *pAccTemperature;
}

__IMMPC_ALWAYS_INLINE void
IMMPC_SetMag(
	immpc_meas_raw_data_s *pRawData_s,
	int16_t *pRawAcc)
{
	pRawData_s->dataMag.rawMag_a[0u] = *pRawAcc++;
	pRawData_s->dataMag.rawMag_a[1u] = *pRawAcc++;
	pRawData_s->dataMag.rawMag_a[2u] = *pRawAcc;

	/* @todo Установить бит обновления данных гироскопа */
	__IMMPC_SET_BIT(
		pRawData_s->dataMainAccGyr.sensorStatus,
		IMMPC_MAG_XYZ_DATA_WAS_UPDATE);

	__IMMPC_SET_BIT(
		pRawData_s->dataReserveAccGyr.sensorStatus,
		IMMPC_MAG_XYZ_DATA_WAS_UPDATE);
}

__IMMPC_ALWAYS_INLINE void
IMMPC_SetMagSelfTest(
	immpc_meas_raw_data_s *pRawData_s,
	int16_t *pRawGyr)
{
	pRawData_s->dataMag.rawMagSelfTest[0u] = *pRawGyr++;
	pRawData_s->dataMag.rawMagSelfTest[1u] = *pRawGyr++;
	pRawData_s->dataMag.rawMagSelfTest[2u] = *pRawGyr;
}

__IMMPC_ALWAYS_INLINE void
IMMPC_SetReserveRawAcc(
	immpc_meas_raw_data_s *pRawData_s,
	int16_t *pRawAcc)
{
	pRawData_s->dataReserveAccGyr.rawReserveAcc_a[0u] = *pRawAcc++;
	pRawData_s->dataReserveAccGyr.rawReserveAcc_a[1u] = *pRawAcc++;
	pRawData_s->dataReserveAccGyr.rawReserveAcc_a[2u] = *pRawAcc;

	/* @todo Установить бит обновления данных гироскопа */
	__IMMPC_SET_BIT(
		pRawData_s->dataReserveAccGyr.sensorStatus,
		IMMPC_ACC_XYZ_DATA_WAS_UPDATE);
}

__IMMPC_ALWAYS_INLINE void
IMMPC_SetReserveRawGyr(
	immpc_meas_raw_data_s *pRawData_s,
	int16_t *pRawGyr)
{
	pRawData_s->dataReserveAccGyr.rawReserveGyr_a[0u] = *pRawGyr++;
	pRawData_s->dataReserveAccGyr.rawReserveGyr_a[1u] = *pRawGyr++;
	pRawData_s->dataReserveAccGyr.rawReserveGyr_a[2u] = *pRawGyr;

	/* @todo Установить бит обновления данных акселерометра */
	__IMMPC_SET_BIT(
		pRawData_s->dataReserveAccGyr.sensorStatus,
		IMMPC_GYR_XYZ_DATA_WAS_UPDATE);
}

__IMMPC_ALWAYS_INLINE void
IMMPC_SetReserveRawGyrTemperature(
	immpc_meas_raw_data_s *pRawData_s,
	int16_t *pGyrTemperature)
{
	pRawData_s->dataReserveAccGyr.rawReserveTempGyr_a[0u] = *pGyrTemperature++;
	pRawData_s->dataReserveAccGyr.rawReserveTempGyr_a[1u] = *pGyrTemperature++;
	pRawData_s->dataReserveAccGyr.rawReserveTempGyr_a[2u] = *pGyrTemperature;
}

__IMMPC_ALWAYS_INLINE void
IMMPC_SetReserveRawAccTemperature(
	immpc_meas_raw_data_s *pRawData_s,
	int16_t *pAccTemperature)
{
	pRawData_s->dataReserveAccGyr.rawReserveTempAcc_a[0u] = *pAccTemperature++;
	pRawData_s->dataReserveAccGyr.rawReserveTempAcc_a[1u] = *pAccTemperature++;
	pRawData_s->dataReserveAccGyr.rawReserveTempAcc_a[2u] = *pAccTemperature;
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
	immpc_meas_raw_data_s *pMeasRawData_s)
{
	/* Возвращает 1 если нужны данные от резервного измерителя */
	return (IMMPC_IsMain6DofNeedByVar(pMeasRawData_s->flagsUseData));
}

__IMMPC_ALWAYS_INLINE void
IMMPC_SetMain6DofNeedFlag(
	immpc_meas_raw_data_s *pMeasRawData_s)
{
	__IMMPC_SET_BIT(
		pMeasRawData_s->flagsUseData,
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
	immpc_meas_raw_data_s *pMeasRawData_s)
{
	/* Возвращает 1 если нужны данные от резервного измерителя */
	return (IMMPC_IsReserve6DofNeedByVar(pMeasRawData_s->flagsUseData));
}

__IMMPC_ALWAYS_INLINE void
IMMPC_SetReserve6DofNeedFlag(
	immpc_meas_raw_data_s *pMeasRawData_s)
{
	__IMMPC_SET_BIT(
		pMeasRawData_s->flagsUseData,
		(IMMPC_FLAG_NEED_RAW_RESERVE_ACC | IMMPC_FLAG_NEED_RAW_RESERVE_GYR));
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
	immpc_meas_raw_data_s *pMeasRawData_s)
{
	/* Возвращает 1 если нужны данные от резервного измерителя */
	return (IMMPC_IsMag3DofNeedByVar(pMeasRawData_s->flagsUseData));
}

__IMMPC_ALWAYS_INLINE void
IMMPC_SetMag3DofNeedFlag(
	immpc_meas_raw_data_s *pMeasRawData_s)
{
	__IMMPC_SET_BIT(
		pMeasRawData_s->flagsUseData,
		(IMMPC_FLAG_NEED_RAW_MAG));
}

/* Работа с флагами --<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

extern immpc_message_pack_type_e
IMMPC_GetDataMessage(
	immpc_meas_raw_data_s *pIMMPC_RawData_s,
	uint8_t *pDataIn,
	size_t 	buffSizeIn,
	uint8_t *pDataOut,
	size_t 	*pLengthOut);

static void
IMMPC_Generate_9dof_main_raw_pack(
	immpc_meas_raw_data_s *pIMMPC_RawData_s,
	uint8_t *pDataTx,
	size_t *pLengthDataTx);

static void
IMMPC_Generate_9dof_reserve_raw_pack(
	immpc_meas_raw_data_s *pIMMPC_RawData_s,
	uint8_t *pDataTx,
	size_t *pLengthDataTx);

static void
IMMPC_Generate_3dof_mag_raw_pack(
	immpc_meas_raw_data_s *pIMMPC_RawData_s,
	uint8_t *pDataTx,
	size_t *pLengthDataTx);

/*#### |End  | <-- Секция - "Прототипы глобальных функций" ###################*/


/*#### |Begin| --> Секция - "Определение макросов" ###########################*/
/*#### |End  | <-- Секция - "Определение макросов" ###########################*/


/*#### |Begin| --> Секция - "Include - подмодули" ############################*/
/*#### |End  | <-- Секция - "Include - подмодули" ############################*/

#endif  /* LIB_A_IMMPC_IIM_PROTOCOL_COMMUNICATE_ */

/*############################################################################*/
/*################################ END OF FILE ###############################*/
/*############################################################################*/
