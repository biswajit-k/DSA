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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head || !(head -> next))
            return head;
        
        head -> next = deleteDuplicates(head -> next);
        ListNode *temp;
        if(head -> val == head -> next -> val)
        {
            temp = head -> next;
            head -> next = head -> next -> next;
            delete temp;
        }
        
        return head;
    }
};