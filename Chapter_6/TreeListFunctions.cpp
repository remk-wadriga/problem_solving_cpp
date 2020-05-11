#include <iostream>

void demonstrateTreeList()
{
    using namespace std;

    TreeList tree1;

    // Lvl 4
    TreeItem* item11 = new TreeItem(35);
    TreeItem* item10 = new TreeItem(29);
    TreeItem* item9 = new TreeItem(19);
    TreeItem* item8 = new TreeItem(13);
    // Lvl 3
    TreeItem* item7 = new TreeItem(30, item10, item11);
    TreeItem* item6 = new TreeItem(18, item8, item9);
    TreeItem* item5 = new TreeItem(6);
    TreeItem* item4 = new TreeItem(3);
    // Lvl 2
    TreeItem* item3 = new TreeItem(21, item6, item7);
    TreeItem* item2 = new TreeItem(5, item4, item5);
    // Lvl 1
    TreeItem* item1 = new TreeItem(8, item2, item3);

    tree1.setHead(item1);

    tree1.print();
    cout << "-----------------" << "\n";

    tree1.addToSearchTree(17);

    tree1.print();
    cout << "-----------------" << "\n";

    cout << "Is search tree: " << tree1.isSearchTree() << "\n";
}