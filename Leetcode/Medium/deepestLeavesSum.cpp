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



// Space complexity: O(H) - 59.7 MB, less than 95.42% of C++ online submissions
//  Time complexity: O(N) - 134 ms, faster than 51.25% of C++ online submissions
// class Solution {
// public:
//     void findSum(TreeNode *root, int curDepth, int maxDepth, int &sum){
//         if(root == NULL) return;
        
//         findSum(root->left, curDepth + 1,  maxDepth, sum);
//         if(curDepth == maxDepth) sum += root->val;
//         findSum(root->right, curDepth + 1, maxDepth, sum);
//     }
    
//     int depth(TreeNode *root){
//         if(root == NULL) return 0;
        
//         int left = depth(root->left);
//         int right = depth(root->right);
        
//         return 1 + max(left, right);
//     }
    
//     int deepestLeavesSum(TreeNode* root) {
//         int maxDepth, sum = 0;
        
//         maxDepth = depth(root);
//         findSum(root, 1, maxDepth, sum);
                
//         return sum;
//     }
// };



// Space complexity: O(H) - 59.7 MB, less than 76.73% of C++ online submissions
//  Time complexity: O(N) - 171 ms, faster than 21.66% of C++ online submissions
class Solution {
public:
    void findSum(TreeNode *root, int curDepth, int &maxDepth, int &sum){
        if(root == NULL) return;
        
        findSum(root->left, curDepth + 1, maxDepth, sum);
        
        if(curDepth > maxDepth){
            maxDepth = curDepth;
            sum = root->val;
        }
        else if(curDepth == maxDepth) sum += root->val;
        
        findSum(root->right, curDepth + 1, maxDepth, sum);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int maxDepth = 0, sum = 0;
        
        findSum(root, 0, maxDepth, sum);
                
        return sum;
    }
};
