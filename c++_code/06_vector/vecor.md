# vector容器

我们在声明数组的时候，采用的是datatype  arrayname[len]的形式，数组在分配之后，不能调整大小，删除和插入数据时操作十分的繁琐，虽然可以采用链表，但是链表的操作更麻烦

与string类一样, 向量vector 同属于STL（Standard Template Library, 标准模板库）中的定义的类, vector是一个封装了动态数组的顺序容器（Sequence Container），它能够存放各种类型的数据和对象。

可以简单的认为vector容器是一个能够存放任意类型的动态数组，与数组相比，vector 容器的优点在于它能够根据需要自动调整的大小，随时放入更多的元素。此外, vector 也提供了成员函数对自身进行操作。

## 容器的定义
首先，如果要在程序中使用vector容器，必须包含头文件 <vector>。如下：

```c++
#include <vector>
```
vector类是一个模板类，位于std命名空间内，为方便使用还需要增加：

```c++
using namespace std;
```
声明一个容器很简单：
```c++
  vector<int> vi;              // 定义用于存放整数的容器
  vector<double> vd;         // 定义用于存放浮点数的容器
  vector<string> vs;           // 定义用于存放string字符串的容器
  vector<struct st_girl> vgirl;  // 定义用于存放超女结构体的容器
  vector<CGirl> vGirl;         // 定义用于存放超女类的容器
```
vector容器可以存放C语言的基本数据类型，可以存放结构体，还可以存放类，这正是我们想要的简单的方法.链表？我已经有二十年没有用它了。


## 函数

```c++

// 1. 向容器尾部增加一个元素x，x就是您要向容器中增加的变量，在本示例中是一个整数，注意，参数x是一个引用，要用变量的名称，不是变量的地址，如vheight.push_back(height);
void push_back(const T& x)

// 2. 返回容器中数据的元素总数。 
int size() 

// 3. 返回容器头指针，指向第一个元素
iterator begin() 

// 4. 返回容器尾指针，指向容器最后一个元素的下一个位置
iterator end()
```