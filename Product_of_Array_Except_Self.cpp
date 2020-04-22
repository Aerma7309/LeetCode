class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int p = 1, cz = 0;
        for (auto i : nums)
        {
            if (i)
                p *= i;
            else
                cz++;
        }
        vector<int> v(nums.size());
        if (cz > 1)
            return v;
        else if (cz == 1)
        {
            int i = find(nums.begin(), nums.end(), 0) - nums.begin();
            v[i] = p;
        }
        else
        {
            for (int i = 0; i < nums.size(); i++)
                v[i] = p / nums[i];
        }
        return v;
    }
};