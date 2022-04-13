// Space complexity: O(N) - 25.8 MB, less than 67.82% of C++ online submissions
//  Time complexity: O(N) - 32 ms, faster than 78.54% of C++ online submissions
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int obtainedDigit = first;
        vector<int> ans;
        
        // the inverse of XOR is XOR itself :o
        
        ans.push_back(first);
        
        for(int digit : encoded){
            obtainedDigit = digit ^ obtainedDigit;
            ans.push_back(obtainedDigit);
        }
        
        return ans;
    }
};
