// Space complexity: O(N) - 56 MB, less than 45.35% of C++ online submissions
//  Time complexity: O(N log N) - 213 ms, faster than 68.35% of C++ online submissions
class Solution {
public:
    int find_(int x, vector<int> &parents){
        if(x != parents[x]){ // if x is not its own parent
            parents[x] = find_(parents[x], parents); // i'll discover who is the parent
        }
        
        return parents[x];
    }
    
    void union_(int x, int y, vector<int> &parents){
        int parentOfX, parentOfY;
        
        parentOfX = find_(x, parents);
        parentOfY = find_(y, parents);
        
        if(parentOfX != parentOfY) parents[parentOfY] = parentOfX; // now they have the same parent
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        // s = "dcab", pairs = [[0, 3], [1, 2]]
        string ans = s;
        vector<int> parents;
        unordered_map<int, vector<int>> dict;
        
        // [0, 1, 2, 3]
        for(unsigned int i = 0; i < s.size(); i++) parents.push_back(i);
        
        // [0, 1, 1, 0]
        for(vector<int> v : pairs) union_(v[0], v[1], parents);
        
        // 0: [0, 3]
        // 1: [1, 2]
        for(unsigned int i = 0; i < parents.size(); i++) dict[find_(parents[i], parents)].push_back(i);
        
        for(auto it = dict.begin(); it != dict.end(); it++){
            vector<int> indexes = it->second;
            vector<char> chars;
            
            for(unsigned int i = 0; i < indexes.size(); i++) chars.push_back(s[indexes[i]]);
            
            sort(chars.begin(), chars.end());
            
            for(unsigned int i = 0; i < indexes.size(); i++){
                ans[indexes[i]] = chars[i];
            }
        }
        
        return ans;
    }
};
