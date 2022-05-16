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



// Space complexity: O(1) - 10.4 MB, less than 96.31% of C++ online submissions
//  Time complexity: O(N) - 11 ms, faster than 88.63% of C++ online submissions
// class Solution {
// public:
//     ListNode* oddEvenList(ListNode* head){
//         if(head == NULL || head->next == NULL) return head;
        
//         ListNode *cur, *oldTail, *newTail;
        
//         oldTail = head;
//         while(oldTail->next != NULL) oldTail = oldTail->next;
        
//         cur = head, newTail = oldTail;
//         while(cur != oldTail){
//             newTail->next = cur->next;
//             cur->next = cur->next->next;
                        
//             cur = cur->next;
//             newTail = newTail->next;
//             newTail->next = NULL; 
            
//             if(newTail == oldTail) break;
//         }
        
//         return head;
//     }
// };



// Space complexity: O(1) - 10.4 MB, less than 76.14% of C++ online submissions
//  Time complexity: O(N) - 11 ms, faster than 88.63% of C++ online submissions
class Solution {
public:
    ListNode* oddEvenList(ListNode* head){
        if(head == NULL) return head;
        
        ListNode *odd, *even, *evenHead;
        
        odd = head, even = evenHead = head->next;
        while(even != NULL && even->next != NULL){
            odd->next = even->next;
            odd = odd->next;
            
            even->next = odd->next;
            even = even->next;
        }
        
        odd->next = evenHead;
        
        return head;
    }
};
