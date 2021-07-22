/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    // {
    //     set<ListNode *> vis;
    //     while (headA)
    //         vis.insert(headA), headA = headA->next;
    //     while (headB)
    //     {
    //         if (vis.find(headB) != vis.end())
    //             return headB;
    //         headB = headB->next;
    //     }
    //     return nullptr;
    // }

    int countListNode(ListNode *root)
    {
        int cnt = 0;
        while (root)
        {
            cnt++;
            root = root->next;
        }
        return cnt;
    }
    ListNode *getIntersectionNodeHelper(ListNode *headA, ListNode *headB, int l1, int l2)
    {
        if (l1 < l2)
            return getIntersectionNodeHelper(headB, headA, l2, l1);
        for (int i = 0; i < l1 - l2; i++)
            headA = headA->next;
        while (headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int l1 = countListNode(headA);
        int l2 = countListNode(headB);
        return getIntersectionNodeHelper(headA, headB, l1, l2);
    }
};
// @lc code=end
