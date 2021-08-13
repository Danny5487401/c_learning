#include <stdio.h>
 
int main()
{
  int    ii=10;
  char   cc='A';
  double dd=100.56;
 
  int    *pii=0;  // 定义整数型指针并初始化
  char   *pcc=0;  // 定义字符型指针并初始化
  double *pdd=0;  // 定义双精度型指针并初始化
 
  pii=&ii;  // 数型指针并指向变量ii
  pcc=&cc;  // 字符型指针并指向变量cc
  pdd=&dd;  // 双精度型指针并指向变量dd
 
  // 输出指针变量的值
  printf("pii的值是：%p\n",pii);
  printf("pcc的值是：%p\n",pcc);
  printf("pdd的值是：%p\n",pdd);

 
  // 通过指针操作内存变量，改变内存变量的值
  *pii=20;    // 同ii=20;
 
  printf("pii的值是：%p\n",pii);
  printf("*pii的值是：%d\n",*pii);
  printf("ii的值是：%d\n",ii);
}