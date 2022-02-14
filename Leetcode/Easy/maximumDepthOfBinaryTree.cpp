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


// Space complexity: O(N) - less than 56.35% of C++ online submissions
//  Time complexity: O(N) - faster than 78.64% of C++ online submissions
class Solution {
public:
    int maxDepth(TreeNode* root) {
       if(root == NULL) return 0;
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        return max(left, right) + 1;
    }
};
