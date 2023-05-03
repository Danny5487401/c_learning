# Function Overloading函数重载

在实际开发中，有时候我们需要实现几个功能类似的函数，例如从XML字符串中解析字段，字段的类型可能是int、long、double。
在C语言中不允许函数同名，程序员只能设计出三个不同名的函数，其函数声明如下：
```c
// 解析XML字符串的函数族，支持int、char *和double三种类型。
// 返回值：0-成功，-1-失败。
int GetXMLBuffer_Int(const char *in_XMLBuffer,const char *in_FieldName,int *out_Value);
int GetXMLBuffer_Str(const char *in_XMLBuffer,const char *in_FieldName,char *out_Value);
int GetXMLBuffer_Double(const char *in_XMLBuffer,const char *in_FieldName,double *out_Value);
```

C语言中函数命名不能重复对程序员是一种负担，编程序的时候需要想象出相近的函数名，调用函数的时候，书写函数名也是一件麻烦的事情。

C++允许多个函数拥有相同的名字，只要它们的参数列表不同就可以，这就是函数的重载（Function Overloading），借助重载，多个功能相近的一系列函数可以使用同一函数名。

函数的参数列表包括参数的类型、参数的个数和参数的顺序，只要有一个不同就叫做参数列表不同。

使用C++函数重载，把变量的值写入文件的函数声明修改如下
```c++
// 解析XML字符串的函数族，支持int、char *和double三种类型。
// 返回值：0-成功，-1-失败。
int GetXMLBuffer(const char *in_XMLBuffer,const char *in_FieldName,int *out_Value);
int GetXMLBuffer(const char *in_XMLBuffer,const char *in_FieldName,char *out_Value);
int GetXMLBuffer(const char *in_XMLBuffer,const char *in_FieldName,double *out_Value);
```

重载就是在一个作用范围内（同一个程序、同一个类、同一个命名空间等）有多个名称相同但参数列表不同的一系列函数。

在使用重载函数时，同名函数的功能应当相似，不要用相同名称的函数名去实现不相干的功能，虽然程序也能运行，但可读性不好，使人觉得莫名其妙。

注意，参数列表不同包括参数的个数不同、类型不同或顺序不同，仅仅参数名称不同是不可以的，函数返回值也不能作为重载的依据。



## C++ 是如何做到函数重载
编译器在编译C++程序时会根据参数列表对函数进行重命名，例如：
```c++
int GetXMLBuffer(const char *in_XMLBuffer,const char *in_FieldName,int *out_Value);
```
重命名为
```c++
int GetXMLBuffer_char_char_int(const char *in_XMLBuffer,const char *in_FieldName,int *out_Value);
```

程序被编译时，编译器会根据参数列表逐个匹配，选择对应的函数，如果匹配失败，编译器就会报错，这叫做重载决议（Overload Resolution）。

所以，函数重载仅仅是语法层面的，本质上它们还是不同的函数，占用不同的内存，入口地址也不一样