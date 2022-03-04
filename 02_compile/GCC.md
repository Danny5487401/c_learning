# GCC

## 组件及命令

组件：

![](.gcc_images/gcc_tools.png)
![](.gcc_images/gcc_tools2.png)

命令：

![](.gcc_images/gcc_options.png)
![](.gcc_images/gcc_option2.png)
![](.gcc_images/gcc_option3.png)

工具集：

![](.gcc_images/gcc_tools3.png)
![](.gcc_images/gcc_tools4.png)



## 目标文件

目标文件是包含带有附加地址和值的助记符号的路线图。这些符号可以用来对各种代码段和数据段进行命名，包括经过初始化的和未初始化的。它们也可以用来定位嵌入的调试信息，就像语义 Web，非常适合由程序进行阅读


### 目标文件的格式

计算机编程领域中存在许多著名的目标文件格式。DOS 系列包括 COM、OBJ 和 EXE 格式。UNIX 和 Linux 使用 a.out、COFF 和 ELF。Microsoft® Windows® 使用可移植的执行文件 (PE) 格式，而 Macintosh 使用 PEF、Mach-O 和其他文件格式。

最初，各种类型的计算机具有自己独特的目标文件格式，但随着 UNIX 和其他在不同硬件平台上提供可移植性的操作系统的出现，一些常用的文件格式上升为通用的标准。其中包括 a.out、COFF 和 ELF 格式

### 使用
```c
#include <stdio.h>

// 主函数
int main()
{
    printf("hellow,world");
    return 0;
}
```
gcc -S hello.c  汇编输出,在当前目录下会生成 hello.s 文件，即为汇编输入文本。

要创建 a.out 文件，可以在 shell 窗口中输入下面的命令：gcc hello.c

#### nm：列出目标文件中的符号
```shell
02_compile git:(feature/clang) ✗ nm a.out 

0000000100008008 d __dyld_private
0000000100000000 T __mh_execute_header
0000000100003f60 T _main
                 U _printf
                 U dyld_stub_binder
```

这些包含可执行代码的段称为正文段。同样地，数据段包含了不可执行的信息或数据。另一种类型的段，称为 BSS 段，它包含以符号数据开头的块。

对于 nm 命令列出的每个符号，它们的值使用十六进制来表示（缺省行为），并且在该符号前面加上了一个表示符号类型的编码字符。

常见的各种编码包括：
- A 表示绝对 (absolute)，这意味着不能将该值更改为其他的连接；
- B 表示 BSS 段中的符号；
- C 表示引用未初始化的数据的一般符号。
可以将目标文件中所包含的不同的部分划分为段。段可以包含可执行代码、符号名称、初始数据值和许多其他类型的数据。



#### objdump：显示目标文件中的详细信息
```shell
02_compile git:(feature/clang) ✗  objdump -d a.out

a.out:  file format Mach-O 64-bit x86-64


Disassembly of section __TEXT,__text:

0000000100003f60 _main:
100003f60: 55                           pushq   %rbp
100003f61: 48 89 e5                     movq    %rsp, %rbp
100003f64: 48 83 ec 10                  subq    $16, %rsp
100003f68: c7 45 fc 00 00 00 00         movl    $0, -4(%rbp)
100003f6f: 48 8d 3d 34 00 00 00         leaq    52(%rip), %rdi
100003f76: b0 00                        movb    $0, %al
100003f78: e8 0d 00 00 00               callq   13 <dyld_stub_binder+0x100003f8a>
100003f7d: 31 c9                        xorl    %ecx, %ecx
100003f7f: 89 45 f8                     movl    %eax, -8(%rbp)
100003f82: 89 c8                        movl    %ecx, %eax
100003f84: 48 83 c4 10                  addq    $16, %rsp
100003f88: 5d                           popq    %rbp
100003f89: c3                           retq

Disassembly of section __TEXT,__stubs:

0000000100003f8a __stubs:
100003f8a: ff 25 70 40 00 00            jmpq    *16496(%rip)

Disassembly of section __TEXT,__stub_helper:

0000000100003f90 __stub_helper:
100003f90: 4c 8d 1d 71 40 00 00         leaq    16497(%rip), %r11
100003f97: 41 53                        pushq   %r11
100003f99: ff 25 61 00 00 00            jmpq    *97(%rip)
100003f9f: 90                           nop
100003fa0: 68 00 00 00 00               pushq   $0
100003fa5: e9 e6 ff ff ff               jmp     -26 <__stub_helper>
```





## ElF 可执行链接格式 （ Executable and Linking Format)

相对于其它文件类型，可执行文件可能是一个操作系统中最重要的文件类型，因为它们是完成操作的真正执行者。可执行文件的大小、运行速度、资源占用情况以及可扩展性、可移植性等与文件格式的定义和文件加载过程紧密相关。

文件中应包含代码和数据。因为文件可能引用外部文件定义的符号（变量和函数），因此重定位信息和符号信息也是需要的。一些辅助信息是可选的，如调试信息、硬件信息等。

基本上任意一种可执行文件格式都是按区间保存上述信息，称为段（Segment）或节（Section）。

相对可执行文件有三个重要的概念：编译（compile）、连接（link，也可称为链接、联接）、加载（load）。源程序文件被编译成目标文件，多个目标文件被连接成一个最终的可执行文件，可执行文件被加载到内存中运行。


### LINUX 平台下 ELF 文件加载过程的简单描述

1. 内核首先读 ELF 文件的头部，然后根据头部的数据指示分别读入各种数据结构，找到标记为可加载（loadable）的段，并调用函数 mmap() 把段内容加载到内存中。在加载之前，内核把段的标记直接传递给 mmap() ，段的标记指示该段在内存中是否可读、可写，可执行。显然，文本段是只读可执行，而数据段是可读可写。这种方式是利用了现代操作系统和处理器对内存的保护功能。
2. 内核分析出 ELF 文件标记为 PT_INTERP 的段中所对应的动态连接器名称，并加载动态连接器。现代 LINUX 系统的动态连接器通常是 /lib/ld-linux.so.2。
3. 内核在新进程的堆栈中设置一些标记-值对，以指示动态连接器的相关操作。
4. 内核把控制传递给动态连接器。
5. 动态连接器检查程序对外部文件（共享库）的依赖性，并在需要时对其进行加载。
6. 动态连接器对程序的外部引用进行重定位，通俗的讲，就是告诉程序其引用的外部变量/函数的地址，此地址位于共享库被加载在内存的区间内。动态连接还有一个延迟（Lazy）定位的特性，即只在 "真正" 需要引用符号时才重定位，这对提高程序运行效率有极大帮助。
7. 动态连接器执行在 ELF 文件中标记为 .init 的节的代码，进行程序运行的初始化。在早期系统中，初始化代码对应函数 _init(void)(函数名强制固定)，
```c
void __attribute((constructor)) init_function(void)
{
    ……
}
```
8.  动态连接器把控制传递给程序，从 ELF 文件头部中定义的程序进入点开始执行。在 a.out 格式和 ELF 格式中，程序进入点的值是显式存在的，在 COFF 格式中则是由规范隐含定义。

    从上面的描述可以看出，加载文件最重要的是完成两件事情：
    - 加载程序段和数据段到内存；
    - 进行外部定义符号的重定位。

    重定位是程序连接中一个重要概念。我们知道，一个可执行程序通常是由一个含有 main() 的主程序文件、若干目标文件、若干共享库（Shared Libraries）组成。