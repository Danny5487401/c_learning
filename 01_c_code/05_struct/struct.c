#include <stdio.h>
// 增加以下代码可以使结构体成员变量之间的内存没有空隙。
// #pragma pack(1)
 
struct st_girl
{
  char name[50];     // 姓名
  int  age;          // 年龄
  int  height;       // 身高，单位：厘米cm
  char sc[30];       // 身材，火辣；普通；飞机场。
  char yz[30];       // 颜值，漂亮；一般；歪瓜裂枣。
};
 
int main()
{
  struct st_girl queen;
  // %hu、%u、%lu 以十进制、无符号的形式输出 short、int、long 类型的整数
  printf("sizeof(struct st_girl) %lu\n",sizeof(struct st_girl));
  printf("sizeof(queen) %lu\n",sizeof(queen));
}
// struct st_girl全部成员变量占用的内存是50+4+4+30+30=118，但是结构体占用的内存是120。