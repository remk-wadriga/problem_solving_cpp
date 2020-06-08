#include <iostream>

template<typename Key, typename Value>
class HashMap
{
public:
    HashMap()
    {
        _head = NULL;
    }
    ~HashMap()
    {

    }

    void add(Key key, Value val)
    {
        using namespace std;

        Node* newNode = new Node(str2int(getHash(key)), val);
        if (_head == NULL) {
            _head = newNode;
        } else {
            addToSearchTreeRecursive(_head, newNode);
        }
    }

    Value* get(Key key)
    {
        Node* node = findItemByKeyRecursive(_head, str2int(getHash(key)));
        return node != NULL ? &node->val : NULL;
    }

    std::string getHash(std::string val, unsigned int length = 16)
    {
        using namespace std;

        unsigned int minLength = 2, realMinLength = 0;

        unsigned int originalSalt = getControlSum(val);
        unsigned int originalStringLength = val.size();

        while (minLength <= length) {
            realMinLength = (minLength *= 2);
        }

        while (minLength <= originalStringLength) {
            minLength *= 2;
        }

        if ((minLength - originalStringLength) < minLength) {
            minLength *= 2;
        }

        for (int i = 0; i < (minLength - originalStringLength); i++) {
        	val += receivingExistCodes(val[i] + val[i + 1]);
        }

        unsigned int maxSalt = getControlSum(val);
        unsigned int vaxStringLength = val.size();

        string hash = "";
        while (val.size() != realMinLength) {
            for (int i = 0, center = val.size() / 2; i < center; i++) {
                hash += receivingExistCodes(val[center - i] + val[center + i]);
            }
            val = hash;
            hash.clear();
        }

        unsigned int rem = realMinLength - length;
        for (int i = 0, countCompress = realMinLength / rem; hash.size() < (length - 4); i++) {
            hash += (i % countCompress == 0 ? receivingExistCodes(val[i] + val[++i]) : val[i]);
        }

        hash += receivingExistCodes(originalSalt);
        hash += receivingExistCodes(originalStringLength);
        hash += receivingExistCodes(maxSalt);
        hash += receivingExistCodes(vaxStringLength);

        return hash;
    }
private:
    struct Node
    {
        Node(unsigned long int key, Value val = Value(), Node* left = NULL, Node* right = NULL)
        {
            this->key = key;
            this->val = val;
            this->left = left;
            this->right = right;
        }
        unsigned long int key;
        Value val;
        Node* left;
        Node* right;
    };
    Node* _head;

    void addToSearchTreeRecursive(Node* head, Node* newVal)
    {
        // Exit condition
        if (head == NULL || head->key == newVal->key) {
            return;
        }

        if (newVal->key < head->key) {
            if (head->left == NULL) {
                head->left = newVal;
            } else if (newVal->key > head->left->key) {
                if (head->left->right != NULL && getMaxValRecursive(head->left->right) >= newVal->key) {
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
            } else if (newVal->key < head->right->key) {
                if (head->right->left != NULL && getMinValRecursive(head->right->left) <= newVal->key) {
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

    Node* findItemByKeyRecursive(Node* head, unsigned long int key)
    {
        // Exit condition
        if (head == NULL) {
            return NULL;
        }
        if (head->key == key) {
            return head;
        }
        // Recursion
        if (key < head->key) {
            return findItemByKeyRecursive(head->left, key);
        } else {
            return findItemByKeyRecursive(head->right, key);
        }
    }

    unsigned long int str2int(std::string code)
    {
        int codeLength = code.length();
        unsigned long int result = 0;
        for (int i = 0; i < codeLength; i++) {
        	result = result * 10 + (code[i] - '0');
        }
        return result;
    }

    int receivingExistCodes(int x)
    {
        x += 256;
        while (!((x >= 48 && x <= 57) || (x >= 65 && x <= 90) || (x >= 97 && x <= 122))) {
            x += (x < 48 ? 24 : -47);
        }
        return x;
    }

    unsigned int getControlSum(std::string str)
    {
        unsigned int salt = 0;
        for (unsigned int len = 0; len < str.size(); len++) {
            salt += int(str[len]);
        }
        return salt;
    }

    unsigned long int getMaxValRecursive(Node* head)
    {
        // Exit condition
        if (head == NULL) {
            return 0;
        }
        // Recursion
        unsigned long int leftMax = getMaxValRecursive(head->left);
        unsigned long int rightMax = getMaxValRecursive(head->right);
        // Calculating
        unsigned long int maxVal = head->key;
        if (head->left != NULL && leftMax > maxVal) {
            maxVal = leftMax;
        }
        if (head->right != NULL && rightMax > maxVal) {
            maxVal = rightMax;
        }
        return maxVal;
    }

    long getMinValRecursive(Node* head)
    {
        // Exit condition
        if (head == NULL) {
            return 0;
        }
        // Recursion
        unsigned long int leftMin = getMinValRecursive(head->left);
        unsigned long int rightMin = getMinValRecursive(head->right);
        // Calculating
        unsigned long int minVal = head->key;
        if (head->left != NULL && leftMin < minVal) {
            minVal = leftMin;
        }
        if (head->right != NULL && rightMin < minVal) {
            minVal = rightMin;
        }
        return minVal;
    }
};