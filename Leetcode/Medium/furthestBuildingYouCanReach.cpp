// Ref: https://www.youtube.com/watch?v=lfbIqCqC3ok
// Space complexity: O(L) - 53.7 MB, less than 42.33% of C++ online submissions
//  Time complexity: O(NlogL) - 122 ms, faster than 85.89% of C++ online submissions
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int diff;
        priority_queue<int, vector<int>, greater<int>> maxDistances;
        
        for(int index = 0; index < (int)heights.size() - 1; index++){
            diff = heights[index + 1] - heights[index];
            
            if(diff > 0){
                maxDistances.push(diff);
                
                if(maxDistances.size() > ladders){
                    bricks -= maxDistances.top();
                    maxDistances.pop();
                }
                
                if(bricks < 0) return index;
            }
        }
        
        return heights.size() - 1;
    }
};
