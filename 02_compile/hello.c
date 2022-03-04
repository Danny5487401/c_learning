// 预处理命令
#include <stdio.h>

// 主函数
int main()
{
    printf("hellow,world");
    return 0;
}

// gcc -S hello.c  汇编输出
// 在当前目录下会生成 hello.s 文件，即为汇编输入文本。

// 接下来研究目标文件，其中使用的有价值的工具有：
// nm：列出目标文件中的符号。
// objdump：显示目标文件中的详细信息。
// readelf：显示关于 ELF 目标文件的信息。