// 在C语言中，用0结束的字符数组表示字符串，有些不方便：1）数组定义后大小不能改变；2）存入的内容只能比数组小，不能大，如果不小心存多了，会引起内存的溢出，这些问题让程序员有些郁闷。

// C++的string属于STL（Standard Template Library, 标准模板库）中的定义的类，它会随存放字符的长度自动伸缩，程序员不必担心内存溢出的问题，string类还和C语言的字符串之间还可以很方便的转换


#include <stdio.h>
#include <string.h>
// 注意这里不是string.h，string.md.h是C语言字符串头文件
#include <string>
 // 方式一：string是一个模板类，位于std命名空间内，为方便使用还需要在程序中增加：
using namespace std;


// 方式二：如果不指定命名空间，也就是说没有using namespace std，创建string对象的方法如下
// std::string.md str;

int main ()
{
  char str1[31];   // C语言风格的字符串。
  memset(str1,0,sizeof(str1)); // memset函数对数组进行初始化
  strcpy(str1,"西施");
 
  string str2;     // C++的string字符串
 
  str2="沉鱼";     // 对str2赋值
  printf("str2=%s\n",str2.c_str());
 
  // 判断str2和str1是否相等
  if (str2!=str1) printf("str2=%s,str1=%s，不相等。\n",str2.c_str(),str1);
 
  strcpy(str1,str2.c_str());   // 把string的内容赋值给C语言风格的字符串。
  printf("str1=%s\n",str1);
}