// Space complexity: O(1) - 89.9 MB, less than 47.76% of C++ online submissions
//  Time complexity: O(NlogN) - 653 ms, faster than 36.14% of C++ online submissions
class Solution {
public:
    static bool sortByEndTime(vector<int> &a, vector<int> &b){
        if(a[1] < b[1]) return true;
        else if(a[1] > b[1]) return false;
        else return a[0] < b[0];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int removed = 0;
        
        sort(intervals.begin(), intervals.end(), sortByEndTime);
        
        for(int left = 0, right = 1; right < (int)intervals.size(); right++){
            if(intervals[left][1] > intervals[right][0]) removed++;
            else left = right;
        }
        
        return removed;
    }
};
