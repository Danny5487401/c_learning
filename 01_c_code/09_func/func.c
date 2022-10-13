// 调用者程序文件
//自定义函数是一个通用的功能模块，可以在公共的头文件中声明，在公共的程序文件中定义。

#include "_public.h"  // 把_public.h头文件包含进来
 
// #include <> 用于包含系统提供的头文件，编译的时候，gcc在系统的头文件目录中寻找头文件。
// #include "" 用于包含程序员自定义的头文件，编译的时候，gcc先在当前目录中寻找头文件，如果找不到，再到系统的头文件目录中寻找。

int main()
{
  int xx,yy,imin,imax;
 
  xx=50; yy=80;
 
  imin=min(xx,yy);
  imax=max(xx,yy);
 
  printf("imin=%d,imax=%d\n",imin,imax);
}

// 编译的时候把调用者程序和公共的程序文件一起编译。
// gcc -o func fun.c _public.c
/*
我们编写的程序中，应该包含哪些头文件呢？有两种方法，一是上百度上查资料，二是使用Linux系统提供的帮助，以strcpy函数为例，在命令行下输入man strcpy回车
*/
