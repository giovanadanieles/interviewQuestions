/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */



// Space complexity: O(1) - 180.1 MB, less than 89.18% of C++ online submissions
//  Time complexity: O(2N) - 1175 ms, faster than 12.17% of C++ online submissions
// class Solution {
// public:
//     ListNode* swapNodes(ListNode* head, int k) {
//         int numOfNodes = 0;
//         ListNode *cur, *first, *second;
        
//         cur = head;
//         while(cur != NULL){
//             numOfNodes ++;
            
//             if(numOfNodes == k) first = cur;
            
//             cur = cur->next;
//         }
        
//         numOfNodes -= k;
        
//         cur = head;
//         while(numOfNodes > 0){
//             cur = cur->next;
//             numOfNodes--;  
//         }
//         second = cur;
        
//         swap(first->val, second->val);
        
//         return head;
//     }
// };



// Space complexity: O(1) - 180.1 MB, less than 57.49% of C++ online submissions
//  Time complexity: O(N) - 580 ms, faster than 96.08% of C++ online submissions
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *first, *last = NULL;
        
        for(ListNode *cur = head; cur != NULL; cur = cur->next){
            
            if(last != NULL) last = last->next;
            
            k--;
            
            if(k == 0){
                first = cur;
                last = head;
            }
        }
        
        swap(first->val, last->val);
        
        return head;
    }
};
