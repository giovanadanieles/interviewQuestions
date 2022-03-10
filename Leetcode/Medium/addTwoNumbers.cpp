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



// Space complexity: O(max(N + M)) - less than 11.57% of C++ online submissions
//  Time complexity: O(max(N + M)) - faster than 59.66% of C++ online submissions
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         int carry = 0;
//         ListNode *sentinel, *cur, *next;
        
//         sentinel = new ListNode();
//         cur = new ListNode();
//         sentinel->next = cur;
        
        
//         while(l1 != NULL || l2 != NULL){
//             if(l1 != NULL && l2 != NULL){
//                 cur->val = (l1->val + l2->val + carry) % 10;
//                 carry = (l1->val + l2->val + carry) / 10;
                
//                 l1 = l1->next, l2 = l2->next;
//             }
//             else if(l1 != NULL){
//                 cur->val = (l1->val + carry) % 10;
//                 carry = (l1->val + carry) / 10;
                
//                 l1 = l1->next;
//             }
//             else{
//                 cur->val = (l2->val + carry) % 10;
//                 carry = (l2->val + carry) / 10;
                
//                 l2 = l2->next;
//             }
            
//             if(l1 != NULL || l2 != NULL){
//                 next = new ListNode();
//                 cur->next = next;
//                 cur = cur->next;
//             }    
//         }
        
//         if(carry != 0){
//             next = new ListNode();
//             cur->next = next;
//             cur = cur->next;
            
//             cur->val = carry;
//         }
        
//         return sentinel->next;
//     }
// };



// Space complexity: O(max(N + M)) - less than 50.05% of C++ online submissions
//  Time complexity: O(max(N + M)) - faster than 52.28% of C++ online submissions
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int x, y, carry = 0;
        ListNode *sentinel, *cur;
        
        cur = sentinel = new ListNode();
        
        while(l1 != NULL || l2 != NULL){
            x = 0;
            if(l1 != NULL){
                x = l1->val;
                l1 = l1->next;
            }
            
            y = 0;
            if(l2 != NULL){
                y = l2->val;
                l2 = l2->next;
            }
            
            cur->next = new ListNode((x + y + carry) % 10);
            carry = (x + y + carry) / 10;
            
            cur = cur->next;
        }
        
        if(carry != 0) cur->next = new ListNode(carry);
        
        return sentinel->next;
    }
};
