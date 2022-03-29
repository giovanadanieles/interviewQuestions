// Space complexity: O(1) -  61.2 MB, less than 91.55% of C++ online submissions
//  Time complexity: O(N) - 104 ms, faster than 91.60% of C++ online submissions
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow1 = 0, slow2 = 0, fast = 0;
                
        do{
            slow1 = nums[slow1];
            fast = nums[nums[fast]];
        } while(slow1 != fast);
    
        // finding the exact intersection
        do{
            slow1 = nums[slow1];
            slow2 = nums[slow2];
        } while(slow1 != slow2);
        
        return slow1;
    }
};
