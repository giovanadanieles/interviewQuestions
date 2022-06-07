// Ref: https://www.youtube.com/watch?v=ZI2z5pq0TqA
// Space complexity: O(N) - 21.8 MB, less than 9.49% of C++ online submissions
//  Time complexity: O(N) - 22 ms, faster than 42.94% of C++ online submissions
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int max_, ans = 0;
//         vector<int> maxLeft, maxRight;
        
//         max_ = 0;
//         for(unsigned int index = 0; index < height.size(); index++){
//             maxLeft.push_back(max_);
//             max_ = max(max_, height[index]);
//         }
        
//         max_ = 0;
//         for(int index = (int)height.size() - 1; index >= 0; index--){
//             maxRight.push_back(max_);
//             max_ = max(max_, height[index]);
//         }
        
//         reverse(maxRight.begin(), maxRight.end());
        
//         for(unsigned int index = 0; index < height.size(); index++){
//             if(min(maxLeft[index], maxRight[index]) - height[index] > 0){
//                 ans += min(maxLeft[index], maxRight[index]) - height[index];
//             }
//         }
        
//         return ans;
//     }
// };



// Space complexity: O(1) - 19.8 MB, less than 24.34% of C++ online submissions
//  Time complexity: O(N) - 17 ms, faster than 65.00% of C++ online submissions
class Solution {
public:
    int trap(vector<int>& height) {
        int left, right, leftMax, rightMax, ans = 0;
        
        if(height.size() == 0) return ans;
        
        left = 0, right = height.size() - 1;
        leftMax = height[left], rightMax = height[right];
        
        while(left < right){
            if(leftMax < rightMax){
                left++;
                leftMax = max(leftMax, height[left]);
                
                ans += leftMax - height[left];
            }
            else{
                right--;
                rightMax = max(rightMax, height[right]);
                
                ans += rightMax - height[right];
            }
        }
        
        return ans;
    }
};
