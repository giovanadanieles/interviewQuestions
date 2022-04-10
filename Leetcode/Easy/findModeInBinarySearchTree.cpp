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



// Space complexity: O(N) - 25.3 MB, less than 56.05% of C++ online submissions
//  Time complexity: O(N) - 18 ms, faster than 87.25% of C++ online submissions
// class Solution {
// public:
//     void inOrder(TreeNode *root, unordered_map<int, int> &frequencies){
//         if(root == NULL) return;
        
//         inOrder(root->left, frequencies);
//         frequencies[root->val]++;
//         inOrder(root->right, frequencies);
//     }
    
//     vector<int> findMode(TreeNode* root) {
//         int greatestFreq = INT_MIN;
//         vector<int> ans;
//         unordered_map<int, int> frequencies;
        
//         inOrder(root, frequencies);
        
//         for(auto it = frequencies.begin(); it != frequencies.end(); it++){
//             greatestFreq = max(greatestFreq, it->second);
//         }
        
//         for(auto it = frequencies.begin(); it != frequencies.end(); it++){
//             if(it->second == greatestFreq) ans.push_back(it->first);
//         }
        
//         return ans;
//     }
// };



// Space complexity: O(H) - 24 MB, less than 80.15% of C++ online submissions
//  Time complexity: O(N) - 42 ms, faster than 18.68% of C++ online submissions
class Solution {
public:
    void inOrder(TreeNode *root, TreeNode* &prev, int &count, int &maxCount, vector<int> &modes){
        if(root == NULL) return;
        
        inOrder(root->left, prev, count, maxCount, modes);
        
        if(prev == NULL || root->val == prev->val) count++;
        else count = 1;
        
        if(count > maxCount){
            maxCount = count;
            modes = {root->val};
        }
        else if(count == maxCount) modes.push_back(root->val);
        
        prev = root;
        
        inOrder(root->right, prev, count, maxCount, modes);
    }
    
    vector<int> findMode(TreeNode* root) {
        int count = 0, maxCount = 0;
        TreeNode* prev = NULL;
        vector<int> modes;
        
        inOrder(root, prev, count, maxCount, modes);
        
        return modes;
    }
};
