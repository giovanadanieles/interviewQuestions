// Space complexity: O(N + M) - less than 46.53% of C++ online submissions
//  Time complexity: O(N + M) - faster than 69.52% of C++ online submissions
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int maxLeft, minRight;
        unsigned int first, second;
        vector<vector<int>> ans;
        
        first = 0, second = 0;
        
        while(first < firstList.size() && second < secondList.size()){
            maxLeft = max(firstList[first][0], secondList[second][0]);
            minRight = min(firstList[first][1], secondList[second][1]);

            if(maxLeft <= minRight)
                ans.push_back({maxLeft, minRight});
            
            if(firstList[first][1] <= secondList[second][1]) first++;
            else second++;
        }
        
        return ans;
    }
};
