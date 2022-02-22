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



// Space complexity: O(N) - less than 42.69% of C++ online submissions
//  Time complexity: O(N) - faster than 100.00% of C++ online submissions
class Solution {
public:
    vector<int> ans;
    
    void solve(TreeNode* root){
        if(root == NULL) return;
        
        if(root->left != NULL) solve(root->left);
        
        ans.push_back(root->val);
        
        if(root->right != NULL) solve(root->right); 
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        solve(root);
        
        return ans;
    }
};
