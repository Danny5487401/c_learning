# C结构体

使用结构体（struct）来存放一组不同类型的数据，语法如下：
```c
struct 结构体名
{
  结构体成员变量一的声明;
  结构体成员变量二的声明;
  结构体成员变量三的声明;
  ......
  结构体成员变量四的声明;
};
```
结构体是一个集合，是一种构造的数据类型，是程序员为了描述一个数据集自己定义出来的数据类型。结构体的成员（member）可以是任意类型的变量，也可以是结构体变量。以超女为例：

```c
struct st_girl
{
  char name[51];   // 姓名
  int  age;        // 年龄
  int  height;     // 身高，单位：cm
  int  weight;     // 体重，单位：kg
  char sc[31];     // 身材，火辣；普通；飞机场
  char yz[31];     // 颜值，漂亮；一般；歪瓜裂枣
}
```

## 结构体变量
结构体是一种程序员自定义的数据类型，是模板，可以用它来定义变量。例如：
```c
 struct st_girl queen, princess, waiting, workers;
```
定义了四个结构体变量，queen王后、princess王妃，waiting宫女和workers侍者。

## 占用内存的情况
理论上讲结构体的各个成员在内存中是连续存放的，和数组非常类似，但是，结构体的占用内存的总大小不一定等于全部成员变量占用内存大小之和。在编译器的具体实现中，为了提高内存寻址的效率，各个成员之间可能会存在缝隙。用sizeof可以得到结构体占用内存在总大小，sizeof(结构体名)或 sizeof(结构体变量名)都可以。

C语言提供了结构体成员内存对齐的方法，在定义结构体之前，增加以下代码可以使结构体成员变量之间的内存没有空隙。
```c
#pragma pack(1)
```

## 结构体的变量名
和数组不一样，结构体变量名不是结构体变量的地址，结构体变量名就是变量名，就象int ii一样，只是不能直接输出，直接输出没有意义。取地址要用&，不用钻牛角尖，不直接输出就行了。
```c
  struct st_girl stgirl;
  printf("%d\n",stgirl);   // 没有意义。
  printf("%p\n",stgirl);   // 没有意义，结构体变量名不是结构体变量的地址。
  printf("%p\n",&stgirl);  // 这才是结构体的地址。
```

## 结构体初始化
采用memset函数初始化结构体，全部成员变量的值清零。
```c
memset(&queen,0,sizeof(struct st_girl));

// 或则
memset(&queen,0,sizeof(queen));
```

注意事项，如果把一个结构体的地址传给子函数，子函数用一个结构体指针（如struct st_girl *pst）来存放传入的结构体的地址，那么，在子函数中只能用以下方法来初始化结构体：
```c
memset(pst,0,sizeof(struct st_girl));

// 不能用以下方法来初始化结构体：
// memset(pst,0,sizeof(pst));
// 因为子函数中用sizeof(pst)，得到的不是结构体占用内存的字节数，而是结构体指针变量占用内存的字节数（8字节）。
```

## 成员的访问
采用圆点.运算符可以访问（使用）结构的成员，结构体成员变量的使用与普通变量的使用相同。


## 结构体指针

结构体是一种自定义的数据类型，结构体变量是内存变量，有内存地址，也就有结构体指针。

在指针章节中我们已经学习过，采用不同数据类型的指针指向不同数据类型的变量的地址，这一规则也适用于结构体。如下：
```c
  struct st_girl queen;
  struct st_girl *pst=&queen;
```
通过结构体指针可以使用结构体成员，一般形式为：
```c
// 第一种写法中，圆点.的优先级高于*，(*pointer)两边的括号不能少。如果去掉括号写作*pointer.memberName，那么就等效于*(pointer.memberName)，这样意义就完全不对了。
(*pointer).memberName

// 或者：
// 第二种写法中，->是一个新的运算符，习惯称它为“箭头”，有了它，可以通过结构体指针直接使用结构体成员；这也是->在C语言中的唯一用途
pointer->memberName
```

## 结构体的复制
在C语言中，结构体的成员如果是基本数据类型（int、char、double）可以用=号赋值，如果是字符串，字符串不是基本数据类型，可以用strcpy函数赋值，如果要把结构体变量的值赋给另一个结构体变量，有两种方法：
1. 一种是把结构体变量成员的值逐个赋值给另一个结构体变量的成员，这种方法太笨，没人使用；  

2.另一种方法是内存拷贝，C语言提供了memcpy（memory copy的简写）实现内存拷贝功能。

```c
void *memcpy(void *dest, const void *src, size_t n);

```
- src 源内存变量的起始地址。

- dest 目的内存变量的起始地址。

- n 需要复制内容的字节数。

- 函数返回指向dest的地址， 函数的返回值意义不大，程序员一般不关心这个返回值。
```c
#include <stdio.h>
#include <string.h>
 
struct st_girl
{
  char name[50];     // 姓名
  int  age;          // 年龄
};
 
void main()
{
  struct st_girl girl1,girl2;
 
  strcpy(girl1.name,"西施");  // 对girl1的成员赋值
  girl1.age=18;
 
  // 把girl1的内容复制到girl2中
  memcpy(&girl2,&girl1,sizeof(struct st_girl));
 
  printf("girl1.name=%s,girl1.age=%d\n",girl1.name,girl1.age);
  printf("girl2.name=%s,girl2.age=%d\n",girl2.name,girl2.age);
}
```
大家可能想起了strcpy函数，与memcpy有相似之处，实际上这两个函数从功能和实现原理上完本不同，甚至不应该放在一起比较。

1）复制的内容不同，strcpy只能复制字符串，而memcpy可以复制任意内容，例如字符数组、整型、结构体、类等。

2）用途不同，通常在复制字符串时用strcpy，而需要复制其他类型数据时则一般用memcpy。

3）复制的方法不同，strcpy不需要指定长度，它遇到被复制字符的串结尾符0才结束，memcpy则是根据其第3个参数决定复制的长度。

## 结构体作为函数的参数

结构体是多个变量集合，作为函数参数时就可以传递整个集合，也就是所有成员。如果结构体成员较多，函数参数的初始化和赋值的内存开销会很大，影响程序的运行效率。所以最好的办法就是传递结构体变量的地址。

## memset和bzero函数
1. memset 函数是内存空间赋值函数，用来给某一块内存空间进行赋值的。包含在<string.h>头文件中。
```c
void *memset(void *s, int v, size_t n);
```

s为内存空间的地址，一般是数组名或结构体的地址。

v为要填充的值，填0就是初始化。

n为要填充的字节数。

在实际开发中，程序员用memset函数对数组或结构体清零

2. bzero函数是内存空间清零。包含在<string.h>头文件中。
```c
void bzero(void *s, size_t n);

```
s为内存空间的地址，一般是数组名或结构体的地址。

n为要清零的字节数。

如果要对数组或结构体清零，用memset和bzero都可以，没什么差别，看程序员的习惯。