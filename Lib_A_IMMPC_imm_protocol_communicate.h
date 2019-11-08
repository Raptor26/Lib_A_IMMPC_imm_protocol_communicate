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

#define IIMPC_START_FRAME									((uint16_t)	0xAAAA)
#define IIMPC_RESPONCE_END_FRAME							((uint8_t)	0x55)

#define IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS             	(0b10000000) /* калиброванный */
#define IIMPC_PACK_REQUESTS_BITS_RESERVE_MEAS            	(0b01000000) /* резервный */
#define IIMPC_PACK_REQUESTS_BITS_READ_MEAS              	(0b00100000) /* чтение данных с пакета с последующей записью */
#define IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST        	(0b00010000) /* запрос или команда */

#define IIMPC_PACK_REQUESTS_BITS_SET_CALIB_MEAS(var)    	(var | IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS)
#define IIMPC_PACK_REQUESTS_BITS_SET_RAW_MEAS(var)      	(var & (~IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS))
#define __IIMPC_PACK_REQUESTS_BITS_IsSetCalibMeas(var)		(IIMPC_PACK_REQUESTS_BITS_SET_CALIB_MEAS(var) == IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS)

#define IIMPC_PACK_REQUESTS_BITS_SET_RESERV_MEAS(var)		(var | IIMPC_PACK_REQUESTS_BITS_RESERV_MEAS)
#define IIMPC_PACK_REQUESTS_BITS_SET_MAIN_MEAS(var)    		(var & (~IIMPC_PACK_REQUESTS_BITS_RESERV_MEAS))
#define __IIMPC_PACK_REQUESTS_BITS_IsSetReservMeas(var) 	(IIMPC_PACK_REQUESTS_BITS_SET_RESERV_MEAS(var) == IIMPC_PACK_REQUESTS_BITS_RESERV_MEAS)

#define IIMPC_PACK_REQUESTS_BITS_SET_READ_MEAS(var)			(var | IIMPC_PACK_REQUESTS_BITS_READ_MEAS)
#define IIMPC_PACK_REQUESTS_BITS_SET_NOT_READ_MEAS(var)		(var & (~IIMPC_PACK_REQUESTS_BITS_READ_MEAS)
#define __IIMPC_PACK_REQUESTS_BITS_IsSetReadFlag(var)		(IIMPC_PACK_REQUESTS_BITS_SET_READ_MEAS(var) == IIMPC_PACK_REQUESTS_BITS_READ_MEAS)

#define IIMPC_PACK_REQUESTS_BITS_SET_REQUEST(var)			(var | IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST)
#define IIMPC_PACK_REQUESTS_BITS_SET_DATA_PAYLOAD(var)		(var & (~IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST)
#define __IIMPC_PACK_REQUESTS_BITS_IsSetDataRequest(var)	(IIMPC_PACK_REQUESTS_BITS_SET_REQUEST(var) == IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST)

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

#define IMMPC_MESSAGE_TYPE_BitsInID(bitsInID) 					(((((uint16_t) 	(0u | (bitsInID))) << 8u) & 0xFF00))
#define IMMPC_MESSAGE_TYPE_BitsInPackRequests(bitsInPackReq)	(((uint16_t) 	(0u | bitsInPackReq)) & 0x00FF)

#define IMMPC_MESSAGE_TYPE_ReturnMessageType(bitsInID, bitsInPackReq)	\
	((IMMPC_MESSAGE_TYPE_BitsInID(bitsInID)) | (IMMPC_MESSAGE_TYPE_BitsInPackRequests(bitsInPackReq)))

typedef enum
{
	IMMPC_MESSAGE_PACK_UNKNOWN = 0u,
	/* пакеты с данными */
	IMMPC_MESSAGE_PACK_9dof_main_raw_pack_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_9DOF_PACK_MAIN,
												0u),
	IMMPC_MESSAGE_PACK_9dof_main_calib_pack_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_9DOF_PACK_MAIN,
												IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS),
	IMMPC_MESSAGE_PACK_9dof_reserve_raw_pack_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_9DOF_PACK_RESERVE,
												IIMPC_PACK_REQUESTS_BITS_RESERVE_MEAS),
	IMMPC_MESSAGE_PACK_9dof_reserve_calib_pack_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_9DOF_PACK_RESERVE,
												IIMPC_PACK_REQUESTS_BITS_RESERVE_MEAS |
												IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS),
	IMMPC_MESSAGE_PACK_mag3dof_raw_pack_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_MAG3DOF_PACK,
												0u),
	IMMPC_MESSAGE_PACK_mag3dof_calib_pack_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_MAG3DOF_PACK,
												IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS),
	IMMPC_MESSAGE_PACK_acc3dof_main_calibmatrix_read_pack_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_ACC3DOF_CALIBMATRIX,
												IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS),
	IMMPC_MESSAGE_PACK_acc3dof_main_calibmatrix_write_pack_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_ACC3DOF_CALIBMATRIX,
												IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS |
												IIMPC_PACK_REQUESTS_BITS_READ_MEAS),
	IMMPC_MESSAGE_PACK_acc3dof_reserve_calibmatrix_read_pack_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_ACC3DOF_CALIBMATRIX,
												IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS |
												IIMPC_PACK_REQUESTS_BITS_RESERVE_MEAS),
	IMMPC_MESSAGE_PACK_acc3dof_reserve_calibmatrix_write_pack_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_ACC3DOF_CALIBMATRIX,
												IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS |
												IIMPC_PACK_REQUESTS_BITS_READ_MEAS |
												IIMPC_PACK_REQUESTS_BITS_RESERVE_MEAS),
	IMMPC_MESSAGE_PACK_gyr3dof_main_calibmatrix_read_pack_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_GYR3DOF_CALIBMATRIX,
												IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS),
	IMMPC_MESSAGE_PACK_gyr3dof_main_calibmatrix_write_pack_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_GYR3DOF_CALIBMATRIX,
												IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS |
												IIMPC_PACK_REQUESTS_BITS_READ_MEAS),
	IMMPC_MESSAGE_PACK_gyr3dof_reserve_calibmatrix_read_pack_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_GYR3DOF_CALIBMATRIX,
												IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS |
												IIMPC_PACK_REQUESTS_BITS_RESERVE_MEAS),
	IMMPC_MESSAGE_PACK_gyr3dof_reserve_calibmatrix_write_pack_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_GYR3DOF_CALIBMATRIX,
												IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS |
												IIMPC_PACK_REQUESTS_BITS_READ_MEAS |
												IIMPC_PACK_REQUESTS_BITS_RESERVE_MEAS),
	IMMPC_MESSAGE_PACK_mag3dof_calibmatrix_read_pack_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_MAG3DOF_CALIBMATRIX,
												IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS),
	IMMPC_MESSAGE_PACK_mag3dof_calibmatrix_write_pack_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_MAG3DOF_CALIBMATRIX,
												IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS |
												IIMPC_PACK_REQUESTS_BITS_READ_MEAS),
	/* запросы */
	IMMPC_MESSAGE_PACK_9dof_main_raw_request_cmd_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_9DOF_PACK_MAIN,
												IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST),

	IMMPC_MESSAGE_PACK_9dof_main_calib_request_cmd_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_9DOF_PACK_MAIN,
												IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST |
												IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS),
	IMMPC_MESSAGE_PACK_9dof_reserve_raw_request_cmd_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_9DOF_PACK_RESERVE,
												IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST |
												IIMPC_PACK_REQUESTS_BITS_RESERVE_MEAS),
	IMMPC_MESSAGE_PACK_9dof_reserve_calib_request_cmd_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_9DOF_PACK_RESERVE,
												IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST |
												IIMPC_PACK_REQUESTS_BITS_RESERVE_MEAS |
												IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS),
	IMMPC_MESSAGE_PACK_acc3dof_main_calibmatrix_request_cmd_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_ACC3DOF_CALIBMATRIX,
												IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST |
												IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS),
	IMMPC_MESSAGE_PACK_acc3dof_reserve_calibmatrix_request_cmd_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_ACC3DOF_CALIBMATRIX,
												IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST |
												IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS |
												IIMPC_PACK_REQUESTS_BITS_RESERVE_MEAS),
	IMMPC_MESSAGE_PACK_gyr3dof_main_calibmatrix_request_cmd_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_GYR3DOF_CALIBMATRIX,
												IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST |
												IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS),
	IMMPC_MESSAGE_PACK_gyr3dof_reserve_calibmatrix_request_cmd_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_GYR3DOF_CALIBMATRIX,
												IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST |
												IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS |
												IIMPC_PACK_REQUESTS_BITS_RESERVE_MEAS),
	IMMPC_MESSAGE_PACK_mag3dof_calibmatrix_request_cmd_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_MAG3DOF_CALIBMATRIX,
												IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST |
												IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS),
	IMMPC_MESSAGE_PACK_mag3dof_raw_request_cmd_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_MAG3DOF_PACK,
												IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST),
	IMMPC_MESSAGE_PACK_mag3dof_calib_request_cmd_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_MAG3DOF_PACK,
												IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST |
												IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS),
	/* команды */
	IMMPC_MESSAGE_PACK_write_all_calibmatrix_in_eeprom_cmd_s = /* запись данных в EEPROM ИИМ */
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_WRITE_ALL_CALIBMATRIX,
												IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS |
												IIMPC_PACK_REQUESTS_BITS_READ_MEAS |
												IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST),
	/* коды ответных сообщений */
	IMMPC_MESSAGE_PACK_response_code_error_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_RESPONSE_CODE_ERROR,
												IIMPC_RESPONCE_END_FRAME),
	IMMPC_MESSAGE_PACK_response_code_invalid_crc_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_RESPONSE_CODE_INVALID_CRC,
												IIMPC_RESPONCE_END_FRAME),
	IMMPC_MESSAGE_PACK_response_code_invalid_calibration_matrix_from_eeprom_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_RESPONSE_CODE_INVALID_CALIBRATION_MATRIX_FROM_EEPROM,
												IIMPC_RESPONCE_END_FRAME),
	IMMPC_MESSAGE_PACK_response_code_ok_s =
		IMMPC_MESSAGE_TYPE_ReturnMessageType(	IMMPC_MESSAGE_ID_RESPONSE_CODE_OK,
												IIMPC_RESPONCE_END_FRAME),
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
	float acc[3u];
	float gyr[3u];
	float mag[3u];

	float accTemp[3u];
	float gyrTemp[3u];
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
	float acc[3u];
	float gyr[3u];
	float mag[3u];

	float accTemp[3u];
	float gyrTemp[3u];
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

/* структура указателей на переменные */
typedef struct
{
	/* данные */
	immpc_9dof_main_raw_pack_s *pIMMPC_9DOF_main_raw_pack_s;
	immpc_9dof_main_calib_pack_s *pIMMPC_9DOF_main_calib_pack_s;
	immpc_9dof_reserve_raw_pack_s *pIMMPC_9DOF_reserve_raw_pack_s;
	immpc_9dof_reserve_calib_pack_s *pIMMPC_9DOF_reserve_calib_pack_s;
	immpc_mag3dof_raw_pack_s *pIMMPC_MAG3DOF_raw_pack_s;
	immpc_mag3dof_calib_pack_s *pIMMPC_MAG3DOF_calib_pack_s;

	/* калибровочные матрицы */
	immpc_acc3dof_main_calibmatrix_pack_s *pIMMPC_ACC3DOF_main_calibmatrix_pack_s;
	immpc_acc3dof_reserve_calibmatrix_pack_s *pIMMPC_ACC3DOF_reserve_calibmatrix_pack_s;
	immpc_gyr3dof_main_calibmatrix_pack_s *pIMMPC_GYR3DOF_main_calibmatrix_pack_s;
	immpc_gyr3dof_reserve_calibmatrix_pack_s *pIMMPC_GYR3DOF_reserve_calibmatrix_pack_s;
	immpc_mag3dof_calibmatrix_pack_s *pIMMPC_MAG3DOF_calibmatrix_pack_s;
} immpc_pointer_data_s;

/*#### |End  | <-- Секция - "Определение констант" ###########################*/


/*#### |Begin| --> Секция - "Определение типов" ##############################*/
/*#### |End  | <-- Секция - "Определение типов" ##############################*/


/*#### |Begin| --> Секция - "Определение глобальных переменных" ##############*/
/*#### |End  | <-- Секция - "Определение глобальных переменных" ##############*/


/*#### |Begin| --> Секция - "Прототипы глобальных функций" ###################*/
extern void
IMMPC_PointerDataInit(
	immpc_pointer_data_s pointerSetData_s);

extern immpc_message_pack_type_e
IMMPC_GetTypeMessage(
	const uint8_t *pData,
	size_t 	buffSize);

extern immpc_message_pack_type_e
IMMPC_GetDataMessage(
	uint8_t *pData,
	size_t 	buffSize,
	uint8_t *pDataResponse,
	size_t 	*pBuffSizeResponse);
/*#### |End  | <-- Секция - "Прототипы глобальных функций" ###################*/


/*#### |Begin| --> Секция - "Определение макросов" ###########################*/
/*#### |End  | <-- Секция - "Определение макросов" ###########################*/


/*#### |Begin| --> Секция - "Include - подмодули" ############################*/
/*#### |End  | <-- Секция - "Include - подмодули" ############################*/

#endif  /* LIB_A_IMMPC_IIM_PROTOCOL_COMMUNICATE_ */

/*############################################################################*/
/*################################ END OF FILE ###############################*/
/*############################################################################*/
