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



// Space complexity: O(H) - 24.1 MB, less than 87.55% of C++ online submissions
//  Time complexity: O(N) - 16 ms, faster than 91.39% of C++ online submissions
// class Solution {
// public:
//     int level = 0;
    
//     void dfs(TreeNode *root, int &ans, int k){
//         if(root == NULL) return;
        
//         dfs(root->left, ans, k);
    
//         level++;
        
//         if(level == k){
//             ans = root->val;
//             return;
//         }
        
//         dfs(root->right, ans, k);
//     }
    
//     int kthSmallest(TreeNode* root, int k) {
//         int ans;
        
//         dfs(root, ans, k);
        
//         return ans;
//     }
// };



// Space complexity: O(N) - 24.5 MB, less than 16.60% of C++ online submissions
//  Time complexity: O(N) - 31 ms, faster than 30.76% of C++ online submissions
class Solution {
public:
    void inOrder(TreeNode *root, vector<int> &order){
        if(root == NULL) return;
        
        inOrder(root->left, order);
        
        order.push_back(root->val);
        
        inOrder(root->right, order);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> order;
        
        inOrder(root, order);
        
        return order[k - 1];
    }
};
