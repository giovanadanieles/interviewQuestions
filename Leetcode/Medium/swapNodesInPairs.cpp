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



// Space complexity: O(1) - less than 55.41% of C++ online submissions
//  Time complexity: O(N) - faster than 57.52% of C++ online submissions
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *cur, *next_, *prev = NULL;
                
        cur = head;
        
        while(cur != NULL && cur->next != NULL){
            next_ = cur->next;
                                    
            if(prev != NULL) prev->next = next_;
            cur->next = next_->next;
            next_->next = cur;

            if(cur == head) head = next_;
            
            prev = next_->next;
            
            if(next_->next != NULL) cur = next_->next->next;
            else cur = next_->next;
        }
        
        return head;
      
    }
};
