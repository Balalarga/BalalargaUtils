#include <iostream>

#include "BalalargaUtils/ArrayTree.h"

struct Item
{
    int id{};
    Item* Children[4]{};
};

int main(int argc, char** argv)
{
    Utils::ArrayTree<Item> tree;
    tree.IterateTree([](Item* item, Item* parent)
    {
        return true;
    });
    for (const Item& item : tree)
    {
        std::cout << item.id;
    }
    return 0;
}
