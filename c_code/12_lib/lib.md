# 库

add.c 封装成静态库和动态库来使用。
## 静态库
首先将 add.c 编译成目标文件:
```shell script
gcc -c add.c -o add.o
```

然后根据目标文件生成静态库:
```shell script
ar -cr libadd.a add.o
```
ar命令可以用来创建、修改库，也可以从库中提出单个模块

* -c 选项表示 创建一个库。不管库是否存在，都将创建
* -r 选项表示 将模块插入库，如果库中有对应的模块，那么进行更新

如果把多个 .o 文件插入库 .a 里,只需要在后面用空格分开写出来，格式：
```shell script
ar -cr 静态库libname.a  name1.o name2.o
```

生成静态库 libadd.a 后，编译 main.c 连接静态库生成可执行文件main:

```shell script
gcc main.c -o main -I./ -L./ -ladd

./main
```
* -I选项表示头文件路径
* -L表示静态库或者动态库的路径


## 动态库
动态库需要使用 -shared 选项以及 -fPIC 选项
```shell script
gcc -c -fPIC add.c -o a.o
```
-fPIC表示代码是和地址无关的，不需要被不同模块重定位

然后根据目标文件生成动态库.so文件
```shell script
gcc -shared -o libadd.so a.o
```
* -shared 选项表示生成的是.so动态库文件
上面的步骤可以直接写成:
```shell script
gcc -shared -fPIC main.c -o libadd.so
```

链接动态库:
```shell script
gcc main.c -o main -I./ -L./ -ladd
```

### 配置动态库的方法
1. 将动态库路径配置到LD_LIBRARY_PATH,只是暂时生效。
```shell script
export LD_LIBRARY_PATH="./:$LD_LIBRARY_PATH"
./main
```
