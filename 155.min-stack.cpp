/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
public:
    // vector<int> v;
    // /** initialize your data structure here. */
    // MinStack()
    // {
    // }

    // void push(int x)
    // {
    //     v.push_back(x);
    // }

    // void pop()
    // {
    //     v.pop_back();
    // }

    // int top()
    // {
    //     return v[v.size() - 1];
    // }

    // int getMin()
    // {
    //     int ans = INT32_MAX;
    //     for (auto i : v)
    //         ans = min(ans, i);
    //     return ans;
    // }

    stack<pair<int, int>> s;
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        if (s.empty())
            s.push({x, x});
        else
            s.push({x, min(x, s.top().second)});
    }

    void pop()
    {
        s.pop();
    }

    int top()
    {
        return s.top().first;
    }

    int getMin()
    {
        return s.top().second;
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
// @lc code=end

