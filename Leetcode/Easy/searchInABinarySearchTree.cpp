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



// Space complexity: O(1) - less than 68.28% of C++ online submissions
//  Time complexity: O(N) - faster than 62.55% of C++ online submissions
// class Solution {
// public:
//     TreeNode* ans;
    
//     void solve(TreeNode* root, int val){
//         if(root == NULL){
//             ans = NULL;
//             return;
//         }
//         else if(root->val == val){
//             ans = root;
//             return;
//         }
        
//         if(root->val > val) searchBST(root->left, val);
//         else searchBST(root->right, val);
//     }
    
//     TreeNode* searchBST(TreeNode* root, int val) {
//         solve(root, val);
        
//         return ans;
//     }
// };



// Space complexity: O(1) - less than 68.28% of C++ online submissions
//  Time complexity: O(N) - faster than 95.25% of C++ online submissions
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        else if(root->val == val) return root;
        
        if(root->val > val) return searchBST(root->left, val);
        return searchBST(root->right, val);
    }
};
