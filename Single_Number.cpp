class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int xr = 0;
        for (auto &i : nums)
        {
            xr ^= i;
        }
        return xr;
    }
};