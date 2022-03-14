/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */



// Space complexity: O(1) - 7.7 MB, less than 39.92% of C++ online submissions
//  Time complexity: O(N) - 12 ms, faster than 86.76% of C++ online submissions
// class Solution {
// public:
//     void deleteNode(ListNode* node) {
//         ListNode *prev;
        
//         do{
//             node->val = node->next->val;
            
//             prev = node;
//             node = node->next;
//         }
//         while(node->next != NULL);
        
//         prev->next = NULL;
//     }
// };



// Space complexity: O(1) - 7.6 MB, less than 39.92% of C++ online submissions
//  Time complexity: O(1) - 23 ms, faster than 25.39% of C++ online submissions
class Solution {
public:
    void deleteNode(ListNode* node) {        
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
