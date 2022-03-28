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



// Space complexity: O(H) - 20.8 MB, less than 81.40% of C++ online submissions
//  Time complexity: O(N) - 23 ms, faster than 32.75% of C++ online submissions
class Solution {
public:
    bool ans = true;
    
    int height(TreeNode* root){
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        
        int h1 = height(root->left);
        int h2 = height(root->right);
        
        if(h1 - h2 > 1 || h1 - h2 < -1) ans = false;
        
        return 1 + max(h1, h2);
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL || root->left == NULL && root->right == NULL) return true;
                
        height(root);
        
        return ans;
    }
};
