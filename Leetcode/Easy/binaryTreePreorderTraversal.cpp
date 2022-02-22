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



// Space complexity: O(N) - less than 77.62% of C++ online submissions
//  Time complexity: O(N) - faster than 100.00% of C++ online submissions
class Solution {
public:
    vector<int> ans;
    
    void preorder(TreeNode* root){
        if(root == NULL) return;
        
        ans.push_back(root->val);
        
        if(root->left != NULL) preorder(root->left);
        if(root->right != NULL) preorder(root->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        
        return ans;
    }
};
