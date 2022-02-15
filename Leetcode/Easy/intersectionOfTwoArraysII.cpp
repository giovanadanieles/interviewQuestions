// Space complexity: O(N) - less than 20.56% of C++ online submissions
//  Time complexity: O(N) - faster than 88.72% of C++ online submissions
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> intersection;
        
        for(unsigned int i = 0; i < nums1.size(); i++){
            intersection[nums1[i]]++;
        }
        
        for(unsigned int i = 0; i < nums2.size(); i++){
            if(intersection[nums2[i]] > 0){
                ans.push_back(nums2[i]);
                intersection[nums2[i]]--;
            }
        }
        
        return ans;
    }
};
