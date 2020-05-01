class Solution
{
public:
    int rangeBitwiseAnd(int m, int n)
    {
        int res = 0;
        for (int i = 30; i >= 0; i--)
        {
            if ((m & (1 << i)) == (n & (1 << i)))
                res |= (m & (1 << i));
            else
                break;
        }
        return res;
    }
};