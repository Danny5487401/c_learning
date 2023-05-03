// 静态多态
// 函数重载就是一个简单的静态多态，静态多态是编译器在编译期间完成的，编译器会根据实参类型来选择调用合适的函数，如果有合适的函数可以调用就调，没有的话就会发出警告或者报错。
#include <stdio.h>
#include <string.h>
 
class CGirl    // 定义超女类
{
public:
  char m_name[50];  // 姓名
  int  m_age;       // 年龄
  int  m_height;    // 身高，单位：厘米cm
  char m_sc[30];    // 身材，火辣；普通；飞机场。
  char m_yz[30];    // 颜值，漂亮；一般；歪瓜裂枣。
 
  int  Show()       // 显示超女基本信息的成员函数体
  { printf("姓名：%s，年龄：%d，身高：%d，身材：%s，颜值：%s\n",m_name,m_age,m_height,m_sc,m_yz); 
  return 0;
  }
};
 
class CKCon:public CGirl   // 定义王妃类，从超女类继承
{
public:
  char m_ch[50];      // 称号
  char m_palace[50];  // 居住的宫殿
  int  m_sal;         // 奉禄
 
  int  Show()     // 显示王妃的称号、宫殿和奉禄
  { printf("姓名：%s，称号：%s，栖：%s，奉禄：%d两银子。\n",m_name,m_ch,m_palace,m_sal); 
  return 0;
  }
};



int main()
{
  CKCon KCon;
 
  strcpy(KCon.m_name,"杨玉环");   KCon.m_age=28;            KCon.m_height=168;
  strcpy(KCon.m_sc,"火辣");       strcpy(KCon.m_yz,"漂亮"); strcpy(KCon.m_ch,"杨贵妃");
  strcpy(KCon.m_palace,"华清宫"); KCon.m_sal=10000;
 
  CGirl *pGirl;   // 基类的指针
  CKCon *pCon;   // 派生类的指针
 
  pGirl=pCon=&KCon;  // 都指向派生类
 
  pGirl->Show();   // 将调用的是基类的Show方法
  pCon->Show();    // 将调用的是派生类的Show方法
}