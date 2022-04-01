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



// Space complexity: O(H) - 16.7 MB, less than 45.48% of C++ online submissions
//  Time complexity: O(max(H, numOfLeafs * szPath)) - 4 ms, faster than 88.49% of C++ online submissions
// class Solution {
// public:
//     void dfs(TreeNode *root, int num, int &total){
//         if(root == NULL) return;
        
//         num = num * 2 + root->val;
        
//         if(root->left == NULL && root->right == NULL){                
//             int temp;
            
//             while(num != 0){
//                 temp = (total & num) << 1;
//                 total = total ^ num;
//                 num = temp;
//             }
                        
//             return;
//         }
                
//         dfs(root->left, num, total);
//         dfs(root->right, num, total);
        
//         return;
//     }
    
//     int sumRootToLeaf(TreeNode* root) {
//         int ans = 0;
        
//         dfs(root, 0, ans);
        
//         return ans;
//     }
// };



// Space complexity: O(H) - 16.7 MB, less than 45.48% of C++ online submissions
//  Time complexity: O(N) - 6 ms, faster than 75.48% of C++ online submissions
class Solution {
public:
    void dfs(TreeNode *root, int num, int &total){
        if(root == NULL) return;
        
        num = (num << 1) | root->val;
        
        if(root->left == NULL && root->right == NULL){                
            total += num;
            return;
        }
                
        dfs(root->left, num, total);
        dfs(root->right, num, total);
        
        return;
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        
        dfs(root, 0, ans);
        
        return ans;
    }
};
