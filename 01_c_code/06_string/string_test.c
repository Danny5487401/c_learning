#include <stdio.h>
#include <string.h>

#define STRLEN 14

int main() {
    char name[50];
    memset(name, 0, sizeof(name));
    strcpy(name, "wucongzhou");

    // 统计字符串长度,strlen 不会计入字符串中多余的终止符。
    printf("name 的长度是%lu\n", strlen(name));     // 输出结果：name 的长度是10

    memset(name, 0, sizeof(name));
    // 拷贝字符串
    strcpy(name, "西施");
    printf("name 的长度是%lu\n", strlen(name));     // 输出结果：name 的长度是4

    // 拼接字符串
    char strA[STRLEN] = "Hello,";
    char strB[] = " world!";
    strncat(strA, strB, STRLEN - strlen(strA) - 1);
    printf("%s\n", strA);


}

// 字符串需要用\0结尾，所以在定义字符串的时候，字符数组的长度要预留多一个字节用来存放\0，\0就是数字0。这是约定
//在C语言中，数组名是数组元素的首地址，字符串是字符数组，所以在获取字符串的地址的时候，不需要用&取地址