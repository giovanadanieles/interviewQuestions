// BRUTE FORCE SOLUTION
// Space complexity: O(1)
//  Time complexity: O(N ^ 2) - TLE
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int curArea, maximumArea = INT_MIN;
        
//         for(unsigned int left = 0; left < height.size(); left++){
//             for(unsigned int right = left + 1; right < height.size(); right++){
//                 curArea = (right - left) * min(height[left], height[right]);
//                 maximumArea = max(maximumArea, curArea);
//             }
//         }
        
//         return maximumArea;
//     }
// };



// Space complexity: O(1) -    59 MB, less than 38.67% of C++ online submissions
//  Time complexity: O(N) - 127 ms, faster than 46.84% of C++ online submissions
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left, right, curArea, maximumArea = INT_MIN;
        
        left = 0, right = height.size() - 1;
        
        while(left < right){
            curArea = (right - left) * min(height[left], height[right]);
            maximumArea = max(maximumArea, curArea);
            
            if(height[left] < height[right]) left++;
            else right--;
        }
        
        return maximumArea;
    }
};
