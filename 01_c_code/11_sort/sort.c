#include <stdlib.h>
#include <stdio.h>
// DIM(values)宏用于计算数组元素的个数
#define DIM(x) (sizeof(x) / sizeof((x)[0]))

// 为了避免对全局名字空间的污染，我们将cmp回调函数定义为仅当前文件内可访问的静态函数
static int cmp_int(const void *_a, const void *_b) //参数格式固定
{
    int *a = (int *)_a; //强制类型转换
    int *b = (int *)_b;
    return *a - *b;
}
/*
 void qsort(void* base,size_t num,size_t width,int(__cdecl*compare)(const void*,const void*)); 
　　参数： 1 待排序数组，排序之后的结果仍放在这个数组中
　　　　　 2 数组中待排序元素数量
　　　　   3 各元素的占用空间大小（单位为字节）
　　      4 指向函数的指针，用于确定排序的顺序（需要用户自定义一个比较函数
*/

int main()
{
    int i;
    int a[10] = {0, 1, 12, 3, 14, 5, 16, 7, 18, 9};
    qsort(a, DIM(a), sizeof(a[0]), cmp_int);
    for (i = 0; i < 10; i++)
        printf("%d ", a[i]);
}
