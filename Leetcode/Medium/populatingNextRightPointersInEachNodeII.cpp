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



// Space complexity: O(N) - 17.6 MB, less than 44.54% of C++ online submissions
//  Time complexity: O(N) - 8 ms, faster than 97.04% of C++ online submissions
// class Solution {
// public:
//     Node* connect(Node* root) {
//         int curLevelSize;
//         Node *curNode;
//         queue<Node*> q;
        
//         if(root == NULL) return root;
        
//         q.push(root);
        
//         while(!q.empty()){
//             curLevelSize = (int)q.size();
            
//             while(curLevelSize > 0){
//                 curNode = q.front();
//                 q.pop();
                
//                 if(curLevelSize > 1) curNode->next = q.front();
//                 else curNode->next = NULL;
                
//                 if(curNode->left != NULL) q.push(curNode->left);
//                 if(curNode->right != NULL) q.push(curNode->right);
                
//                 curLevelSize--;
//             }
//         }
        
//         return root;
//     }
// };



// Space complexity: O(1) - 17.2 MB, less than 99.32% of C++ online submissions
//  Time complexity: O(N) - 12 ms, faster than 86.96% of C++ online submissions
// class Solution {
// public:
//     Node* connect(Node* root) {
//         Node *head = root;
        
//         while(head != NULL){
//             Node *dummy = NULL;
//             Node *temp = dummy;
            
//             while(head != NULL){
//                 if(head->left != NULL){
//                     if(temp == NULL){
//                         dummy = head->left;
//                         temp = head->left;
//                     } 
//                     else{
//                         temp->next = head->left;
//                         temp = temp->next;
//                     }
//                 }
//                 if(head->right != NULL){
//                     if(temp == NULL){
//                         dummy = head->right;
//                         temp = head->right;
//                     }
//                     else{
//                         temp->next = head->right;
//                         temp = temp->next;
//                     }
//                 }
                
//                 head = head->next;
//             }
            
//             head = dummy;
//         }
        
//         return root;
//     }
// };



// Ref: https://www.youtube.com/watch?v=yl-fdkyQD8A
// Space complexity: O(1) - 17.2 MB, less than 99.32% of C++ online submissions
//  Time complexity: O(N) - 20 ms, faster than 43.23% of C++ online submissions
class Solution {
public:
    Node* connect(Node* root) {
        Node *head = root;
        
        while(head != NULL){
            Node *dummy = new Node();
            Node *temp = dummy;
            
            while(head != NULL){
                if(head->left != NULL){
                    temp->next = head->left;
                    temp = temp->next;
                }
                
                if(head->right != NULL){
                    temp->next = head->right;
                    temp = temp->next;
                }
                
                head = head->next;
            }
            
            head = dummy->next;
        }
        
        return root;
    }
};
