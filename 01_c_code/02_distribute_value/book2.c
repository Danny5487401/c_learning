#include <stdio.h>
#include <string.h>

int main() {
    int ii = 0;   // 定义整数型变量并初始化
    char cc = 0;   // 定义字符型变量并初始化
    double money = 0;   // 定义浮点型变量并初始化
    char name[20];  // 定义字符串变量
    
    memset(name, 0, sizeof(name));  // 字符串初始化

    ii = 10;   // 整数型变量赋值10
    cc = 'A';  // 字符型变量赋值'A'
    money = 1500.87;  // 浮点型变量赋值1500.87
    strcpy(name, "西施");  // 对字符串变量赋值"西施"

    printf("ii=%d=\n", ii);
    printf("cc=%c=\n", cc);
    printf("money=%f=\n", money);
    printf("name=%s=\n", name);
}