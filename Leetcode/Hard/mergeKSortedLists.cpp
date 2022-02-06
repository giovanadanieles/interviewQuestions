// Space complexity: O(N) - less than 16.02% of C++ online submissions
//  Time complexity: O(N log N) - faster than 98.45% of C++ online submissions

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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int, int> frequencies;
        ListNode *ans, *cur, *next;
        
        if(lists.size() == 0){
            ans = NULL;
            
            return ans;
        }
        
        for(unsigned int i = 0; i < lists.size(); i++){
            cur = lists[i];
            
            while(cur != NULL){
                frequencies[cur->val]++;
                
                cur = cur->next;
            }
        }
        
        map<int, int>::iterator it, aux;
        for(it = frequencies.begin(); it != frequencies.end(); it++){
            aux = it;
            aux++;
            
            if(frequencies.size() != 0){
                if(it == frequencies.begin()){
                    cur = new ListNode();
                    ans = cur;
                }

                for(int i = 0; i < it->second; i++){
                    next = new ListNode();

                    cur->val = it->first;
                    cur->next = next;

                    if(i == it->second - 1 && aux == frequencies.end()) cur->next = NULL;

                    cur = cur->next;
                }   
            }
        }
        
        return ans;
    }
};
