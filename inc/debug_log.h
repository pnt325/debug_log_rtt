#ifndef _DEBUG_LOG_H_
#define _DEBUG_LOG_H_

#include <stdint.h>

/* Macro */
#define USE_DEBUG_LOG
//#define USE_DEBUG_ASSERT
#define USE_DEBUG_ASSERT_FULL


#ifdef USE_DEBUG_LOG

/* TODO Comment this macro if don't use timestampe in log */
//#define USE_DEBUG_LOG_TIMESTAMP

#include "../utils/SEGGER_RTT/RTT/SEGGER_RTT.h"
#define debug_log_init()                SEGGER_RTT_ConfigUpBuffer(0, NULL, NULL, 0, SEGGER_RTT_MODE_NO_BLOCK_SKIP);	\
										SEGGER_RTT_printf(0, RTT_CTRL_CLEAR)
#define debug_logln()                   SEGGER_RTT_printf(0, "\r\n");
#define debug_log(__c, ...)             SEGGER_RTT_printf(0, RTT_CTRL_TEXT_BRIGHT_WHITE""__c, ##__VA_ARGS__)
#ifdef USE_DEBUG_LOG_TIMESTAMP
uint32_t __debug_log_gettick_ms(void);
#define debug_logi(_tag, __c, ...)      SEGGER_RTT_printf(0, RTT_CTRL_TEXT_BRIGHT_WHITE"I (%u) %s: "__c"\r\n", __debug_log_gettick_ms, _tag, ##__VA_ARGS__)
#define debug_loge(_tag, __c, ...)      SEGGER_RTT_printf(0,   RTT_CTRL_TEXT_BRIGHT_RED"E (%u) %s: "__c"\r\n", __debug_log_gettick_ms, _tag, ##__VA_ARGS__)
#define debug_logw(_tag, __c, ...)      SEGGER_RTT_printf(0,       RTT_CTRL_TEXT_YELLOW"W (%u) %s: "__c"\r\n", __debug_log_gettick_ms, _tag, ##__VA_ARGS__)
#else 	/* not define USE_DEBUG_LOG_TIMESTAMP */
#define debug_logi(_tag, __c, ...)      SEGGER_RTT_printf(0, RTT_CTRL_TEXT_BRIGHT_WHITE"I %s: "__c"\r\n", _tag, ##__VA_ARGS__)
#define debug_loge(_tag, __c, ...)      SEGGER_RTT_printf(0,   RTT_CTRL_TEXT_BRIGHT_RED"E %s: "__c"\r\n", _tag, ##__VA_ARGS__)
#define debug_logw(_tag, __c, ...)      SEGGER_RTT_printf(0,       RTT_CTRL_TEXT_YELLOW"W %s: "__c"\r\n", _tag, ##__VA_ARGS__)
#endif	/*end USE_DEBUG_LOG_TIMESTAMP*/
#else 	/* not define USE_DEBUG_LOG*/
#define debug_log_init()
#define debug_log(__c, ...)
#define debug_logln()
#define debug_logi(_tag, __c, ...)
#define debug_loge(_tag, __c, ...)
#define debug_logw(_tag, __c, ...)
#endif	/* end USE_DEBUG_LOG */

#if defined(USE_DEBUG_ASSERT) && defined(USE_DEBUG_ASSERT_FULL)
#error "! Multi assert defined !"
#else
#if defined(USE_DEBUG_ASSERT)
void __debug_assert(void);
#define debug_assert(__v)		(__v)?(void)0: __debug_assert()
#elif defined(USE_DEBUG_ASSERT_FULL)
void __debug_assert(const char* _f, int _l);
#define debug_assert(__v)							\
	do												\
	{												\
		if(__v);									\
		else										\
			__debug_assert(__func__, __LINE__);		\
	} while (0);
#else
#define debug_assert(__v)
#endif
#endif

#endif /*_DEBUG_LOG_H_*/
