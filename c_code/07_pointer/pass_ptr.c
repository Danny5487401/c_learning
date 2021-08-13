#include <stdio.h>
 
// 声明funcld函数，p是一个指针变量
void funcld(int *p);  
 
int main()
{
  int a=10;
 
  printf("位置一：a是一个变量，变量的地址是%p，a的值是 %d\n",&a,a);
  funcld(&a);   // 调用函数，传递变量a的地址的值
  printf("位置二：a是一个变量，变量的地址是%p，a的值是 %d\n",&a,a);
}
 
void funcld(int *p)
{
  printf("位置三：p是一个指针 %p, 指向的变量的值是 %d\n",p,*p);
  *p=20;
  printf("位置四：p是一个指针 %p, 指向的变量的值是 %d\n",p,*p);
}