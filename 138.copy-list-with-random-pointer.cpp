/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;
        map<Node *, Node *> m;
        Node *temp = head;
        Node *newHead = new Node(temp->val);
        Node *newTail = newHead;
        m[temp] = newHead;
        while (temp->next)
        {
            newTail->next = new Node(temp->next->val);
            m[temp->next] = newTail->next;
            temp = temp->next;
            newTail = newTail->next;
        }
        temp = head;
        Node *rhead = newHead;
        while (temp)
        {
            if (temp->random)
                rhead->random = m[temp->random];
            else
                rhead->random = nullptr;
            temp = temp->next;
            rhead = rhead->next;
        }
        return newHead;
    }
};
// @lc code=end
