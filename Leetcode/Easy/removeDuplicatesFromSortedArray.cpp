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
                    swap(nums[i + 1], nums[j]);

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
