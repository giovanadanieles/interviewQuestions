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



// Space complexity: O(N) - 18.2 MB, less than 42.46% of C++ online submissions
//  Time complexity: O(N) - 58 ms, faster than 40.69% of C++ online submissions
// class Solution {
// public:
//     void reorderList(ListNode* head) {
//         ListNode *slow, *fast;
//         stack<ListNode*> stck;
        
//         slow = fast = head;
        
//         while(fast != NULL && fast->next != NULL){
//             slow = slow->next;
//             fast = fast->next->next;
//         }
        
//         fast = slow;
//         slow = slow->next;
        
//         while(slow != NULL){
//             stck.push(slow);
//             slow = slow->next;
//         }
        
//         fast->next = NULL;
//         fast = slow = head;
        
//         while(!stck.empty()){
//             fast = slow->next;
            
//             slow->next = stck.top();
//             stck.pop();
            
//             slow->next->next = fast;
//             slow = slow->next->next;
//         }   
//     }
// };



// Space complexity: O(1) - 17.8 MB, less than 51.45% of C++ online submissions
//  Time complexity: O(N) - 42 ms, faster than 80.28% of C++ online submissions
class Solution {
public:
    void reorderList(ListNode* head) {
        // 1st step: reverse second half of the list
        // 2nd step: merge the elements from the two halves
        
        ListNode *slow, *fast, *prev, *cur;
        
        if(head->next == NULL || head->next->next == NULL) return;
        
        slow = fast = head;
        while(fast != NULL && fast->next != NULL){
            if(fast->next->next != NULL) slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = slow->next;
        slow->next = NULL;
        
        prev = NULL;
        cur = fast;
        
        while(cur != NULL){
            fast = cur->next;
            cur->next = prev;
            
            prev = cur;
            cur = fast;
        }
        
        slow = head, fast = prev;
                        
        while(fast != NULL){
            cur = slow->next;
            slow->next = fast;
            
            fast = fast->next;
            slow->next->next = cur;
            
            slow = slow->next->next;
        }
    }
};
