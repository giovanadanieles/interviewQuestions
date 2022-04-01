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



// Space complexity: O(V) - 11.4 MB, less than 32.37% of C++ online submissions
//  Time complexity: O(V + E) - 16 ms, faster than 98.93% of C++ online submissions
class Solution {
public:
    vector<int> ans;
    
    void simplePostOrder(Node* root){
        if(root == NULL) return;
        
        for(unsigned int i = 0; i < root->children.size(); i++){
            simplePostOrder(root->children[i]);
        }
        
        ans.push_back(root->val);
    }
    
    vector<int> postorder(Node* root) {
        simplePostOrder(root);
        
        return ans;
    }
};
