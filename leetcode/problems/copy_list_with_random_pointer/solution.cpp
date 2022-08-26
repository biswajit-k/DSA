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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(!head)   return nullptr;
        Node *dummy = new Node(head -> val);
        Node *curr_d = dummy, *curr_h = head;
        
        unordered_map<Node*, Node*> link;
        link[head] = dummy;
        
        while(curr_h -> next)
        {
            curr_h = curr_h -> next;
            curr_d -> next = new Node(curr_h -> val);
            curr_d = curr_d -> next;
            
            link[curr_h] = curr_d;
        }
        
        curr_h = head;
        curr_d = dummy;
        
        while(curr_h)
        {
            Node *pointed = curr_h -> random;
            
            if(!pointed)    curr_d -> random = nullptr;
            else curr_d -> random = link[pointed];
            
            curr_h = curr_h -> next;
            curr_d = curr_d -> next;
        }
        
        return dummy;
    }
};