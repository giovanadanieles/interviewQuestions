/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */



// Space complexity: O(N) - less than 13.46% of C++ online submissions
//  Time complexity: O(N) - faster than 30.25% of C++ online submissions
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         unordered_set<ListNode*> lists;
        
//         while(head != NULL){
//             if(lists.find(head) == lists.end()) lists.insert(head);
//             else return true;
            
//             head = head->next;
//         }
        
//         return false;
//     }
// };



// Space complexity: O(1) - less than 81.61% of C++ online submissions
//  Time complexity: O(N) - faster than 83.93% of C++ online submissions
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow, *fast;
        
        if(head == NULL || head->next == NULL) return false;
        
        slow = head;
        fast = head->next;
        
        while(slow != NULL && fast != NULL){
            if(slow == fast) return true;
            
            slow = slow->next;
            if(fast->next != NULL) fast = fast->next->next;
            else fast = fast->next;
        }
        
        return false;
    }
};
