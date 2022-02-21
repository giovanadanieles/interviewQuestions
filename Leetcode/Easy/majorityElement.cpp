// BOYER-MOORE MAJORITY VOTING ALGORITHM
// Space complexity: O(1) - less than 52.43% of C++ online submissions
//  Time complexity: O(N) - faster than 91.43% of C++ online submissions

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count, res;
        
        res = nums[0], count = 1;
        
        for(unsigned int i = 1; i < nums.size(); i++){
            if(nums[i] == res) count++;
            else{
                if(count == 0){
                    res = nums[i];
                    count = 1;
                }
                else count--;
            }
        }
        
        return res;
    }
};
