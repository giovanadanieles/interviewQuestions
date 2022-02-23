/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/



// Space complexity: O(N) - less than 23.72% of C++ online submissions
//  Time complexity: O(N) - faster than 93.06% of C++ online submissions
class Solution {
public:
    unordered_map<Node*, Node*> oldToNew;
    
    Node* dfs(Node* node){
        if(oldToNew.find(node) != oldToNew.end()) return oldToNew[node];
        
        Node* copy = new Node(node->val);
        oldToNew[node] = copy;
        
        for(unsigned int i = 0; i < node->neighbors.size(); i++){
            copy->neighbors.push_back(dfs(node->neighbors[i]));
        }
        
        return copy;
    }
    
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        else return dfs(node);        
    }
};
