class Solution
{
public:
    int longestOnes(vector<int> &A, int K=1)
    {
        int i = 0, j = 0, size = A.size();
        for (i = 0; i < size; i++)
        {

            if (A[i] == 0)
                K--;
            if (K < 0)
            {
                if (A[j] == 0)
                    K++;
                j++;
            }
        }
        return i - j;
    }
};