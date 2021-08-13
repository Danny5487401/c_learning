#include <stdio.h>
#include <stdlib.h>   // 如果不包含这个头文件，会出现意外的结果。
#include <time.h>  //  <time.h> 头文件中的 time 函数即可得到一个精确到秒的时间作为种子
 
int main()
{
  int  ii;
  long ll;
 
  ii=atoi("-2147483647"); // 把字符串nptr转换为int整数
  ll=atol("-9223372036854775807"); //  把字符串nptr转换为long整数
  printf("ii=%d\n",ii);  // 求int整数的绝对值
  printf("ll=%ld\n",ll); // 求long整数的绝对值
 
  ii=abs(ii);
  ll=labs(ll);
  printf("ii=%d\n",ii);
  printf("ll=%ld\n",ll);

  int jj;
  //  随机数生成器的初始化函数
  srand(time(0));  // 播下随机种子
 
  for (jj=0;jj<5;jj++)  // 生成5个随机数
  {
    printf("%d ", rand() % 51 + 100);  // 产生100~150的随机数
  }
 
  printf("\n");
}

/*
别名typedef unsigned int size_t;
size_t ii; 等同于 unsigned int ii;
*/