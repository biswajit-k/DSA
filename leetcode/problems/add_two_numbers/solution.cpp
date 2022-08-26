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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *head = new ListNode(0), *curr = head;
        int carry = 0;
        
        while(l1 || l2)
        {
            int v1 = l1 ? l1 -> val : 0;
            int v2 = l2 ? l2 -> val : 0;
            
            curr -> val = (v1 + v2 + carry) % 10;
            carry = (v1 + v2 + carry) / 10;
            
            if(l1) l1 = l1 -> next;
            if(l2) l2 = l2 -> next;
            
            if(l1 || l2 || carry)
            {
                curr -> next = new ListNode(0);
                curr = curr -> next;
            }       
            
        }
        if(carry)   curr -> val = carry;
        
        return head;   
    }
};