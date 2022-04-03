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



// Ref: https://www.youtube.com/watch?v=UVafek_SnXE

// Space complexity: O(H) - 54.3 MB, less than 23.05% of C++ online submissions
//  Time complexity: O(N) - 54 ms, faster than 18.78% of C++ online submissions
class Solution {
public:
    string tree2str(TreeNode* root) {
        if(root == NULL) return "";
        
        if(root->left == NULL && root->right == NULL) return to_string(root->val);
        
        string leftStr = tree2str(root->left);
        string rightStr = tree2str(root->right);
        
        if(rightStr == "") return to_string(root->val) + "(" + leftStr + ")";
        else return to_string(root->val) + "(" + leftStr + ")(" + rightStr + ")";
    }
};
