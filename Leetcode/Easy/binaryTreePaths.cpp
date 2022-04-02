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



// Space complexity: O(N) - 13.2 MB, less than 46.08% of C++ online submissions
//  Time complexity: O(N) - 4 ms, faster than 74.10% of C++ online submissions
class Solution {
public:
    void inOrder(TreeNode *root, string path, vector<string> &ans){
        if(root == NULL) return;
        
        path += to_string(root->val) + "->";
        
        if(root->left == NULL && root->right == NULL){
            path.erase(path.length() - 2, 2);
            ans.push_back(path);
            
            return;
        }
        
        inOrder(root->left, path, ans);
        inOrder(root->right, path, ans);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        
        inOrder(root, "", ans);
        
        return ans;
    }
};
