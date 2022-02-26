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



// Space complexity: O(N) - less than 50.36% of C++ online submissions
//  Time complexity: O(N) - faster than 31.08% of C++ online submissions
class Solution {    
public:
    void solve(TreeNode* root, int val){
        if(root->val > val){
            if(root->left == NULL) root->left = new TreeNode(val);
            else solve(root->left, val);
        }
        else{
            if(root->right == NULL) root->right = new TreeNode(val);
            else solve(root->right, val);
        }
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        
        solve(root, val);
        
        return root;
    }
};
