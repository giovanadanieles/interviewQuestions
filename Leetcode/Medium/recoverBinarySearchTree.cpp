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



// Ref: https://www.youtube.com/watch?v=bJBwOMPhe6Y

// Space complexity: O(N) - 58.9 MB, less than 12.67% of C++ online submissions
//  Time complexity: O(N) - 32 ms, faster than 83.70% of C++ online submissions
class Solution {
public:
    void inOrder(TreeNode *root, vector<TreeNode*> &v){
        if(root == NULL) return;
        
        inOrder(root->left, v);
        v.push_back(root);
        inOrder(root->right, v);
    }
    
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> v;
        vector<int> orderedValues;
        
        inOrder(root, v);
        
        for(unsigned int i = 0; i < v.size(); i++) orderedValues.push_back(v[i]->val);
        
        sort(orderedValues.begin(), orderedValues.end());
        
        for(unsigned int i = 0; i < v.size(); i++) v[i]->val = orderedValues[i];
    }
};
