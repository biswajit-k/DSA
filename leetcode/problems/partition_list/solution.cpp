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
        
        if(!head)
            return nullptr;

        ListNode dummy = ListNode(), *slow = &dummy, *fast = &dummy;
        dummy.next = head;

        ListNode *temp;
        while(fast -> next)
        {
            if(fast -> next -> val >= x)
            {
                fast = fast -> next;
                continue;
            }
            temp = fast -> next;
            fast -> next = temp -> next;
            temp -> next = slow -> next;
            slow -> next = temp;
            slow = slow -> next;
            if(fast -> next  == temp)
                fast = fast -> next;
        }

        return dummy.next;
    }
};