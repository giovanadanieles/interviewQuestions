// Space complexity: O(N) - 12.8 MB, less than 36.21% of C++ online submissions
//  Time complexity: O(NlogN) - 33 ms, faster than 5.82% of C++ online submissions
// class Solution {
// public:
//     vector<string> topKFrequent(vector<string>& words, int k) {
//         vector<string> ans;
//         unordered_map<string, int> wordFreq;
//         map<int, vector<string>> freqWord;
        
//         for(string word: words) wordFreq[word]++;
                
//         for(auto it = wordFreq.begin(); it != wordFreq.end(); it++) freqWord[it->second].push_back(it->first);
            
//         for(auto it = freqWord.rbegin(); it != freqWord.rend() && k > 0; it++){
//             if(it->second.size() > 1) sort(it->second.begin(), it->second.end());
            
//             for(unsigned int i = 0; i < it->second.size() && k > 0; i++){
//                 ans.push_back(it->second[i]);
//                 k--;
//             }
//         }
                
//         return ans;
//     }
// };



// Ref: https://www.youtube.com/watch?v=cupg2TGIkyM
// Space complexity: O(N) - 12.7 MB, less than 53.16% of C++ online submissions
//  Time complexity: O(NlogK) - 19 ms, faster than 43.85% of C++ online submissions
class Solution {
public:
    struct customCmp{
        bool operator()(pair<int, string> &a, pair<int, string> &b){
            return (a.first > b.first || (a.first == b.first && a.second < b.second));
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string, int> wordFreq;
        priority_queue<pair<int, string>, vector<pair<int, string>>, customCmp> kMostFreq;
        
        for(string word: words) wordFreq[word]++;
                
        for(auto it = wordFreq.begin(); it != wordFreq.end(); it++){
            kMostFreq.push({it->second, it->first});
            
            if(kMostFreq.size() > k) kMostFreq.pop();
        }
        
        while(!kMostFreq.empty()) ans.push_back(kMostFreq.top().second), kMostFreq.pop();
        
        reverse(ans.begin(), ans.end());
                
        return ans;
    }
};
