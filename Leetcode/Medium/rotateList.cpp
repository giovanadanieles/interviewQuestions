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



// Space complexity: O(1) - less than 55.87% of C++ online submissions
//  Time complexity: O(2N) = O(N) - faster than 94.34% of C++ online submissions
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == NULL || head->next == NULL) return head;
        
        int noOfNodes = 1, cut;
        ListNode *cur, *newHead;
        
        cur = head;
        
        do{
            cur = cur->next;
            noOfNodes++;
            
        } while(cur->next != NULL);
        
        cut = (k % noOfNodes);              
        if(cut == 0) return head;
                
        cur->next = head;
        
        while((noOfNodes - cut) >= 1){
            cut++;
            cur = cur->next;
        }
        
        newHead = cur->next;
        cur->next = NULL;
                
        return newHead;
    }
};
