// Space complexity: O(N) - 18.9 MB, less than 85.31% of C++ online submissions
//  Time complexity: O(N log N) - 32 ms, faster than 96.46% of C++ online submissions
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        sort(intervals.begin(), intervals.end());
        
        ans.push_back(intervals[0]);
        
        for(unsigned int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= ans.back()[1]){ 
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else ans.push_back(intervals[i]);
        }
        
        return ans;
    }
};
