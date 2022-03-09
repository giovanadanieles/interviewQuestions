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



// Space complexity: O(1) - less than 20.51% of C++ online submissions
//  Time complexity: O(N) - faster than 32.14% of C++ online submissions
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *sentinel, *slow, *fast;
        
        sentinel = new ListNode(0, head);
        slow = sentinel;
        fast = head;
        
        while(fast != NULL){
            if(fast->next != NULL && fast->val == fast->next->val){
                while(fast->next != NULL && fast->val == fast->next->val){
                    fast = fast->next;
                }
                slow->next = fast->next;
            }
            else slow = slow->next;
                
            fast = fast->next;            
        }
        
        return sentinel->next;
    }
};
