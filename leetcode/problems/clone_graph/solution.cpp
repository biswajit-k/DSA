/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    unordered_map<int, Node*> nodes;

    void dfs(Node *curr) {

        Node *curr_ref = nodes[curr -> val];

        for(auto& child: curr -> neighbors)
        {
            Node *child_clone;
            if(!nodes.count(child -> val))
            {
                child_clone = new Node(child -> val);
                nodes[child -> val] = child_clone;
                dfs(child);
            }
            else 
                child_clone = nodes[child -> val];
                
            (curr_ref -> neighbors).push_back(child_clone);
        }

    }

    Node* cloneGraph(Node* node) {
        
        if(!node)
            return nullptr;

        Node *root = new Node(node -> val);
        nodes[node -> val] = root;

        dfs(node);        

        return root;
    }
};





