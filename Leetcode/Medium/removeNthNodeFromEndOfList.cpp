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



// Space complexity: O(1) - 10.7 MB, less than 75.22% of C++ online submissions
//  Time complexity: O(N) - 0 ms, faster than 100.00% of C++ online submissions 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = NULL;
        
        while(fast->next != NULL){
            fast = fast->next;
            
            if(n == 1) slow = head;
            else if(slow != NULL) slow = slow->next;
            
            n--;
        }
        
        if(slow == NULL) return head->next;
                        
        slow->next = slow->next->next;
        
        return head;
    }
};
