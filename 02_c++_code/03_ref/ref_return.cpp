
// 引用用于函数的返回值，
#include <stdio.h>
 
int value;  // 定义一个全局变量。
 
int fun1(int ii); // 函数的返回值是int
int &fun2(int ii); // 函数的返回值是int引用
 
int main()
{
  int aa=fun1(10);
  printf("aa=%d\n",aa);
 
  // int &bb=fun1(10);
  // printf("bb=%d\n",bb);
 
  int cc=fun2(20);
  printf("cc=%d\n",cc);
 
  int &dd=fun2(20);
  printf("dd=%d\n",dd);
}
 
int fun1(int ii) // 函数的返回值是int
{
  value=10+ii;
  return value;
}
 
// 函数的返回值是int引用
int &fun2(int ii)
{
  value=20+ii;
  return value;
}