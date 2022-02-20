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



// ITERATIVE SOLUTION
// Space complexity: O(1) - less than 42.47% of C++ online submissions
//  Time complexity: O(N) - faster than 68.61% of C++ online submissions
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev, *cur, *next;
        
        if(head == NULL || head->next == NULL) return head;
        
        prev = NULL;
        cur = head;
        
        while(cur != NULL){
            next = cur->next;
            
            cur->next = prev;
            
            prev = cur;
            cur = next;
        }
        
        
        return prev;
    }
};



// RECURSIVE SOLUTION
// Space complexity: O(N) - less than 10.49% of C++ online submissions
//  Time complexity: O(N) - faster than 14.61% of C++ online submissions
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(head == NULL) return NULL;
        
//         ListNode* newHead = head;
        
//         // if there's still a subproblem
//         if(head->next != NULL){
//             newHead = reverseList(head->next);
//             head->next->next = head;
//         }
        
//         head->next = NULL;
        
//         return newHead;
//     }
// };
