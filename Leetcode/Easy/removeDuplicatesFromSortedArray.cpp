/*
Runtime: 16 ms, faster than 85.44% of C++ online submissions for Remove Duplicates from Sorted Array.
Memory Usage: 14.2 MB, less than 99.99% of C++ online submissions for Remove Duplicates from Sorted Array.

Best Solution: v.erase(unique(v.begin(), v.end()), v.end())
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unsigned int j = 1;
        int i = 0;
        
        while(j < nums.size()){
            if(nums[i + 1] <= nums[i]){
                if(j == 1) j = i + 2;

                while(j < nums.size() && nums[i] >= nums[j]){
                    j++;
                } 

                if(j < nums.size()){
                    nums[i + 1] = nums[j];

                    i = i + 1;
                    j++;
                }
            }
            else{
                i++;
                j++;
            }
        }
        
        if(nums.size() < 1) return 0;
        else return i + 1;
    }
};
