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



// Space complexity: O(H) - 23.6 MB, less than 96.94% of C++ online submissions
//  Time complexity: O(V + E) - 37 ms, faster than 20.68% of C++ online submissions
// class Solution {
// public:
//     int postOrder(TreeNode *root, int &tilt){
//         if(root == NULL) return 0;
        
//         int left = postOrder(root->left, tilt);
//         int right = postOrder(root->right, tilt);
        
//         tilt += abs(right - left);
        
//         return right + left + root->val;
//     }
    
//     int findTilt(TreeNode* root) {
//         int totalSum, tilt = 0;
        
//         totalSum = postOrder(root, tilt);
        
//         return tilt;
//     }
// };



// Space complexity: O(H) - 23.8 MB, less than 36.21% of C++ online submissions
//  Time complexity: O(V + E) - 16 ms, faster than 90.04% of C++ online submissions
class Solution {
public:
    int totalSum;
    
    void postOrder(TreeNode *root, int &tilt){
        if(root == NULL){
            totalSum = 0;
            return;
        }
        
        postOrder(root->left, tilt);
        int left = totalSum;
        
        postOrder(root->right, tilt);
        int right = totalSum;
        
        tilt += abs(right - left);
        
        totalSum = right + left + root->val;
    }
    
    int findTilt(TreeNode* root) {
        int tilt = 0;
        
        postOrder(root, tilt);
        
        return tilt;
    }
};
