class MinStack
{
public:
    vector<int> v;
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        v.push_back(x);
    }

    void pop()
    {
        v.pop_back();
    }

    int top()
    {
        return v[v.size() - 1];
    }

    int getMin()
    {
        int ans = INT32_MAX;
        for (auto i : v)
            ans = min(ans, i);
        return ans;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */