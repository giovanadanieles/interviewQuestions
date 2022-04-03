/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



// Ref: https://www.youtube.com/watch?v=13m9ZCB8gjw

// Space complexity: O(H) - 14.2 MB, less than 59.33% of C++ online submissions
//  Time complexity: O(N) - 16 ms, faster than 84.49% of C++ online submissions
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
            The easist way to do this is save the path until p and q and after that compare the paths.
            P.e.: 3 6 2
                  3 6 11 5
            6 are the last node in common, so it's the LCA.
            
            Problem: we need extra space...
        */   
        
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;
        
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        
        if(left != NULL && right != NULL) return root;
        else if(left == NULL && right == NULL) return NULL;
        else return left != NULL ? left : right;
    }
};
