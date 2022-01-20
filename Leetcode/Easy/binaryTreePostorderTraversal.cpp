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



// Space complexity: O(N) - faster than 44.20% of C++ online submissions
//  Time complexity: O(N) - less than 63.75% of C++ online submissions
class Solution {
public:
    vector<int> answer;
    
    void recTransversal(TreeNode* root){        
        if(root->left != NULL) recTransversal(root->left);
        if(root->right != NULL) recTransversal(root->right);
        
        answer.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        if(root != NULL) recTransversal(root);
        
        return answer;
    }
};
