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



// Space complexity: O(N) - 10 MB, less than 46.09% of C++ online submissions
//  Time complexity: O(V + E) - 3 ms, faster than 68.21% of C++ online submissions
// class Solution {
// public:
//     bool isUnivalTree(TreeNode* root) {
//         set<int> s;
//         queue<TreeNode*> q;
        
//         s.insert(root->val);
//         q.push(root);
        
//         while(!q.empty()){
//             TreeNode *cur = q.front();
//             q.pop();
            
//             if(cur->left != NULL){
//                 q.push(cur->left);
//                 s.insert(cur->left->val);
//             }
            
//             if(cur->right != NULL){
//                 q.push(cur->right);
//                 s.insert(cur->right->val);
//             }
//         }
        
//         if(s.size() == 1) return true;
//         else return false;
//     }
// };



// Space complexity: O(H) - 9.9 MB, less than 46.09% of C++ online submissions
//  Time complexity: O(V + E) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    int val = -1;
    
    bool isUnivalTree(TreeNode* root) {
        if(root == NULL) return true;
        
        if(val < 0) val = root->val;
        
        return val == root->val && isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};
