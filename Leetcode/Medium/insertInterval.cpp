// Space complexity: O(N) - 16.9 MB, less than 92.55% of C++ online submissions
//  Time complexity: O(N) - 20 ms, faster than 63.33% of C++ online submissions 
// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) { 
//         int oldSize, left = 0;
//         vector<vector<int>> ans;
                
//         oldSize = intervals.size();
//         for(unsigned int i = 0; i < intervals.size() && intervals.size() == oldSize; i++){
//             if(intervals[i][0] > newInterval[0]){
//                 intervals.insert(intervals.begin() + i, newInterval);
//             }
//         }
//         if(intervals.size() == oldSize) intervals.push_back(newInterval);
        
//         for(unsigned int i = 1; i < intervals.size(); i++){
//             if(intervals[left][1] >= intervals[i][0]){
//                 intervals[left][1] = max(intervals[i][1], intervals[left][1]);
//                 intervals[i][0] = INT_MIN;    
//             }
//             else{
//                 left++;
//                 while(left < i && intervals[left][0] == INT_MIN) left++;
//             }
//         }
        
//         for(unsigned int i = 0; i < intervals.size(); i++){
//             if(intervals[i][0] != INT_MIN) ans.push_back(intervals[i]);
//         }
        
//         return ans;
//     }
// };



// Space complexity: O(N) - 17 MB, less than 76.08% of C++ online submissions
//  Time complexity: O(N) - 29 ms, faster than 31.39% of C++ online submissions
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) { 
        vector<vector<int>> ans;
        
        for(unsigned int i = 0; i < intervals.size(); i++){
            // if and else if: there's no overlapping
            if(newInterval[1] < intervals[i][0]){
                ans.push_back(newInterval);
                ans.insert(ans.end(), intervals.begin() + i, intervals.end());
                return ans;
            }
            else if(newInterval[0] > intervals[i][1]){
                ans.push_back(intervals[i]);
            }
            // now handling overlapping
            else{
                newInterval = {min(newInterval[0], intervals[i][0]),
                               max(newInterval[1], intervals[i][1])};
            }
        }
        
        ans.push_back(newInterval);
        
        return ans;
    }
};
