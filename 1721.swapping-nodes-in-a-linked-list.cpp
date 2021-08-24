/*
 * @lc app=leetcode id=1721 lang=cpp
 *
 * [1721] Swapping Nodes in a Linked List
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
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *preFirst = nullptr, *first = head;
        int cnt = 1;
        for (; cnt < k and first; cnt++)
            preFirst = first, first = first->next;
        ListNode *preSecond = nullptr, *second = head, *iter = first->next;
        for (; iter; cnt++)
            preSecond = second, second = second->next, iter = iter->next;

        if (preFirst)
            preFirst->next = second;
        if (preSecond)
            preSecond->next = first;
            
        swap(first->next, second->next);

        if (k == 1)
            return second;
        if (k == cnt)
            return first;
        return head;
    }
};
// @lc code=end
