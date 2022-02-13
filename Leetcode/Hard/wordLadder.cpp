// Space: faster than 69.16% of C++ online submissions
//  Time: less than 11.98% of C++ online submissions
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unsigned int i, ans = 0, curSize;
        string pattern, cur;
        queue<string> q;
        unordered_set<string> visited;
        unordered_map<string, vector<string>> neighboursList;
        
        for(i = 0; i < wordList.size(); i++){
            if(wordList[i] == endWord) break;
        }
        if(i == wordList.size()) return ans;
        
        wordList.push_back(beginWord);
        
        for(i = 0; i < wordList.size(); i++){
            for(unsigned int j = 0; j < wordList[i].size(); j++){
                pattern = wordList[i];
                pattern[j] = '*';
                
                neighboursList[pattern].push_back(wordList[i]);                
            }
        }
        
        visited.insert(beginWord);
        
        q.push(beginWord);
        ans++;
        
        while(!q.empty()){
            curSize = q.size();
            
            for(i = 0; i < curSize; i++){
                cur = q.front();
                q.pop();
                
                if(cur == endWord) return ans;
                
                for(unsigned int j = 0; j < cur.size(); j++){
                    pattern = cur;
                    pattern[j] = '*';
                    
                    for(unsigned int k = 0; k < neighboursList[pattern].size(); k++){
                        if(visited.find(neighboursList[pattern][k]) == visited.end()){
                            visited.insert(neighboursList[pattern][k]);
                            
                            q.push(neighboursList[pattern][k]);                                    
                        }
                    }
                }                
            }
            
            ans++;            
        }
        
        return 0;
    }
};
