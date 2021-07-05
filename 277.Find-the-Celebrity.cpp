// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution
{
public:
    /**
     * @param n a party with n people
     * @return the celebrity's label or -1
     */
    int findCelebrity(int n)
    {
        int lb = 0, ub = n - 1;
        while (lb < ub)
        {
            if (knows(lb, ub))
                lb++;
            else
                ub--;
        }
        // lb is candidate for being celebrity
        for (int i = 0; i < n; i++)
            if (lb != i and (knows(lb, i) or not knows(i, lb)))
                return -1;

        return lb;
    }
};