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



// Space complexity: O(H) - 7.1 MB, less than 22.48% of C++ online submissions
//  Time complexity: O(N) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    typedef long long int lli;
    
    void inOrder(TreeNode *root, lli &firstMin, lli &secMin){
        if(root == NULL) return;
        
        inOrder(root->left, firstMin, secMin);
        
        if(root->val < firstMin){
            if(firstMin != LLONG_MAX) secMin = firstMin;
            firstMin = root->val;
        }
        if(root->val < secMin && root->val != firstMin) secMin = root->val;
        
        inOrder(root->right, firstMin, secMin);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        lli firstMin = LLONG_MAX, secMin = LLONG_MAX;
        
        inOrder(root, firstMin, secMin);
        
        return secMin == LLONG_MAX ? -1 : secMin;
    }
};
