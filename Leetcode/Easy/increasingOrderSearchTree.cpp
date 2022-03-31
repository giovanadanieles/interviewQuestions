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



// Space complexity: O(N) - 7.9 MB, less than 61.52% of C++ online submissions
//  Time complexity: O(N) - 4 ms, faster than 52.39% of C++ online submissions
// class Solution {
// public:
//     TreeNode *newRoot = new TreeNode();
    
//     void dfs(TreeNode* oldRoot){
//         if(oldRoot == NULL) return;
        
//         dfs(oldRoot->left);
        
//         newRoot->right = new TreeNode(oldRoot->val);
//         newRoot = newRoot->right;
                        
//         dfs(oldRoot->right);
//     }
    
//     TreeNode* increasingBST(TreeNode* root) {
//         TreeNode *ans = newRoot;
        
//         dfs(root);
        
//         return ans->right;
//     }
// };



// Space complexity: O(H) - 7.6 MB, less than 79.44% of C++ online submissions 
//  Time complexity: O(N) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    TreeNode *newRoot = new TreeNode();
    
    void dfs(TreeNode* oldRoot){
        if(oldRoot == NULL) return;
        
        dfs(oldRoot->left);
        
        oldRoot->left = NULL;
        newRoot->right = oldRoot;
        newRoot = oldRoot;
                        
        dfs(oldRoot->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *ans = newRoot;
        
        dfs(root);
        
        return ans->right;
    }
};
