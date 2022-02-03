// Space complexity: O(N) - less than 31.90% of C++ online submissions
//  Time complexity: O(N logN) - faster than 19.01% of C++ online submissions
class Solution {
public: 
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        double distance;
        vector<pair<double, int>> distances;
        vector<vector<int>> ans;
        
        for(unsigned int i = 0; i < points.size(); i++){
            distance = sqrt(points[i][0] * points[i][0] +
                                 points[i][1] * points[i][1]);
            
            distances.push_back(make_pair(distance, i));
        }
        
        sort(distances.begin(), distances.end());
        
        for(int i = 0; i < points.size(), k > 0; i++, k--){
            ans.push_back(points[distances[i].second]);
        }

        return ans;
    }
};
