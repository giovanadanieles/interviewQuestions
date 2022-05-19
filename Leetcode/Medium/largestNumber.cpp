// Space complexity: O(N) - 11 MB, less than 89.21% of C++ online submissions
//  Time complexity: O(NlogN) - 12 ms, faster than 54.23% of C++ online submissions
class Solution {
public:
    static bool customCmp(int a, int b){
        string aStr = to_string(a), bStr = to_string(b), temp;

        temp = aStr;
        aStr += bStr;
        bStr += temp;

        return aStr > bStr;
    } 
    
    string largestNumber(vector<int>& nums) {
        string ans = "";
        
        sort(nums.begin(), nums.end(), customCmp);
        
        for(auto val : nums) ans += to_string(val);
        
        if(ans[0] == '0') return "0";
        else return ans;
    }
};
