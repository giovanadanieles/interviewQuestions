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



// Space complexity: O(T1 + T2) - 12.8 MB, less than 26.60% of C++ online submissions
//  Time complexity: O(T1 + T2) - 7 ms, faster than 42.18% of C++ online submissions
class Solution {
public:
    void dfs(TreeNode* root, string &leafValue){
        if(root->right == NULL && root->left == NULL){
            leafValue += root->val;
            return;
        }
        
        if(root->left != NULL) dfs(root->left, leafValue);
        if(root->right != NULL) dfs(root->right, leafValue);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string leafVal1 = "", leafVal2 = "";
        
        dfs(root1, leafVal1);
        dfs(root2, leafVal2);
        
        if(leafVal1 == leafVal2) return true;
        else return false;
    }
};
