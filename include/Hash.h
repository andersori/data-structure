#ifndef HASH_H
#define HASH_H

#include <memory>
#include <vector>

using std::shared_ptr;
using std::unique_ptr;
using std::make_shared;
using std::make_unique;
using std::vector;

template <class Key, class T>
class Hash
{
    public:
        Hash(unsigned int);
        virtual ~Hash();

    protected:
        unsigned int MAX_SIZE;
        unsigned int size;
        unique_ptr<vector<shared_ptr<T> > > items;
};


template <class Key, class T>
Hash<Key, T>::Hash(unsigned int MAX_SIZE)
{
    this->MAX_SIZE = MAX_SIZE;
    items(MAX_SIZE);

}

#endif // HASH_H
