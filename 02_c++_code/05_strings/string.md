<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**  *generated with [DocToc](https://github.com/thlorenz/doctoc)*

- [标准模板库中string](#%E6%A0%87%E5%87%86%E6%A8%A1%E6%9D%BF%E5%BA%93%E4%B8%ADstring)
  - [使用](#%E4%BD%BF%E7%94%A8)
    - [1. string的声明](#1-string%E7%9A%84%E5%A3%B0%E6%98%8E)
    - [2. string的重载的操作符](#2-string%E7%9A%84%E9%87%8D%E8%BD%BD%E7%9A%84%E6%93%8D%E4%BD%9C%E7%AC%A6)
    - [3. 最重要的一个成员函数](#3-%E6%9C%80%E9%87%8D%E8%A6%81%E7%9A%84%E4%B8%80%E4%B8%AA%E6%88%90%E5%91%98%E5%87%BD%E6%95%B0)
    - [应用经验](#%E5%BA%94%E7%94%A8%E7%BB%8F%E9%AA%8C)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# 标准模板库中string

在C语言中，用0结束的字符数组表示字符串，有些不方便：1）数组定义后大小不能改变；2）存入的内容只能比数组小，不能大，如果不小心存多了，会引起内存的溢出，这些问题让程序员有些郁闷。

C++的string属于STL（Standard Template Library, 标准模板库）中的定义的类，它会随存放字符的长度自动伸缩，程序员不必担心内存溢出的问题，string类还和C语言的字符串之间还可以很方便的转换。

## 使用

### 1. string的声明

首先，为了在程序中使用string类，必须包含头文件 <string>。如下：
```c++
#include <string>
```
注意这里不是string.h，string.h是C语言字符串头文件。
string是一个模板类，位于std命名空间内，为方便使用还需要在程序中增加：

```c++
using namespace std;  // 指定缺省的使名空间。
string str;       // 创建string对象。
```
如果不指定命名空间，也就是说没有using namespace std，创建string对象的方法如下：
```c++
std::string str;
```

### 2. string的重载的操作符
可以用=直接赋值。

可以用 ==、>、<、>=、<=、和!=比较字符串。

可以用+或者+=操作符连接两个字符串。

可以用[]获取指定位置的字符，类似数组。

### 3. 最重要的一个成员函数
```c++
  const char *c_str();
```
string类采用动态分配内存的方式来存放字符串，c_str函数返回这个字符串的地址。

可用下列函数来获得string的一些特性。
```c++
  int size();             // 返回当前字符串的大小。
  int length();           // 返回当前字符串的长度，注意和size的区别。
  void clear();           // 清空字符串。
```

### 应用经验
C++的string类是一个变长的字符串，不需要程序员担心内存溢出的问题，还提供了很多字符串操作函数，初学者可能会想，用它取代C语言中的字符串（以0结尾的字符数组）一定是个很好的主意。我要告诉各位，这是不可能的，因为string中的字符串存储的内存空间没有固定的位置（它也没办法有固定位置）。

对初学者来说，用C/C++写一些简单的程序，做一些简单的事情，不懂得实际项目开发的需求，例如Oracle和MySQL数据库提供的接口，在交换数据的时候需要绑定一个固定的地址，string是做不到的。

我的建议是采用string存放一些需要动态分配内存的临时数据，避开动态内存技术带来的坑，然后转换为C的字符串。C的字符串没有string类那么丰富的成员函数，这个不是问题，我们可以自己写，这也是我不想介绍string成员函数的原因，与其花时间去研究string的成员函数，还不如自己写一个