// Space complexity: O(12 * 59) = O(1) - 6.3 MB, less than 88.08% of C++ online submissions
//  Time complexity: O(12 * 59) = O(1) - 6 ms, faster than 13.65% of C++ online submissions
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        
        for(int hour = 0; hour < 12; hour++){
            for(int minute = 0; minute < 60; minute++){
                if(__builtin_popcount(hour) + __builtin_popcount(minute) == turnedOn){
                    string result;
                    
                    if(minute < 10) result = to_string(hour) + ":0" + to_string(minute);
                    else result = to_string(hour) + ":" + to_string(minute);
                    
                    ans.push_back(result);
                }
            }
        }
        
        return ans;
    }
};
