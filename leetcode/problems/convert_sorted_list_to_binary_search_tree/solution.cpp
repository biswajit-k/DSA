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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* helper(ListNode* curr, int n) {
        
        if(n == 0)  return nullptr;
        
        int mid = (n + 1) / 2;
        ListNode *trav = curr;
        for(int i = 0; i < mid - 1; i++)  trav = trav -> next;
        
        TreeNode *root = new TreeNode(trav -> val);
        
        root -> left = helper(curr, mid - 1);
        root -> right = helper(trav -> next, n - mid);
        
        return root;
    }
    
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        int n = 0;
        ListNode *trav = head;
        while(trav) trav = trav -> next, n++;
        
        return helper(head, n);
    }
};