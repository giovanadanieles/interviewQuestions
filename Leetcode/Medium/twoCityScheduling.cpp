// Ref: https://www.youtube.com/watch?v=d-B_gk_gJtQ

// Space complexity: O(N) - 7.9 MB, less than 47.19% of C++ online submissions
//  Time complexity: O(N log N) - 8 ms, faster than 42.57% of C++ online submissions
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int finalCosts = 0;
        vector<pair<int, int>> diffCosts;
        
        for(unsigned int i = 0; i < costs.size(); i++){
            diffCosts.push_back({costs[i][1] - costs[i][0], i});
        }
        
        sort(diffCosts.begin(), diffCosts.end());
        
        for(unsigned int i = 0; i < costs.size(); i++){
            if(i < costs.size() / 2) finalCosts += costs[diffCosts[i].second][1];
            else finalCosts += costs[diffCosts[i].second][0];
        }
        
        return finalCosts;
    }
};
