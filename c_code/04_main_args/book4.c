#include <stdio.h>
 
int main(int argc,char *argv[],char *envp[])
{
  int ii=0;
 
  // 显示参数的个数
  printf("argc is %d\n",argc);
 
  // 列出全部的参数
  for (ii=0;ii<argc;ii++)
  {
    printf("argv[%d] is %s\n",ii,argv[ii]);
  }
  int jj = 0;
 
  while (envp[jj] != 0)  // 数组最后一个元素是0
  {
    printf("%s\n",envp[ii]); ii++;
  }
}
/*
int argc，存放了命令行参数的个数。

char *argv[]，是个字符串的数组，每个元素都是一个字符指针，指向一个字符串，即命令行中的每一个参数。

char *envp[]，也是一个字符串的数组，这个数组的每一个元素是指向一个环境变量的字符指针
*/