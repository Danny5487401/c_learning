# C++的library库使用

## 1.静态库使用
1. 把程序文件public.cpp编译成静态库的指令：
```shell
g++ -c -o libpublic.a public.cpp
```


2. 生成可执行文件
```shell
# 使用静态库的方法一，直接把调用者源代码和静态库文件名一起编译。
g++ -o main main.cpp libpublic.a

#  使用静态库的方法二，采用L参数指定静态库文件的目录，-l参数指定静态库名。
g++ -o main1 main.cpp -L/Users/python/Desktop/c_learning/c++_code/11_lib -lpublic
```

注意：
1）如果要指定多个静态库文件的目录，用法是“-L/目录1 -L目录2 -L目录3”；

2）链接库的文件名是libpublic.a，但链接库名是”public”，不是“libpublic.a”；

3）如果要指定多个静态库，用法是“-l库名1 -l库名2 -l库名3”。

## 2.  动态库使用


1. 把程序文件public.cpp编译成动态库的指令：
```shell
g++ -fPIC -shared -o libpublic.so public.cpp
```

解释参数：-fPIC 使用地址无关代码模式进行编译， -shared 产生共享对象文件，即生成动态库。

2. 可执行文件
```shell

g++ -o main1 main.cpp -L/Users/python/Desktop/c_learning/c++_code/11_lib -lpublic
```

Note:如果在动态库文件和静态库文件同时存在，优先使用动态库编译。

Linux系统中采用LD_LIBRARY_PATH环境变量指定动态库文件的目录。
注意：1）如果要指定多个动态库文件的目录，用法是“export LD_LIBRARY_PATH=目录1:目录2:目录3:.”，目录之间用半角的冒号分隔，最后的圆点指当前目录。