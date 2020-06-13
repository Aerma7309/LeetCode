/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */
// #include <bits/stdc++.h>
// @lc code=start
class RandomizedSet
{
public:
    /** Initialize your data structure here. */

    // unordered_set<int> s;

    // RandomizedSet()
    // {
    //     srand(time(NULL));
    // }

    // /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    // bool insert(int val)
    // {
    //     if (s.find(val) == s.end())
    //     {
    //         s.insert(val);
    //         return true;
    //     }
    //     return false;
    // }

    // /** Removes a value from the set. Returns true if the set contained the specified element. */
    // bool remove(int val)
    // {
    //     if (s.find(val) != s.end())
    //     {
    //         s.erase(val);
    //         return true;
    //     }
    //     return false;
    // }

    // /** Get a random element from the set. */
    // int getRandom()
    // {
    //     int r = rand() % s.size();
    //     auto a = s.begin();
    //     advance(a,r);
    //     return *a;
    // }

    unordered_map<int, int> m;
    vector<int> l;
    RandomizedSet()
    {
        srand(time(NULL));
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (m.find(val) == m.end())
        {
            l.emplace_back(val);
            m[val] = l.size() - 1;
            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (m.find(val) != m.end())
        {
            int index = m[val];
            l[index] = l.back();
            m[l.back()] = index;
            l.pop_back();
            m.erase(val);
            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        return l[rand() % l.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
