// Space complexity: O(1) - less than 46.29% of C++ online submissions
//  Time complexity: O(N) - faster than 66.20% of C++ online submissions
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        
        for(unsigned int i = 0; i < prices.size() - 1; i++){
            if(prices[i] < prices[i + 1]){
                profit += prices[i + 1] - prices[i];
            }
        }
        
        return profit;
    }
};

/*
The solution is correct not because you are selling on the days which are higher than the previous day but rather the loop adds up all potential gains.   So if for example the array is  [5, 7, 100] the best is to buy on day 1 where the price is 5 and sell on day three where the price is 100.  This solution adds the gains of day one to day two with the gains of day two to day three.  Even if selling and re buying on the same day is not allowed this is still correct.

In this example, we are not selling on day 2 at price 7 and buying it again at price 7 on the same day. We are just calculating what profit we would make if we sold on day 2 (which will be 7-5 = 2). On day 3 we check what additional profit we would have made if we didn't sell on day 2 (100-7= 93 in our case), which would then add up with the gains we would have had on day 2.
*/
