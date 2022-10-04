#include "includes.h"
#define TASK_STK_SIZE 512 //任务堆栈长度
char *s1 = "18001030108";
char *s2 = "liuxiaopeng";

OS_STK StartTaskStk[TASK_STK_SIZE]; //定义任务堆栈区
OS_STK MyTaskStk[TASK_STK_SIZE];    //定义任务堆栈区
OS_STK YouTaskStk[TASK_STK_SIZE];   //定义任务堆栈区
INT16S key;                         //用于退出的键

INT8U err;
INT8U y = 0; //字符显示位置

void Fun(INT8U x, INT8U y);
void StartTask(void *data); //声明起始任务
void MyTask(void *data);    //声明任务
void YouTask(void *data);   //声明任务

//定义一个信号量 0
OS_EVENT *Fun_Semp;
INT8U time = 0;
/************************主函数*********************************/
void main(void)
{
    OSInit();                  //初始化μC/OS-II_II
    PC_DOSSaveReturn();        //保存Dos环境
    PC_VectSet(uCOS, OSCtxSw); //安装μC/OS-II_II中断

    OSTaskCreate(StartTask,                        //创建任务StartTask
                 (void *)0,                        //给任务传递参数
                 &StartTaskStk[TASK_STK_SIZE - 1], //设置任务堆栈栈顶
                 0);                               //使任务的优先级别为0
    Fun_Semp = OSSemCreate(0);                     // 定义信号量
    OSStart();                                     //启动多任务管理
}
/***********************任务StartTask*******************************/
void StartTask(void *pdata)
{
#if OS_CRITICAL_METHOD == 3
    OS_CPU_SR cpu_sr;
#endif
    pdata = pdata;
    OS_ENTER_CRITICAL();
    PC_VectSet(0x08, OSTickISR);      //安装时钟中断向量
    PC_SetTickRate(OS_TICKS_PER_SEC); //设置μC/OS-II_II时钟频率
    OS_EXIT_CRITICAL();

    OSStatInit();                                //初始化统计任务
    OSTaskCreate(MyTask,                         //创建任务MyTask
                 (void *)0,                      //给任务传递参数
                 &MyTaskStk[TASK_STK_SIZE - 1],  //设置任务堆栈栈顶
                 1);                             //使任务的优先级别为1
    OSTaskCreate(YouTask,                        //创建任务YouTask
                 (void *)0,                      //给任务传递参数
                 &YouTaskStk[TASK_STK_SIZE - 1], //设置任务堆栈栈顶
                 2);                             //使任务的优先级别为2

    for (;;)
    {
        //如果按下Esc键则退出μC/OS-II_II
        if (PC_GetKey(&key) == TRUE)
        {
            if (key == 0x1B)
            {
                PC_DOSReturn();
            }
        }
        OSTimeDlyHMSM(0, 0, 3, 0); //等待3秒
    }
}
/************************任务MyTask*******************************/
void MyTask(void *pdata)
{
#if OS_CRITICAL_METHOD == 3
    OS_CPU_SR cpu_sr;
#endif
    pdata = pdata;
    for (;;)
    {

        if (time >= 6)                    //是否过了6S？
        {
            OSSemPend(Fun_Semp, 0, &err); //判断YOUTASK是否同意？(请求信号量)

            PC_DispStr(0, ++y,
                       s1,
                       DISP_BGND_BLACK + DISP_FGND_RED);

            Fun(13, y); //调用函数fun
            break;
        }
        

        OSTimeDlyHMSM(0, 0, 1, 0); //等待1秒
        time++;
    }
}
/************************任务YouTask******************************/
void YouTask(void *pdata)
{
#if OS_CRITICAL_METHOD == 3
    OS_CPU_SR cpu_sr;
#endif
    pdata = pdata;
    //执行发送信号量
    OSSemPost(Fun_Semp);
    for (;;)
    {
        PC_DispStr(0, ++y,
                   s2,
                   DISP_BGND_BLACK + DISP_FGND_WHITE);

        OSTimeDlyHMSM(0, 0, 1, 0); //等待1秒
    }
}
void Fun(INT8U x, INT8U y)
{
    PC_DispStr(x, y, "invoked Fun()!",
               DISP_BGND_BLACK + DISP_FGND_BLUE);
}

