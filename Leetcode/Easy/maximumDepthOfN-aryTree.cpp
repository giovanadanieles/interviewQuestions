/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/



// Space complexity: O(max(W, H)) - 11.6 MB, less than 5.47% of C++ online submissions
//  Time complexity: O(V * log V) - 43 ms, faster than 5.22% of C++ online submissions
// class Solution {
// public:
//     int maxDepth(Node* root) {
//         if(root == NULL) return 0;
        
//         priority_queue<int> depths;
//         for(unsigned int i = 0; i < root->children.size(); i++){
//             depths.push(maxDepth(root->children[i]));
//         }
        
//         if(root->children.size() > 0) return 1 + depths.top();
//         else return 1;
//     }
// };



// Space complexity: O(H) - 10.8 MB, less than 33.36% of C++ online submissions
//  Time complexity: O(V + E) - 20 ms, faster than 55.73% of C++ online submissions
class Solution {
public:
    int maxDepth(Node* root) {
        if(root == NULL) return 0;
        
        int ans = 0;
        
        for(unsigned int i = 0; i < root->children.size(); i++){
            ans = max(ans, maxDepth(root->children[i]));
        }
        
        return ans + 1;
    }
};
