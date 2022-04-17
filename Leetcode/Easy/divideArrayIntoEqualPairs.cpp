// Space complexity: O(N) - 14.7 MB, less than 30.34% of C++ online submissions
//  Time complexity: O(N) - 11 ms, faster than 93.95% of C++ online submissions
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        for(unsigned int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }
        
        for(auto it = freq.begin(); it != freq.end(); it++){
            if(it->second % 2 == 1) return false;
        }
        
        return true;
    }
};
