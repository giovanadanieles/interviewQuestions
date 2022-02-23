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



// Space complexity: O(N) - less than 62.17% of C++ online submissions
//  Time complexity: O(N) - faster than 100.00% of C++ online submissions
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        int nElements;
        TreeNode *cur;
        queue<TreeNode*> q;
        vector<int> level;
        vector<vector<int>> ans;
        
        if(root == NULL) return ans;
        
        q.push(root);
        level.push_back(root->val);
        ans.push_back(level);
        
        while(!q.empty()){
            nElements = q.size();
            
            level.clear();
            
            while(nElements > 0){
                cur = q.front();
                q.pop();

                if(cur->left != NULL){
                    q.push(cur->left);
                    level.push_back(cur->left->val);
                }

                if(cur->right != NULL){
                    q.push(cur->right);
                    level.push_back(cur->right->val);
                }
                
                nElements--;
            }
            
            if(level.size() != 0) ans.push_back(level);
        }
        
        return ans;
    }
};
