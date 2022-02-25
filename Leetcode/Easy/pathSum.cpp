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



// Space complexity: O(N) - less than 40.50% of C++ online submissions
//  Time complexity: O(N) - faster than 42.19% of C++ online submissions
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        else if(root->left == NULL && root->right == NULL && targetSum - root->val == 0) return true;
        else{
            return hasPathSum(root->left, targetSum - root->val) || 
                   hasPathSum(root->right, targetSum - root->val);
        }       
    }
};
