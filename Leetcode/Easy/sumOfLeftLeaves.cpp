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



// Space complexity: O(H) - 13.4 MB, less than 82.92% of C++ online submissions
//  Time complexity: O(N) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    void dfsSum(TreeNode* root, bool &isLeft, int &sum){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL && isLeft) sum += root->val;
        
        isLeft = true;
        dfsSum(root->left, isLeft, sum);
        
        isLeft = false;
        dfsSum(root->right, isLeft, sum);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        bool isLeft = false;
        int sum = 0;
        
        dfsSum(root, isLeft, sum);
        
        return sum;
    }
};
