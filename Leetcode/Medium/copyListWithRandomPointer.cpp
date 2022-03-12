/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/



// Space complexity: O(N) - less than 88.04% of C++ online submissions
//  Time complexity: O(2N) = O(N) - faster than 40.57% of C++ online submissions
// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         unordered_map<Node*, Node*> oldToNew;
//         Node *sentinel, *cur;
        
//         if(head == NULL) return head;
        
//         sentinel = head;
        
//         while(head != NULL){
//             cur = new Node(head->val);
            
//             oldToNew.insert({head, cur});
            
//             head = head->next;
//         }
        
//         head = sentinel;
//         sentinel = oldToNew[head];
        
//         while(head != NULL){
//             cur = oldToNew[head];
            
//             if(cur != NULL){
//                 cur->next = oldToNew[head->next];
//                 cur->random = oldToNew[head->random];
//             }
                        
//             head = head->next;
//         }
        
//         return sentinel;
//     }
// };



// Space complexity: O(1) - less than 98.38% of C++ online submissions
//  Time complexity: O(3N) = O(N) - faster than 28.54% of C++ online submissions
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *sentinel, *next;
        
        if(head == NULL) return head;
        
        sentinel = head;
        while(head != NULL){
            next = new Node(head->val);
            
            next->next = head->next;
            head->next = next;
            
            head = head->next->next;
        }
        
        head = sentinel;
        while(head != NULL){
            if(head->random != NULL) head->next->random = head->random->next;
            
            head = head->next->next;
        }
        
        head = sentinel;
        next = sentinel = sentinel->next;
        while(next->next != NULL){
            head->next = next->next;
            next->next = next->next->next;
            
            next = next->next;
            head = head->next;
        }
        head->next = NULL;
       
        return sentinel;
    }
};
