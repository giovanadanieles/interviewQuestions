// Space complexity: O(N) - 14.3 MB, less than 32.08% of C++ online submissions
//  Time complexity: O(N) -  8 ms, faster than 60.28% of C++ online submissions
class Solution {
public:
    bool binarySearch(vector<int>& v, int target){
        int left, right, middle;
        
        left = 0, right = v.size() - 1;
        
        while(left <= right){
            middle = left + (right - left) / 2;
            
            if(v[middle] == target) return true;
            
            if(v[middle] < target) left = middle + 1;
            else right = middle - 1;
        }
        
        return false;
    }
    
    bool search(vector<int>& nums, int target) {
        int pivot;
        
        for(unsigned int i = 1; i < nums.size(); i++){
            if(nums[i - 1] > nums[i]){
                pivot = i;
                break;
            }
        }
        
        vector<int> v1 = {nums.begin(), nums.begin() + pivot};
        vector<int> v2 = {nums.begin() + pivot, nums.end()};
        
        return binarySearch(v1, target) || binarySearch(v2, target);
    }
};
