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



// Space complexity: O(log N) - 34.8 MB, less than 5.82% of C++ online submissions
//  Time complexity: O(N) - 66 ms, faster than 32.32% of C++ online submissions
// class Solution {
// public:
//     TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
//         if(root1 == NULL && root2 == NULL) return NULL;
        
//         int x = (root1 != NULL) ? root1->val : 0;
//         int y = (root2 != NULL) ? root2->val : 0;
        
//         TreeNode *result = new TreeNode(x + y);
        
//         if(root1 != NULL && root2 != NULL){
//             result->left = mergeTrees(root1->left, root2->left);
//             result->right = mergeTrees(root1->right, root2->right);
//         }
//         else if(root1 != NULL){
//             result->left = mergeTrees(root1->left, root2);
//             result->right = mergeTrees(root1->right, root2);
//         }  
//         else{
//             result->left = mergeTrees(root1, root2->left);
//             result->right = mergeTrees(root1, root2->right);
//         }
        
//         return result;
//     }
// };



// Space complexity: O(log N) - 32.3 MB, less than 63.23% of C++ online submissions
//  Time complexity: O(N) - 40 ms, faster than 80.93% of C++ online submissions
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL) return root2;
        if(root2 == NULL) return root1;
        
        root1->val += root2->val;
        
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        
        return root1;
    }
};
