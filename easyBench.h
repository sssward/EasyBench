#ifndef _EASYBENCH_H_
#define _EASYBENCH_H_

#include <stdint.h>

#define SYSCLK 170000000  //设置当前系统时钟频率

typedef struct Bench
{
    uint32_t startTick;
	uint32_t stopTick;
    float usedTime;
}Bench;

void EasyBench_systick_Init(void);
void EasyBench_Start(Bench *bench);
void EasyBench_Stop(Bench *bench);
void EasyBench_Calculate(Bench *bench);

#endif 
