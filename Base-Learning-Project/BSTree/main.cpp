#include <iostream>
#include "BSTree.h"
using namespace std;

int main() {
    BSTree<int> t;
    t.Insert(12);
    t.Insert(3);
//    t.Insert(9);
//    t.Insert(8);
//    t.Insert(7);
//    t.Insert(6);
//    t.Insert(5);
//    t.Insert(4);
//    t.Insert(3);
//    t.Insert(2);
//    t.Insert(1);

    /*
    cout << "中序遍历： " << endl;
    t.InOrder(); // 中序遍历过程中是把树按照升序排列的
     */

    cout << "前序遍历： " << endl;
    t.PreOrder();

    /*
    cout << "后序遍历： " << endl;
    t.PostOrder();

    cout << "层次遍历： " << endl;
    t.LayerOrder();

    cout << "层次遍历（带标签）： " << endl;
    t.LayerOrderWithTag();
    */

    cout << "前序遍历储存： " << endl;
    t.PreOrderSave();

    return 0;
}
