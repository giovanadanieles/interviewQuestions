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



// Space complexity: O(H) - 20.2 MB, less than 65.29% of C++ online submissions
//  Time complexity: O(N) - 28 ms, faster than 11.02% of C++ online submissions
class Solution {
public:
    int pathSize(TreeNode* root, int &diameter){
        if(root == NULL) return 0;
        
        int left = pathSize(root->left, diameter);
        int right = pathSize(root->right, diameter);
        
        diameter = max(diameter, left + right);
        
        return 1 + max(left, right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = INT_MIN;
        
        pathSize(root, diameter);
        
        return diameter;
    }
};
