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
  {
    printf("姓名：%s，年龄：%d，身高：%d，身材：%s，颜值：%s\n",m_name,m_age,m_height,m_sc,m_yz);
    return 0;
  }
};
/*
class <派生类名>:<继承方式> <基类名>
{
  // 派生类类体
};
继承方式是 public、protected 或 private 其中的一个，基类是之前定义过的某个类的名称。如果未指定继承方式，则默认为 private
*/
class CKCon:public CGirl   // 定义王妃类，从超女类继承
{
public:
  char m_ch[50];      // 称号
  char m_palace[50];  // 居住的宫殿
  int  m_sal;         // 奉禄
 
  int  Show()     // 显示王妃的称号、宫殿和奉禄
  {
    printf("姓名：%s，称号：%s，栖：%s，奉禄：%d两银子。\n",m_name,m_ch,m_palace,m_sal);
    return 0;
  }
};


int main()
{
  CKCon KCon;   // 实例化一个KCon对象
 
  strcpy(KCon.m_name,"杨玉环");
  KCon.m_age=28;     
  KCon.m_height=168;
  strcpy(KCon.m_sc,"火辣");
  strcpy(KCon.m_yz,"漂亮");
  strcpy(KCon.m_ch,"杨贵妃");
  strcpy(KCon.m_palace,"华清宫");
  KCon.m_sal=10000;
 
  KCon.Show();   // 如果子类中没有Show函数，就会调用父类的Show函数。
};

/*
当一个类派生自基类，该基类可以被继承为 public、protected 或 private 几种方式，当使用不同类型的继承时，遵循以下几个规则：

1）公有继承（public）：当类派生以public方式继承时，基类的公有成员也是派生类的公有成员，基类的保护成员也是派生类的保护成员，基类的私有成员不能直接被派生类访问，但是可以通过调用基类的公有和保护成员来访问。

2）保护继承（protected）： 当类派生以protected方式继承时，基类的公有和保护成员将成为派生类的保护成员。

3）私有继承（private）：当类派生以private方式继承时，基类的公有和保护成员将成为派生类的私有成员。

我们几乎不使用 protected 或 private 继承，通常使用 public 继承
基类与派生类的指针

  基类的指针可以指向基类对象，也可以指向派生类对象，但是不能通过基类的指针访问派生类的成员。

  派生类的指针可以指向派生类对象，但不可以指向基类对象。
  */