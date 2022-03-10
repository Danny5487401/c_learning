# 树
![](.btree_images/tree.png)

## 基本术语
![](.btree_images/tree_words.png)
![](.btree_images/tree_words2.png)

## 树的性质
![](.btree_images/tree_attribute.png)
![](.btree_images/tree_attribute1.png)
![](.btree_images/tree_attribute2.png)
![](.btree_images/tree_attribute3.png)

## binary_tree二叉树
![](.btree_images/binary_tree.png)

### 性质
![](.btree_images/binary_attribute1.png)
![](.btree_images/binart_attribute2.png)

## 二叉树和度为2的树的区别
![](.btree_images/binary_tree_vs_other_tree.png)

### 满二叉树
![](.btree_images/full_binary_tree.png)

### 完全二叉树
![](.btree_images/whole_binary_tree.png)

### 二叉排序树
![](.btree_images/sorted_binary_tree.png)


## 二叉树的存储结构
### 完全二叉树的顺序存储
![](.btree_images/full_binary_tree_sequence_store.png)
![](.btree_images/full_binary_store.png)
用顺序存储的方法普通二叉树容易造成空间的浪费

### 二叉树的链式存储
![](.btree_images/binary_chain_store.png)

## 二叉树的遍历
![](.btree_images/read_binary.png)

### 层次遍历
![](.btree_images/layer_read.png)
![](dataStructure/02_btree/.btree_images/layer_read_process.png)
借助队列，出队时，帮左右子元素入队。

### 三种遍历方式
![](.btree_images/three_ways_of_read_binary_tree.png)

1. 先序遍历
![](.btree_images/left_root_right.png)
![](.btree_images/left_root_right1.png)
![](.btree_images/tips_of_left_root_right.png)

2. 中序遍历
![](.btree_images/left_root_right2.png)
![](.btree_images/tips_of_left_root_right1.png)

3. 后序遍历
![](.btree_images/left_root_right3.png)
![](.btree_images/tips_of_left_root_right2.png)

#### 遍历方式代码实现
递归方案实现先序遍历
![](.btree_images/iterate_preorder.png)

递归方案实现中序遍历
![](.btree_images/iterate_inorder.png)

递归方案实现后序遍历
![](.btree_images/iterate_postoder.png)


栈的方式实现中序遍历
![](.btree_images/stack_oder.png)


## 二叉树的遍历
由遍历序列构造二叉树
![](dataStructure/02_btree/.btree_images/construct_tree.png)

先序+中序遍历 构造二叉树
![](.btree_images/construct_tree1.png)
![](.btree_images/construct_tree2.png)


层次+中序遍历 
![](.btree_images/construct_tree3.png)

## 线索二叉树
![](.btree_images/index_tree.png)
线索二叉树，可以理解是用了二叉树中的空指针。

二叉树线索化
![](.btree_images/index_tree2.png)

### 线索二叉树数据结构
![](.btree_images/threaded_tree_struct.png)


### 线索二叉树求前继和后继
![](.btree_images/threaded_tree_pre_post_order.png)

#### 先序线索二叉树求后继
 ![](.btree_images/preorder_get_postorder.png)
 
#### 中序线索二叉树求前继和后继
![](.btree_images/inorder_tree_pre_post.png)