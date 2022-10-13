#include <stdio.h>
 
int main()
{
  double    A=18;      // 定义变量A，赋值18
  double    B=5;       // 定义变量B，赋值5
 
  printf("A的值是：%lf\n",A);
  printf("B的值是：%lf\n",B);
 
  printf("A+B的值是：%lf\n",A+B);
  printf("A-B的值是：%lf\n",A-B);
  printf("A*B的值是：%lf\n",A*B);
  printf("A/B的值是：%lf\n",A/B);
 
  //printf("A除B的余数是：%lf\n",A%B);
 
  A++;  // 自增1
  printf("A自增后的值是：%lf\n",A);
 
  B--;  // 自减1
  printf("B自减后的值是：%lf\n",B);
 
  return 0;
}