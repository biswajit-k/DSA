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
        
        ListNode dummy, *curr, *prev = &dummy, *temp;
        dummy.next = head;

        for(int i = 0; i < left - 1; i++)
            prev = prev -> next;

        curr = prev -> next;
        ListNode *rev_point = prev;
        for(int i = 0; i < right - left + 1; i++)
        {
            temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }

        rev_point -> next -> next = curr;
        rev_point -> next = prev;

        return dummy.next;
    }
};