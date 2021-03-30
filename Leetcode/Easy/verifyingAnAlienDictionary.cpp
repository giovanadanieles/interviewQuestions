// Version 1: 
//              runtime beats 34.73% of cpp submissions
//              memory usage beats 22.81% of cpp submissions

bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> alphabet;
        
        for(int i = 0; i < 26; i++){
            alphabet[order[i]] = i;
        }
        
        for(unsigned int i = 1; i < words.size(); i++){          
            for(int j = 0; j < max(words[i].size(), words[i-1].size()); j++){
                if(j > words[i].size() - 1) return false;
                if(alphabet[words[i-1][j]] < alphabet[words[i][j]]) break;
                else if(alphabet[words[i-1][j]] > alphabet[words[i][j]]) return false;            
            }
        }
        
        return true;
 }
    
    
// Version 2: 
//              runtime beats 34.73% of cpp submissions
//              memory usage beats 43.84% of cpp submissions

bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> alphabet;
        
        for(int i = 0; i < 26; i++){
            alphabet[order[i]] = i;
        }
        
        for(unsigned int i = 0; i < words.size(); i++){          
            for(int j = 0; j < words[i].size(); j++){
                words[i][j] = alphabet[words[i][j]];           
            }
        }
        
        return is_sorted(words.begin(), words.end());
  }
