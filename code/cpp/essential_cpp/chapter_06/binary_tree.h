
#ifndef __ESSENTIAL_CPP_BINARY_TREE_H__
#define __ESSENTIAL_CPP_BINARY_TREE_H__

#include <iostream>

#include "bt_node.h"

namespace chapter_06
{

template <typename ElemType>
class BinaryTree
{
    friend std::ostream& operator<<(std::ostream &os, const BinaryTree<ElemType> &bt);
public:
    BinaryTree();
    BinaryTree(const BinaryTree &);
    ~BinaryTree();
    BinaryTree& operator=(const BinaryTree &);
public:
    bool Empty() const { return root_ == 0; }
    void Clear();
    void Insert(const ElemType &elem);
    void Remove(const ElemType &elem);

    void Preorder();
    void Inorder();
    void Postorder();
private:
    void RemoveRoot();
    void Clear(BTnode<ElemType> *pt);

    void Copy(BTnode<ElemType> *tar, BTnode<ElemType> *src);    //
private:
    BTnode<ElemType>    *root_;
};

template<typename ElemType>
inline std::ostream& operator<<(std::ostream &os, const BinaryTree<ElemType> &bt)
{
    os << "Tree ...\n";

}

template<typename ElemType>
BinaryTree<ElemType>::BinaryTree() : root_(0)
{

}

template<typename ElemType>
BinaryTree<ElemType>::BinaryTree(const BinaryTree &rhs)
{
    Copy(root_, rhs.root_);
}

template<typename ElemType>
BinaryTree<ElemType>::~BinaryTree()
{
    Clear();
}

template<typename ElemType>
BinaryTree<ElemType>& BinaryTree<ElemType>::operator=(const BinaryTree &rhs)
{
    if (this != &rhs)
    {
        Clear();
        Copy(root_, rhs.root_);
    }

    return *this;
}

template<typename ElemType>
void BinaryTree<ElemType>::Clear()
{
    if (root_) Clear(root_);
    root_ = 0;
}

template<typename ElemType>
void BinaryTree<ElemType>::Insert(const ElemType &elem)
{
    if (!root_)
        root_ = new BTnode<ElemType>(elem);
    else
        root_->InsertValue(elem);
}

template<typename ElemType>
void BinaryTree<ElemType>::Remove(const ElemType &elem)
{
    if (root_->val_ == elem)
        RemoveRoot();
    else
        root_->RemoveValue(elem, root_);
}

template<typename ElemType>
void BinaryTree<ElemType>::RemoveRoot()
{
    if (!root_) return;

    BTnode<ElemType> *tmp = root_;
    if (root_->rchild_)                 // 存在右子树
    {
        root_ = root_->rchild_;
        if (tmp->lchild_)               // 存在原左子树
        {
            BTnode<ElemType> *lc = tmp->lchild_;
            BTnode<ElemType> *newlc = root_->lchild_;

            if (!newlc)
               root_->lchild_ = lc;
            else
                BTnode<ElemType>::LchildLeaf(lc, newlc);
        }
    }
    else
        root_ = root_->lchild_;         // 不存在右子树

    delete tmp;
}

template<typename ElemType>
void BinaryTree<ElemType>::Clear(BTnode<ElemType> *pt)
{
    if (pt)
    {
        Clear(pt->lchild_);
        Clear(pt->rchild_);
        delete pt;
        pt = 0;
    }
}

template<typename ElemType>
void BinaryTree<ElemType>::Preorder()
{
    root_->Preorder(root_, std::cout);
}

template<typename ElemType>
void BinaryTree<ElemType>::Inorder()
{
    root_->Inorder(root_, std::cout);
}

template<typename ElemType>
void BinaryTree<ElemType>::Postorder()
{
    root_->Postorder(root_, std::cout);
}

}

#endif //__ESSENTIAL_CPP_UTIL_BINARY_TREE_H__
