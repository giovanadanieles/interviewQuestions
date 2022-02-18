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



// Space complexity: O(N + M) - less than 9.16% of C++ online submissions
//  Time complexity: O(N + M) - faster than 34.80% of C++ online submissions
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         ListNode *head, *cur;
        
//         if(list1 == NULL && list2 == NULL) return NULL;
        
//         head = new ListNode();
        
//         if(list1 != NULL && list2 != NULL){
//             if(list1->val <= list2->val){
//                 head->val = list1->val;
//                 list1 = list1->next;
//             }
//             else{
//                 head->val = list2->val;
//                 list2 = list2->next;
//             }
//         }
//         else if(list1 == NULL){
//             head->val = list2->val;
//             list2 = list2->next;
//         }
//         else{
//             head->val = list1->val;
//             list1 = list1->next;
//         }
        
//         cur = head;
        
//         while(list1 != NULL || list2 != NULL){
//             if(list1 != NULL && list2 != NULL){
//                 if(list1->val <= list2->val){
//                     cur->next = new ListNode(list1->val);
//                     list1 = list1->next;
//                 }
//                 else{
//                     cur->next = new ListNode(list2->val);
//                     list2 = list2->next;
//                 }
//             }
//             else if(list2 == NULL){
//                 cur->next = new ListNode(list1->val);    
//                 list1 = list1->next;
//             }
//             else{
//                 cur->next = new ListNode(list2->val);
//                 list2 = list2->next;
//             }
            
//             cur = cur->next;
//         }
        
//         return head;
//     }
// };



// Space complexity: O(1) - less than 45.23% of C++ online submissions
//  Time complexity: O(N + M) - faster than 76.05% of C++ online submissions
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head, *cur;
        
        if(list1 == NULL && list2 == NULL) return NULL;
        
        head = new ListNode();
        
        cur = head;
        
        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                cur->next = list1;
                list1 = list1->next;
            }
            else{
                cur->next = list2;
                list2 = list2->next;
            }
            
            cur = cur->next;
        }
        
        if(list1 != NULL) cur->next = list1;
        else if(list2 != NULL) cur->next = list2;
        
        return head->next;
    }
};
