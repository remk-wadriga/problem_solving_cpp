#include <iostream>
#include <cmath>
#include <vector>
#include "./TreeItem.cpp"
using namespace std;

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

    void print()
    {
        // Get tree width and height
        int height = getHeight();
        int width = getLeafCount();

        // Create a levels array
        vector<string> levels[height + 1];
        fillArrRecursive(levels, width / 2, getHead());

        // Print each level
        for (int i = 0; i < height; i++) {
        	for (int j = 0; j < levels[i].size(); j++) {
        		cout << levels[i][j] << " ";
        	}
        	cout << "\n";
        }
    }

    TreeItem* findItem(int x, int y)
    {
        using namespace std;
        TreeItem* item = getHead();

        if (item == NULL || (x == 0 && y == 0)) {
            return item;
        }

        for (int i = 0; i < y && item != NULL; i++) {
            int width = pow(i, 2);

        }

        return NULL;
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

    int getHeight()
    {
        return getHeightRecursive(getHead());
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

    int getHeightRecursive(TreeItem* head)
    {
        // Exit condition
        if (head == NULL) {
            return 0;
        }
        // Recursion
        int leftHeight = 1 + getHeightRecursive(head->left);
        int rightHeight = 1 + getHeightRecursive(head->right);
        return leftHeight > rightHeight ? leftHeight : rightHeight;
    }

    void fillArrRecursive(vector<string> levels[], int spaces, TreeItem* head, int level = 0)
    {
        // Exit condition
        if (head == NULL) {
            levels[level].push_back("");
            return;
        }

        // Add items to their levels
        for (int i = 0; i < spaces; i++) {
            levels[level].push_back("");
        }
        levels[level].push_back(head->toString());

        // Recursion
        fillArrRecursive(levels, spaces - 1, head->left, level + 1);
        fillArrRecursive(levels, spaces - 1, head->right, level + 1);
    }
};