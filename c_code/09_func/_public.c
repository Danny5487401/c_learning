// 公共的程序文件

#include "_public.h"  // 包含自定义函数声明的头文件
 
// 用于比较两个整数的大小，函数返回较小者
int min(const int ii1,const int ii2)   // min函数定义
{
  if (ii1<ii2) return ii1;
 
  return ii2;
}
 
// 用于比较两个整数的大小，函数返回较大者
int max(const int ii1,const int ii2)   // max函数定义
{
  if (ii1>ii2) return ii1;
 
  return ii2;
}