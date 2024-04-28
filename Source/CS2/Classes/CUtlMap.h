#pragma once

#include <cstdint>

namespace cs2
{

template <typename Key, typename Value, typename Index = int>
struct Node {
    Index left;
    Index right;
    Index parent;
    Index type;
    Key key;
    Value value;
};

template <typename Key, typename Value, typename Index = int>
struct CUtlMap {
    Index size;
    Index allocationCount;
    Node<Key, Value, Index>* memory;
    Index root;
    Index numElements;
};

}
