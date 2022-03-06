# C_learning 学习C语言
![](.README_images/c_language.png)

经典语句：在中国，没有纯C程序员，如果他不会C++，不是他对C有多么执着，可能是不会C++。嵌入式开发可能是个例外，可能还有其它只能用C不能用C++的场景。


参考 c 语言技术网 https://www.freecplus.net/dad5c75aa6214160a1937cc09ed33135.html

## 第一章 c 语言学习

- [1 基本结构编译过程](c_code/01_basic_structure/make_process.md)
- [2 定义变量并初始化](c_code/02_distribute_value/book2.c)
- [3 运算符](c_code/03_opration_symbol/book3.c)
- [4 main 函数的参数](c_code/04_main_args/book4.c)
- [5 结构体](c_code/05_struct/struct.c)
- [6 字符串及常用函数](c_code/06_string/string.md)
- 7 指针
- [8 类型转换](c_code/08_int/transfer.c)
- [9 函数声明与定义](c_code/09_func/func.md)
- [10 头文件](c_code/10_head_files/head.md)
- [11 排序 sort](c_code/11_sort/sort.c)

## 第二章 c++语言学习
- 1 函数重载
- 2 类和对象
- 3 引用
- 4 运算符重载
- 5 STL（Standard Template Library, 标准模板库）- string 类
- 6 STL（Standard Template Library, 标准模板库）- vector 容器
- 7 类的继承
- 8 类的多态
- 9 套接字 socket
- 10 信号量
- 11 静态库和动态库

## 第三章 数据结构与算法

- [1 linear list线性表](dataStructure/01_linear_list/linear_list.md)
  - [1.1 顺序表 静态实现，数据元素是整数](dataStructure/01_linear_list/seqlist1.c)
  - [1.2 顺序表 静态实现，数据元素是结构体](dataStructure/01_linear_list/seqlist2.c)
  - [1.3 顺序表 动态实现，数据元素是整数](dataStructure/01_linear_list/seqlist3.c)
  - [1.4 顺序表 动态实现，数据元素是结构体](dataStructure/01_linear_list/seqlist4.c)
- [2 link list链表](dataStructure/02_link_list/link_list.md)  
  - [2.1 带头结点的单链表的实现，数据元素是整数](dataStructure/02_link_list/linklist1.c)
  - [2.2 带头结点的单链表的实现，数据元素是结构体](dataStructure/02_link_list/linklist2.c)


- [3 B 树](dataStructure/03_btree/btree.md)
  - [3.1 二叉树的层次遍历](dataStructure/03_btree/btree1.c)
  - [3.2 二叉树的前序遍历、中序遍历和后序遍历，包括递归和非递归两种方法](dataStructure/03_btree/btree2.c)
  
- [4 图](dataStructure/04_graph/graph.md)
  - 4.1 BFS (Breadth First Search 广度优先遍历）
  - 4.2 DFS (Depth First Search 深度优先搜索)
  - 4.3 单源最短路径算法(Floyd(弗洛伊德)算法)
  - 4.4 拓扑排序
  - 4.5 关键路径
- 5 hash哈希表
  
- 6 queue队列
  
- 7 stack栈
  
- 8 排序算法
  - 8.1 冒泡排序
  - 8.2 桶排序
  - 8.3 计数排序
  - 8.4 堆排序
  - 8.5 插入排序
  - 8.6 归并排序
    - 递归的方法实现
    - 循环的方法实现
  - 8.7 快速排序
  - 8.8 基数排序
  - 8.9 选择排序
  - 8.10 希尔排序
- [Clang 及 LLVM 介绍](Clang.md)

注意 ⚠️：**_中文注释乱码设置 vscode:files.autoGuessEncoding 项的值改为 true 即可，数据结构中推荐编码格式为 GBK_**
