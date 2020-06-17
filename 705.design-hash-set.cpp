/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */

// @lc code=start
class MyHashSet
{
public:
    /** Initialize your data structure here. */
    vector<bool> hash;
    MyHashSet()
    {
        hash.resize(1000005, 0);
    }

    void add(int key)
    {
        hash[key] = true;
    }

    void remove(int key)
    {
        hash[key] = false;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        return hash[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end
