/*
 * @lc app=leetcode id=1171 lang=cpp
 *
 * [1171] Remove Zero Sum Consecutive Nodes from Linked List
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode;
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        int sum = 0, cnt = 0;
        set<int> m;
        m.insert(0);
        stack<pair<ListNode *, int>> s;
        // q.push({nullptr, 0});
        for (ListNode *curr = head; curr; curr = curr->next)
        {
            sum += curr->val;
            if (m.count(sum))
            {
                while (not s.empty() and s.top().second != sum)
                    m.erase(s.top().second), s.pop(); //m.find(s.top().second)
                if (not s.empty())
                    s.top().first->next = curr->next;
            }
            else
                s.push({curr, sum});
            m.insert(sum);
        }
        while (s.size() > 1)
            s.pop();
        if (s.empty())
            return nullptr;
        return s.top().first;
    }
};
// @lc code=end
