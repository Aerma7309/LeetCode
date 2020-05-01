// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        long long lb = 1, ub = n, mid;
        int res = -1;
        while (lb <= ub)
        {
            mid = (lb + ub) / 2;
            if (isBadVersion(mid))
            {
                res = mid;
                ub = mid - 1;
            }
            else
                lb = mid + 1;
        }
        return res;
    }
};