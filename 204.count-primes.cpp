/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n <= 2)
            return 0;
        int res = 1;
        vector<bool> sieve(n + 5);
        for (int i = 3; i <= (int)sqrt(n); i += 2)
            if (not sieve[i])
                for (int j = i * i; j <= n; j += i)
                    sieve[j] = true;

        for (int i = 3; i < n; i += 2)
            if (not sieve[i])
                res++;
        return res;
    }
};
// @lc code=end
