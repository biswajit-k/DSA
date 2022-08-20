/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    void doit(Node* child, Node* par)
    {
        if(!par)
        {
            child -> next = nullptr;
            return;
        }
        
        if(par -> left != child)
        {
            child -> next = par -> left;
            child = child -> next;
        }
        
        else
        {
            child -> next = par -> right;
            par = par -> next;
            child = child -> next;
        }
        
        doit(child, par);
    }
    
    Node* connect(Node* root) {
        
        if(!root)   return root;
        
        root -> next = nullptr;
        
        Node* curr = root;
        
        while(curr -> left)
        {
            // Node* now = curr;
            doit(curr -> left, curr);
            curr = curr -> left;
        }
        
        return root;
    }
};