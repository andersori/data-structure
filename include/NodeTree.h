#ifndef NODETREE_H
#define NODETREE_H

#include <memory>

using std::shared_ptr;

template <class T>
class NodeTree
{
    public:
        NodeTree();
        virtual ~NodeTree();

        T getData() const;
        shared_ptr<NodeTree<T> > getLeft() const;
        shared_ptr<NodeTree<T> > getRight() const;

        void setData(T);
        void setLeft(shared_ptr<NodeTree<T> >);
        void setRight(shared_ptr<NodeTree<T> >);

    private:
        T data;
        shared_ptr<NodeTree<T> > left;
        shared_ptr<NodeTree<T> > right;
};

template <class T>
NodeTree<T>::NodeTree()
{
    left = nullptr;
    right = nullptr;
}

template <class T>
NodeTree<T>::~NodeTree()
{
    //nothing to do
}

template <class T>
T NodeTree<T>::getData() const
{
    return data;
}

template <class T>
shared_ptr<NodeTree<T> > NodeTree<T>::getLeft() const
{
    return left;
}

template <class T>
shared_ptr<NodeTree<T> > NodeTree<T>::getRight() const
{
    return right;
}

template <class T>
void NodeTree<T>::setData(T data)
{
    this->data = data;
}

template <class T>
void NodeTree<T>::setLeft(shared_ptr<NodeTree<T> > left)
{
    this->left = left;
}

template <class T>
void NodeTree<T>::setRight(shared_ptr<NodeTree<T> > right)
{
    this->right = right;
}

#endif // NODETREE_H
