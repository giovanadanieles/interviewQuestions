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



// Space complexity: O(N) - 42.8 MB, less than 5.03% of C++ online submissions
//  Time complexity: O(N) - 91 ms, faster than 13.05% of C++ online submissions
class Solution {
public:
    unordered_set<int> values;
    
    void inorderTrans(TreeNode* root){
        if(root == NULL) return;
        
        values.insert(root->val);
        inorderTrans(root->left);
        inorderTrans(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        inorderTrans(root);
        
        unordered_set<int>::iterator it;
        for(it = values.begin(); it != values.end(); it++){
            if(*it != k - *it && values.find(k - *it) != values.end()) return true;
        }
        
        return false;
    }
};
