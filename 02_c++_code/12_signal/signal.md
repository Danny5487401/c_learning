<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**  *generated with [DocToc](https://github.com/thlorenz/doctoc)*

- [signal信号](#signal%E4%BF%A1%E5%8F%B7)
  - [信号作用](#%E4%BF%A1%E5%8F%B7%E4%BD%9C%E7%94%A8)
  - [signal库函数](#signal%E5%BA%93%E5%87%BD%E6%95%B0)
    - [应用](#%E5%BA%94%E7%94%A8)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# signal信号
signal信号是进程之间相互传递消息的一种方法，信号全称为软中断信号，也有人称作软中断，从它的命名可以看出，它的实质和使用很象中断。

软中断信号（signal，又简称为信号）用来通知进程发生了事件。进程之间可以通过调用kill库函数发送软中断信号。Linux内核也可能给进程发送信号，通知进程发生了某个事件（例如内存越界）。

注意，信号只是用来通知某进程发生了什么事件，无法给进程传递任何数据，进程对信号的处理方法有三种：

1）第一种方法是，忽略某个信号，对该信号不做任何处理，就象未发生过一样。

2）第二种是设置中断的处理函数，收到信号后，由该函数来处理。

3）第三种方法是，对该信号的处理采用系统的默认操作，大部分的信号的默认操作是终止进程。

## 信号作用
服务程序运行在后台，如果想让中止它，强行杀掉不是个好办法，因为程序被杀的时候，程序突然死亡，没有释放资源，会影响系统的稳定，用Ctrl+c中止与杀程序是相同的效果。

如果能向后台程序发送一个信号，后台程序收到这个信号后，调用一个函数，在函数中编写释放资源的代码，程序就可以有计划的退出，安全而体面。

信号还可以用于网络服务程序抓包等，


## signal库函数 

signal库函数可以设置程序对信号的处理方式。

函数声明：
```c++
sighandler_t signal(int signum, sighandler_t handler);
```
参数signum表示信号的编号。

参数handler表示信号的处理方式，有三种情况：

1）SIG_IGN：忽略参数signum所指的信号。

2）一个自定义的处理信号的函数，信号的编号为这个自定义函数的参数。

3）SIG_DFL：恢复参数signum所指信号的处理方法为默认值。 

程序员不关心signal的返回值。

### 应用
在实际开发中，在main函数开始的位置，程序员会先屏蔽掉全部的信号。
```c++
 for (int ii=0;ii<100;ii++) signal(ii,SIG_IGN);
```
这么做的目的是不希望程序被干扰。然后，再设置程序员关心的信号的处理函数。

程序员关心的信号有三个：SIGINT、SIGTERM和SIGKILL。

程序在运行的进程中，如果按Ctrl+c，将向程序发出SIGINT信号，信号编号是2。

采用“kill 进程编号”或“killall 程序名”向程序发出的是SIGTERM信号，编号是15。

采用“kill -9 进程编号”向程序发出的是SIGKILL信号，编号是9，此信号不能被忽略，也无法捕获，程序将突然死亡。

所以，程序员只要设置SIGINT和SIGTERM两个信号的处理函数就可以了，这两个信号可以使用同一个处理函数，函数的代码是释放资源
