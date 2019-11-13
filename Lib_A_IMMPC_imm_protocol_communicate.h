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

#define __IMMPC_IS_SET_BIT(REG, BIT)	((REG) & (BIT) == BIT)

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

/* указатели на функции */
typedef struct
{
	/* ... */
} immpc_api_s;

///* структура указателей на переменные */
//typedef struct
//{
//	/* данные */
//	immpc_9dof_main_raw_pack_s *pIMMPC_9DOF_main_raw_pack_s;
//	immpc_9dof_main_calib_pack_s *pIMMPC_9DOF_main_calib_pack_s;
//	immpc_9dof_reserve_raw_pack_s *pIMMPC_9DOF_reserve_raw_pack_s;
//	immpc_9dof_reserve_calib_pack_s *pIMMPC_9DOF_reserve_calib_pack_s;
//	immpc_mag3dof_raw_pack_s *pIMMPC_MAG3DOF_raw_pack_s;
//	immpc_mag3dof_calib_pack_s *pIMMPC_MAG3DOF_calib_pack_s;
//
//	/* калибровочные матрицы */
//	immpc_acc3dof_main_calibmatrix_pack_s *pIMMPC_ACC3DOF_main_calibmatrix_pack_s;
//	immpc_acc3dof_reserve_calibmatrix_pack_s *pIMMPC_ACC3DOF_reserve_calibmatrix_pack_s;
//	immpc_gyr3dof_main_calibmatrix_pack_s *pIMMPC_GYR3DOF_main_calibmatrix_pack_s;
//	immpc_gyr3dof_reserve_calibmatrix_pack_s *pIMMPC_GYR3DOF_reserve_calibmatrix_pack_s;
//	immpc_mag3dof_calibmatrix_pack_s *pIMMPC_MAG3DOF_calibmatrix_pack_s;
//} immpc_pointer_data_s;


/* структура данных */
typedef struct
{
	/* "сырые" */
	int16_t rawMainAcc_a[3u];
	int16_t rawMainGyr_a[3u];

	int16_t rawReserveAcc_a[3u];
	int16_t rawReserveGyr_a[3u];

	int16_t rawMainTempAcc_a[3u];
	int16_t rawMainTempGyr_a[3u];

	int16_t rawReserveTempAcc_a[3u];
	int16_t rawReserveTempGyr_a[3u];

	int16_t rawMag_a[3u];
//	int16_t rawMainMag_a[3u];
//	int16_t rawReserveMag_a[3u];
	int16_t rawMagSelfTest[3u];

	/* калиброванные */
	__IMMPC_FPT__ calibMainAcc[3u];
	__IMMPC_FPT__ calibMainGyr[3u];

	__IMMPC_FPT__ calibReserveAcc[3u];
	__IMMPC_FPT__ calibReserveGyr[3u];

	__IMMPC_FPT__ normMainTempAcc[3u];
	__IMMPC_FPT__ normMainTempGyr[3u];

	__IMMPC_FPT__ normReserveTempAcc[3u];
	__IMMPC_FPT__ normReserveTempGyr[3u];

	__IMMPC_FPT__ calibMag[3u];
//	__IMMPC_FPT__ calibMainMag_a[3u];
//	__IMMPC_FPT__ calibReserveMag_a[3u];
} immpc_meas_data_s;

///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Запись данных в структуру.
// * 			Служит для записи данных полученные из датчика.
// *
// * @param[out]	*pData_s: 	Указатель на область памяти структуры, в которой будут содержаться
// * 							данные
// *
// * @param[in]	*pRawMainAcc_a:	Указатель на область памяти, из которой будут считываться данные
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_SetRawMainAcc(
//	immpc_meas_data_s *pData_s,
//	int16_t *pRawMainAcc_a)
//{
//	pData_s->rawMainAcc_a[0u] = *pRawMainAcc_a++;
//	pData_s->rawMainAcc_a[1u] = *pRawMainAcc_a++;
//	pData_s->rawMainAcc_a[2u] = *pRawMainAcc_a;
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Получение данных из структуры.
// * 			Служит для чтения данных, которые будут записаны в отправляемый пакет.
// *
// * @param[in]	*pData_s: 	Указатель на область памяти структуры, из которой будут считываться данные.
// *
// * @param[out]	*pRawMainAcc_a:	Указатель на область памяти, в которую будут запысываться данные.
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_GetRawMainAcc(
//	immpc_meas_data_s *pData_s,
//	int16_t *pRawMainAcc_a)
//{
//	*pRawMainAcc_a++ = pData_s->rawMainAcc_a[0u];
//	*pRawMainAcc_a++ = pData_s->rawMainAcc_a[1u];
//	*pRawMainAcc_a = pData_s->rawMainAcc_a[2u];
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Запись данных в структуру.
// * 			Служит для записи данных полученные из датчика.
// *
// * @param[out]	*pData_s: 	Указатель на область памяти структуры, в которой будут содержаться
// * 							данные
// *
// * @param[in]	*pCalibMainAcc_a:	Указатель на область памяти, из которой будут считываться данные
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_SetCalibMainAcc(
//	immpc_meas_data_s *pData_s,
//	__IMMPC_FPT__ *pCalibMainAcc_a)
//{
//	pData_s->calibMainAcc_a[0u] = *pCalibMainAcc_a++;
//	pData_s->calibMainAcc_a[1u] = *pCalibMainAcc_a++;
//	pData_s->calibMainAcc_a[2u] = *pCalibMainAcc_a;
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Получение данных из структуры.
// * 			Служит для чтения данных, которые будут записаны в отправляемый пакет.
// *
// * @param[in]	*pData_s: 	Указатель на область памяти структуры, из которой будут считываться данные.
// *
// * @param[out]	*pCalibMainAcc_a:	Указатель на область памяти, в которую будут запысываться данные.
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_GetCalibMainAcc(
//	immpc_meas_data_s *pData_s,
//	__IMMPC_FPT__ *pCalibMainAcc_a)
//{
//	*pCalibMainAcc_a++ =	pData_s->calibMainAcc_a[0u];
//	*pCalibMainAcc_a++ =	pData_s->calibMainAcc_a[1u];
//	*pCalibMainAcc_a =		pData_s->calibMainAcc_a[2u];
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Запись данных в структуру.
// * 			Служит для записи данных полученные из датчика.
// *
// * @param[out]	*pData_s: 	Указатель на область памяти структуры, в которой будут содержаться
// * 							данные
// *
// * @param[in]	*pRawMainGyr_a:	Указатель на область памяти, из которой будут считываться данные
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_SetRawMainGyr(
//	immpc_meas_data_s *pData_s,
//	int16_t *pRawMainGyr_a)
//{
//	pData_s->rawMainGyr_a[0u] = *pRawMainGyr_a++;
//	pData_s->rawMainGyr_a[1u] = *pRawMainGyr_a++;
//	pData_s->rawMainGyr_a[2u] = *pRawMainGyr_a;
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Получение данных из структуры.
// * 			Служит для чтения данных, которые будут записаны в отправляемый пакет.
// *
// * @param[in]	*pData_s: 	Указатель на область памяти структуры, из которой будут считываться данные.
// *
// * @param[out]	*pRawMainGyr_a:	Указатель на область памяти, в которую будут запысываться данные.
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_GetRawMainGyr(
//	immpc_meas_data_s *pData_s,
//	int16_t *pRawMainGyr_a)
//{
//	*pRawMainGyr_a++ =	pData_s->rawMainGyr_a[0u];
//	*pRawMainGyr_a++ =	pData_s->rawMainGyr_a[1u];
//	*pRawMainGyr_a =	pData_s->rawMainGyr_a[2u];
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Запись данных в структуру.
// * 			Служит для записи данных полученные из датчика.
// *
// * @param[out]	*pData_s: 	Указатель на область памяти структуры, в которой будут содержаться
// * 							данные
// *
// * @param[in]	*pCalibMainGyr_a:	Указатель на область памяти, из которой будут считываться данные
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_SetCalibMainGyr(
//	immpc_meas_data_s *pData_s,
//	__IMMPC_FPT__ *pCalibMainGyr_a)
//{
//	pData_s->calibMainGyr_a[0u] = *pCalibMainGyr_a++;
//	pData_s->calibMainGyr_a[1u] = *pCalibMainGyr_a++;
//	pData_s->calibMainGyr_a[2u] = *pCalibMainGyr_a;
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Получение данных из структуры.
// * 			Служит для чтения данных, которые будут записаны в отправляемый пакет.
// *
// * @param[in]	*pData_s: 	Указатель на область памяти структуры, из которой будут считываться данные.
// *
// * @param[out]	*pCalibMainGyr_a:	Указатель на область памяти, в которую будут запысываться данные.
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_GetCalibMainGyr(
//	immpc_meas_data_s *pData_s,
//	__IMMPC_FPT__ *pCalibMainGyr_a)
//{
//	*pCalibMainGyr_a++ =	pData_s->calibMainGyr_a[0u];
//	*pCalibMainGyr_a++ =	pData_s->calibMainGyr_a[1u];
//	*pCalibMainGyr_a =		pData_s->calibMainGyr_a[2u];
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Запись данных в структуру.
// * 			Служит для записи данных полученные из датчика.
// *
// * @param[out]	*pData_s: 	Указатель на область памяти структуры, в которой будут содержаться
// * 							данные
// *
// * @param[in]	*pRawMainTempAcc_a:	Указатель на область памяти, из которой будут считываться данные
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_SetRawMainTempAcc(
//	immpc_meas_data_s *pData_s,
//	int16_t *pRawMainTempAcc_a)
//{
//	pData_s->rawMainTempAcc_a[0u] = *pRawMainTempAcc_a++;
//	pData_s->rawMainTempAcc_a[1u] = *pRawMainTempAcc_a++;
//	pData_s->rawMainTempAcc_a[2u] = *pRawMainTempAcc_a;
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Получение данных из структуры.
// * 			Служит для чтения данных, которые будут записаны в отправляемый пакет.
// *
// * @param[in]	*pData_s: 	Указатель на область памяти структуры, из которой будут считываться данные.
// *
// * @param[out]	*pRawMainTempAcc_a:	Указатель на область памяти, в которую будут запысываться данные.
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_GetRawMainTempAcc(
//	immpc_meas_data_s *pData_s,
//	int16_t *pRawMainTempAcc_a)
//{
//	*pRawMainTempAcc_a++ =	pData_s->rawMainTempAcc_a[0u];
//	*pRawMainTempAcc_a++ =	pData_s->rawMainTempAcc_a[1u];
//	*pRawMainTempAcc_a = 	pData_s->rawMainTempAcc_a[2u];
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Запись данных в структуру.
// * 			Служит для записи данных полученные из датчика.
// *
// * @param[out]	*pData_s: 	Указатель на область памяти структуры, в которой будут содержаться
// * 							данные
// *
// * @param[in]	*pNormMainTempAcc_a:	Указатель на область памяти, из которой будут считываться данные
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_SetNormMainTempAcc(
//	immpc_meas_data_s *pData_s,
//	__IMMPC_FPT__ *pNormMainTempAcc_a)
//{
//	pData_s->normMainTempAcc_a[0u] = *pNormMainTempAcc_a++;
//	pData_s->normMainTempAcc_a[1u] = *pNormMainTempAcc_a++;
//	pData_s->normMainTempAcc_a[2u] = *pNormMainTempAcc_a;
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Получение данных из структуры.
// * 			Служит для чтения данных, которые будут записаны в отправляемый пакет.
// *
// * @param[in]	*pData_s: 	Указатель на область памяти структуры, из которой будут считываться данные.
// *
// * @param[out]	*pNormMainTempAcc_a:	Указатель на область памяти, в которую будут запысываться данные.
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_GetNormMainTempAcc(
//	immpc_meas_data_s *pData_s,
//	__IMMPC_FPT__ *pNormMainTempAcc_a)
//{
//	*pNormMainTempAcc_a++ = pData_s->normMainTempAcc_a[0u];
//	*pNormMainTempAcc_a++ =	pData_s->normMainTempAcc_a[1u];
//	*pNormMainTempAcc_a =	pData_s->normMainTempAcc_a[2u];
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Запись данных в структуру.
// * 			Служит для записи данных полученные из датчика.
// *
// * @param[out]	*pData_s: 	Указатель на область памяти структуры, в которой будут содержаться
// * 							данные
// *
// * @param[in]	*pRawMainTempGyr_a:	Указатель на область памяти, из которой будут считываться данные
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_SetRawMainTempGyr(
//	immpc_meas_data_s *pData_s,
//	int16_t *pRawMainTempGyr_a)
//{
//	pData_s->rawMainTempGyr_a[0u] = *pRawMainTempGyr_a++;
//	pData_s->rawMainTempGyr_a[1u] = *pRawMainTempGyr_a++;
//	pData_s->rawMainTempGyr_a[2u] = *pRawMainTempGyr_a;
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Получение данных из структуры.
// * 			Служит для чтения данных, которые будут записаны в отправляемый пакет.
// *
// * @param[in]	*pData_s: 	Указатель на область памяти структуры, из которой будут считываться данные.
// *
// * @param[out]	*pRawMainTempGyr_a:	Указатель на область памяти, в которую будут запысываться данные.
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_GetRawMainTempGyr(
//	immpc_meas_data_s *pData_s,
//	int16_t *pRawMainTempGyr_a)
//{
//	*pRawMainTempGyr_a++ =	pData_s->rawMainTempGyr_a[0u];
//	*pRawMainTempGyr_a++ =	pData_s->rawMainTempGyr_a[1u];
//	*pRawMainTempGyr_a =	pData_s->rawMainTempGyr_a[2u];
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Запись данных в структуру.
// * 			Служит для записи данных полученные из датчика.
// *
// * @param[out]	*pData_s: 	Указатель на область памяти структуры, в которой будут содержаться
// * 							данные
// *
// * @param[in]	*pNormMainTempGyr_a:	Указатель на область памяти, из которой будут считываться данные
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_SetNormMainTempGyr(
//	immpc_meas_data_s *pData_s,
//	__IMMPC_FPT__ *pNormMainTempGyr_a)
//{
//	pData_s->normMainTempGyr_a[0u] = *pNormMainTempGyr_a++;
//	pData_s->normMainTempGyr_a[1u] = *pNormMainTempGyr_a++;
//	pData_s->normMainTempGyr_a[2u] = *pNormMainTempGyr_a;
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Получение данных из структуры.
// * 			Служит для чтения данных, которые будут записаны в отправляемый пакет.
// *
// * @param[in]	*pData_s: 	Указатель на область памяти структуры, из которой будут считываться данные.
// *
// * @param[out]	*pNormMainTempGyr_a:	Указатель на область памяти, в которую будут запысываться данные.
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_GetNormMainTempGyr(
//	immpc_meas_data_s *pData_s,
//	__IMMPC_FPT__ *pNormMainTempGyr_a)
//{
//	*pNormMainTempGyr_a++ =	pData_s->normMainTempGyr_a[0u];
//	*pNormMainTempGyr_a++ =	pData_s->normMainTempGyr_a[1u];
//	*pNormMainTempGyr_a =	pData_s->normMainTempGyr_a[2u];
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Запись данных в структуру.
// * 			Служит для записи данных полученные из датчика.
// *
// * @param[out]	*pData_s: 	Указатель на область памяти структуры, в которой будут содержаться
// * 							данные
// *
// * @param[in]	*pRawMag_a:	Указатель на область памяти, из которой будут считываться данные
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_SetRawMag(
//	immpc_meas_data_s *pData_s,
//	int16_t *pRawMag_a)
//{
//	pData_s->rawMag_a[0u] = *pRawMag_a++;
//	pData_s->rawMag_a[1u] = *pRawMag_a++;
//	pData_s->rawMag_a[2u] = *pRawMag_a;
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Получение данных из структуры.
// * 			Служит для чтения данных, которые будут записаны в отправляемый пакет.
// *
// * @param[in]	*pData_s: 	Указатель на область памяти структуры, из которой будут считываться данные.
// *
// * @param[out]	*pRawMag_a:	Указатель на область памяти, в которую будут запысываться данные.
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_GetRawMag(
//	immpc_meas_data_s *pData_s,
//	int16_t *pRawMag_a)
//{
//	*pRawMag_a++ =	pData_s->rawMag_a[0u];
//	*pRawMag_a++ =	pData_s->rawMag_a[1u];
//	*pRawMag_a =	pData_s->rawMag_a[2u];
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Запись данных в структуру.
// * 			Служит для записи данных полученные из датчика.
// *
// * @param[out]	*pData_s: 	Указатель на область памяти структуры, в которой будут содержаться
// * 							данные
// *
// * @param[in]	*pCalibMag_a:	Указатель на область памяти, из которой будут считываться данные
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_SetCalibMag(
//	immpc_meas_data_s *pData_s,
//	__IMMPC_FPT__ *pCalibMag_a)
//{
//	pData_s->calibMag_a[0u] = *pCalibMag_a++;
//	pData_s->calibMag_a[1u] = *pCalibMag_a++;
//	pData_s->calibMag_a[2u] = *pCalibMag_a;
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Получение данных из структуры.
// * 			Служит для чтения данных, которые будут записаны в отправляемый пакет.
// *
// * @param[in]	*pData_s: 	Указатель на область памяти структуры, из которой будут считываться данные.
// *
// * @param[out]	*pCalibMag_a:	Указатель на область памяти, в которую будут запысываться данные.
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_GetCalibMag(
//	immpc_meas_data_s *pData_s,
//	__IMMPC_FPT__ *pCalibMag_a)
//{
//	*pCalibMag_a++ =	pData_s->calibMag_a[0u];
//	*pCalibMag_a++ =	pData_s->calibMag_a[1u];
//	*pCalibMag_a =		pData_s->calibMag_a[2u];
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Запись данных в структуру.
// * 			Служит для записи данных полученные из датчика.
// *
// * @param[out]	*pData_s: 	Указатель на область памяти структуры, в которой будут содержаться
// * 							данные
// *
// * @param[in]	*pRawReserveAcc_a:	Указатель на область памяти, из которой будут считываться данные
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_SetRawReserveAcc(
//	immpc_meas_data_s *pData_s,
//	int16_t *pRawReserveAcc_a)
//{
//	pData_s->rawMainAcc_a[0u] = *pRawReserveAcc_a++;
//	pData_s->rawMainAcc_a[1u] = *pRawReserveAcc_a++;
//	pData_s->rawMainAcc_a[2u] = *pRawReserveAcc_a;
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Получение данных из структуры.
// * 			Служит для чтения данных, которые будут записаны в отправляемый пакет.
// *
// * @param[in]	*pData_s: 	Указатель на область памяти структуры, из которой будут считываться данные.
// *
// * @param[out]	*pRawReserveAcc_a:	Указатель на область памяти, в которую будут запысываться данные.
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_GetRawReserveAcc(
//	immpc_meas_data_s *pData_s,
//	int16_t *pRawReserveAcc_a)
//{
//	*pRawReserveAcc_a++ =	pData_s->rawReserveAcc_a[0u];
//	*pRawReserveAcc_a++ =	pData_s->rawReserveAcc_a[1u];
//	*pRawReserveAcc_a = 	pData_s->rawReserveAcc_a[2u];
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Запись данных в структуру.
// * 			Служит для записи данных полученные из датчика.
// *
// * @param[out]	*pData_s: 	Указатель на область памяти структуры, в которой будут содержаться
// * 							данные
// *
// * @param[in]	*pCalibReserveAcc_a:	Указатель на область памяти, из которой будут считываться данные
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_SetCalibReserveAcc(
//	immpc_meas_data_s *pData_s,
//	__IMMPC_FPT__ *pCalibReserveAcc_a)
//{
//	pData_s->calibReserveAcc_a[0u] = *pCalibReserveAcc_a++;
//	pData_s->calibReserveAcc_a[1u] = *pCalibReserveAcc_a++;
//	pData_s->calibReserveAcc_a[2u] = *pCalibReserveAcc_a;
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Получение данных из структуры.
// * 			Служит для чтения данных, которые будут записаны в отправляемый пакет.
// *
// * @param[in]	*pData_s: 	Указатель на область памяти структуры, из которой будут считываться данные.
// *
// * @param[out]	*pCalibReserveAcc_a:	Указатель на область памяти, в которую будут запысываться данные.
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_GetCalibReserveAcc(
//	immpc_meas_data_s *pData_s,
//	__IMMPC_FPT__ *pCalibReserveAcc_a)
//{
//	*pCalibReserveAcc_a++ =	pData_s->calibReserveAcc_a[0u];
//	*pCalibReserveAcc_a++ =	pData_s->calibReserveAcc_a[1u];
//	*pCalibReserveAcc_a =	pData_s->calibReserveAcc_a[2u];
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Запись данных в структуру.
// * 			Служит для записи данных полученные из датчика.
// *
// * @param[out]	*pData_s: 	Указатель на область памяти структуры, в которой будут содержаться
// * 							данные
// *
// * @param[in]	*pRawReserveGyr_a:	Указатель на область памяти, из которой будут считываться данные
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_SetRawReserveGyr(
//	immpc_meas_data_s *pData_s,
//	int16_t *pRawReserveGyr_a)
//{
//	pData_s->rawReserveGyr_a[0u] = *pRawReserveGyr_a++;
//	pData_s->rawReserveGyr_a[1u] = *pRawReserveGyr_a++;
//	pData_s->rawReserveGyr_a[2u] = *pRawReserveGyr_a;
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Получение данных из структуры.
// * 			Служит для чтения данных, которые будут записаны в отправляемый пакет.
// *
// * @param[in]	*pData_s: 	Указатель на область памяти структуры, из которой будут считываться данные.
// *
// * @param[out]	*pRawReserveGyr_a:	Указатель на область памяти, в которую будут запысываться данные.
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_GetRawReserveGyr(
//	immpc_meas_data_s *pData_s,
//	int16_t *pRawReserveGyr_a)
//{
//	*pRawReserveGyr_a++ =	pData_s->rawReserveGyr_a[0u];
//	*pRawReserveGyr_a++ =	pData_s->rawReserveGyr_a[1u];
//	*pRawReserveGyr_a =		pData_s->rawReserveGyr_a[2u];
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Запись данных в структуру.
// * 			Служит для записи данных полученные из датчика.
// *
// * @param[out]	*pData_s: 	Указатель на область памяти структуры, в которой будут содержаться
// * 							данные
// *
// * @param[in]	*pCalibReserveGyr_a:	Указатель на область памяти, из которой будут считываться данные
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_SetCalibReserveGyr(
//	immpc_meas_data_s *pData_s,
//	__IMMPC_FPT__ *pCalibReserveGyr_a)
//{
//	pData_s->calibReserveGyr_a[0u] = *pCalibReserveGyr_a++;
//	pData_s->calibReserveGyr_a[1u] = *pCalibReserveGyr_a++;
//	pData_s->calibReserveGyr_a[2u] = *pCalibReserveGyr_a;
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Получение данных из структуры.
// * 			Служит для чтения данных, которые будут записаны в отправляемый пакет.
// *
// * @param[in]	*pData_s: 	Указатель на область памяти структуры, из которой будут считываться данные.
// *
// * @param[out]	*pCalibReserveGyr_a:	Указатель на область памяти, в которую будут запысываться данные.
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_GetCalibReserveGyr(
//	immpc_meas_data_s *pData_s,
//	__IMMPC_FPT__ *pCalibReserveGyr_a)
//{
//	*pCalibReserveGyr_a++ =	pData_s->calibReserveGyr_a[0u];
//	*pCalibReserveGyr_a++ =	pData_s->calibReserveGyr_a[1u];
//	*pCalibReserveGyr_a =	pData_s->calibReserveGyr_a[2u];
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Запись данных в структуру.
// * 			Служит для записи данных полученные из датчика.
// *
// * @param[out]	*pData_s: 	Указатель на область памяти структуры, в которой будут содержаться
// * 							данные
// *
// * @param[in]	*pRawReserveTempAcc_a:	Указатель на область памяти, из которой будут считываться данные
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_SetRawReserveTempAcc(
//	immpc_meas_data_s *pData_s,
//	int16_t *pRawReserveTempAcc_a)
//{
//	pData_s->rawMainTempAcc_a[0u] = *pRawReserveTempAcc_a++;
//	pData_s->rawMainTempAcc_a[1u] = *pRawReserveTempAcc_a++;
//	pData_s->rawMainTempAcc_a[2u] = *pRawReserveTempAcc_a;
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Получение данных из структуры.
// * 			Служит для чтения данных, которые будут записаны в отправляемый пакет.
// *
// * @param[in]	*pData_s: 	Указатель на область памяти структуры, из которой будут считываться данные.
// *
// * @param[out]	*pRawReserveAcc_a:	Указатель на область памяти, в которую будут запысываться данные.
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_GetRawReserveTempAcc(
//	immpc_meas_data_s *pData_s,
//	int16_t *pRawReserveTempAcc_a)
//{
//	*pRawReserveTempAcc_a++ =	pData_s->rawReserveTempAcc_a[0u];
//	*pRawReserveTempAcc_a++ =	pData_s->rawReserveTempAcc_a[1u];
//	*pRawReserveTempAcc_a = 	pData_s->rawReserveTempAcc_a[2u];
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Запись данных в структуру.
// * 			Служит для записи данных полученные из датчика.
// *
// * @param[out]	*pData_s: 	Указатель на область памяти структуры, в которой будут содержаться
// * 							данные
// *
// * @param[in]	*pNormReserveTempAcc_a:	Указатель на область памяти, из которой будут считываться данные
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_SetNormReserveTempAcc(
//	immpc_meas_data_s *pData_s,
//	__IMMPC_FPT__ *pNormReserveTempAcc_a)
//{
//	pData_s->normReserveTempAcc_a[0u] = *pNormReserveTempAcc_a++;
//	pData_s->normReserveTempAcc_a[1u] = *pNormReserveTempAcc_a++;
//	pData_s->normReserveTempAcc_a[2u] = *pNormReserveTempAcc_a;
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Получение данных из структуры.
// * 			Служит для чтения данных, которые будут записаны в отправляемый пакет.
// *
// * @param[in]	*pData_s: 	Указатель на область памяти структуры, из которой будут считываться данные.
// *
// * @param[out]	*pNormReserveTempAcc_a:	Указатель на область памяти, в которую будут запысываться данные.
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_GetNormReserveTempAcc(
//	immpc_meas_data_s *pData_s,
//	__IMMPC_FPT__ *pNormReserveTempAcc_a)
//{
//	*pNormReserveTempAcc_a++ =	pData_s->normReserveTempAcc_a[0u];
//	*pNormReserveTempAcc_a++ =	pData_s->normReserveTempAcc_a[1u];
//	*pNormReserveTempAcc_a =	pData_s->normReserveTempAcc_a[2u];
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Запись данных в структуру.
// * 			Служит для записи данных полученные из датчика.
// *
// * @param[out]	*pData_s: 	Указатель на область памяти структуры, в которой будут содержаться
// * 							данные
// *
// * @param[in]	*pRawReserveTempGyr_a:	Указатель на область памяти, из которой будут считываться данные
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_SetRawReserveTempGyr(
//	immpc_meas_data_s *pData_s,
//	int16_t *pRawReserveTempGyr_a)
//{
//	pData_s->rawReserveTempGyr_a[0u] = *pRawReserveTempGyr_a++;
//	pData_s->rawReserveTempGyr_a[1u] = *pRawReserveTempGyr_a++;
//	pData_s->rawReserveTempGyr_a[2u] = *pRawReserveTempGyr_a;
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Получение данных из структуры.
// * 			Служит для чтения данных, которые будут записаны в отправляемый пакет.
// *
// * @param[in]	*pData_s: 	Указатель на область памяти структуры, из которой будут считываться данные.
// *
// * @param[out]	*pRawReserveTempGyr_a:	Указатель на область памяти, в которую будут запысываться данные.
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_GetRawReserveTempGyr(
//	immpc_meas_data_s *pData_s,
//	int16_t *pRawReserveTempGyr_a)
//{
//	*pRawReserveTempGyr_a++ =	pData_s->rawReserveTempGyr_a[0u];
//	*pRawReserveTempGyr_a++ =	pData_s->rawReserveTempGyr_a[1u];
//	*pRawReserveTempGyr_a =		pData_s->rawReserveTempGyr_a[2u];
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Запись данных в структуру.
// * 			Служит для записи данных полученные из датчика.
// *
// * @param[out]	*pData_s: 	Указатель на область памяти структуры, в которой будут содержаться
// * 							данные
// *
// * @param[in]	*pNormReserveTempGyr_a:	Указатель на область памяти, из которой будут считываться данные
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_SetNormReserveTempGyr(
//	immpc_meas_data_s *pData_s,
//	__IMMPC_FPT__ *pNormReserveTempGyr_a)
//{
//	pData_s->normReserveTempGyr_a[0u] = *pNormReserveTempGyr_a++;
//	pData_s->normReserveTempGyr_a[1u] = *pNormReserveTempGyr_a++;
//	pData_s->normReserveTempGyr_a[2u] = *pNormReserveTempGyr_a;
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Получение данных из структуры.
// * 			Служит для чтения данных, которые будут записаны в отправляемый пакет.
// *
// * @param[in]	*pData_s: 	Указатель на область памяти структуры, из которой будут считываться данные.
// *
// * @param[out]	*pNormReserveTempGyr_a:	Указатель на область памяти, в которую будут запысываться данные.
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_GetNormReserveTempGyr(
//	immpc_meas_data_s *pData_s,
//	__IMMPC_FPT__ *pNormReserveTempGyr_a)
//{
//	*pNormReserveTempGyr_a++ =	pData_s->normReserveTempGyr_a[0u];
//	*pNormReserveTempGyr_a++ =	pData_s->normReserveTempGyr_a[1u];
//	*pNormReserveTempGyr_a =	pData_s->normReserveTempGyr_a[2u];
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Запись данных в структуру.
// * 			Служит для записи данных полученные из датчика.
// *
// * @param[out]	*pData_s: 	Указатель на область памяти структуры, в которой будут содержаться
// * 							данные
// *
// * @param[in]	*pRawMagSelfTest_a:	Указатель на область памяти, из которой будут считываться данные
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_SetRawMagSelfTest(
//	immpc_meas_data_s *pData_s,
//	int16_t *pRawMagSelfTest)
//{
//	pData_s->rawMagSelfTest[0u] = *pRawMagSelfTest++;
//	pData_s->rawMagSelfTest[1u] = *pRawMagSelfTest++;
//	pData_s->rawMagSelfTest[2u] = *pRawMagSelfTest;
//}
//
///*-------------------------------------------------------------------------*//**
// * @author	Dmitry Tanikeev
// * @date	12-ноя-2019
// *
// * @brief	Получение данных из структуры.
// * 			Служит для чтения данных, которые будут записаны в отправляемый пакет.
// *
// * @param[in]	*pData_s: 	Указатель на область памяти структуры, из которой будут считываться данные.
// *
// * @param[out]	*pRawMagSelfTest_a:	Указатель на область памяти, в которую будут запысываться данные.
// */
//__IMMPC_ALWAYS_INLINE void
//IMMPC_GetRawMagSelfTest(
//	immpc_meas_data_s *pData_s,
//	int16_t *pRawMagSelfTest)
//{
//	*pRawMagSelfTest++ =	pData_s->rawMagSelfTest[0u];
//	*pRawMagSelfTest++ =	pData_s->rawMagSelfTest[1u];
//	*pRawMagSelfTest =		pData_s->rawMagSelfTest[2u];
//}




/*#### |End  | <-- Секция - "Определение констант" ###########################*/


/*#### |Begin| --> Секция - "Определение типов" ##############################*/
/*#### |End  | <-- Секция - "Определение типов" ##############################*/


/*#### |Begin| --> Секция - "Определение глобальных переменных" ##############*/
/*#### |End  | <-- Секция - "Определение глобальных переменных" ##############*/


/*#### |Begin| --> Секция - "Прототипы глобальных функций" ###################*/
extern void
IMMPC_PointerDataInit(
	immpc_meas_data_s *pDataMeas_ss);

extern immpc_message_pack_type_e
IMMPC_GetTypeMessage(
	const uint8_t *pData,
		  size_t 	buffSize,
		  uint8_t *pMessageHead);

extern immpc_message_pack_type_e
IMMPC_GetDataMessage(
	uint8_t *pDataIn,
	size_t 	buffSize,
	immpc_meas_data_s *pIMMPC_Data_s,
	uint8_t *pDataOut,
	size_t 	*pLengthOut);
/*#### |End  | <-- Секция - "Прототипы глобальных функций" ###################*/


/*#### |Begin| --> Секция - "Определение макросов" ###########################*/
/*#### |End  | <-- Секция - "Определение макросов" ###########################*/


/*#### |Begin| --> Секция - "Include - подмодули" ############################*/
/*#### |End  | <-- Секция - "Include - подмодули" ############################*/

#endif  /* LIB_A_IMMPC_IIM_PROTOCOL_COMMUNICATE_ */

/*############################################################################*/
/*################################ END OF FILE ###############################*/
/*############################################################################*/
