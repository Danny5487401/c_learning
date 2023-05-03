#include <stdio.h>
#include <string.h>
 
// 重载strcpy函数，对dest初始化，防止内存溢出。
char *strcpy(char *dest, const char *src,size_t destsize);
 
int main()
{
  char dest[10];
 
  strcpy(dest,"www.freecplus.net",sizeof(dest));  // 新strcpy
  printf("=%s=\n",dest);
 
  strcpy(dest,"www.freecplus.net");   // 旧strcpy，strcpy函数有两个缺陷：1）没有对dest变量进行初始化；2）如果src的长度超过dest，会造成内存溢出。
  printf("=%s=\n",dest);
}
 
// 重载strcpy函数，对dest初始化，防止内存溢出
char *strcpy(char *dest, const char *src,size_t destsize)
{
  memset(dest,0,destsize);  // 对dest初始化
 
  // 计算需要复制的字符数，不能超出destsize-1
  size_t len=0;
  if (strlen(src)<=destsize-1) len=strlen(src);
  else len=destsize-1;
 
  strncpy(dest,src,len);   // 复制字符串，超出的将扔掉
  dest[len]=0;  // 强制字符串的结尾标志
 
  return dest;
}