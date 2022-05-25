// Ref 1: https://leetcode.com/problems/russian-doll-envelopes/discuss/2071477/Best-Explanation-with-Pictures
// Ref 2: https://leetcode.com/problems/russian-doll-envelopes/discuss/2072549/C%2B%2B-or-2-Approaches-well-Explained-O(N2)-and-O(NlogN)-or-Easy-and-clean-Code

// Space complexity: O(N) - 77.5 MB, less than 92.11% of C++ online submissions
//  Time complexity: O(NlogN) - 520 ms, faster than 43.38% of C++ online submissions
class Solution {
public:
    static bool customCmp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]) return a[1] > b[1];
        else return a[0] < b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int index;
        vector<int> lis;
        
        sort(envelopes.begin(), envelopes.end(), customCmp);
        
        for(int i = 0; i < envelopes.size(); i++){
            index = lower_bound(lis.begin(), lis.end(), envelopes[i][1]) - lis.begin();
            
            if(index >= lis.size()) lis.push_back(envelopes[i][1]);
            else lis[index] = envelopes[i][1];
        }
        
        return lis.size();
    }
};
