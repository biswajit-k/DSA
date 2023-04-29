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

class Solution {
public:

    Node* dfs(Node* curr) {
    
        Node* child = curr -> child;
        curr -> child = nullptr;
        if(child)
        {
            Node *c_tail = dfs(child);
            c_tail -> next = curr -> next;
            curr -> next = child;
            child -> prev = curr;
            if(c_tail -> next)
            {
                c_tail -> next -> prev = c_tail;
                return dfs(c_tail -> next);
            }
            return c_tail;
        }
        if(curr -> next)
            return dfs(curr -> next);
        return curr;
    }

    Node* flatten(Node* head) {
        if(!head)
            return head;
        dfs(head);
        return head;
    }
};