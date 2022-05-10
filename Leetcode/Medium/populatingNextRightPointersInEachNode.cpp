/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/



// Space complexity: O(W) - 17 MB, less than 51.87% of C++ online submissions
//  Time complexity: O(N) - 20 ms, faster than 80.63% of C++ online submissions
// class Solution {
// public:
//     Node* connect(Node* root) {
//         int curLevelSize;
//         Node *cur, *head;
//         queue<Node*> q;
        
//         if(root == NULL) return NULL;
//         else q.push(root), head = root;
        
//         while(!q.empty()){
//             curLevelSize = q.size();
            
//             while(curLevelSize > 0){
//                 cur = q.front(), q.pop();
                
//                 if(curLevelSize > 1) cur->next = q.front();
//                 else cur->next = NULL;
                
//                 if(cur->left != NULL) q.push(cur->left);
//                 if(cur->right != NULL) q.push(cur->right);
                
//                 curLevelSize--;
//             }
//         }
        
//         return head;
//     }
// };



// Ref: https://www.youtube.com/watch?v=U4hFQCa1Cq0

// Space complexity: O(1) - 16.8 MB, less than 68.04% of C++ online submissions
//  Time complexity: O(N) - 34 ms, faster than 23.33% of C++ online submissions
class Solution {
public:
    Node* connect(Node* root) {
        Node *cur, *nxt;
        
        cur = root, nxt = root != NULL ? root->left : NULL;
        
        while(cur != NULL && nxt != NULL){
            cur->left->next = cur->right;
            
            if(cur->next != NULL){
                cur->right->next = cur->next->left;
                cur = cur->next;
            }
            else{
                cur = nxt;
                nxt = cur->left;
            }
        }
        
        return root;
    }
};
