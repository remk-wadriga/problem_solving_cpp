#include <iostream>



void demonstrateTreeList()
{
    using namespace std;

    TreeList tree1;

    TreeItem* item6l = new TreeItem(9);
    TreeItem* item6r = new TreeItem(12);
    TreeItem* item6 = new TreeItem(4, item6l, item6r);

    TreeItem* item5l = new TreeItem(-11);
    TreeItem* item5r = new TreeItem(10);
    TreeItem* item5 = new TreeItem(1, item5l, item5r);

    TreeItem* item4l = new TreeItem(-3, item5);
    TreeItem* item4r = new TreeItem(-3, item6);
    TreeItem* item4 = new TreeItem(8, item4l, item4r);

    TreeItem* item3l = new TreeItem(2);
    TreeItem* item3r = new TreeItem(5, item4);
    TreeItem* item3 = new TreeItem(7, item3l, item3r);

    TreeItem* item2l = new TreeItem(4, item3);
    TreeItem* item2r = new TreeItem(1);
    TreeItem* item2 = new TreeItem(6, item2l, item2r);

    TreeItem* item1l = new TreeItem(-1);
    TreeItem* item1r = new TreeItem(3, NULL, item2);
    TreeItem* item1 = new TreeItem(2, item1l, item1r);

    tree1.setHead(item1);

    tree1.print();
    cout << "-----------------" << "\n";

    cout << tree1.getLeafCount() << "\n";
}