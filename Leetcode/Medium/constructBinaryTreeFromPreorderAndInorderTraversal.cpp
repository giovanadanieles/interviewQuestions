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


//Ref: https://www.youtube.com/watch?v=ihj4IQGZ2zc

// Space complexity: O(N ^ 2) - 74 MB, less than 11.37% of C++ online submissions
//  Time complexity: O(N ^ 2) - 102 ms, faster than 6.78% of C++ online submissions
// class Solution {
// public:
//     int findPositionOfNum(int num, vector<int> &inorder){
//         for(unsigned int i = 0; i < inorder.size(); i++){
//             if(inorder[i] == num) return i;
//         }
        
//         return -1;
//     }
    
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         /*
//         *   The preorder vector show us the current root. The inorder vector show us
//         * how many nodes are on the left and how many are on the right of the cur node.
//         *   Ex: preorder = [3, 9, 20, 15, 7]
//         *       inorder  = [9, 3, 15, 20, 7]
//         *       -> The cur node (3) can be found on position 1 of inorder. So, it has 
//         *      1 node to the left and 3 nodes to the right --> going back to the preorder vector
//         *      we'll see that the 1 left is 9 and the 3 others are 20, 15 and 7.
//         */
        
//         if(preorder.empty() || inorder.empty()) return NULL;
        
//         TreeNode *root = new TreeNode(preorder[0]);
//         int position = findPositionOfNum(root->val, inorder);
        
//         vector<int> preLeft = {preorder.begin() + 1, preorder.begin() + position + 1};
//         vector<int> inLeft = {inorder.begin(), inorder.begin() + position};
        
//         root->left = buildTree(preLeft, inLeft);
        
//         vector<int> preRight = {preorder.begin() + position + 1, preorder.end()};
//         vector<int> inRight = {inorder.begin() + position + 1, inorder.end()};
            
//         root->right = buildTree(preRight, inRight);
        
//         return root;
//     }
// };



// Space complexity: O(N) - 26.5 MB, less than 28.75% of C++ online submissions
//  Time complexity: O(N) - 19 ms, faster than 80.30% of C++ online submissions
class Solution {
public:
    int preorderIndex;
    unordered_map<int, int> inorderIndex;
    
    TreeNode* arrayToTree(vector<int> &preorder, int left, int right){
        if(left > right) return NULL;
        
        int rootValue = preorder[preorderIndex++];
        TreeNode *root = new TreeNode(rootValue);
        
        root->left = arrayToTree(preorder, left, inorderIndex[rootValue] - 1);
        root->right = arrayToTree(preorder, inorderIndex[rootValue] + 1, right);
            
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderIndex = 0;
        for(unsigned int i = 0; i < inorder.size(); i++) inorderIndex[inorder[i]] = i;
    
        return arrayToTree(preorder, 0, preorder.size() - 1);
    }
};
