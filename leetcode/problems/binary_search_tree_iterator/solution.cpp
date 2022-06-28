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
class BSTIterator {
public:
    
    stack<TreeNode*> st;
    TreeNode* curr;
    
    BSTIterator(TreeNode* root) {
       curr = root;
    }
    
    int next() {
      
        while(curr && curr -> left)
        {
            st.push(curr);
            curr = curr -> left;
        }
        
        if(!curr)
        {
            curr = st.top();
            st.pop();
        }
        
        int x = curr -> val;
        
        curr = curr -> right;
        return x;
        
    }
    
    bool hasNext() {
        return (curr || !st.empty());
    }
};

/*
    - push curr_node
    - if left_node exist
        - curr_node = curr -> left
    - else 
        - visit curr_node
        if right_node exist
            - curr_node = curr -> right 
        else 
            - visit nearest_unvisited_parent
            
    while(curr && curr -> left exist)
        st.push(curr)
        curr = curr -> left;
        
    if(!curr)
        curr = st.top()
        st.pop()
        
    print(curr)
    
    curr = curr -> right

*/



/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


