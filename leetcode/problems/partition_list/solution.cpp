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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode dummy;
        ListNode *prefix = &dummy;
        prefix -> next = head;
        
        ListNode *curr = head;
        
        //Extend prefix until value smaller than x is found
        while(curr && curr -> val < x)
        {
            prefix -> next = curr;
            prefix = curr;
            curr = curr -> next;
        }
        
        // now curr either points to value >= x or end of list
        while(curr && curr -> next)
        {
            if(curr -> next -> val >= x)
                curr = curr -> next;
            
            // else pick-out the value and place in the left partition
            else 
            {
                ListNode *temp = prefix -> next;
                prefix -> next = curr -> next;
                curr -> next = curr -> next -> next;
                prefix = prefix -> next;
                prefix -> next = temp;
            }
        }
            
        return dummy.next;
    }
};