#include <stdio.h>
#include <string.h>
 
struct st_girl
{
  char name[50];     // 姓名
  int  age;          // 年龄
  int  height;       // 身高，单位：厘米cm
  char sc[30];       // 身材，火辣；普通；飞机场。
  char yz[30];       // 颜值，漂亮；一般；歪瓜裂枣。
  int  show();       // 声明结构体成员函数show，用于显示其它成员变量的值。
};
 
int main()
{
  st_girl stgirl;      // struct关键定可以不书写
  memset(&stgirl,0,sizeof(stgirl));
  strcpy(stgirl.name,"西施");
  stgirl.age=22;
  stgirl.height=168;
  strcpy(stgirl.sc,"火辣");
  strcpy(stgirl.yz,"漂亮");
 
  stgirl.show();  // 调用结构体的成员函数
}
 
int st_girl::show()   // 结构体st_girl成员函数的定义
{
  printf("name=%s,age=%d,height=%d,sc=%s,yz=%s\n",name,age,height,sc,yz);
  return 0;
}