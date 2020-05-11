#include <iostream>

void demonstrateTreeList()
{
    using namespace std;

    TreeList tree1;

    // Lvl 4
    TreeItem* item11 = new TreeItem(12);
    TreeItem* item10 = new TreeItem(10);
    TreeItem* item9 = new TreeItem(8);
    TreeItem* item8 = new TreeItem(1);
    TreeItem* item7 = new TreeItem(6);
    TreeItem* item6 = new TreeItem(3);
    // Lvl 3
    TreeItem* item5 = new TreeItem(11, item10, item11);
    TreeItem* item4 = new TreeItem(7, item8, item9);
    TreeItem* item3 = new TreeItem(5, item6, item7);
    // Lvl 2
    TreeItem* item2 = new TreeItem(9, item4, item5);
    // Lvl 1
    TreeItem* item1 = new TreeItem(7, item3, item2);

    tree1.setHead(item1);

    tree1.print();
    cout << "-----------------" << "\n";

    cout << "Is search tree: " << tree1.isSearchTree() << "\n";
}