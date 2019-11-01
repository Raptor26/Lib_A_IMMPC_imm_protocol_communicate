/**
 * @file    %<%NAME%>%.%<%EXTENSION%>%
 * @author  %<%USER%>%
 * @version
 * @date    %<%DATE%>%, %<%TIME%>%
 * @brief
 */


#ifndef LIB_A_IIMPC_IIM_PROTOCOL_COMMUNICATE_
#define LIB_A_IIMPC_IIM_PROTOCOL_COMMUNICATE_


/*#### |Begin| --> Секция - "Include" ########################################*/
/*==== |Begin| --> Секция - "C libraries" ====================================*/
#include "stdint.h"
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

#define IIMPC_START_FRAME								((uint16_t)0xAAAA)

#define IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS             0b10000000
#define IIMPC_PACK_REQUESTS_BITS_RESERV_MEAS            0b01000000
#define IIMPC_PACK_REQUESTS_BITS_READ_MEAS              0b00100000
#define IIMPC_PACK_REQUESTS_BITS_IS_DATA_REQUEST        0b00010000

#define IIMPC_PACK_REQUESTS_BITS_SET_CALIB_MEAS(var)    (var | IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS)
#define IIMPC_PACK_REQUESTS_BITS_SET_RAW_MEAS(var)      (var & (~IIMPC_PACK_REQUESTS_BITS_CALIB_MEAS))

typedef enum
{
	IMMPC_MESSAGE_ID_INKNOW = 0,
	IMMPC_MESSAGE_ID_9DOF_PACK_MAIN_,
	IMMPC_MESSAGE_ID_9DOF_PACK_RESERVE,

	IMMPC_MESSAGE_ID_ACC3DOF_CALIBMATRIX,
	IMMPC_MESSAGE_ID_GYR3DOF_CALIBMATRIX,
	IMMPC_MESSAGE_ID_MAG3DOF_CALIBMATRIX,

	IMMPC_MESSAGE_ID_3DOF_PACK_MAIN,

} immpc_message_id_e;

typedef enum
{
	IMMPC_MESSAGE_PACK_UNKNOW = 0u,
	IMMPC_MESSAGE_PACK_9dof_main_raw_pack_s,
} immpc_message_struct_e;

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

/*#### |End  | <-- Секция - "Определение констант" ###########################*/


/*#### |Begin| --> Секция - "Определение типов" ##############################*/
/*#### |End  | <-- Секция - "Определение типов" ##############################*/


/*#### |Begin| --> Секция - "Определение глобальных переменных" ##############*/
/*#### |End  | <-- Секция - "Определение глобальных переменных" ##############*/


/*#### |Begin| --> Секция - "Прототипы глобальных функций" ###################*/
/*#### |End  | <-- Секция - "Прототипы глобальных функций" ###################*/


/*#### |Begin| --> Секция - "Определение макросов" ###########################*/
/*#### |End  | <-- Секция - "Определение макросов" ###########################*/


/*#### |Begin| --> Секция - "Include - подмодули" ############################*/
/*#### |End  | <-- Секция - "Include - подмодули" ############################*/

#endif  /* LIB_A_IIMPC_IIM_PROTOCOL_COMMUNICATE_ */

/*############################################################################*/
/*################################ END OF FILE ###############################*/
/*############################################################################*/
