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



// Space complexity: O(N) - 25.8 MB, less than 5.97% of C++ online submissions
//  Time complexity: O(N) - 19 ms, faster than 78.58% of C++ online submissions
// class Solution {
// public:
//     int getMinimumDifference(TreeNode* root) {
//         int minDiff = INT_MAX, levelSize, front;
//         priority_queue<int> pq;
//         queue<TreeNode*> q;
        
//         q.push(root);
        
//         while(!q.empty()){
//             levelSize = q.size();
            
//             while(levelSize > 0){
//                 if(q.front()->left != NULL) q.push(q.front()->left);
//                 if(q.front()->right != NULL) q.push(q.front()->right);
                
//                 pq.push(q.front()->val);
                
//                 q.pop();
//                 levelSize--;
//             }
//         }
        
//         while(pq.size() > 1){
//             front = pq.top();
//             pq.pop();
            
//             minDiff = min(minDiff, front - pq.top());
//         }
        
//         return minDiff;
//     }
// };



// Space complexity: O(H) - 25.1 MB, less than 95.40% of C++ online submissions
//  Time complexity: O(N) - 28 ms, faster than 42.44% of C++ online submissions
class Solution {
public:
    void inOrder(TreeNode* root, TreeNode* &prev, int &minDiff){
        if(root == NULL) return;
        
        inOrder(root->left, prev, minDiff);
        
        if(prev != NULL) minDiff = min(minDiff, root->val - prev->val);
        prev = root;
        
        inOrder(root->right, prev, minDiff);
    }
    
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        TreeNode *prev = NULL;
        
        inOrder(root, prev, minDiff);
        
        return minDiff;
    }
};
