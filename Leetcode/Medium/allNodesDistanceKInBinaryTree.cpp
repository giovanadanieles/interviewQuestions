/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



// Ref: https://www.youtube.com/watch?v=nPtARJ2cYrg
// Space complexity: O(V + E) - 13.5 MB, less than 29.59% of C++ online submissions
//  Time complexity: O(V + E) - 19 ms, faster than 9.08% of C++ online submissions
class Solution {
public:
    void inOrder(TreeNode* root, unordered_map<int, vector<int>> &graph){        
        if(root->left != NULL){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            
            inOrder(root->left, graph);
        }
        
        if(root->right != NULL){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            
            inOrder(root->right, graph);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        int cur, levelSize, distance = 0;
        queue<int> q;
        vector<int> ans;
        unordered_set<int> visited;
        unordered_map<int, vector<int>> graph;
        
        inOrder(root, graph);
        
        q.push(target->val);
        visited.insert(target->val);
        
        while(!q.empty()){
            levelSize = q.size();
            
            while(levelSize > 0){
                cur = q.front();
                q.pop();
                
                if(distance == k) ans.push_back(cur);
                
                for(auto neigh : graph[cur]){
                    if(visited.find(neigh) == visited.end()){
                        q.push(neigh);
                        visited.insert(neigh);
                    }
                }
                
                levelSize--;
            }
            
            distance++;
        }
        
        return ans;
    }
};
