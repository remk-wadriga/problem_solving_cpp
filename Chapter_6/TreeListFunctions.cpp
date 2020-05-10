#include <iostream>

void demonstrateTreeList()
{
    using namespace std;

    TreeList tree1;

    // Lvl 4
    TreeItem* item11 = new TreeItem(1);
    TreeItem* item10 = new TreeItem(1);
    TreeItem* item9 = new TreeItem(0);
    TreeItem* item8 = new TreeItem(3);
    TreeItem* item7 = new TreeItem(2);
    TreeItem* item6 = new TreeItem(1);
    // Lvl 3
    TreeItem* item5 = new TreeItem(2, item10, item11);
    TreeItem* item4 = new TreeItem(4, item8, item9);
    TreeItem* item3 = new TreeItem(4, item6, item7);
    // Lvl 2
    TreeItem* item2 = new TreeItem(6, item4, item5);
    // Lvl 1
    TreeItem* item1 = new TreeItem(9, item3, item2);

    tree1.setHead(item1);

    cout << "-----------------" << "\n";

    cout << "Is heat: " << tree1.isHeat() << "\n";
}