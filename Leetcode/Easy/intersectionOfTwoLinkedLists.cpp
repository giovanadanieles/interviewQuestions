/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val        else greater = 2;;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */



// Space complexity: O(1) - less than 88.99% of C++ online submissions
//  Time complexity: O(M + N) - faster than 65.53% of C++ online submissions
class Solution {
public:
    pair<int, int> helper(ListNode *headA, ListNode *headB){
        pair<int, int> listsSize;
        
        while(headA != NULL && headB != NULL){
            listsSize.first++, listsSize.second++;
            headA = headA->next, headB = headB->next;
        }
        
        if(headA!= NULL){
            while(headA != NULL){
                listsSize.first++;
                headA = headA->next;
            }
        }
        else{
            while(headB != NULL){
                listsSize.second++;
                headB = headB->next;
            }
        }
        
        return listsSize;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int dif, greater;
        pair<int, int> listsSize;
        
        listsSize = helper(headA, headB);
        
        if(listsSize.first >= listsSize.second) greater = 1;
        else greater = 2;
        
        dif = abs(listsSize.first - listsSize.second);
        
        while(dif > 0){
            greater == 1 ? headA = headA->next : headB = headB->next;
            dif--;
        }
        
        while(headA != NULL && headB != NULL){
            if(headA == headB) return headA;
            
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }
};
