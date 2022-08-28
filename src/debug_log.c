
#include "../inc/debug_log.h"
#include "../inc/debug_log_inc.h"

#ifdef USE_DEBUG_ASSERT
void __debug_assert(void)
{
	__disable_irq();
	while(1)
	{

	}
}
#endif

#ifdef USE_DEBUG_ASSERT_FULL
void __debug_assert(const char* _f, int _l)
{
	debug_loge("Assert", "%s, %d", _f, _l);
	__disable_irq();
	while(1)
	{

	}
}
#endif
