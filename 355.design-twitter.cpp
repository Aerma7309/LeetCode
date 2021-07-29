/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Twitter
{
    map<int, set<int>> following;
    vector<pair<int, int>> tweets;

public:
    /** Initialize your data structure here. */
    Twitter()
    {
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        if (following[userId].empty())
            following[userId].insert(userId);
        tweets.push_back({userId, tweetId});
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        if (following[userId].empty())
            following[userId].insert(userId);
        vector<int> res;
        for (int i = tweets.size() - 1; i >= 0 and res.size() < 10; i--)
        {
            if (following[userId].find(tweets[i].first) != following[userId].end()) // found someone whom user is following
                res.push_back(tweets[i].second);
        }
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)
    {
        if (following[followerId].empty())
            following[followerId].insert(followerId);
        if (following[followerId].find(followeeId) == following[followerId].end())
            following[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId)
    {
        if (following[followerId].empty())
            following[followerId].insert(followerId);
        if (following[followerId].find(followeeId) != following[followerId].end())
            following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end
