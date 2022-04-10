// Space complexity: O(N) - 8.2 MB, less than 99.88% of C++ online submissions
//  Time complexity: O(N) - 5 ms, faster than 53.39% of C++ online submissions
class Solution {
public:
    int calPoints(vector<string>& ops) {
        int firstPrev = -1, secPrev = -2, sum = 0;
        vector<int> record;
        
        for(string op : ops){
            if(op == "C"){
                record.pop_back();
                firstPrev--, secPrev--;
            }
            else if(op == "D"){
                record.push_back(record[firstPrev] * 2);
                firstPrev++, secPrev++;
            }
            else if(op == "+"){
                record.push_back(record[firstPrev] + record[secPrev]);
                firstPrev++, secPrev++;
            }
            else{
                record.push_back(stoi(op));
                firstPrev++, secPrev++;
            }
        }
        
        for(unsigned int i = 0; i < record.size(); i++){
            sum += record[i];
        }
        
        return sum;
    }
};
