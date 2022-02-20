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



// Space complexity: O(1) - less than 47.58% of C++ online submissions
//  Time complexity: O(N) - faster than 56.88% of C++ online submissions
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *cur, *sentinel;
        
        sentinel = new ListNode();
        sentinel->next = head;
        
        cur = sentinel;
        
        while(cur != NULL){
            if(cur->next != NULL && cur->next->val == val){                
                cur->next = cur->next->next;
            }
            else cur = cur->next; 
        }
        
        return sentinel->next;
    }
};
