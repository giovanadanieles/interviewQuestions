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



// Space complexity: O(2H) - 10 MB, less than 78.48% of C++ online submissions
//  Time complexity: O(2N) -  4 ms, faster than 44.34% of C++ online submissions
// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if(p == NULL && q == NULL) return true;
//         else if(p == NULL) return false;
//         else if(q == NULL) return false;
        
//         if(p->val == q->val){
//             return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//         }
//         else return false;
//     }
// };



// Space complexity: O(2H) - 10 MB, less than 78.48% of C++ online submissions
//  Time complexity: O(2N) -  0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        else if(p == NULL || q == NULL) return false;
        else if(p->val != q->val) return false;
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
