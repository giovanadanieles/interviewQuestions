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



// Space complexity: O(W) - 12.2 MB, less than 46.71% of C++ online submissions
//  Time complexity: O(V + E) = O(N) - 7 ms, faster than 32.56% of C++ online submissions
// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         int isLeft = -1, levelSize;
//         TreeNode *cur;
//         deque<TreeNode*> d;
//         vector<int> aux;
//         vector<vector<int>> ans;
        
//         if(root == NULL) return ans;
        
//         d.push_back(root);
        
//         while(!d.empty()){
//             levelSize = d.size();
//             isLeft *= -1;
                        
//             aux.clear();
            
//             while(levelSize > 0){
//                 if(isLeft == 1){
//                     cur = d.front();
                    
//                     if(cur->left != NULL) d.push_back(cur->left);
//                     if(cur->right != NULL) d.push_back(cur->right);
                    
//                     aux.push_back(cur->val);
//                     d.pop_front();
//                 }
//                 else{
//                     cur = d.back();
                    
//                     if(cur->right != NULL) d.push_front(cur->right);
//                     if(cur->left != NULL) d.push_front(cur->left);
                    
//                     aux.push_back(cur->val);
//                     d.pop_back();
//                 }
                
//                 levelSize--;
//             }
            
//             ans.push_back(aux);
//         }
        
//         return ans;
//     }
// };



// Space complexity: O(W) - 12 MB, less than 76.66% of C++ online submissions
//  Time complexity: O(V + E) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int isLeft = -1, levelSize;
        TreeNode *cur;
        queue<TreeNode*> q;
        vector<int> aux;
        vector<vector<int>> ans;
        
        if(root == NULL) return ans;
        
        q.push(root);
        
        while(!q.empty()){
            levelSize = q.size();
            isLeft *= -1;
            
            aux.clear();
            
            while(levelSize > 0){
                cur = q.front();

                if(cur->left != NULL) q.push(cur->left);
                if(cur->right != NULL) q.push(cur->right);

                aux.push_back(cur->val);
                q.pop();
               
                
                levelSize--;
            }
            
            if(isLeft == -1) reverse(aux.begin(), aux.end());
            ans.push_back(aux);
        }
        
        return ans;
    }
};
