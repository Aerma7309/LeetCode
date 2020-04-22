class Solution
{
public:
    int sum = 0, res = 0;
    map<int, int> m;
    int findMaxLength(vector<int> &nums)
    {
        m[0] = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i])
                ++sum;
            else
                --sum;
            auto f = m.find(sum);
            if (f != m.end())
                res = max(res, i - m[sum]);
            else
                m[sum] = i;
        }
        return res;
    }
};