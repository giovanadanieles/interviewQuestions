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



// Space complexity: O(log N)   - less than 10.92% of C++ online submissions
//  Time complexity: O(N log N) - faster than 32.94% of C++ online submissions
class Solution {
public:
    ListNode* getMidNode(ListNode* head){
        ListNode *slow, *fast;
        
        slow = head;
        fast = head->next;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode *sentinel, *tail;
        
        sentinel = new ListNode();
        tail = sentinel;
        
        while(left != NULL && right != NULL){
            if(left->val < right->val){
                tail->next = left;
                
                left = left->next;
            }
            else{
                tail->next = right;
                
                right = right->next;
            }
            
            tail = tail->next;
        }
        
        if(left != NULL) tail->next = left;
        if(right != NULL) tail->next = right;
        
        return sentinel->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        //splitting list into two halfs
        ListNode* left = head;
        ListNode* right = getMidNode(head);
        ListNode* rightBegin = right->next;
        
        right->next = NULL;
        right = rightBegin;
        
        left = sortList(left);
        right = sortList(right);
        
        return merge(left, right);
    }
};
