#include <stdio.h>
#include <string.h>   
#include <vector>      // vector需要的头文件
#include <algorithm>   // sort函数需要的头文件
 
struct st_girl       // 超女数据结构
{
  char name[50];     // 姓名
  int  age;          // 年龄
};
 
// 自定义排序函数，按超女姓名排序
bool sortbyname(const st_girl &p1,const st_girl &p2)
{
  if (strcmp(p1.name,p2.name)<=0) return true;
  return false;
}
 
// 自定义排序函数，按超女年龄排序
bool sortbyage(const st_girl &p1,const st_girl &p2)
{
  if (p1.age<p2.age) return true;
  return false;
}



int main ()
{
  struct st_girl stgirl;             // 超女数据结构
  std::vector<struct st_girl> vgirl; // 存放超女结构体的容器
 
  strcpy(stgirl.name,"西施"); stgirl.age=18;
  vgirl.push_back(stgirl);
 
  strcpy(stgirl.name,"杨玉环"); stgirl.age=28;
  vgirl.push_back(stgirl);

  strcpy(stgirl.name,"杨幂"); stgirl.age=20;
  vgirl.push_back(stgirl);
 
  //sort(vgirl.begin(),vgirl.end());   // 如果不指定排序函数，编译将报错
  //sort(vgirl.begin(),vgirl.end(),sortbyname); // 按超女的姓名排序
  sort(vgirl.begin(),vgirl.end(),sortbyage);  // 按超女的年龄排序
 
  for (int ii=0;ii<vgirl.size();ii++)
  {
    printf("vgirl[%d].name=%s,vgirl[%d].age=%d\n",\
            ii,vgirl[ii].name,ii,vgirl[ii].age);
  }
}