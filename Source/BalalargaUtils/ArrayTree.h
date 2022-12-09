#pragma once

#include <functional>
#include <vector>

namespace Utils
{

template<class T,
    T** (T::*ChildrenGetter)() = &T::Children,
    size_t (T::*ChildrenCountGetter)() const = &T::ChildrenCount,
    T* T::* ParentRef = nullptr>
class ArrayTree
{
public:
    template<class... Tail>
    ArrayTree(T i, Tail... t)
    {
        _items.push_back(T(t));
    }

    ArrayTree() = default;

    typename std::vector<T>::iterator begin() { return _items.begin(); }
    typename std::vector<T>::iterator end() { return _items.end(); }

    void IterateTree(std::function<bool(T*, T*)>&& func)
    {
        for (auto& item: _items)
        {
            if (!func(item, item.*ParentRef))
                break;
        }
    }

private:
    std::vector<T> _items;
};
}