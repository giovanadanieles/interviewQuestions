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



// Space complexity: O(N) [if counted output space, otherwise O(log N)] - less than 62.37% of C++ online submissions
//  Time complexity: O(N) - faster than 97.45% of C++ online submissions
class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    
    void solve(TreeNode* root, int sum){
        if(root == NULL) return;
        
        path.push_back(root->val);

        if(root->left == NULL && root->right == NULL && sum - root->val == 0) ans.push_back(path);

        if(root->left != NULL) solve(root->left, sum - root->val);
        
        if(root->right != NULL) solve(root->right, sum - root->val);

        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        solve(root, targetSum);
        
        return ans;
    }
};
