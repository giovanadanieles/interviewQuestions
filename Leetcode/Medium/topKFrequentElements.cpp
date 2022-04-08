// Space complexity: O(N) - 13.8 MB, less than 41.36% of C++ online submissions
//  Time complexity: O(K log N) - 16 ms, faster than 82.44% of C++ online submissions
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> numFreq;
//         priority_queue<pair<int, int>> topK;
//         vector<int> ans;
        
//         for(unsigned int i = 0; i < nums.size(); i++){
//             numFreq[nums[i]]++;
//         }
        
//         for(auto it = numFreq.begin(); it != numFreq.end(); it++){
//             topK.push({it->second, it->first});
//         }
        
//         while(!topK.empty() && k > 0){
//             ans.push_back(topK.top().second);
            
//             topK.pop();
//             k--;
//         }
        
//         return ans;
//     }
// };



// Space complexity: O(N) - 15.1 MB, less than 9.46% of C++ online submissions
//  Time complexity: O(N) - 24 ms, faster than 42.80% of C++ online submissions
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> numFreq;
        vector<vector<int>> bucket(nums.size() + 1);
        
        for(unsigned int i = 0; i < nums.size(); i++){
            numFreq[nums[i]]++;
        }
        
        for(auto it = numFreq.begin(); it != numFreq.end(); it++){
            bucket[it->second].push_back(it->first);
        }
        
        for(int i = bucket.size() - 1; i >= 0 && k > 0; i--){
            for(unsigned int j = 0; j < bucket[i].size(); j++){
                ans.push_back(bucket[i][j]);
                k--;
            }
        }
        
        return ans;
    }
};
