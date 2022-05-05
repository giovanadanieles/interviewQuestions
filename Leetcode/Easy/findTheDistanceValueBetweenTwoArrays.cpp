// Ref: https://leetcode.com/problems/find-the-distance-value-between-two-arrays/discuss/1909718/C%2B%2B-oror-Binary-Search-approach

// Space complexity: O(1) - 13 MB, less than 73.59% of C++ online submissions
//  Time complexity: O(NlogN) - 15 ms, faster than 56.06% of C++ online submissions
class Solution {
public:  
    bool isValid(vector<int> &arr, int x, int d){
        int left, right, middle;
        
        left = 0, right = arr.size() - 1;
        while(left <= right){
            middle = left + (right - left) / 2;
            
            if(abs(arr[middle] - x) <= d) return false;
            else if(arr[middle] < x) left = middle + 1;
            else right = middle - 1;    
        }
        
        return true;
    }
    
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        
        sort(arr2.begin(), arr2.end());
        
        for(unsigned int i = 0; i < arr1.size(); i++){            
            if(isValid(arr2, arr1[i], d) == true) ans++;
        }
        
        return ans;
    }
};
