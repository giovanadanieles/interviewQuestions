// Space complexity: O(1) - less than 22.48% of C++ online submissions
//  Time complexity: O(log N) - faster than 100.00% of C++ online submissions

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left, right, mid;
        
        left = 1, right = n;
        
        while(left < right){
            mid = left + (right - left) / 2;
            
            if(isBadVersion(mid) == false) left = mid + 1;
            else right = mid;
        }
        
        return left;
    }
};
