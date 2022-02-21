#include "public.h" // 把public.h头文件包含进来

int main()
{
    func();
}


// 1. 把程序文件public.cpp编译成静态库的指令：
// g++ -c -o libpublic.a public.cpp


// 2. 编译
// 使用静态库的方法一，直接把调用者源代码和静态库文件名一起编译。
// g++ -o main main.cpp libpublic.a
// 使用静态库的方法二，采用L参数指定静态库文件的目录，-l参数指定静态库名。
//  g++ -o main1 main.cpp -L/Users/python/Desktop/c_learning/c++_code/11_lib -lpublic