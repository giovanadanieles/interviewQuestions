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



// Space complexity: O(H) - 12.7 MB, less than 79.76% of C++ online submissions
//  Time complexity: O(N) - 7 ms, faster than 76.16% of C++ online submissions
class Solution {
public:
    pair<TreeNode*, TreeNode*> preOrder(TreeNode *root){
        if(root == NULL) return {NULL, NULL};
        
        auto [left, lastLeft] = preOrder(root->left);
        auto [right, lastRight] = preOrder(root->right);
        
        root->left = NULL;
        root->right = left;
        
        lastLeft != NULL ? lastLeft->right = right : root->right = right;
        
        TreeNode *end;
        
        if(lastRight == NULL && lastLeft == NULL) end = root;
        else if(lastRight == NULL) end = lastLeft;
        else end = lastRight;
        
        return {root, end};
    }
    
    void flatten(TreeNode* root) {
        preOrder(root);
    }
};
