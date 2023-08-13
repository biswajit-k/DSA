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
    
    int double_list(ListNode *head)
    {
        if(!head)
            return 0;
        
        int carry = double_list(head -> next);
        int v = carry + 2 * (head -> val);
        
        head -> val = v % 10;
        return v / 10;
    }
    
    ListNode* doubleIt(ListNode* head) {
        
        ListNode front;
        front.next = head;
        
        int final_carry = double_list(head);
        
        if(final_carry)
        {
            ListNode *first_node = new ListNode(final_carry);
            first_node -> next = head;
            front.next = first_node;
        }
     
        return front.next;
    }
};