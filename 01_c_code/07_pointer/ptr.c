#include <stdio.h>
 
int main()
{
  int    ii=10;
  char   cc='A';
  double dd=100.56;
 
  printf("变量ii的地址是：%p\n",&ii);
  printf("变量cc的地址是：%p\n",&cc);
  printf("变量dd的地址是：%p\n",&dd);
 
  return 0;
}
// 程序运行了两次，每次输出的结果不一样，原因很简单，程序每次运行的时候，向系统申请内存，系统随机分配内存，就像您去宾馆开房，如果您不提前预约指定房号，每次得到的房间编号大概率不会相同