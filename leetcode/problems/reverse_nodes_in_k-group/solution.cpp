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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(!head)   return nullptr;

        ListNode *curr = head, *prev = nullptr, *temp;

        int len = 0;
        for(int i = 0; i < k && curr; i++)  
            curr = curr -> next, len++;

        if(len < k) return head;

        curr = head;
        for(int i = 0; i < k && curr; i++)
        {
            temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        head -> next = reverseKGroup(curr, k);
        return prev;
    }
};