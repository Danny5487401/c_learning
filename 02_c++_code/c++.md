C++
C++读作“C加加”，是“C Plus Plus”的简称，C++ 是在C语言的基础上增加新特性，从语法上看，C语言是 C++ 的一部分，C语言代码几乎不用修改就能够以 C++ 的方式编译。


## C++程序的命名规则

C++头文件一般采用.h后缀，也用有.hpp的。

C++程序文件一般采用.cpp后缀，也有用.cc的，建议采用.cpp，C++对程序文件的命名没有强制要求，采用.cpp为后缀是大部分程序员的习惯。


## C++程序的编译

在某些操作系统中，C和C++是同一个编译器，在CentOS中，C的编译器是gcc，C++的编译器是g++。

编译C程序的命令是gcc，编译C++程序的命令是g++，g++命令和gcc命令的用法相同，把gcc改为g++就可以了


## C++布尔类型（bool）
C语言并没有彻底从语法上支持“真”和“假”，只是用 0 和非 0 来代表。这点在 C++中得到了改善，C++ 新增了 bool 类型（布尔类型），它占用 1 个字节长度。bool 类型只有两个取值，true 和 false：true 表示“真”，false 表示“假”。

bool 是类型名字，也是 C++ 中的关键字，它的用法和 int、char、long 是一样的，可以用=赋值，可以用于函数的参数和返回值。
```c++
bool flag=true;  // 定义bool型变量flag，赋值为true

if (flag) printf("flag is true");
else printf("flag is fals");

flag=false;    // 把flag赋值为false

if (flag) printf("flag is true");      
else printf("flag is fals");
```

## C++函数的缺省参数
在C语言中，函数在声明的时候指定了参数列表，调用的时候函数参数的个数、顺序和数据类型必须与函数声明参数列表相同，但是在C++中，声明函数的时候，可以为函数指定缺省参数，调用时缺省参数可以不填写。例如
```c++
int writetofile(FILE *fp,char *strbuf,bool enbuffer=true); // 指定参数enbuffer的缺省值为true


```
enbuffer参数表示是否启用缓冲区，writetofile函数被调用的时候，如果只写fp和strbuf参数，不写enbuffer参数，enbuffer参数将缺省为true，

## C++动态内存管理

在C语言中，动态管理内存用 malloc() 函数，释放内存用 free() 函数。

在C++中，这两个函数仍然可以使用，但是C++又新增了两个关键字，new 和 delete，new 用来动态分配内存，delete 用来释放内存。

和C语言的动态内存管理一样，C++动态内存管理的应用场景不多