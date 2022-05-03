// Space complexity: O(NlogN) - 27.4 MB, less than 32.30% of C++ online submissions
//  Time complexity: O(N) - 47 ms, faster than 40.90% of C++ online submissions
// class Solution {
// public:
//     int findUnsortedSubarray(vector<int>& nums) {
//         int leftMost = INT_MAX, rightMost = INT_MIN;
//         vector<int> ordered = nums;
        
//         sort(ordered.begin(), ordered.end());
        
//         for(int i = 0; i < (int)nums.size(); i++){
//             if(nums[i] != ordered[i]){
//                 leftMost = min(leftMost, i);
//                 rightMost = max(rightMost, i);
//             }
//         }
        
//         if(leftMost == INT_MAX && rightMost == INT_MIN) return 0;
//         else return leftMost != rightMost ? rightMost - leftMost + 1 : leftMost;
//     }
// };



// Space complexity: O(1) - 26.6 MB, less than 68.99% of C++ online submissions
//  Time complexity: O(N) - 40 ms, faster than 60.97% of C++ online submissions
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = -1, end = -1, prevHigh, prevLow;
        
        prevLow = 0, prevHigh = nums.size() - 1;
        
        for(int i = 0; i < (int)nums.size(); i++){
            if(nums[i] < nums[prevLow]) end = i;
            else prevLow = i;
        }
        
        for(int i = (int)nums.size() - 1; i >= 0; i--){
            if(nums[i] > nums[prevHigh]) start = i;
            else prevHigh = i;
        }
        
        return start != -1 && end != -1 ? end - start + 1 : 0;
    }
};
