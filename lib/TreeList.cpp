#include <iostream>
#include "./TreeItem.cpp"

class TreeList
{
public:
    typedef TreeItem* list;

    TreeList()
    {
        _headItem = NULL;
    }

    void setHead(TreeItem* headItem)
    {
        _headItem = headItem;
    }
    TreeItem* getHead()
    {
        return _headItem;
    }

    void print(std::string sep = "")
    {
        TreeItem* item = getHead();
        while (item != NULL) {
            std::cout << item->toString() << sep;
            item = item->left;
        }
        std::cout << "\n";
    }

    int getMaxVal()
    {
        return getMaxValRecursively(getHead());
    }

    int getItemsCount()
    {
        return getItemsCountRecursively(getHead());
    }

    int getLeafCount()
    {
        return getLeafCountRecursively(getHead());
    }

    // Binary tree is "heat" when each node is bigger than any node in it's left and right branches
    bool isHeat()
    {
        return isHeatRecursive(getHead());
    }

    // Binary tree is "search tree" when each node is bigger than any node in it's left branch and smaller than any node in it's right branch
    bool isSearchTree()
    {
        return isSearchTreeRecursive(getHead());
    }
private:
    TreeItem* _headItem;

    int getMaxValRecursively(TreeItem* head)
    {
        // Exit condition
        if (head == NULL) {
            return 0;
        }

        int max = head->val;
        // Recursion
        int leftMax = getMaxValRecursively(head->left);
        int rightMax = getMaxValRecursively(head->right);

        if (head->left != NULL && leftMax > max) {
            max = leftMax;
        }
        if (head->right != NULL && rightMax > max) {
            max = rightMax;
        }

        return max;
    }

    int getItemsCountRecursively(TreeItem* head)
    {
        // Exit condition
        if (head == NULL) {
            return 0;
        }

        // Recursion
        return 1 + getItemsCountRecursively(head->left) + getItemsCountRecursively(head->right);
    }

    int getLeafCountRecursively(TreeItem* head)
    {
        // Exit condition
        if (head == NULL) {
            return 0;
        }

        // Recursion
        int res = getLeafCountRecursively(head->left) + getLeafCountRecursively(head->right);
        return res == 0 ? 1 : res;
    }

    bool isHeatRecursive(TreeItem* head)
    {
        // Exit condition
        if (head == NULL) {
            return true;
        }
        // Calculation
        if (head->left != NULL && head->left->val >= head->val) {
            return false;
        }
        if (head->right != NULL && head->right->val >= head->val) {
            return false;
        }
        // Recursion
        return isHeatRecursive(head->left) && isHeatRecursive(head->right);
    }

    bool isSearchTreeRecursive(TreeItem* head)
    {
        // Exit condition
        if (head == NULL) {
            return true;
        }
        // Calculation
        if (head->left != NULL && head->left->val >= head->val) {
            return false;
        }
        if (head->right != NULL && head->right->val <= head->val) {
            return false;
        }
        // Recursion
        return isSearchTreeRecursive(head->left) && isSearchTreeRecursive(head->right);
    }
};