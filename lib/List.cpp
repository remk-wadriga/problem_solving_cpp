#include <iostream>

template<typename T>
class List
{
public:
    List()
    {
        _head = NULL;
        _size = 0;
    }
    List(T nodes[], const int size)
    {
        _head = NULL;
        _size = 0;
        for (int i = size - 1; i >= 0; i--) {
        	push_front(nodes[i]);
        }
    }
    ~List()
    {
        clear();
    }

    T& operator[](const int index)
    {
        int i = 0;
        Node* currentNode = _head;
        while (i++ < index && currentNode != NULL) {
            currentNode = currentNode->next;
        }
        T* nullPtr = NULL;
        return currentNode != NULL ? currentNode->data : *nullPtr;
    }

    void push_front(T data)
    {
        _size++;
        _head = new Node(data, _head);
    }

    void push_back(T data)
    {
        _size++;
        Node* newNode = new Node(data);
        if (_head == NULL) {
            return;
        }

        Node* lastNode = _head;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }

    void pop_front()
    {
        if (_head == NULL) {
            return;
        }
        _size--;
        Node* deletedNode = _head;
        _head = _head->next;
        delete deletedNode;
    }

    void pop_back()
    {
        remove(getSize() - 1);
    }

    void insert(T data, const int index)
    {
        int ind = index;
        if (ind < 0) {
            ind = getSize() + ind;
        }
        if (ind > getSize() || ind < 0) {
            return;
        }
        if (_head == NULL || ind == 0) {
            push_front(data);
            return;
        }

        _size++;
        Node* beforeNode = _head;
        while (--ind > 0 && beforeNode->next != NULL) {
            beforeNode = beforeNode->next;
        }
        beforeNode->next = new Node(data, beforeNode->next);
    }

    void remove(const int index)
    {
        int ind = index;
        if (ind < 0) {
            ind = getSize() + ind - 1;
        }
        if (ind >= getSize() || ind < 0) {
            return;
        }
        if (_head == NULL || ind == 0) {
            pop_front();
            return;
        }

        _size--;
        Node* beforeNode = _head;
        while (--ind > 0 && beforeNode->next != NULL) {
            beforeNode = beforeNode->next;
        }
        Node* deletedNode = beforeNode->next;
        beforeNode->next = deletedNode->next;
        delete deletedNode;
    }

    void clear()
    {
        while (getSize() > 0) {
            pop_front();
        }
    }

    int getSize()
    {
        return _size;
    }
private:
    class Node
    {
    public:
        Node(T data = T(), Node* next = NULL)
        {
            this->data = data;
            this->next = next;
        }
        Node* next;
        T data;
    };

    Node* _head;
    int _size;
};