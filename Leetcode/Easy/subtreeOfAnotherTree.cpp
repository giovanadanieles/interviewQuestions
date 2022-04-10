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



// NOT ACCEPTED - WORKS ONLY ON TREES WITHOUT REPEATED NUMBERS
// class Solution {
// public:    
//     bool isSubtree(TreeNode* root, TreeNode* subRoot) {
//         if(root == NULL && subRoot == NULL) return true;
//         else if(root == NULL || subRoot == NULL) return false;
        
//         if(root->val == subRoot->val) return compareTrees(root->left, subRoot->left) && compareTrees(root->right, subRoot->right);
//         else return compareTrees(root->left, subRoot) || compareTrees(root->right, subRoot);
//     }
// };



// // Space complexity: O(heightR * heightS) - 28.6 MB, less than 96.25% of C++ online submissions
// //  Time complexity: O(R * S) - 37 ms, faster than 44.12% of C++ online submissions
// class Solution {
// public:    
//     // O(subRoot_size)
//     bool isEqual(TreeNode *root, TreeNode *subRoot){
//         if(root == NULL && subRoot == NULL) return true;
//         else if(root == NULL || subRoot == NULL) return false;
//         else if(root->val != subRoot->val) return false;
        
//         return isEqual(root->left, subRoot->left) && isEqual(root->right, subRoot->right);
//     }
    
//     // O(root_size)
//     void compareTrees(TreeNode *root, TreeNode* subRoot, int &isSub){
//         if(root == NULL) return;
//         if(isSub == true) return;
        
//         compareTrees(root->left, subRoot, isSub);
//         isSub |= isEqual(root, subRoot);
//         compareTrees(root->right, subRoot, isSub);
//     }
    
//     bool isSubtree(TreeNode* root, TreeNode* subRoot) {
//         int isSub = false;
        
//         compareTrees(root, subRoot, isSub);
        
//         return isSub;
//     }
// };



// Space complexity: O(heightR * heightS) - 28.9 MB, less than 21.05% of C++ online submissions
//  Time complexity: O(R * S) - 31 ms, faster than 62.91% of C++ online submissions
class Solution {
public:    
    // O(subRoot_size)
    bool isEqual(TreeNode *root, TreeNode *subRoot){
        if(root == NULL && subRoot == NULL) return true;
        else if(root == NULL || subRoot == NULL) return false;
        else if(root->val != subRoot->val) return false;
        
        return isEqual(root->left, subRoot->left) && isEqual(root->right, subRoot->right);
    }
    
    // O(root_size)
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL) return true;
        if(root == NULL) return false;
        
        if(isEqual(root, subRoot) == true) return true;
        else return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
