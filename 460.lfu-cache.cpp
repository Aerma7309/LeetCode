/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class LFUCache
{
    struct CacheNode
    {
        int key, value, frequency;
        CacheNode(int k, int d, int f)
        {
            key = k, value = d, frequency = f;
        }
    };

    int size;

    map<int, list<CacheNode *>> data;
    map<int, list<CacheNode *>::iterator> cache;
    void increment(int key)
    {

        CacheNode *old = *(cache[key]);
        CacheNode *node = new CacheNode(old->key, old->value, old->frequency + 1);
        data[old->frequency + 1].push_front(node);
        data[old->frequency].erase(cache[key]);
        cache[key] = data[old->frequency + 1].begin();
        if (data[old->frequency].empty())
            data.erase(old->frequency);
        delete old;
    }

public:
    LFUCache(int capacity)
    {
        size = capacity;
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end())
            return -1;
        increment(key);
        return (*cache[key])->value;
    }

    void put(int key, int value)
    {
        if (size == 0)
            return;
        if (cache.find(key) != cache.end())
        {
            (*cache[key])->value = value;
            increment(key);
        }
        else
        {
            if (cache.size() == size)
            {
                int key = (*(data.begin()->second.rbegin()))->key;
                CacheNode *old = *(cache[key]);
                cache.erase(key);
                (data.begin()->second).pop_back();
                delete old;
            }
            CacheNode *node = new CacheNode(key, value, 1);
            data[1].push_front(node);
            cache[key] = data[1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
