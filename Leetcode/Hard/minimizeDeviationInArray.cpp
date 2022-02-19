// Space complexity: O(N) - less than 83.44% of C++ online submissions
//  Time complexity: O(N logN logX), being X max vaue = O(N log^2 N)  - faster than 43.04% of C++ online submissions
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int value, maxValue, minValue = INT_MAX, diff = INT_MAX;
        priority_queue<int> orderedNumbers;
        
        for(unsigned int i = 0; i < nums.size(); i++){
            value = nums[i];
            if(value % 2 == 1) value *= 2;
            
            orderedNumbers.push(value);
            
            minValue = min(minValue, value);
        }
        
        while(orderedNumbers.top() % 2 == 0){
            maxValue = orderedNumbers.top();
            orderedNumbers.pop();
            
            diff = min(diff, maxValue - minValue);
            minValue = min(minValue, maxValue / 2);
            
            orderedNumbers.push(maxValue / 2);
        }
        
        return min(diff, orderedNumbers.top() - minValue);
    }
};
