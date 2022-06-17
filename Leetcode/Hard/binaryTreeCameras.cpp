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



// Ref: https://www.youtube.com/watch?v=2Gh5WPjAgJk
// Space complexity: O(N) - 23.8 MB, less than 16.30% of C++ online submissions
//  Time complexity: O(N) - 19 ms, faster than 43.21% of C++ online submissions
// class Solution {
// public:
//     int numOfCams;
//     unordered_set<TreeNode*> covered;
    
//     void postorder(TreeNode *root, TreeNode *parent){
//         if(root != NULL){
//             postorder(root->left, root);
//             postorder(root->right, root);
            
//             // conditions to add a new camera:
//             //      1. the node is not covered and its parent is NULL;
//             //      2. some of its children isn't covered.
//             if((covered.find(root) == covered.end() && parent == NULL) ||
//                (covered.find(root->left) == covered.end()) ||
//                (covered.find(root->right) == covered.end())){
//                 numOfCams++;
                
//                 covered.insert(root), covered.insert(parent);
//                 covered.insert(root->left), covered.insert(root->right);
//             }
//         }
//     }
    
//     int minCameraCover(TreeNode* root) {
//         numOfCams = 0;
//         covered.insert(NULL);
        
//         postorder(root, NULL);
        
//         return numOfCams;
//     }
// };



// Ref: https://www.youtube.com/watch?v=2Gh5WPjAgJk
// Space complexity: O(1) - 21.2 MB, less than 55.06% of C++ online submissions
//  Time complexity: O(N) - 19 ms, faster than 43.21% of C++ online submissions
class Solution {
public:
    int numOfCams;
    
    // Tree states: 
    //      0 --> No camera
    //      1 --> Covered by some camera
    //      2 --> Contains a camera
    int postorder(TreeNode *root){
        if(root == NULL) return 1;
        
        int left = postorder(root->left);
        int right = postorder(root->right);
        
        if(left == 0 || right == 0){
            numOfCams++;
            return 2;
        }
        else if(left == 2 || right == 2) return 1;
        else return 0;
    }
    
    int minCameraCover(TreeNode* root) {
        numOfCams = 0;
        
        return postorder(root) == 0 ? numOfCams + 1 : numOfCams;
    }
};
