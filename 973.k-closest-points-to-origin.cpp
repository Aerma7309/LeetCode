/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
class Solution
{
public:
    class mycomprator
    {
    public:
        bool operator()(pair<int, int> &a, pair<int, int> &b)
        {
            return (a.first * a.first + a.second * a.second) < (b.first * b.first + b.second * b.second);
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomprator> pq;
        for (auto &i : points)
        {
            pq.emplace(i[0], i[1]);
            if (pq.size() > K)
                pq.pop();
        }
        cout << pq.size();
        vector<vector<int>> res(0, vector<int>(2));
        while (!pq.empty())
        {
            const pair<int, int> &tmp = pq.top();
            res.push_back(vector<int>{tmp.first, tmp.second});
            pq.pop();
        }
        return res;
    }
};
// @lc code=end
