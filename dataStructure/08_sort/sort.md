# 排序

## 堆排序
![](.sort_images/heap_idea.png)

可以用数组下标表示
![](.sort_images/heap_idea1.png)


### 分类
大顶堆: 用于升序
小顶堆： 用于降序
![](.sort_images/large_small_heap.png)

### 过程

![](.sort_images/heap_process1.png)
1. 从倒数第二层最后一个结点46开始
![](.sort_images/heapify1.png)
![](.sort_images/heapify2.png)

2. 从倒数第三层最后一个结点96开始
![](.sort_images/heapify3.png)

3. 轮到第一层
![](.sort_images/heapify4.png)

4. 第一个和最后一个，即96和22交换
![](.sort_images/heapify5.png)

5. 拿走96，然后进行22元素的下沉(heapify--->理解为元素的下沉)
![](.sort_images/heapify6.png)
![](.sort_images/heapify7.png)

6. 91和22进行交换，重复5的操作进行下沉
![](.sort_images/heapify8.png)
![](.sort_images/heapify9.png)

7. 最后结果
![](.sort_images/heapify_rsp.png)
