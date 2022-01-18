/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
        
    bool doit(ListNode *head){
        if(head -> val == int(1e6))
            return true;
        auto after = head -> next;
        if(after == NULL)
            return false;
        head -> val = int(1e6);
        return doit(after);
    }
    
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        return doit(head);
    }
};