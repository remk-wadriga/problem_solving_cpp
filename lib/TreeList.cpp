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

    int getMaxVal()
    {
        return getMaxValRecursive(getHead());
    }

    int getMinVal()
    {
        return getMinValRecursive(getHead());
    }

    int getItemsCount()
    {
        return getItemsCountRecursive(getHead());
    }

    int getLeafCount()
    {
        return getLeafCountRecursive(getHead());
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

    TreeItem* findItemByVal(int val)
    {
        return findItemByValRecursive(getHead(), val);
    }

    void addToSearchTree(int val)
    {
        addToSearchTreeRecursive(getHead(), new TreeItem(val));
    }
private:
    TreeItem* _headItem;

    int getMaxValRecursive(TreeItem* head)
    {
        // Exit condition
        if (head == NULL) {
            return 0;
        }
        // Recursion
        int leftMax = getMaxValRecursive(head->left);
        int rightMax = getMaxValRecursive(head->right);
        // Calculating
        int maxVal = head->val;
        if (head->left != NULL && leftMax > maxVal) {
            maxVal = leftMax;
        }
        if (head->right != NULL && rightMax > maxVal) {
            maxVal = rightMax;
        }
        return maxVal;
    }

    int getMinValRecursive(TreeItem* head)
    {
        // Exit condition
        if (head == NULL) {
            return 0;
        }
        // Recursion
        int leftMin = getMinValRecursive(head->left);
        int rightMin = getMinValRecursive(head->right);
        // Calculating
        int minVal = head->val;
        if (head->left != NULL && leftMin < minVal) {
            minVal = leftMin;
        }
        if (head->right != NULL && rightMin < minVal) {
            minVal = rightMin;
        }
        return minVal;
    }

    int getItemsCountRecursive(TreeItem* head)
    {
        // Exit condition
        if (head == NULL) {
            return 0;
        }

        // Recursion
        return 1 + getItemsCountRecursive(head->left) + getItemsCountRecursive(head->right);
    }

    int getLeafCountRecursive(TreeItem* head)
    {
        // Exit condition
        if (head == NULL) {
            return 0;
        }

        // Recursion
        int res = getLeafCountRecursive(head->left) + getLeafCountRecursive(head->right);
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
        if (head->left != NULL) {
            if (head->left->val >= head->val) {
                return false;
            }
            if (getMaxValRecursive(head->left) >= head->val) {
                return false;
            }
        }
        if (head->right != NULL) {
            if (head->right->val <= head->val) {
                return false;
            }
            if (getMinValRecursive(head->right) <= head->val) {
                return false;
            }
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

    TreeItem* findItemByValRecursive(TreeItem* head, int val)
    {
        // Exit condition
        if (head == NULL) {
            return NULL;
        }
        if (head->val == val) {
            return head;
        }
        // Recursion
        TreeItem* left = findItemByValRecursive(head->left, val);
        if (left != NULL) {
            return left;
        }
        return findItemByValRecursive(head->right, val);
    }

    void addToSearchTreeRecursive(TreeItem* head, TreeItem* newVal)
    {
        // Exit condition
        if (head == NULL || head->val == newVal->val) {
            return;
        }

        if (newVal->val < head->val) {
            if (head->left == NULL) {
                head->left = newVal;
            } else if (newVal->val > head->left->val) {
                if (head->left->right != NULL && getMaxValRecursive(head->left->right) >= newVal->val) {
                    return;
                }
                newVal->left = head->left;
                head->left = newVal;
            } else {
                // Recursion
                addToSearchTreeRecursive(head->left, newVal);
            }
        } else {
            if (head->right == NULL) {
                head->right = newVal;
            } else if (newVal->val < head->right->val) {
                if (head->right->left != NULL && getMinValRecursive(head->right->left) <= newVal->val) {
                    return;
                }
                newVal->right = head->right;
                head->right = newVal;
            } else {
                // Recursion
                addToSearchTreeRecursive(head->right, newVal);
            }
        }
    }
};