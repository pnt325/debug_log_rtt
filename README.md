# debug_log_rtt
Source code for debug text log over Segger RTT

## Support

### 1. Print text color

| Text    | Color  |
|---------|--------|
| Normal  | <span style="color:white">White</span>   |
| Info    | <span style="color:white">White</span>   |
| Warning | <span style="color:yellow">Yellow</span> |
| Error   | <span style="color:red">Red</span>       |

### 2. Assert

| Format      | Details                                  |
|-------------|------------------------------------------|
| ASSERT      | Without message                          |
| ASSERT_FULL | Function name and linenumber message     |

### 3. Usage

Enable log `timestamp` in [debug_log.h](inc/debug_log.h)
```c
Line 12

/* TODO Comment this macro if don't use timestampe in log */
#define USE_DEBUG_LOG_TIMESTAMP
```

If defined macro `USE_DEBUG_LOG_TIMESTAMP` implement function `__debug_log_gettick_ms` return current tick count in `ms`
```c
uint32_t __debug_log_gettick_ms(void)
{
    return HAL_getTick();
}
```

Update include MCU arch [debug_log_inc.h](inc/debug_log_inc.h)

```c
Line 4

// TODO Change include source for another task
#include "stm32f7xx_hal.h"
```