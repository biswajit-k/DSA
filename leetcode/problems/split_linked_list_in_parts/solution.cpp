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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        vector<ListNode*> res;

        int len = 0;
        ListNode *curr = head;
        while(curr)
            len++, curr = curr -> next;
        
        curr = head;
        for(int i = 0; i < k; i++)
        {
            ListNode *part_head = curr;
            int moves = len / k + (len % k > i);

            for(int j = 0; j < moves; j++)
            {
                if(j == moves - 1)
                {
                    ListNode *temp = curr -> next;
                    curr -> next = nullptr;
                    curr = temp;
                }
                else
                    curr = curr -> next;
            }

            res.push_back(part_head);
        }

        return res;
    }
};