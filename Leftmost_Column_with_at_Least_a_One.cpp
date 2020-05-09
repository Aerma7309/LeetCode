class Solution
{
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix)
    {
        vector<int> v = binaryMatrix.dimensions();
        int i = v[0] - 1, j = v[1] - 1, res = -1;
        while (true)
        {
            if (binaryMatrix.get(i, j))
            {
                res = j;
                if (j == 0)
                    break;
                j--;
            }
            else
            {
                if (i == 0)
                    break;
                i--;
            }
        }
        return res;
    }
};