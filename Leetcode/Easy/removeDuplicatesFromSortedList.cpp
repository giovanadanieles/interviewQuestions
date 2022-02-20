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



// Space complexity: O(1) - less than 36.25% of C++ online submissions
//  Time complexity: O(N) - faster than 38.94% of C++ online submissions
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur;
        
        if(head == NULL || head->next == NULL) return head;
        
        cur = head;
        
        while(cur->next != NULL){
            if(cur->next->val == cur->val) cur->next = cur->next->next;
            else cur = cur->next;
        }
        
        return head;
    }
};
