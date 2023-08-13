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
    
    string twice_str(string& s) {
        
        string res = "";
        int carry = 0;
        
        for(int i = s.length() - 1; i > -1; i--)
        {
            int digit = s[i] - '0';
            res += '0' + (digit * 2 + carry) % 10;
            carry = (digit * 2 + carry) / 10;
        }
        
        if(carry)
            res += '0' + carry;
    
        reverse(begin(res), end(res));
        
        return res;
    }
    
    ListNode* doubleIt(ListNode* head) {
     
        string num = "";
        
        ListNode *curr = head;
        
        while(curr)
        {
            num += curr -> val + '0';
            curr = curr -> next;
        }
        
        string s_num = twice_str(num);
        // cout << s_num[0] << '\n';
        
        ListNode *new_head = new ListNode(s_num[0] - '0');
        curr = new_head;
        
        for(int i = 1; i < s_num.length(); i++)
        {
            ListNode *nxt = new ListNode(s_num[i] - '0');
            curr -> next = nxt;
            curr = nxt;
        }
        curr -> next = nullptr;
        
        return new_head;
    }
};