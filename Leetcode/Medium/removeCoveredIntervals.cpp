// Space complexity: O(N) - less than 59.43% of C++ online submissions
//  Time complexity: O(N) - faster than 60.96% of C++ online submissions
class Solution {
public:
    typedef pair<int, int> pii;
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<pii> ans;
        
        if(intervals.size() == 0) return 0;
        
        sort(intervals.begin(), intervals.end());
        
        ans.push_back(make_pair(intervals[0][0], intervals[0][1]));
        
        for(unsigned int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] > ans[ans.size() - 1].second)
                ans.push_back(make_pair(intervals[i][0], intervals[i][1]));
            else{
                if(intervals[i][1] <= ans[ans.size() - 1].second ||
                   intervals[i][0] == ans[ans.size() - 1].first){
                    ans[ans.size() - 1].second = max(ans[ans.size() - 1].second, intervals[i][1]);
                }
                else ans.push_back(make_pair(intervals[i][0], intervals[i][1]));
            }
        }
        
        return ans.size();
    }
};
