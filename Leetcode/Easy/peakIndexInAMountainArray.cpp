// Space complexity: O(1) - 11.6 MB, less than 50.09% of C++ online submissions
//  Time complexity: O(logN) - 12 ms, faster than 69.26% of C++ online submissions
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left, right, middle;
        
        left = 0, right = arr.size() - 1;
        
        while(left < right){
            middle = left + (right - left) / 2;
            
            if(arr[middle] < arr[middle + 1]) left = middle + 1;
            else right = middle;
        }
        
        return left;
    }
};
