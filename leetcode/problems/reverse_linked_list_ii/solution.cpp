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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        
        ListNode *curr = head;
        for(int i = 0; i < left - 1; i++)
            curr = curr -> next;
        
        ListNode *prev = nullptr;
        
        for(int i = 0; i < right - left + 1; i++)
        {
            ListNode *temp = curr -> next;
            curr -> next = prev;
            
            prev = curr;
            curr = temp;
        }
               
        if(left == 1)
            head = prev;
        else
        {
            ListNode *mover = head;
            for(int i = 0; i < left - 2; i++)   mover = mover -> next;
            mover -> next = prev;   
        }
        
        ListNode *mover = prev;
        while(prev -> next)
            prev = prev -> next;
        prev -> next = curr;
            
        return head;
    }
};