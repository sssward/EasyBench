#include "easyBench.h"

void EasyBench_systick_Init(void)
{
    SysTick->LOAD = 0xFFFFFF; // 设置重装载值
    SysTick->VAL = 0;         // 清除当前值
    SysTick->CTRL = SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_CLKSOURCE_Msk; // 启用SysTick，使用处理器时钟
}

inline void EasyBench_Start(Bench *bench)
{
    bench->startTick = SysTick->VAL;
}

inline void EasyBench_Stop(Bench *bench)
{
	bench->stopTick = SysTick->VAL;
}

void EasyBench_Calculate(Bench *bench)
{
	bench->usedTime = ((float)((bench->startTick - bench->stopTick) & 0xFFFFFF) / SYSCLK * 1000000) - 0.111765;
}