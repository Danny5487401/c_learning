<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**  *generated with [DocToc](https://github.com/thlorenz/doctoc)*

- [继承和派生](#%E7%BB%A7%E6%89%BF%E5%92%8C%E6%B4%BE%E7%94%9F)
  - [基类和派生类](#%E5%9F%BA%E7%B1%BB%E5%92%8C%E6%B4%BE%E7%94%9F%E7%B1%BB)
  - [基类与派生类的指针](#%E5%9F%BA%E7%B1%BB%E4%B8%8E%E6%B4%BE%E7%94%9F%E7%B1%BB%E7%9A%84%E6%8C%87%E9%92%88)
  - [多继承](#%E5%A4%9A%E7%BB%A7%E6%89%BF)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# 继承和派生

继承是面向对象程序设计中最重要的一个概念。继承允许我们根据一个类来定义另一个类，达到了代码功能重用效果。

当创建一个类时，如果待创建的类与另一个类存在某些共同特征，程序员不需要全部重新编写成员变量和成员函数，只需指定继承另一个类即可，被继承的类称为基类或父类，新建的类称为派生类或子类。

## 基类和派生类
定义一个派生类，需要指定它的基类，语法如下：

```c++
class <派生类名>:<继承方式> <基类名>
{
  // 派生类类体
};
```
继承方式是 public、protected 或 private 其中的一个，基类是之前定义过的某个类的名称。如果未指定继承方式，则默认为 private。

1）公有继承（public）：当类派生以public方式继承时，基类的公有成员也是派生类的公有成员，基类的保护成员也是派生类的保护成员，基类的私有成员不能直接被派生类访问，但是可以通过调用基类的公有和保护成员来访问。

2）保护继承（protected）： 当类派生以protected方式继承时，基类的公有和保护成员将成为派生类的保护成员。

3）私有继承（private）：当类派生以private方式继承时，基类的公有和保护成员将成为派生类的私有成员。

我们几乎不使用 protected 或 private 继承，通常使用 public 继承。

## 基类与派生类的指针
基类的指针可以指向基类对象，也可以指向派生类对象，但是不能通过基类的指针访问派生类的成员。

派生类的指针可以指向派生类对象，但不可以指向基类对象。

## 多继承
多继承即一个派生类可以有多个基类，它继承了多个基类的特性。

C++ 类可以从多个基类继承成员，语法如下：
```c++
class <派生类名>:<继承方式1><基类名1>,<继承方式2><基类名2>,…
{
  // 派生类类体
};
```
其中，继承方式是 public、protected 或 private 其中的一个，用来修饰每个基类，各个基类之间用逗号分隔。