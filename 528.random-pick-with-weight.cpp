/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 */

// @lc code=start
typedef long long ll;
class Solution
{
    vector<ll> v;

public:
    Solution(vector<int> &w)
    {
        srand(time(0));
        v.reserve(w.size());
        ll sum = 0;
        for (auto &i : w)
        {
            sum += i;
            v.emplace_back(sum);
        }
    }

    int pickIndex()
    {
        int rno = rand() % v.back();
        return upper_bound(v.begin(),v.end(),rno)-v.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * ll param_1 = obj->pickIndex();
 */
// @lc code=end
