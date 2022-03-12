# queue队列
![](.queue_images/queue.png)
![](.queue_images/queue2.png)

## 队列的顺序存储
![](.queue_images/sequnce_queue.png)
![](.queue_images/sequnce_queue2.png)
1. 出队，头指针往后移，从1-->3
2. 入队，尾指针往后移，可以从8-->9-->1

用数组实现的队列（循环队列）
![](.queue_images/sequence_queue_code.png)

### 队空和队满判断
![](.queue_images/sequence_queue_code2.png)
1. 通过牺牲一个存储单元

![](.queue_images/extra_length_sequence_code3.png)
2. 增加辅助变量 


### 队列的顺序存储代码实现
![](.queue_images/queue_code1.png)
![](.queue_images/queue_code2.png)
![](.queue_images/queue_code3.png)
![](.queue_images/queue_code4.png)


## 队列的链式存储
![](.queue_images/link_queue.png)

![](.queue_images/link_queue2.png)

入队
![](.queue_images/link_enqueue.png)

出队
![](.queue_images/link_dequeue.png)


## 双端队列--实际没有什么价值
![](.queue_images/double_end_queue.png)