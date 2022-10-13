#include <stdio.h>
#include <string.h>

 
int main()
{
  char name[51];
  strcpy(name,"C语言技术网(www.freecplus.net)");
 
  printf("%p\n",name);
  printf("%p\n",&name);
  printf("%p\n",&name[0]);
 
  printf("%s\n",name); //  数组名
  printf("%s\n",&name); // 对数组取地址
  printf("%s\n",&name[0]); // 数组元素的首地址
  // 数组名、对数组取地址和数组元素的首地址是同一回事,在应用开发中，程序员一般用数组名，书写最简单。

  char   cc[4];   // 字符数组
  int    ii[4];   // 整数数组
  double dd[4];   // 浮点数组


  // 用地址相加的方式显示数组全部元素的的址
  printf("%p %p %p %p\n",cc,cc+1,cc+2,cc+3);
  printf("%p %p %p %p\n",ii,ii+1,ii+2,ii+3);
  printf("%p %p %p %p\n",dd,dd+1,dd+2,dd+3);

  //cc是char型，一个存储单元是1个字节，数组ii是int型，一个存储单元是4个字节，数组ll是long型，一个存储单元是8个字节，
}

/*
第一行输出的每个地址的增量是1，第二行的每个地址的增量是4，第三行的每个地址的增量是8，为什么会这样？
 因为数组cc是char型，一个存储单元是1个字节，数组ii是int型，一个存储单元是4个字节，数组ll是long型，一个存储单元是8个字节，地址加1指的是下一个存储单元，不是数学意义中的1。
 */