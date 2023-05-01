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
    bool isPalindrome(ListNode* head) {
        
        ListNode *fast = head, *slow = head;

        while(fast && fast -> next)
            fast = fast -> next -> next, slow = slow -> next;

        ListNode *temp;
        fast = slow;
        slow = nullptr;

        while(fast)
        {
            temp = fast -> next;
            fast -> next = slow;
            slow = fast;
            fast = temp;
        }
        while(slow && slow != head)
        {
            if(slow -> val != head -> val)
                return false;
            slow = slow -> next;
            head = head -> next;
        }

        return true;
    }
};