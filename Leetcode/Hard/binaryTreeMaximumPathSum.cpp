// Space complexity: O(h) - less than 92.06% of C++ online submissions
//  Time complexity: O(N) - faster than 47.03% of C++ online submissions

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
class Solution {
public:
    int ans;
    
    int dfs(TreeNode* root){
        if(root == NULL) return 0;
        
        int leftMax = dfs(root->left);
        int rightMax = dfs(root->right);
        
        leftMax = max(leftMax, 0);
        rightMax = max(rightMax, 0);
        
        // Do split
        ans = max(ans, root->val + leftMax + rightMax);
        
        // Do not split
        return root->val + max(leftMax, rightMax);
    }
    
    int maxPathSum(TreeNode* root) {
        ans = root->val;
        
        dfs(root);
        
        return ans;
        
    }
};
