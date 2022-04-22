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



// Space complexity: O(N) - 24.1 MB, less than 59.88% of C++ online submissions
//  Time complexity: O(N), O(1), O(1) - 36 ms, faster than 62.03% of C++ online submissions
// class BSTIterator {
// public:
//     int curPos;
//     vector<int> ordered;
    
//     void inOrder(TreeNode *root){
//         if(root == NULL) return;
        
//         inOrder(root->left);
//         ordered.push_back(root->val);
//         inOrder(root->right);
//     }
    
//     BSTIterator(TreeNode* root) {
//         inOrder(root);
//         curPos = -1;
//     }
    
//     int next() {
//         return ordered[++curPos];
//     }
    
//     bool hasNext() {
//         return curPos < (int)ordered.size() - 1;
//     }
// };



// Space complexity: O(H) - 24.1 MB, less than 87.81% of C++ online submissions
//  Time complexity: O(1), average - 35 ms, faster than 66.13% of C++ online submissions
class BSTIterator {
public:
    stack<TreeNode*> stck;
    
    void addAllLeft(TreeNode *root){
        while(root != NULL){
            stck.push(root);
            root = root->left;
        }
    }
    
    BSTIterator(TreeNode* root) {
        addAllLeft(root);
    }
    
    int next() {
        TreeNode *cur = stck.top();
        stck.pop();
        
        addAllLeft(cur->right);
        
        return cur->val;
    }
    
    bool hasNext() {
        return !stck.empty();
    }
};



/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
