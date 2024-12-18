<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**  *generated with [DocToc](https://github.com/thlorenz/doctoc)*

- [指针](#%E6%8C%87%E9%92%88)
  - [变量的地址](#%E5%8F%98%E9%87%8F%E7%9A%84%E5%9C%B0%E5%9D%80)
  - [指针](#%E6%8C%87%E9%92%88-1)
  - [对指针赋值](#%E5%AF%B9%E6%8C%87%E9%92%88%E8%B5%8B%E5%80%BC)
  - [空指针](#%E7%A9%BA%E6%8C%87%E9%92%88)
  - [数组的地址](#%E6%95%B0%E7%BB%84%E7%9A%84%E5%9C%B0%E5%9D%80)
  - [指针占用内存情况](#%E6%8C%87%E9%92%88%E5%8D%A0%E7%94%A8%E5%86%85%E5%AD%98%E6%83%85%E5%86%B5)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# 指针

## 变量的地址

内存变量简称变量，在C语言中，每定义一个变量，系统就会给变量分配一块内存，而内存是有地址的。如果把计算机的内存区域比喻成一个大宾馆，每块内存的地址就像宾馆房间的编号。

## 指针

指针是一种特别变量，全称是指针变量，专用于存放其它变量在内存中的地址编号，指针在使用之前要先声明，语法是：
```c
datatype *varname;
```

datatype 是指针的基类型，它必须是一个有效的C数据类型（int、char、double或其它自定义的数据类型），
varname 是指针的名称。用来声明指针的星号 * 与乘法中使用的星号是相同的。
但是，在这个场景中，星号是用来表示这个变量是指针。以下是有效的指针声明：
```c
int  *ip;  // 一个整型的指针
char  *cp;  // 一个字符型的指针
double  *dp;  // 一个 double 型的指针
```

## 对指针赋值

不管是整型、浮点型、字符型，还是其他的数据类型的内存变量，它的地址都是一个十六进制数，可以理解为内存单元的编号。

我们用整数型指针存放整数型变量的地址；
用字符型指针存放字符型变量的地址；
用双精度型指针存放双精度型变量的地址;
用自定义数据类型指针存放自定义数据类型变量的地址。

## 空指针
空指针就是说指针没有指向任何内存变量，指针的值是空，所以不能操作内存，否则可能会引起程序的崩溃。

```c
#include <stdio.h>
 
int main()
{
  int *pi=0;  // 定义一个指针
 
  printf("pi的值是 %p\n",pi);
 
  *pi=10;  // 试图对空指针进行赋值操作，必将引起程序的崩溃
 
  return 0;
}
```
```shell script
➜  07_pointer git:(feature/c) ✗ gcc -o test test.c  
➜  07_pointer git:(feature/c) ✗ ./test 
pi的值是 0x0
[1]    50106 segmentation fault  ./test
```
## 数组的地址
在C语言中，数组占用的内存空间是连续的，数组名是数组元素的首地址，也是数组的地址。

在应用开发中，地址的运算很重要，主要用于字符串操作，

## 指针占用内存情况
指针也是一种内存变量，是内存变量就要占用内存空间，在C语言中，任何类型的指针占用8字节的内存（32位操作系统4字节）。
```c
  printf("sizeof(int *) is %d.\n",sizeof(int *));        // 输出：sizeof(int *) is 8
  printf("sizeof(char *) is %d.\n",sizeof(char *));      // 输出：sizeof(char *) is 8
  printf("sizeof(double *) is %d.\n",sizeof(double *));  // 输出：sizeof(double *) is 8
``` 
输出的结果都是8。

