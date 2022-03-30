//
// Created by python on 2022/3/30.
//
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void EXIT(int sig)
{
    printf("收到了信号%d，程序退出。\n",sig);

    // 在这里添加释放资源的代码

    exit(0);   // 程序退出。
}

int main()
{
    for (int ii=0;ii<100;ii++) signal(ii,SIG_IGN); // 屏蔽全部的信号

    signal(SIGINT,EXIT);  signal(SIGTERM,EXIT); // 设置SIGINT和SIGTERM的处理函数

    while (1)  // 一个死循环
    {
        sleep(10);
    }
}
/*
➜  12_signal git:(feature/c++) ✗ ./signal &
[1] 99261
➜  12_signal git:(feature/c++) ✗ killall signal
收到了信号15，程序退出。
[1]  + 99261 done       ./signal
➜  12_signal git:(feature/c++) ✗ ./signal
^C收到了信号2，程序退出。

 */

