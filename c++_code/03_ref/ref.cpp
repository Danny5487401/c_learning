// 对于习惯使用C进行开发的程序员来说，&符号是取地址符，但是在C++中，它除了取地址，还有其它的用途，叫做引用（reference），引用是C++的新特性
//  int ii;
//   int &rii=ii;  // 定义引用rii，它是变量ii的引用，即别名。
//   rii=1;  等价于  ii=1;

#include <stdio.h>
 
void func(int *a) // a是一个指针变量
{ *a=20; }
 
void func(int &ra) // ra是一个引用
{ ra=30; }
 
int main ()
{
  int ii=0;
 
  func(&ii);  // 传递变量的地址
  printf("1 ii=%d\n",ii);
 
  func(ii);   // 引用
  printf("2 ii=%d\n",ii);
}