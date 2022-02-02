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



// Space complexity: O(N) - less than 63.75% of C++ online submissions
//  Time complexity: O(N) - faster than 44.20% of C++ online submissions
// class Solution {
// public:
//     vector<int> answer;
    
//     void recTransversal(TreeNode* root){        
//         if(root->left != NULL) recTransversal(root->left);
//         if(root->right != NULL) recTransversal(root->right);
        
//         answer.push_back(root->val);
//     }
    
//     vector<int> postorderTraversal(TreeNode* root) {
//         if(root != NULL) recTransversal(root);
        
//         return answer;
//     }
// };



// Space complexity: O(N) - less than 87.59% of C++ online submissions
//  Time complexity: O(N) - faster than 6.26% of C++ online submissions 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> answer;
        stack<TreeNode*> s;
        
        if(root == NULL) return answer;
        
        s.push(root);
        
        while(!s.empty()){
            TreeNode* curr = s.top();
            s.pop();
            
            answer.insert(answer.begin(), curr->val);
            
            if(curr->left != NULL) s.push(curr->left);
            if(curr->right != NULL) s.push(curr->right);
        }
        
        return answer;
    }
};
