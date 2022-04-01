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



// Space complexity: O(N) - 11.6 MB, less than 96.07% of C++ online submissions
//  Time complexity: O(N) - 23 ms, faster than 83.01% of C++ online submissions
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        int curSize;
        queue<Node*> q;
        vector<int> temp;
        vector<vector<int>> order;
        
        if(root == NULL) return order;
        
        q.push(root);
        
        while(!q.empty()){
            temp.clear();
            curSize = q.size();
            
            while(curSize > 0){
                for(unsigned int i = 0; i < q.front()->children.size(); i++){
                    q.push(q.front()->children[i]);
                }
                
                temp.push_back(q.front()->val);
                q.pop();
                
                curSize--;
            }
            
            order.push_back(temp);
        }
        
        return order;
    }
};
