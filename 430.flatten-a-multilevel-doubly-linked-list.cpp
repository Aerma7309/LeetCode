/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
    Node *flatten(Node *head)
    {
        if (!head)
            return nullptr;
        stack<Node *> s;
        Node *temp = head;
        while (temp->next or temp->child or !s.empty())
        {
            if (temp->child)
            {
                if (temp->next)
                    s.push(temp->next);
                temp->next = temp->child;
                temp->child = nullptr;
                temp->next->prev = temp;
                temp = temp->next;
            }
            else if (temp->next)
                temp = temp->next;
            else
            {
                Node *n = s.top();
                s.pop();
                temp->next = n;
                n->prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};
// @lc code=end
