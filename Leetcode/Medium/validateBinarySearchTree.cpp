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



// Space complexity: O(1) - 21.7 MB, less than 70.97% of C++ online submissions
//  Time complexity: O(2N) = O(N) - 16 ms, faster than 60.44% of C++ online submissions
class Solution {
public:
    bool isValid(TreeNode* node, long long leftBound, long long rightBound){
        if(node == NULL) return true; //an empty BST is a valid BST
        
        if(node->val >= rightBound || node->val <= leftBound) return false;
        
        return (isValid(node->left, leftBound, node->val) &&
                isValid(node->right, node->val, rightBound));
    }
    
    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
};
