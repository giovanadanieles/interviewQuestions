// Ref: https://www.youtube.com/watch?v=yN38EEUOdao
// Space complexity: O(N) - 63.5 MB, less than 30.03% of C++ online submissions
//  Time complexity: O(NlogN) - 511 ms, faster than 23.05% of C++ online submissions
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int maxTime = 0, greaterTime;
        priority_queue<int> finishTimes;
        
        sort(courses.begin(), courses.end(), [](auto &a, auto &b) {
             return a[1] < b[1];});
        
        for(auto course : courses){
            int duration = course[0], lastDay = course[1];
            
            finishTimes.push(duration);
            maxTime += duration;
            
            if(maxTime > lastDay){
                greaterTime = finishTimes.top();
                finishTimes.pop();
                
                maxTime -= greaterTime;
            }
        }
        
        return finishTimes.size();
    }
};
