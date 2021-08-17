// 与string类一样, 向量vector 同属于STL（Standard Template Library, 标准模板库）中的定义的类, vector是一个封装了动态数组的顺序容器（Sequence Container），它能够存放各种类型的数据和对象。

// 可以简单的认为vector容器是一个能够存放任意类型的动态数组，与数组相比，vector 容器的优点在于它能够根据需要自动调整的大小，随时放入更多的元素。此外, vector 也提供了成员函数对自身进行操作。
#include <stdio.h>
#include <vector>      // vector需要的头文件
#include <algorithm>   // sort函数需要的头文件
 
int main ()
{
  int height=0;             // 存放从键盘输入的超女身高
  std::vector<int> vheight; // 存放超女身高的容器
 
  while (true)
  {
    printf("请输入超女身高（0-结束输入）：");
    scanf("%d",&height);         // 接受键盘输入的数据
    if (height==0) break;        // 0-结束输入
    vheight.push_back(height);   // 把数据追加入容器,height是一个引用，要用变量的名称
  }
 
  for (int ii=0;ii<vheight.size();ii++) // 显示排序前容器中的记录
  {
    printf("vheight[%d]=%d\n",ii,vheight[ii]);
  }
 
    // 采用sort()函数对容器中的元素进行排序,第三个参数此时缺省的排序方法是从小到大排序
  sort(vheight.begin(),vheight.end());  // 容器中的记录排序
  
 
  for (int ii=0;ii<vheight.size();ii++) // 显示排序后容器中的记录
  {
    printf("vheight[%d]=%d\n",ii,vheight[ii]);
  }
    
    // 容器是类，有析构函数，析构函数中会自动清空容器中的元素，释放内存资源，不需要程序员担
  // vheight.clear();  // 清空容器，可以不写。
}