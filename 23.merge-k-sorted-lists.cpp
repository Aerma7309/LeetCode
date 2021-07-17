/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto ListNodecomparator = [&](ListNode *a, ListNode *b)
        { return a->val > b->val; };
        priority_queue<ListNode *, vector<ListNode *>, decltype(ListNodecomparator)> pq(ListNodecomparator);
        for (auto &list : lists)
            if (list)
                pq.push(list);
        ListNode *dummy, *end;
        dummy = end = new ListNode(-1);
        while (not pq.empty())
        {
            ListNode *node = pq.top();
            pq.pop();
            end->next = node;
            end = end->next;
            if (node->next)
                pq.push(node->next);
        }
        end->next = nullptr;
        return dummy->next;
    }
};
// @lc code=end
