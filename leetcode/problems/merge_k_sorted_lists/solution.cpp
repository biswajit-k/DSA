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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode dummy, *curr = &dummy, *temp;

        auto comp = [](ListNode *l1, ListNode *l2) {
            if(l1 -> val > l2 -> val)
                return true;
            return false;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);

        for(auto& lst: lists)
            if(lst)
                pq.push(lst);

        while(pq.size() > 1)
        {
            temp = pq.top();
            pq.pop();

            curr -> next = temp;
            temp = temp -> next;

            if(temp)
                pq.push(temp);
            
            curr = curr -> next;
        }

        if(pq.size())
            curr -> next = pq.top();

        curr = dummy.next ? dummy.next : nullptr;

        return curr;
    }
};