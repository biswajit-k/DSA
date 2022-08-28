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
    
    int get_len(ListNode* l)
    {
        int len = 0;
        while(l)
            l = l -> next, len++;
        return len;
    }
    
    ListNode* add(ListNode *l1, ListNode *l2, int diff)
    {
        if(!l1 || !l2)  return nullptr;
        
        ListNode *nxt;
        
        if(diff)    nxt = add(l1 -> next, l2, diff - 1);
        else    nxt = add(l1 -> next, l2 -> next, diff);
        
        int carry = 0;
        if(nxt)
        {
            carry = (nxt -> val) / 10;
            nxt -> val %= 10;    
        }
        
        ListNode *curr = new ListNode(0);
        if(diff)    curr -> val = carry + l1 -> val;
        else    curr -> val = carry + l1 -> val + l2 -> val;
        
        curr -> next = nxt;
        return curr;
    }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int len1 = get_len(l1), len2 = get_len(l2);
        
        ListNode *res;
        
        if(len1 >= len2)
            res = add(l1, l2, len1 - len2);
        else 
            res = add(l2, l1, len2 - len1);
        
        if(res -> val > 9)
        {
            ListNode *temp = res;
            res = new ListNode((temp -> val) / 10);
            temp -> val %= 10;
            res -> next = temp;
        }
        
        return res;
    }
};