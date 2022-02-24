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



// Space complexity: O(N) - less than 7.51% of C++ online submissions
//  Time complexity: O(N) - faster than 52.32% of C++ online submissions
// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         int size;
//         TreeNode *curLeft, *curRight;
//         vector<string> leftVal, rightVal;
//         queue<TreeNode*> left, right;
        
//         if(root->left == NULL && root->right == NULL) return true;
//         if(root->left == NULL || root->right == NULL) return false;
//         if(root->left->val != root->right->val) return false;
                
//         left.push(root->left);
//         right.push(root->right);
        
//         while(!left.empty() && !right.empty()){
//             size = left.size();
            
//             if(size != right.size()) return false;
            
//             while(size > 0){
//                 curLeft = left.front();
//                 left.pop();
                
//                 curRight = right.front();
//                 right.pop();
                
//                 if(curLeft && curLeft->left != NULL){
//                     left.push(curLeft->left);
//                     leftVal.push_back(to_string(curLeft->left->val));
//                 }
//                 else leftVal.push_back("null");
                
//                 if(curLeft && curLeft->right != NULL){
//                     left.push(curLeft->right);
//                     leftVal.push_back(to_string(curLeft->right->val));
//                 }
//                 else leftVal.push_back("null");
                
//                 if(curRight && curRight->left != NULL){
//                     right.push(curRight->left);
//                     rightVal.push_back(to_string(curRight->left->val));
//                 }
//                 else rightVal.push_back("null");
                
//                 if(curRight && curRight->right != NULL){
//                     right.push(curRight->right);
//                     rightVal.push_back(to_string(curRight->right->val));
//                 }
//                 else rightVal.push_back("null");
                
                
//                 size--;
//             }
            
//             if(leftVal.size() != rightVal.size()) return false;
                
//             for(unsigned int i = 0, j = rightVal.size() - 1; i < leftVal.size(); i++, j--){           
//                 if(leftVal[i] != rightVal[j]) return false;
//             }
            
//             leftVal.clear(), rightVal.clear();
            
//         }
        
//         if(!left.empty() || !right.empty()) return false;
        
//         return true;
//     }
// };



// Space complexity: O(N) - faster than 61.26% of C++ online submissions
//  Time complexity: O(N) - less than 17.63% of C++ online submissions
class Solution {
public:
    bool solve(TreeNode* left, TreeNode* right){
        if(left == NULL || right == NULL) return left == right;
        
        if(left->val != right->val) return false;
        
        return solve(left->left, right->right) && solve(left->right, right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        
        return solve(root->left, root->right);
    }
};
