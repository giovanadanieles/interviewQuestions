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



// Space complexity: O(W) - 22.6 MB, less than 31.02% of C++ online submissions
//  Time complexity: O(N) - 12 ms, faster than 93.60% of C++ online submissions
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        int curSize, nodesAtLevel;
        double sum;
        vector<double> ans;
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()){
            sum = 0.0;
            curSize = nodesAtLevel = q.size();
            
            while(curSize > 0){
                sum += q.front()->val;
                
                if(q.front()->left != NULL) q.push(q.front()->left);
                if(q.front()->right != NULL) q.push(q.front()->right);
                
                q.pop();
                
                curSize--;
            }
            
            ans.push_back(sum / nodesAtLevel);
        }
        
        
        return ans;
    }
};
