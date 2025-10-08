# linux 



## compile_commands.json

compile_commands.json 是一个常见的编译数据库文件格式，通常用于包含项目中所有编译命令的详细信息，旨在帮助 IDE 或构建工具准确地解析代码并提供智能功能（如跳转到定义、自动补全、代码分析等）。
compile_commands.json 主要用于 C/C++ 项目，特别是在使用 CMake 等构建系统时，提供了详细的编译信息。

## 在线调试

远程 linux 服务器安装 clangd server 


拉取代吗
```shell
git clone --branch v6.8 --depth 1 https://github.com/torvalds/linux.git
```

安装编译工具链
```shell
sudo apt-get install  clang llvm build-essential flex bison libelf-dev libssl-dev bc libncurses5-dev libncursesw5-dev bear
```


编译 Linux Kernel, 当前是 amd64 架构
```shell

# 默认配置编译文件
root@node1:/opt/linux# make ARCH=x86_64 O=build defconfig

# 进行配置
root@node1:/opt/linux# make ARCH=x86_64 O=build menuconfig

root@node1:/opt/linux# make ARCH=x86_64 O=build compile_commands.json
```



```shell
# vscode 启用 compile_commands.json 支持
root@node1:/opt/linux# cat .vscode/settings.json 
{
    "clangd.compilationDatabasePath": "build"
}
```




## 参考

- [手把手教你使用VSCode进行linux内核代码阅读和开发](https://zhuanlan.zhihu.com/p/558286384)