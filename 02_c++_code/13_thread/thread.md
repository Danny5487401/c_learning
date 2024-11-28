<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**  *generated with [DocToc](https://github.com/thlorenz/doctoc)*

- [线程](#%E7%BA%BF%E7%A8%8B)
  - [线程的使用](#%E7%BA%BF%E7%A8%8B%E7%9A%84%E4%BD%BF%E7%94%A8)
    - [1. 创建线程](#1-%E5%88%9B%E5%BB%BA%E7%BA%BF%E7%A8%8B)
    - [2. 线程的终止](#2-%E7%BA%BF%E7%A8%8B%E7%9A%84%E7%BB%88%E6%AD%A2)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# 线程
和多进程相比，多线程是一种比较节省资源的多任务操作方式。启动一个新的进程必须分配给它独立的地址空间，每个进程都有自己的堆栈段和数据段，系统开销比较高，进行数据的传递只能通过进行间通信的方式进行。在同一个进程中，可以运行多个线程，运行于同一个进程中的多个线程，它们彼此之间使用相同的地址空间，共享全局变量和对象，启动一个线程所消耗的资源比启动一个进程所消耗的资源要少。

## 线程的使用

### 1. 创建线程
在Linux下，采用pthread_create函数来创建一个新的线程，函数声明：
```c++
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,void *(*start_routine) (void *), void *arg);
```
- 参数thread为为指向线程标识符的地址。

- 参数attr用于设置线程属性，一般为空，表示使用默认属性。

- 参数start_routine是线程运行函数的地址，填函数名就可以了。

- 参数arg是线程运行函数的参数。新创建的线程从start_routine函数的地址开始运行，该函数只有一个无类型指针参数arg。若要想向start_routine传递多个参数，可以将多个参数放在一个结构体中，然后把结构体的地址作为arg参数传入，但是要非常慎重，程序员一般不会这么做。

在编译时注意加上-lpthread参数，以调用静态链接库。因为pthread并非Linux系统的默认库。

### 2. 线程的终止
 如果进程中的任一线程调用了exit，则整个进程会终止，所以，在线程的start_routine函数中，不能采用exit。

线程的终止有三种方式：

1）线程的start_routine函数代码结束，自然消亡。

2）线程的start_routine函数调用pthread_exit结束。

3）被主进程或其它线程中止。

```c++
void pthread_exit(void *retval);
```
参数retval填空，即0