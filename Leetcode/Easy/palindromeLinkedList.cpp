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



// Space complexity: O(N/2) = O(N) - 120.8 MB, less than 39.40% of C++ online submissions
//  Time complexity: O(2*N) = O(N) -  332 ms, faster than 45.42% of C++ online submissions
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         int listSize = 0, halfList;
//         ListNode* cur;
//         stack<int> firstItems;
        
//         cur = head;
//         while(cur != NULL){
//             listSize++;
//             cur = cur->next;
//         }
        
//         cur = head, halfList = listSize / 2;;
//         while(halfList > 0){
//             firstItems.push(cur->val);
//             cur = cur->next, halfList--;
//         }
        
//         if(listSize % 2 == 1) cur = cur->next;
        
//         while(cur != NULL){
//             if(firstItems.top() != cur->val) return false;
            
//             firstItems.pop();
//             cur = cur->next;
//         }
        
//         return true;
//     }
// };



// Space complexity: O(1) - 114.2 MB, less than 72.31% of C++ online submissions
//  Time complexity: O(N) - 168 ms, faster than 98.60% of C++ online submissions
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow, *fast, *prev, *aux;
        
        slow = fast = head;
        
        // finding middle (slow)
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // reversing second half of the list
        prev = NULL;
        while(slow != NULL){
            aux = slow->next;
            slow->next = prev;
            prev = slow;
            slow = aux;
        }
        
        while(prev != NULL){
            if(head->val != prev->val) return false;
            
            head = head->next, prev = prev->next;
        }
        
        return true;
    }
};
