<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**  *generated with [DocToc](https://github.com/thlorenz/doctoc)*

- [多态](#%E5%A4%9A%E6%80%81)
  - [静态多态](#%E9%9D%99%E6%80%81%E5%A4%9A%E6%80%81)
  - [动态多态](#%E5%8A%A8%E6%80%81%E5%A4%9A%E6%80%81)
  - [虚函数](#%E8%99%9A%E5%87%BD%E6%95%B0)
  - [纯虚函数](#%E7%BA%AF%E8%99%9A%E5%87%BD%E6%95%B0)
  - [C++ 接口（抽象类）](#c-%E6%8E%A5%E5%8F%A3%E6%8A%BD%E8%B1%A1%E7%B1%BB)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# 多态
多态按字面的意思就是多种形态。当类之间存在继承关系时，就可能会用到多态，调用成员函数时，会根据对象的类型来执行不同的函数。

## 静态多态
函数重载就是一个简单的静态多态，静态多态是编译器在编译期间完成的，编译器会根据实参类型来选择调用合适的函数，如果有合适的函数可以调用就调，没有的话就会发出警告或者报错。

## 动态多态
动态多态是在程序运行时根据基类的引用（指针）指向的对象来确定自己具体该调用哪一个类的虚函数。

让我们对程序稍作修改，在 CGirl类中，Show方法的声明前放置关键字 virtual，如下所示：

```c++
  virtual int  Show()       // 显示超女基本信息的成员函数体
```

## 虚函数
虚函数是在基类中使用关键字 virtual 声明的函数，在派生类中重新定义虚函数。

我们想要的是在程序中可以根据所调用的对象类型来选择调用的函数，这种操作被称为动态链接，或后期绑定。

## 纯虚函数
我们可以在基类中只声明虚函数，没有函数的定义，在派生类中去实现函数的定义，这个时候就会用到纯虚函数。
```c++
class CGirl    // 定义超女类
{
public:
  char m_name[50];  // 姓名
  int  m_age;       // 年龄
  int  m_height;    // 身高，单位：厘米cm
  char m_sc[30];    // 身材，火辣；普通；飞机场。
  char m_yz[30];    // 颜值，漂亮；一般；歪瓜裂枣。
 
  virtual int Show()=0; // 申明一个纯虚函数。
};
```

virtual int Show()=0;;告诉编译器，函数只有声明，没有定义，是纯虚函数。


##  C++ 接口（抽象类）
接口描述了类的行为和功能，是标准和规范，而不需要完成类的功能实现。

C++ 接口是用抽象类来实现的，如果类中至少有一个函数被声明为纯虚函数，则这个类就是抽象类。

设计抽象类的目的，是为了给其他类提供一个可以继承的基类。抽象类不能用于实例化对象，它只能作为接口使用。如果试图实例化一个抽象类的对象，会导致编译错误。

如果一个基类的派生类需要实例化，则必须实现每个虚函数的定义，如果没有在派生类中纯虚函数的定义会导致编译错误。

可用于实例化对象的类被称为具体类