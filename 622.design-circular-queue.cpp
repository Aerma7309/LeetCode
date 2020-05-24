/*
 * @lc app=leetcode id=622 lang=cpp
 *
 * [622] Design Circular Queue
 */

// @lc code=start
class MyCircularQueue
{
    vector<int> q;
    int size;
    int capacity;
    int start_index;
    int end_index;

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k)
    {
        q.resize(k);
        capacity = k;
        size = 0;
        start_index = 0;
        end_index = k - 1;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value)
    {
        if (size == capacity)
            return false;
        end_index = (end_index + 1) % capacity;
        q[end_index] = value;
        size++;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue()
    {
        if (size == 0)
            return false;
        size--;
        start_index = (start_index + 1) % capacity;
        return true;
    }

    /** Get the front item from the queue. */
    int Front()
    {
        if (size == 0)
            return -1;
        return q[start_index];
    }

    /** Get the last item from the queue. */
    int Rear()
    {
        if (size == 0)
            return -1;
        return q[end_index];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty()
    {
        return size == 0;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull()
    {
        return size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end
