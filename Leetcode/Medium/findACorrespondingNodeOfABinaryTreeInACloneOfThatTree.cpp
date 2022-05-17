/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



// Space complexity: O(H) - 163.9 MB, less than 81.14% of C++ online submissions
//  Time complexity: O(N) - 989 ms, faster than 7.20% of C++ online submissions
class Solution {
public:
    void inOrder(TreeNode* original, TreeNode* cloned, TreeNode* target, TreeNode* &ans){
        if(original == NULL || ans != NULL) return;
        
        inOrder(original->left, cloned->left, target, ans);
        if(original == target) ans = cloned;
        inOrder(original->right, cloned->right, target, ans);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode *ans = NULL;
        
        inOrder(original, cloned, target, ans);
        
        return ans;
    }
};
