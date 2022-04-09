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



// Space complexity: O(H) - 9.8 MB, less than 21.58% of C++ online submissions
//  Time complexity: O(N) - 4 ms, faster than 51.80% of C++ online submissions
class Solution {
public:
    void inOrder(TreeNode* cur, int &prev, int &minDiff){
        if(cur == NULL) return;
        
        inOrder(cur->left, prev, minDiff);
        
        if(prev != -1) minDiff = min(minDiff, cur->val - prev);
        prev = cur->val;
        
        inOrder(cur->right, prev, minDiff);
    }
    
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX, prev = -1;
        
        inOrder(root, prev, minDiff);
        
        return minDiff;
    }
};
