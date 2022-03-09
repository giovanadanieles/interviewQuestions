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



// Space complexity: O(log N) - less than 94.34% of C++ online submissions
//  Time complexity: O(N) - faster than 91.48% of C++ online submissions
class Solution {
    TreeNode* solve(int left, int right, vector<int>& nums){
        if(left > right) return NULL;
        
        int middle = left + (right - left) / 2;
        
        TreeNode* root = new TreeNode(nums[middle]);
        root->left = solve(left, middle - 1, nums);
        root->right = solve(middle + 1, right, nums);
        
        return root;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(0, nums.size() - 1, nums);
    }
};
