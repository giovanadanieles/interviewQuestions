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



// Space complexity: O(3N) - 12.9 MB, less than 67.98% of C++ online submissions
//  Time complexity: O(N log N) - 11 ms, faster than 30.10% of C++ online submissions
class Compare {
    public:
        bool operator() (pair<int, int> a, pair<int, int> b) {
            if(a.first == b.first) return a.second > b.second;
            else return a.first > b.first;
        }
};

class Solution {
public:
    int minVPos = INT_MAX, maxVPos = INT_MIN; 
    unordered_map<int, priority_queue<pair<int, int>, vector<pair<int, int>>, Compare>> positionNumbers;

    void inOrder(TreeNode *root, int y, int x){
        if(root == NULL) return;

        inOrder(root->left, y - 1, x + 1);
        
        minVPos = min(minVPos, y);
        maxVPos = max(maxVPos, y);
        
        positionNumbers[y].push({x, root->val});
        
        inOrder(root->right, y + 1, x + 1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<int> aux;
        vector<vector<int>> ans;
        
        inOrder(root, 0, 0);
        
        for(int i = minVPos; i <= maxVPos; i++){
            if(positionNumbers.find(i) != positionNumbers.end()){
                aux.clear();
                
                while(!positionNumbers[i].empty()){
                    aux.push_back(positionNumbers[i].top().second);
                    positionNumbers[i].pop();
                }

                ans.push_back(aux);
            }
        }
        
        return ans;
    }
};
