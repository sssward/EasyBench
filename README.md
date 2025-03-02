# EasyBench
一个简单精准的用于测量任意程序段耗时的库
## 简介 
基于SysTick,使用方便且精准,通用性高,无需硬件支持。
对比keil中DEBUG记录的时间,误差在20ns内
## 使用方法
1.在easyBanch.h中设置当前系统时钟频率
```c
#define HCLK 170000000
```
2.注册测量单元
```c
Bench tim1;
```
3.测量
```c
EasyBench_Start(&tim1);
//填充需要测量耗时的程序段
EasyBench_Stop(&tim1);
EasyBench_Calculate(&tim1);
```
4.查看测量单元计算的时间
```c
tim1.usedTime
```