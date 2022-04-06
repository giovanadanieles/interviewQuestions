// Space complexity: O(1) - 15.7 MB, less than 43.36% of C++ online submissions
//  Time complexity: O(N) - 12 ms, faster than 86.73% of C++ online submissions
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left, right;
        vector<int> ans;
        
        left = 0, right = numbers.size() - 1;   
        while(left < right){
            if(numbers[left] + numbers[right] == target){
                ans.push_back(left + 1), ans.push_back(right + 1);
                return ans;
            }
            
            if(numbers[left] + numbers[right] < target) left++;
            else right--;
        }
        
        return ans;
    }
};
