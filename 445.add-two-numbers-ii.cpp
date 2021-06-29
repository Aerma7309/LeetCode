/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> s1, s2;
        while (l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }
        ListNode *res = nullptr;
        int carry = 0;

        while (not s1.empty() and not s2.empty())
        {
            int sum = s1.top() + s2.top() + carry;
            carry = sum / 10;
            sum %= 10;
            ListNode *node = new ListNode(sum);
            node->next = res;
            res = node;
            s1.pop();
            s2.pop();
        }

        while (not s1.empty())
        {
            int sum = s1.top() + carry;
            carry = sum / 10;
            sum %= 10;
            ListNode *node = new ListNode(sum);
            node->next = res;
            res = node;
            s1.pop();
        }
        while (not s2.empty())
        {
            int sum = s2.top() + carry;
            carry = sum / 10;
            sum %= 10;
            ListNode *node = new ListNode(sum);
            node->next = res;
            res = node;
            s2.pop();
        }
        if (carry)
        {
            ListNode *node = new ListNode(carry);
            node->next = res;
            res = node;
        }
        return res;
    }
};
// @lc code=end
