/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */

// @lc code=start

class MyLinkedList
{
public:
    class Node
    {
    public:
        int val;
        Node *next;
        Node(int data)
        {
            val = data;
            next = nullptr;
        }
        ~Node(){};
    };
    Node *Head;
    Node *Tail;
    int size;
    /** Initialize your data structure here. */
    MyLinkedList()
    {
        Head = nullptr;
        Tail = nullptr;
        size = 0;
    }
    ~MyLinkedList() {}
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if (index >= size)
            return -1;
        Node *temp = Head;
        while (index > 0)
        {
            temp = temp->next;
            --index;
        }
        return temp->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
            Head = Tail = temp;
        else
        {
            temp->next = Head;
            Head = temp;
        }
        ++size;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
            Head = Tail = temp;
        else
        {
            Tail->next = temp;
            Tail = temp;
        }
        ++size;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index > size)
            return;
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        if (index == size)
        {
            addAtTail(val);
            return;
        }
        Node *temp = Head;
        while (index > 1)
        {
            temp = temp->next;
            --index;
        }
        Node *newnode = new Node(val);
        newnode->next = temp->next;
        temp->next = newnode;
        ++size;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index >= size)
            return;
        if (index == 0)
        {
            Node *temp = Head;
            Head = Head->next;
            delete temp;
        }
        else
        {
            Node *temp = Head;
            while (index > 1)
            {
                temp = temp->next;
                --index;
            }
            if (temp->next == Tail)
                Tail = temp;
            Node *toDel = temp->next;
            temp->next = toDel->next;
            delete toDel;
        }
        --size;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
