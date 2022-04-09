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



// Space complexity: O(H) - 11 MB, less than 47.65% of C++ online submissions
//  Time complexity: O(N) - 4 ms, faster than 65.26% of C++ online submissions
// class Solution {
// public:
//     void depth(TreeNode* root, TreeNode* curParent, TreeNode* &nodeParent, int node, int &curDepth, int &nodeDepth){
//         if(root == NULL) return;
//         if(root->val == node){
//             nodeParent = curParent;
//             nodeDepth = curDepth;
//             return;
//         }
        
//         curParent = root;
//         curDepth++;
        
//         depth(root->left, curParent, nodeParent, node, curDepth, nodeDepth);
//         depth(root->right, curParent, nodeParent, node, curDepth, nodeDepth);
        
//         curDepth--;
//     }
    
//     bool isCousins(TreeNode* root, int x, int y) {
//         int depthAux, xDepth, yDepth;
//         TreeNode *parentAux, *xParent, *yParent;
        
//         depthAux = 0, parentAux = root;
//         depth(root, parentAux, xParent, x, depthAux, xDepth);
        
//         depthAux = 0, parentAux = root;
//         depth(root, parentAux, yParent, y, depthAux, yDepth);
        
//         return xDepth == yDepth && xParent != yParent;
//     }
// };



// Space complexity: O(H) - 11 MB, less than 47.65% of C++ online submissions
//  Time complexity: O(N) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    int xDepth = -1, yDepth = -1;
    TreeNode *xParent, *yParent;
    
    void dfs(TreeNode *root, TreeNode *parent, int x, int y, int depth){
        if(root == NULL) return;
        
        if(root->val == x){
            xDepth = depth;
            xParent = parent;
        }
        
        if(root->val == y){
            yDepth = depth;
            yParent = parent;
        }
        
        if(xDepth != -1 && yDepth != -1) return;
        
        dfs(root->left, root, x, y, depth + 1);
        dfs(root->right, root, x, y, depth + 1);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, root, x, y, 0);
        
        return xDepth == yDepth && xParent != yParent;
    }
};
