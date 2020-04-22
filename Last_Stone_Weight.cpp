class Solution
{
public:
    int a, b;
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> q;
        for (auto &i : stones)
            q.push(i);
        while (q.size() > 1)
        {
            a = q.top();
            q.pop();
            b = q.top();
            q.pop();
            if ((a - b) > 0)
                q.push(a - b);
        }

        if (q.empty())
            return 0;
        return q.top();
    }
};