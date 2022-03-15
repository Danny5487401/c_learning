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
![](dataStructure/03_btree/.btree_images/layer_read_process.png)
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
![](dataStructure/03_btree/.btree_images/construct_tree.png)

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


### 二叉排序树的节点删除
![](.btree_images/delete_ast.png) 
![](.btree_images/delete_ast_node.png)

### 二叉排序树的查找效率分析
![](.btree_images/ast_performance_of_searching.png)
查找成功  的平均查找长度（ASL average search length）

![](.btree_images/ast_performance_of_searching_fail.png) 
查找失败   的平均查找长度（ASL average search length）

![](.btree_images/ast_performance_of_searching_fail_n_suc.png)


## 平衡二叉树 ---代码实现过于复杂
![](.btree_images/balance_tree.png)
![](.btree_images/avl.png) 

### 插入和删除 数据后不平衡
![](.btree_images/unbalanced_avl.png)

调整方式：调整最小不平衡子树，如70是最小的
![](.btree_images/sort_avl.png) 

从最小不平衡子树出发   
![](.btree_images/sort_avl2.png)
![](.btree_images/sort_avl3.png)
![](.btree_images/sort_avl4.png)

1. 左左更高
![](.btree_images/sort_avl5.png)
向右旋转，然后30放在右侧左子树
![](.btree_images/sort_avl6.png)
![](.btree_images/sort_avl7.png)

2. 左右更高
![](.btree_images/sort_avl8.png) 
 ![](.btree_images/sort_avl9.png)
向左旋转,  向右旋转
![](.btree_images/sort_avl10.png) 
![](.btree_images/sort_avl11.png)
![](.btree_images/sort_avl12.png)
![](.btree_images/sort_avl13.png)

总结：  
![](.btree_images/sort_avl14.png)


### 树高和节点关系
![](.btree_images/avl_height.png)
![](.btree_images/avl_height1.png)

### 哈夫曼huffman树（最优二叉树）
在通信上广泛应用

把经常访问放在跟根结点最近的地方
![](.btree_images/hf_tree.png)
![](.btree_images/hf_tree1.png)

二进制表示:书写简单，不容易泄密
![](.btree_images/hf_tree2.png)
1. 浪费空间
2. 人物长度固定

![](.btree_images/hf_tree3.png)
1. 长度不固定
2. 长度短
