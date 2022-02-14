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


// Space complexity: O(N) - less than 21.32% of C++ online submissions
//  Time complexity: O(N) - faster than 35.84% of C++ online submissions
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        unsigned int queueLen;
        TreeNode *cur, *rightSide;
        vector<int> ans;
        queue<TreeNode*> q;
        
        if(root == NULL) return ans;
        
        q.push(root);
        
        while(!q.empty()){
            rightSide = NULL;
            queueLen = q.size();
            
            // Removing nodes from current level and adding nodes from next level
            for(unsigned int i = 0; i < queueLen; i++){
                cur = q.front();
                q.pop();
                
                if(cur != NULL){
                    rightSide = cur;
                    q.push(rightSide->left);
                    q.push(rightSide->right);
                }
            }
            
            if(rightSide != NULL) ans.push_back(rightSide->val);
        }
        
        return ans;
    }
};
