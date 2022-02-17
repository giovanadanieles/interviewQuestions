// Space complexity: O(N) - less than 73.73% of C++ online submissions
//  Time complexity: O(N ^ 2) - faster than 56.71% of C++ online submissions
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> frequencies(9, 0);
        
        // checking rows 
        for(unsigned int i = 0; i < board.size(); i++){
            for(unsigned int j = 0; j < board[i].size(); j++){
                if(board[i][j] != '.') frequencies[board[i][j] - '0' - 1]++;
            }
            
            for(int j = 0; j < 9; j++){
                if(frequencies[j] > 1) return false;
            }
            
            fill(frequencies.begin(), frequencies.end(), 0);
        }
        
        // checking columns
        for(unsigned int j = 0; j < board.size(); j++){
            for(unsigned int i = 0; i < board[j].size(); i++){
                if(board[i][j] != '.') frequencies[board[i][j] - '0' - 1]++;
            }
            
            for(int i = 0; i < 9; i++){
                if(frequencies[i] > 1) return false;
            }
            
            fill(frequencies.begin(), frequencies.end(), 0);
        }
        
        // checking 3x3 squares
        for(int control = 0; control < 9; control += 3){
            for(int i = 0; i < 9; i++){
                for(int j = control; j < control + 3; j++){
                    if(board[i][j] != '.') frequencies[board[i][j] - '0' - 1]++;
                }
                
                if((i + 1) % 3 == 0){
                    for(int j = 0; j < 9; j++){
                        if(frequencies[j] > 1) return false;
                    }

                    fill(frequencies.begin(), frequencies.end(), 0);
                } 
            }
        }
        
        return true;
    }
};
