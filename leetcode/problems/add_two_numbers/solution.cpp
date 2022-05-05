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
    /*
        TO NOTE-
        1. see qn example carefully , what is the structure
        2. how to use new keyword
        3. see nullity when doing next
        4. when to create new node
        5. don't forget to add last carry if present
        
    */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0), *cur = head;
        int carry = 0;
        while(l1 || l2)
        {
            int v1 = l1 ? l1 -> val : 0;
            int v2 = l2 ? l2 -> val : 0;
            
            ListNode * nxt = new ListNode((v1 + v2 + carry) % 10);
            cur -> next = nxt;
            cur = cur -> next;
            carry = (v1 + v2 + carry) / 10;
            
            if(l1)
                l1 = l1 -> next;
            if(l2)
                l2 = l2 -> next;
            
        }
        if(carry)
            cur -> next = new ListNode(carry);
        
        head = head -> next;
        
        return head;
    }
};