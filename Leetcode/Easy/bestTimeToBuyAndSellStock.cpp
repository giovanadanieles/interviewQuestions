// Space complexity: O(1) - less than 53.71% of C++ online submissions
//  Time complexity: O(N) - faster than 51.45% of C++ online submissions
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minValue = INT_MAX;
        int profit = 0;
        
        for(unsigned int i = 0; i < prices.size(); i++){
            if(prices[i] < minValue) minValue = prices[i];
            else{
                profit = max(profit, prices[i] - minValue);
            }
        }
        
        return profit;
    }
};
