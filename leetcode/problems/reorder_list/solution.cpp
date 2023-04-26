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
    void reorderList(ListNode* head) {
        
        ListNode *head1 = head, *head2 = head;

        while(head2 && head2 -> next) 
        {
            head2 = head2 -> next -> next;
            head1 = head1 -> next;
        }

        // reverse list from head1 part, head1 behaves as 'curr'
        ListNode *prev = nullptr, *temp;

        while(head1)
        {
            temp = head1 -> next;
            head1 -> next = prev;
            prev = head1;
            head1 = temp;
        }
        head2 = prev;
        head1 = head;

        while(head2 && head1 != head2)
        {
            temp = head1 -> next;
            head1 -> next = head2;

            head1 = temp;

            temp = head2 -> next;
            if(head2 -> next)
                head2 -> next = head1;
            head2 = temp;
        }

    }
};