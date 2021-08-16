// 在类的内部，即类的成员函数中，无论成员被声明为 public、protected 还是 private，都是可以互相访问的，没有访问权限的限制。

// 在类的外部（定义类的代码之外），只能通过对象访问public的成员，不能访问 private、protected 属性的成员
// 如果既不写 private 也不写 public，就默认为 private

// 成员变量大都以m_开头
// 构造函数的名字和类名相同，没有返回值，不能被显式的调用，而是在创建对象时自动执行。

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

// 文件操作类声明
class CFile
{
private:
  FILE *m_fp;        // 文件指针
  bool  m_bEnBuffer; // 是否启用缓冲区，true-启用；false-不启用
public:
  CFile();   // 类的构造函数
  CFile(bool bEnBuffer);   // 类的构造函数
 
 ~CFile();   // 类的析构函数

  void EnBuffer(bool bEnBuffer=true);  // 启、禁用缓冲区
 
  // 打开文件，参数与fopen相同，打开成功true，失败返回false         
  bool Open(const char *filename,const char *openmode);
 
  // 调用fprintf向文件写入数据
  void Fprintf(const char *fmt,... );
 
  // 调用fgets从文件中读取一行
  bool Fgets(char *strBuffer,const int ReadSize);
 
  // 关闭文件指针
  void Close();
};

int main(int argc,char *argv[])
{
  if (argc !=2) { printf("请输入待打开的文件名。\n"); return -1; }
 
  CFile File;
 
  if (File.Open(argv[1],"r")==false) { printf("File.Open(%s)失败。\n",argv[1]); return -1; }
 
  char strLine[301];
 
  while (true)
  { // 从文件中读取每一行
    if (File.Fgets(strLine,300)==false) break;
 
    printf("%s",strLine);   // 把从文件中读到的内容显示到屏幕
  }
}

CFile::CFile()   // 类的构造函数
{
  m_fp=0;
  m_bEnBuffer=true;
}
 
CFile::CFile(bool bEnBuffer)   // 类的构造函数
{
  m_fp=0;
  m_bEnBuffer=bEnBuffer;
}

// 关闭文件指针
void CFile::Close()
{
  if (m_fp!=0) fclose(m_fp);  // 关闭文件指针
  m_fp=0;
}
 
CFile::~CFile()   // 类的析构函数
{
  Close();  // 调用Close释放资源
}

// 打开文件，参数与fopen相同，打开成功true，失败返回false         
bool CFile::Open(const char *filename,const char *openmode)
{
  Close();  // 打开新的文件之前，如果已经打开了文件，关闭它。
 
  if ( (m_fp=fopen(filename,openmode)) == 0 ) return false;
 
  return true;
}

// 调用fprintf向文件写入数据
void CFile::Fprintf(const char *fmt,...)
{
  if ( m_fp == 0 ) return;
 
  va_list arg;
  va_start(arg,fmt);
  vfprintf(m_fp,fmt, arg);
  va_end(arg);
 
  if ( m_bEnBuffer == false ) fflush(m_fp);
}
 
// 调用fgets从文件中读取一行
bool CFile::Fgets(char *strBuffer,const int ReadSize)
{
  if ( m_fp == 0 ) return false;
 
  memset(strBuffer,0,ReadSize);
 
  if (fgets(strBuffer,ReadSize,m_fp) == 0) return false;
 
  return true;
}