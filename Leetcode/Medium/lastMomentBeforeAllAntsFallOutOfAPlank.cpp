// Space complexity: O(1) - 22.7 MB, less than 86.19% of C++ online submissions
//  Time complexity: O(N), being N max(leftSize, rightSize) - 35 ms, faster than 48.54% of C++ online submissions
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = INT_MIN, maxSize;
        
        maxSize = max((int)left.size(), (int)right.size());
        
        for(unsigned int i = 0; i < maxSize; i++){
            if(i < left.size()) ans = max(ans, left[i] - 0);
            if(i < right.size()) ans = max(ans, n - right[i]);
        }
        
        return ans;
    }
};
