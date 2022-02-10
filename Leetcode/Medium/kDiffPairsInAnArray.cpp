// Space complexity: O(N) - less than 37.23% of C++ online submissions
//  Time complexity: O(N) - faster than 74.86% of C++ online submissions
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans = 0;         
        unordered_map<int, int> frequencies;
        
        for(unsigned int i = 0; i < nums.size(); i++){
            frequencies[nums[i]]++;
        }
            
        unordered_map<int, int>::iterator it;
        for(it = frequencies.begin(); it != frequencies.end(); it++){
            if(k == 0){
                if(it->second > 1) ans++;
            }
            else{
                if(frequencies.find(k + it->first) != frequencies.end()) ans++;  
            }     
        }
        
        return ans;
    }
};
