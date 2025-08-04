<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**  *generated with [DocToc](https://github.com/thlorenz/doctoc)*

- [C_learning 学习C语言](#c_learning-%E5%AD%A6%E4%B9%A0c%E8%AF%AD%E8%A8%80)
  - [经典语句](#%E7%BB%8F%E5%85%B8%E8%AF%AD%E5%8F%A5)
  - [第一章 c 语言学习](#%E7%AC%AC%E4%B8%80%E7%AB%A0-c-%E8%AF%AD%E8%A8%80%E5%AD%A6%E4%B9%A0)
  - [第二章 c++语言学习](#%E7%AC%AC%E4%BA%8C%E7%AB%A0-c%E8%AF%AD%E8%A8%80%E5%AD%A6%E4%B9%A0)
  - [编译器](#%E7%BC%96%E8%AF%91%E5%99%A8)
  - [cmake](#cmake)
  - [参考](#%E5%8F%82%E8%80%83)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# C_learning 学习C语言

![](.assets/img/.README_images/c_language.png)

注意 ⚠️：**_中文注释乱码时，设置 vscode:files.autoGuessEncoding 项的值改为 true 即可，数据结构中推荐编码格式为 GBK_**


## 经典语句

1. 在中国，没有纯C程序员，如果他不会C++，不是他对C有多么执着，可能是不会C++。嵌入式开发可能是个例外，可能还有其它只能用C不能用C++的场景。
2. 我对前辈们的智慧怀敬畏之心，智慧的光芒流传千古，不学习是我们的损失。如果你以后成为了大佬，希望不要骄傲，只是因为站在巨人的肩膀上

## 第一章 c 语言学习

- [1 基本结构编译过程](01_c_code/01_basic_structure/make_process.md)
- [2 定义变量并初始化](01_c_code/02_distribute_value/book2.c)
- [3 运算符](01_c_code/03_opration_symbol/book3.c)
- [4 main 函数的参数](01_c_code/04_main_args/book4.c)
- [5 结构体](01_c_code/05_struct/struct.md)
- [6 字符串及常用函数](01_c_code/06_string/string.md)
- [7 指针](01_c_code/07_pointer/ptr.md)
    - [7.1 变量的地址](01_c_code/07_pointer/ptr.c)
    - [7.2 对指针赋值](01_c_code/07_pointer/ptr_value.c)
    - [7.3 函数的指针参数传递](01_c_code/07_pointer/pass_ptr.c)
    - [7.4 数组的地址及运算](01_c_code/07_pointer/array_ptr.c)
- [8 类型转换](01_c_code/08_int/transfer.c)
- [9 函数声明与定义](01_c_code/09_func/func.md)
- [10 头文件](01_c_code/10_head_files/head.md)
- [11 排序 sort](01_c_code/11_sort/sort.c)
- [12 库的生成](01_c_code/12_lib/lib.md)
    - [12.1 静态库.a](01_c_code/12_lib/01_static_lib/main.c)
    - [12.2 动态库.so](01_c_code/12_lib/02_dynamic_lib/main.c)
- 16 stdio.h 输入输出

## [第二章 c++语言学习](02_c++_code/c++.md)
note: 推荐指定C++版本编译 -std=c++11
- [1 Function Overloading函数重载](02_02_c++_code/01_func/func_reload.md)
- [2 类和对象](02_c++_code/02_class_n_object/class.md)
    - [2.1 C++结构体相对C新特性](02_c++_code/02_class_n_object/method.cpp)
    - [2.2 C++ 类和对象](02_c++_code/02_class_n_object/class.cpp)
    - [2.3 文件操作封装成一个类](02_c++_code/02_class_n_object/class_member.cpp)
- [3 &符号特性(引用)](02_c++_code/03_ref/ref.md)
    - [3.1 引用用于函数的参数](02_c++_code/03_ref/ref.cpp)
    - [3.2 引用用于函数的返回值](02_c++_code/03_ref/ref_return.cpp)
- [4 运算符重载](02_c++_code/04_operation_reload/operator.md)
- [5 STL（Standard Template Library, 标准模板库）- string 类](02_c++_code/05_strings/string.md)
- [6 STL（Standard Template Library, 标准模板库）- vector 容器](02_c++_code/06_vector/vecor.md)
- [7 类的继承](02_c++_code/07_inherit/inherit.md)
- [8 类的多态](02_c++_code/08_polymorphism/polymorphism.md)
    - [8.1 静态多态](02_c++_code/08_polymorphism/static_poly.cpp)
    - [8.2 动态多态](02_c++_code/08_polymorphism/dynamic_poly.cpp)
- [9 套接字 socket](02_c++_code/09_socket/socket.md)
- 10 信号量
- [11 静态库和动态库](02_c++_code/11_lib/lib.md)
- [12 signal信号](02_c++_code/12_signal/signal.md)
- [13 线程](02_c++_code/13_thread/thread.md)

## 编译器
- 1 [LLVM 及子项目Clang-->为了替代 GCC](Clang.md)
- 2 [GCC (GNU Compiler Collection)](gcc.md)
- 3 MSVC (Microsoft Visual C++)：微软开发的编译器，通常与Visual Studio集成

## [cmake](cmake.md)


## 参考
- [c 语言技术网](https://www.infoq.cn/profile/ABEEA6B21FEBE9/publish)