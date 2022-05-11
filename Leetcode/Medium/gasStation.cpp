// Ref: https://www.youtube.com/watch?v=lJwbPZGo05A

// Space complexity: O(1) - 69.4 MB, less than 88.70% of C++ online submissions
//  Time complexity: O(N) - 115 ms, faster than 41.36% of C++ online submissions
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumGas = 0, sumCost = 0, total = 0, startPos = 0;
        
        for(unsigned int i = 0; i < gas.size(); i++){
            sumGas += gas[i];
            sumCost += cost[i];
        }
        
        if(sumGas < sumCost) return -1;
        
        for(unsigned int i = 0; i < gas.size(); i++){
            total += gas[i] - cost[i];
            
            if(total < 0){
                startPos = i + 1;
                total = 0;
            }
        }
        
        return startPos;
    }
};
