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



// Space complexity: O(H) - 144.7 MB, less than 71.44% of C++ online submissions
//  Time complexity: O(V + E) - 379 ms, faster than 32.16% of C++ online submissions
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        
        if(left != 0 && right != 0) return 1 + min(left, right);
        else return 1 + max(left, right);
    }
};
