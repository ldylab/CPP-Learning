//
// Created by Henry on 2021/12/5.
//

#ifndef BSTREE_BSTREE_H
#define BSTREE_BSTREE_H
#include "queue"
using namespace std;

template <typename T> struct BSNode {
  // 构造函数，初始化变量（struct就是全部都是public的class）
  // 在初始化的过程中，只是定义node的数值，其左右node都是定义为null
  BSNode(T t) : value(t), l_child(nullptr), r_child(nullptr) {}

  BSNode() = default;

  // 定义每一个Node中含有的变量
  T value;
  BSNode<T> *l_child;
  BSNode<T> *r_child;
  BSNode<T> *parent;
};

// 二叉树的相关功能
template <typename T> class BSTree {
  // 在结构体中默认是public，在class中默认是private
public:
  // 构造函数
  BSTree();
  // 析构函数
  ~BSTree();

  // 二叉树的遍历
  void PreOrder();          // 前序遍历二叉树
  void InOrder();           // 中序遍历二叉树
  void PostOrder();         // 后续遍历二叉树
  void LayerOrder();        // 层次遍历二叉树
  void LayerOrderWithTag(); // 层次遍历二叉树
  void PreOrderSave();      // 前序遍历储存二叉树

  // 二叉树查找（返回的是二叉树的node）
  BSNode<T> *SearchRecursion(T key); // 递归查找
  BSNode<T> *SearchIterator(T key);  // 迭代查找

  // 查找极值
  T SearchMinimun(); // 查找最小值
  T SearchMaximun(); // 查找最大值

  // 查找前后节点
  BSNode<T> *Successor(BSNode<T> *x);   // 查找指定节点的后继节点
  BSNode<T> *Predecessor(BSNode<T> *x); // 查找指定节点的前驱节点

  void Insert(T key); // 插入指定值节点
  void Remove(T key); // 删除指定值节点
  void Destory();     // 销毁二叉树
  void Print();       // 打印二叉树

private:
  BSNode<T> *root_;
  string pre_order_save_;

private:
  BSNode<T> *Search(BSNode<T> *&p, T key);
  void Remove(BSNode<T> *p, T key);
  void PreOrder(BSNode<T> *p);
  void InOrder(BSNode<T> *p);
  void PostOrder(BSNode<T> *p);
  void LayerOrder(BSNode<T> *p);
  void LayerOrderWithTag(BSNode<T> *p);
  void PreOrderSave(BSNode<T> *p);
  T SearchMinimun(BSNode<T> *p);
  T SearchMaximum(BSNode<T> *p);
  void Destory(BSNode<T> *&p);
};

// 默认构造函数
template <typename T> BSTree<T>::BSTree() : root_(nullptr){};

// 默认析构函数
template <typename T> BSTree<T>::~BSTree() { Destory(root_); };

// 插入函数
template <typename T> void BSTree<T>::Insert(T key) {
  BSNode<T> *tmp_parent = nullptr; // 当前这个树的父节点
  BSNode<T> *tmp_node = root_;     // 当前这个树的首个节点

  // 假如目前的树为空树
  // 输入的tmp_node为空时
  if (tmp_node == nullptr) {
    tmp_node = new BSNode<T>(key);
    root_ = tmp_node;
  } else { // 假如不是空树
    // 查找适合插入的节点
    while (tmp_node != nullptr) {
      tmp_parent = tmp_node;
      // 假如key大于节点 -> 转移到有节点
      if (key > tmp_node->value) {
        tmp_node = tmp_node->r_child;
      } else if (key < tmp_node->value) {
        tmp_node = tmp_node->l_child;
      } else {
        break;
      }
    }

    tmp_node = new BSNode<T>(key);
    // 开始插入
    if (key > tmp_parent->value)
      tmp_parent->r_child = tmp_node;
    else
      tmp_parent->l_child = tmp_node;
  }

  // 指明新节点的父节点
  tmp_node->parent = tmp_parent;
};

// 查找函数
template <typename T> BSNode<T> *BSTree<T>::SearchIterator(T key) {
  // 按照其中的规律找到其需要的元素
  BSNode<T> *tmp_node = root_;
  while (tmp_node != nullptr) {
    if (key == tmp_node->value) {
      return tmp_node;
    } else if (key > tmp_node->value) {
      tmp_node = tmp_node->r_child;
    } else {
      tmp_node = tmp_node->l_child;
    }
  }
  return nullptr;
};

// 查找函数（递归函数）
template <typename T> BSNode<T> *BSTree<T>::SearchRecursion(T key) {
  return Search(root_, key);
};

// 递归查找的类内部实现
template <typename T>
BSNode<T> *BSTree<T>::Search(BSNode<T> *&tmp_node, T key) {
  if (tmp_node == nullptr)
    return nullptr;
  if (tmp_node->value == key)
    return tmp_node;
  if (key > tmp_node->value)
    return Search(tmp_node->r_child, key);
  return Search(tmp_node->l_child, key);
};

// 删除指定节点
// 内部使用函数
template <typename T> void BSTree<T>::Remove(BSNode<T> *tmp_node, T key){};

// References: https://blog.csdn.net/Li_haiyu/article/details/94437906
// 寻找前驱节点
// 一个节点的前驱节点有3种情况：
// 1. 若该节点存在左子树，则其前驱节点为左子树最右边的节点；
// 2. 若该节点不存在左子树，则利用parent指针指向父节点找：
//    2.1 若满足该节点是其父节点的右节点，则该父节点为当前节点的前驱节点；
//    2.2
//    若不满足上述，则更新父节点为祖父节点，当前节点更新为其父节点，直到满足条件或者父节点为空，
//        为空表示到达根节点依旧没有找到。
template <typename T> BSNode<T> *BSTree<T>::Predecessor(BSNode<T> *tmp_node) {
  // 假如为空，直接返回为空
  if (tmp_node == nullptr) {
    return tmp_node;
  }

  // 假如其左子树存在，则返回其左子树的最右边节点
  if (tmp_node->l_child != nullptr) {
    return LeftTreeMostRight(tmp_node->l_child);
  } else { // 若其左子树不存在，则向父节点寻找，满足当前节点是父节点的右孩子节点即可，否则向上更新当前节点和其父节点
    BSNode<T> *tmp_parent = tmp_node->parent; // 当前这个树的父节点
    while (tmp_parent->r_child != tmp_node && tmp_parent != nullptr) {
      tmp_node = tmp_parent;
      tmp_parent = tmp_node->parent;
    }
    return tmp_parent;
  }
};

// 找到其左子树的最右边节点
template <typename T> BSNode<T> *LeftTreeMostRight(BSNode<T> *tmp_node) {
  while (tmp_node != nullptr) {
    tmp_node = tmp_node->r_child;
  }
  return tmp_node->parent;
};

// 寻找其中的后继节点
// 一个节点的后继节点有3中情况
// 1. 若该节点存在右子树，则其后驱节点为右子树最左边的节点；
// 2. 若该节点不存在右子树，则利用parent指针指向父节点找：
//    2.1 若满足该节点是其父节点的左节点，则该父节点为当前节点的前驱节点；
//    2.2
//    若不满足上述，则更新父节点为祖父节点，当前节点更新为其父节点，直到满足条件或者父节点为空，
//        为空表示到达根节点依旧没有找到。
template <typename T> BSNode<T> *BSTree<T>::Successor(BSNode<T> *tmp_node) {
  // 假如为空，直接返回为空
  if (tmp_node == nullptr) {
    return tmp_node;
  }

  // 假如其右子树存在，则返回其右子树的最左边节点
  if (tmp_node->r_child != nullptr) {
    return RightTreeMostRight(tmp_node->r_child);
  } else { // 若其右子树不存在，则向父节点寻找，满足当前节点是父节点的左孩子节点即可，否则向上更新当前节点和其父节点
    BSNode<T> *tmp_parent = tmp_node->parent; // 当前这个树的父节点
    while (tmp_parent->l_child != tmp_node && tmp_parent != nullptr) {
      tmp_node = tmp_parent;
      tmp_parent = tmp_node->parent;
    }
    return tmp_parent;
  }
};

// 找到其右子树的最左边节点
template <typename T> BSNode<T> *RightTreeMostRight(BSNode<T> *tmp_node) {
  while (tmp_node != nullptr) {
    tmp_node = tmp_node->l_child;
  }
  return tmp_node->parent;
};

// 遍历算法（采用递归算法）
// 前序遍历算法：根结点 ---> 左子树 ---> 右子树
template <typename T> void BSTree<T>::PreOrder() { PreOrder(root_); };
template <typename T> void BSTree<T>::PreOrder(BSNode<T> *tmp_node) {
  if (tmp_node != nullptr) {
    // 打印根节点
    cout << tmp_node->value << endl;
    // 打印左子树
    PreOrder(tmp_node->l_child);
    // 打印右子树
    PreOrder(tmp_node->r_child);
  }
};

// 前序遍历储存
template <typename T> void BSTree<T>::PreOrderSave() { PreOrderSave(root_); };
template <typename T> void BSTree<T>::PreOrderSave(BSNode<T> *tmp_node) {
  if (tmp_node != nullptr) {
    // 打印根节点
    cout << tmp_node->value;
    cout << "!" << endl;
    // 打印左子树
    PreOrderSave(tmp_node->l_child);
    if (tmp_node->l_child == nullptr) {
      cout << "#!" << endl;
    }
    // 打印右子树
    PreOrderSave(tmp_node->r_child);
    if (tmp_node->r_child == nullptr) {
      cout << "#!" << endl;
    }
  }
};

// 中序遍历算法：左子树 ---> 根结点 ---> 右子树
template <typename T> void BSTree<T>::InOrder() { InOrder(root_); };
template <typename T> void BSTree<T>::InOrder(BSNode<T> *tmp_node) {
  if (tmp_node != nullptr) {
    InOrder(tmp_node->l_child);
    cout << tmp_node->value << endl;
    InOrder(tmp_node->r_child);
  }
};

// 后序遍历算法：左子树 ---> 右子树 ---> 根结点
template <typename T> void BSTree<T>::PostOrder() { PostOrder(root_); };
template <typename T> void BSTree<T>::PostOrder(BSNode<T> *tmp_node) {
  if (tmp_node != nullptr) {
    PostOrder(tmp_node->l_child);
    PostOrder(tmp_node->r_child);
    cout << tmp_node->value << endl;
  }
};

// 层次遍历算法：
template <typename T> void BSTree<T>::LayerOrder() { LayerOrder(root_); };
template <typename T> void BSTree<T>::LayerOrder(BSNode<T> *tmp_node) {
  // 把首个节点给push进去
  queue<BSNode<T> *> q_tmp_;
  q_tmp_.push(tmp_node);

  while (q_tmp_.empty() != 1) {
    BSNode<T> *node = q_tmp_.front();
    q_tmp_.pop();
    if (node->l_child != nullptr) {
      q_tmp_.push(node->l_child);
    }
    if (node->r_child != nullptr) {
      q_tmp_.push(node->r_child);
    }
    cout << node->value << endl;
  }
};

// 层次遍历算法：
template <typename T> void BSTree<T>::LayerOrderWithTag() {
  LayerOrderWithTag(root_);
};
template <typename T> void BSTree<T>::LayerOrderWithTag(BSNode<T> *tmp_node) {
  // 利用两个节点记录
  BSNode<T> *last = nullptr;
  BSNode<T> *n_last = nullptr;

  // 把首个节点给push进去
  queue<BSNode<T> *> q_tmp_;
  q_tmp_.push(tmp_node);

  while (q_tmp_.empty() != 1) {
    BSNode<T> *node = q_tmp_.front();
    q_tmp_.pop();

    if (node->l_child != nullptr) {
      q_tmp_.push(node->l_child);
    }
    if (node->r_child != nullptr) {
      q_tmp_.push(node->r_child);
    }
    cout << node->value << endl;

    // 每一层结束就打印一个"#"符号
    if (node->parent == last) {
      // 它是空节点
      if (node->parent == nullptr) {
        cout << "#" << endl;
        last = node;
      } else if (node->parent == last &&
                 node == node->parent->r_child) { // 右节点
        last = node;
        cout << "#" << endl;
      } else if (node->parent->r_child != nullptr) {

        // 假如这个节点是左子树，并且他还是有右子树
      } else {
        // 这个节点只有左子树，没有右子树
        cout << "#" << endl;
        last = node;
      }
    }
  }
};

// 寻找最大元素：最右边的叶子节点值最大；
template <typename T> T BSTree<T>::SearchMaximun() {
  return SearchMaximum(root_);
};

template <typename T> T BSTree<T>::SearchMaximum(BSNode<T> *tmp_node) {
  if (tmp_node->value != nullptr) {
    return SearchMaximum(tmp_node->r_child);
  }
  return tmp_node->value;
};

// 寻找最小元素：最左边的叶子节点值最小；
template <typename T> T BSTree<T>::SearchMinimun() {
  return SearchMinimun(root_);
};

template <typename T> T BSTree<T>::SearchMinimun(BSNode<T> *tmp_node) {
  if (tmp_node->value != nullptr) {
    return SearchMinimun(tmp_node->l_child);
  }
  return tmp_node->value;
};

// 销毁二叉树
template <typename T> void BSTree<T>::Destory() { Destory(root_); };

// 注意下这里采用的引用的写法，是要把原来树的new空间给集中销毁掉
template <typename T> void BSTree<T>::Destory(BSNode<T> *&tmp_node) {
  if (tmp_node != nullptr) {
    if (tmp_node != nullptr) {
      // 删除左边子树
      if (tmp_node->l_child != nullptr) {
        Destory(tmp_node->l_child);
      }
      // 删除右边子树
      if (tmp_node->r_child != nullptr) {
        Destory(tmp_node->r_child);
      }
      delete tmp_node;
      tmp_node = nullptr; // 要将其指向NULL空间
    }
  }
};

#endif // BSTREE_BSTREE_H
