/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/



// Space complexity: O(N) - 106.8 MB, less than 8.51% of C++ online submissions
//  Time complexity: O(V + E) - 58 ms, faster than 8.82% of C++ online submissions
class Solution {
public:
    vector<int> ans;
    
    void simplePreOrder(Node* root){
        if(root == NULL) return;
        
        ans.push_back(root->val);
        
        for(unsigned int i = 0; i < root->children.size(); i++){
            preorder(root->children[i]);
        }
    }
    
    vector<int> preorder(Node* root) {
        simplePreOrder(root);
        
        return ans;
    }
};
