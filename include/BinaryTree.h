#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "NodeTree.h"

#include <memory>

using std::shared_ptr;
using std::make_shared;

template <class T>
class BinaryTree
{
    public:
        BinaryTree();
        virtual ~BinaryTree();

        virtual void add(const T&);

    protected:
        shared_ptr<NodeTree<T> > root;
        unsigned int _size;

};

template <class T>
BinaryTree<T>::BinaryTree()
{
    _size = 0;
    root = nullptr;
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
    //nothing to do
}

template <class T>
void BinaryTree<T>::add(const T& data)
{
    if(root != nullptr)
    {
        shared_ptr<NodeTree<T> > current = root;

        while(current != nullptr)
        {
            if(current < )
            {

            }
        }

        //insertion

        throw;
    }
    else
    {
        root = make_shared<NodeTree<T> >();
        root->setData(data);
    }
}

#endif // BINARYTREE_H
