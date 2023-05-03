#include <stdio.h>
#include <string.h>   
 
class CGirl    // 定义类
{
public:
  char m_name[50];  // 姓名
  char m_sc[30];    // 身材，火辣；普通；飞机场。
 
  bool operator==(const CGirl &Girl);  // 重载==运算符
};
 
int main()
{
  CGirl Girl1,Girl2;
 
  strcpy(Girl1.m_name,"西施");
  strcpy(Girl2.m_name,"东施");
   
  if (Girl1 == Girl2) printf("Girl1和Girl2是同一个人。\n");
  else printf("Girl1和Girl2不是同一个人。\n");
}

bool CGirl::operator==(const CGirl &Girl)  // 重载==运算符
{
  // 如果两个类的姓名相同，就相等
  if (strcmp(m_name,Girl.m_name)== 0) return true;
 
  return false;
}
// 因为操作符重载函数operator==是CGirl类的一个成员函数，所以对象Girl1、Girl2都可以调用该函数。
// 其中的 if (Gril1 == Gril2) 语句，相当于对象Gril1调用函数operator==，把对象Girl2作为一个参数传递给该函数，从而实现了两个对象的比较

// Note:我们把语句改为if (Gril1 ！= Gril2) ，会如何？编译如下：编译无法通过，因为CGirl类并没有重载!=运算符。