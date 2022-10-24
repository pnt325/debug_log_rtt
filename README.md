# debug_log_rtt
Source code for debug text log over Segger RTT

## Support

### 1. Print text color

| Text | Color |
|------|-------|
| Normal | White |
| Info | White |
| Warning | Yellow |
| Error | Red

### 2. Assert

|Format | Details |
|-------|---------|
| ASSERT | without print message. |
| ASSERT_FULL | Print message file and line.

### 3. Usage

Implement the function: `__debug_log_gettick_ms`
```c
uint32_t __debug_log_gettick_ms(void)
{
    return HAL_getTick();
}
```

Change suitable project MCU and HAL: [debug_log_inc](inc/debug_log_inc.h)

```c
// TODO Change include source for another task
#include "stm32f7xx_hal.h"
```