
struct TreeItem
{
    int val;
    TreeItem* left;
    TreeItem* right;

    TreeItem()
    {
        TreeItem(0);
    }
    TreeItem(int value, TreeItem* leftItem = NULL, TreeItem* rightItem = NULL)
    {
        val = value;
        left = leftItem;
        right = rightItem;
    }

    std::string toString()
    {
        return std::to_string(val);
    }

    TreeItem* createCopy()
    {
        return new TreeItem(val);
    }
};