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



// Space complexity: O(logN) - 64.6 MB, less than 61.56% of C++ online submissions
//  Time complexity: O(N)    - 194 ms, faster than 39.19% of C++ online submissions
// class Solution {
// public:
//     int ans = 0;
    
//     int rangeSumBST(TreeNode* root, int low, int high) {
//         if(root == NULL) return 0;
//         if(root->val >= low && root->val <= high) ans += root->val;
        
//         rangeSumBST(root->left, low, high);
//         rangeSumBST(root->right, low, high);
        
//         return ans;
//     }
// };



// Space complexity: O(N) - 64.8 MB, less than 7.23% of C++ online submissions
//  Time complexity: O(N) - 147 ms, faster than 72.31% of C++ online submissions
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        TreeNode *cur;
        queue<TreeNode*> q;
        
        if(root == NULL) return ans;
        
        q.push(root);
        
        while(!q.empty()){
            cur = q.front();
            q.pop();
            
            if(cur->val >= low && cur->val <= high) ans += cur->val;
            
            if(cur->left != NULL && cur->val > low) q.push(cur->left);
            if(cur->right != NULL && cur->val < high) q.push(cur->right);
        }
        
        return ans;
    }
};
