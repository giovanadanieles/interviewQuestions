// Space complexity: O(N) - less than 61.67% of C++ online submissions
//  Time complexity: O(N log N) - faster than 45.75% of C++ online submissions
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int earn1 = 0, earn2 = 0, ans, aux;
        vector<int> noRepNums;
        unordered_map<int, int> numsFreq;
        
        for(unsigned int i = 0; i < nums.size(); i++){
            if(numsFreq.find(nums[i]) == numsFreq.end()) noRepNums.push_back(nums[i]);
            numsFreq[nums[i]]++;
        }
        
        sort(noRepNums.begin(), noRepNums.end());
        
        for(unsigned int i = 0; i < noRepNums.size(); i++){
            ans = noRepNums[i] * numsFreq[noRepNums[i]];
            
            if(i > 0 && noRepNums[i] == noRepNums[i - 1] + 1){
                aux = earn2;
                earn2 = max(ans + earn1, earn2);
                earn1 = aux;
            }
            else{
                ans += earn2;
                
                earn1 = earn2;
                earn2 = ans;
            }            
        }
        
        return earn2;
    }
};
