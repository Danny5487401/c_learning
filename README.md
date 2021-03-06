# C_learning 学习C语言
![](.README_images/c_language.png)

参考 **c 语言技术网** https://www.freecplus.net/dad5c75aa6214160a1937cc09ed33135.html

## 经典语句
1. 在中国，没有纯C程序员，如果他不会C++，不是他对C有多么执着，可能是不会C++。嵌入式开发可能是个例外，可能还有其它只能用C不能用C++的场景。
2. 我对前辈们的智慧怀敬畏之心，智慧的光芒流传千古，不学习是我们的损失。如果你以后成为了大佬，希望不要骄傲，只是因为站在巨人的肩膀上


## 第一章 c 语言学习
- [1 基本结构编译过程](c_code/01_basic_structure/make_process.md)
- [2 定义变量并初始化](c_code/02_distribute_value/book2.c)
- [3 运算符](c_code/03_opration_symbol/book3.c)
- [4 main 函数的参数](c_code/04_main_args/book4.c)
- [5 结构体](c_code/05_struct/struct.md)
- [6 字符串及常用函数](c_code/06_string/string.md)
- [7 指针](c_code/07_pointer/ptr.md)
    - [7.1 变量的地址](c_code/07_pointer/ptr.c)
    - [7.2 对指针赋值](c_code/07_pointer/ptr_value.c)
    - [7.3 函数的指针参数传递](c_code/07_pointer/pass_ptr.c)
    - [7.4 数组的地址及运算](c_code/07_pointer/array_ptr.c)
- [8 类型转换](c_code/08_int/transfer.c)
- [9 函数声明与定义](c_code/09_func/func.md)
- [10 头文件](c_code/10_head_files/head.md)
- [11 排序 sort](c_code/11_sort/sort.c)
- [12 库的生成](c_code/12_lib/lib.md)
    - [12.1 静态库.a](c_code/12_lib/01_static_lib/main.c)
    - [12.2 动态库.so](c_code/12_lib/02_dynamic_lib/main.c)

## [第二章 c++语言学习](c++_code/c++.md)
- [1 Function Overloading函数重载](c++_code/01_func/func_reload.md)
- [2 类和对象](c++_code/02_class_n_object/class.md)
    - [2.1 C++结构体相对C新特性](c++_code/02_class_n_object/method.cpp)
    - [2.2 C++ 类和对象](c++_code/02_class_n_object/class.cpp)
    - [2.3 文件操作封装成一个类](c++_code/02_class_n_object/class_member.cpp)
- [3 &符号特性(引用)](c++_code/03_ref/ref.md)
    - [3.1 引用用于函数的参数](c++_code/03_ref/ref.cpp)
    - [3.2 引用用于函数的返回值](c++_code/03_ref/ref_return.cpp)
- [4 运算符重载](c++_code/04_operation_reload/operator.md)
- [5 STL（Standard Template Library, 标准模板库）- string 类](c++_code/05_strings/string.md)
- [6 STL（Standard Template Library, 标准模板库）- vector 容器](c++_code/06_vector/vecor.md)
- [7 类的继承](c++_code/07_inherit/inherit.md)
- [8 类的多态](c++_code/08_polymorphism/polymorphism.md)
    - [8.1 静态多态](c++_code/08_polymorphism/static_poly.cpp)
    - [8.2 动态多态](c++_code/08_polymorphism/dynamic_poly.cpp)
- [9 套接字 socket](c++_code/09_socket/socket.md)
- 10 信号量
- [11 静态库和动态库](c++_code/11_lib/lib.md)
- [12 signal信号](c++_code/12_signal/signal.md)
- [13 线程](c++_code/13_thread/thread.md)


## 第三章 数据结构
- [1 linear list线性表](dataStructure/01_linear_list/linear_list.md)
  - [1.1 顺序表 静态实现，数据元素是整数](dataStructure/01_linear_list/seqlist1.c)
  - [1.2 顺序表 静态实现，数据元素是结构体](dataStructure/01_linear_list/seqlist2.c)
  - [1.3 顺序表 动态实现，数据元素是整数](dataStructure/01_linear_list/seqlist3.c)
  - [1.4 顺序表 动态实现，数据元素是结构体](dataStructure/01_linear_list/seqlist4.c)
- [2 link list链表](dataStructure/02_link_list/link_list.md)  
  - [2.1 带头结点的单链表的实现，数据元素是整数](dataStructure/02_link_list/linklist1.c)
  - [2.2 带头结点的单链表的实现，数据元素是结构体](dataStructure/02_link_list/linklist2.c)
  - [2.3 不带头结点的单链表的实现](dataStructure/02_link_list/linklist3.c)
  - [2.4 带头结点的双链表的实现，数据元素是整数](dataStructure/02_link_list/linklist4.c)
  - [2.5 带头结点的循环单链表的实现，数据元素是整数](dataStructure/02_link_list/linklist5.c)
  - 2.6 常见的考题


- [3 B 树](dataStructure/03_btree/btree.md)
  - [3.1 二叉树的层次遍历](dataStructure/03_btree/btree1.c)
  - [3.2 二叉树的前序遍历、中序遍历和后序遍历，包括递归和非递归两种方法](dataStructure/03_btree/btree2.c)
  - [3.3 中序线索二叉树的创建及求前驱后继的方法](dataStructure/03_btree/btree3.c)
  - [3.4 二叉排序树的各种操作，包括插入、删除、查找](dataStructure/03_btree/btree4.c)

  
- [4 图](dataStructure/04_graph/graph.md)
  - 4.1 BFS (Breadth First Search 广度优先遍历）
  - 4.2 DFS (Depth First Search 深度优先搜索)
  - 4.3 单源最短路径算法(Floyd(弗洛伊德)算法)
  - 4.4 拓扑排序
  - 4.5 关键路径
- 5 hash哈希表
  
- [6 queue队列](dataStructure/06_queue/queue.md)
  - [6.1 循环队列的数组实现，队尾指针指向队尾的下一个元素，没有length的辅助变量](dataStructure/06_queue/seqqueue1.c)
  - [6.2 循环队列的数组实现，队尾指针指向队尾的下一个元素，增加了length的辅助变量](dataStructure/06_queue/seqqueue2.c)
  - [6.3 循环队列的数组实现，队尾指针指向队尾元素，没有length的辅助变量](dataStructure/06_queue/seqqueue3.c)
  - [6.4 循环队列的数组实现，队尾指针指向队尾元素，增加了length的辅助变量](dataStructure/06_queue/seqqueue4.c)
  - [6.5 队列的链表实现（带头结点）](dataStructure/06_queue/linkqueue1.c)
  
- [7 stack栈](dataStructure/07_stack/stack.md)
  - [7.1 顺序栈的实现，数据元素是整数](dataStructure/07_stack/seqstack1.c)
  - [7.2 链栈的实现，数据元素是整数](dataStructure/07_stack/linkstack1.c)
  - [7.3 顺序栈检查括号是否匹配，支持()[]{}三种括号](dataStructure/07_stack/seqstack2.c)
  - [7.4 用顺序栈实现中缀表达式转后缀表达式](dataStructure/07_stack/seqstack3.c)
  
- [8 排序算法](dataStructure/08_sort/sort.md)
  - 8.1 冒泡排序
  - 8.2 桶排序
  - 8.3 计数排序
  - [8.4 堆排序](dataStructure/08_sort/heapsort.c)
  - [8.5 插入排序](dataStructure/08_sort/insertsort.c)
  - 8.6 归并排序
    - [递归的方法实现](dataStructure/08_sort/mergesort.c)
    - [循环的方法实现](dataStructure/08_sort/mergesort1.c)
  - 8.7 快速排序
  - 8.8 基数排序
  - [8.9 选择排序](dataStructure/08_sort/selectsort1.c)
  - [8.10 希尔排序](dataStructure/08_sort/shellsort.c)
  
- [9 数组和广义表](dataStructure/09_array/array.md)
- [10 串](dataStructure/10_string/string.md)
- [11 查找](dataStructure/11_search/search.md)
  - [11.1 顺序查找](dataStructure/11_search/seqsearch.c)
  - [11.2 二分查找](dataStructure/11_search/binsearch.c)
- [12 递归](dataStructure/12_recursive/recursive.md)
  
## [第四章 algorithm算法](algorithm/algorithm.md) 
  - [1 蛮力法Exhausitive Attack](algorithm/01_Exhaustive_Attack.md)
  - [2 分治法Divide and Conquer](algorithm/02_divide_n_conquer.md)
  - [3 贪心法Greedy Method](algorithm/03_greedy_method.md)
  - [4 动态规划dynamic programming](algorithm/dynamic_programming.md)

##  [Clang 及 LLVM 介绍](Clang.md)
##  [gcc介绍](gcc.md)

注意 ⚠️：**_中文注释乱码时，设置 vscode:files.autoGuessEncoding 项的值改为 true 即可，数据结构中推荐编码格式为 GBK_**


