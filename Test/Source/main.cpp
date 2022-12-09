#include <array>
#include <iostream>

#include "BalalargaUtils/ArrayTree.h"

struct Item
{
    int id{};
    std::array<Item*, 4> ChildrenArr;
    std::vector<Item*> ChildrenVec;
    Item** Children()
    {
        return ChildrenArr.data();
    }
    size_t ChildrenCount()
    {
        return ChildrenArr.max_size();
    }
};

int main(int argc, char** argv)
{
    // TODO: const/non-const functions for template arguments
    Utils::ArrayTree<Item> tree;
    // tree.IterateTree([](Item* item, Item* parent)
    // {
        // return true;
    // });
    // for (const Item& item : tree)
    // {
        // std::cout << item.id;
    // }
    return 0;
}
