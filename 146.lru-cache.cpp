/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
public:
    list<pair<int, int>> cache;
    map<int, list<pair<int, int>>::iterator> keylist;
    int size;
    LRUCache(int capacity)
    {
        size = capacity;
    }

    void update(int key, int value)
    {
        cache.erase(keylist[key]);
        cache.push_front({key, value});
        keylist[key] = cache.begin();
    }

    int get(int key)
    {
        if (keylist.find(key) != keylist.end())
        {
            update(key, keylist[key]->second);
            return keylist[key]->second;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (keylist.find(key) != keylist.end())
            update(key, value);
        else
        {
            cache.push_front({key, value});
            keylist[key] = cache.begin();
            if (cache.size() > size)
            {
                keylist.erase(cache.back().first);
                cache.pop_back();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

