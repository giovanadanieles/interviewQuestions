// Space complexity: O(N) - 10.8 MB, less than 29.07% of C++ online submissions
//  Time complexity: O(N log N) - 8 ms, faster than 84.93% of C++ online submissions
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int ones, curNum;
        vector<int> ans;
        vector<pair<int, int>> onesFreq;
        
        for(unsigned int i = 0; i < arr.size(); i++){
            ones = 0, curNum = arr[i];
            
            while(curNum > 0){
                ones += curNum & 1;
                curNum >>= 1;
            }
            
            onesFreq.push_back({ones, arr[i]});
        }
        
        sort(onesFreq.begin(), onesFreq.end());
        
        for(unsigned int i = 0; i < onesFreq.size(); i++) ans.push_back(onesFreq[i].second);
        
        return ans;
    }
};
