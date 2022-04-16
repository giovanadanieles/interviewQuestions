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



// Space complexity: O(H) - 33.4 MB, less than 62.77% of C++ online submissions
//  Time complexity: O(N) - 39 ms, faster than 82.21% of C++ online submissions
class Solution {
public:
    void dfs(TreeNode* root, int &curVal){
        if(root == NULL) return;
        
        dfs(root->right, curVal);
        curVal += root->val;
        
        root->val = curVal;
        
        dfs(root->left, curVal);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int curVal = 0;
        
        dfs(root, curVal);
        
        return root;
    }
};
