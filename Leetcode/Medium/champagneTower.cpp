// Space complexity: O(R) - less than 54.18% of C++ online submissions
//  Time complexity: O(R ^ 2), being R = query_row - faster than 31.90% of C++ 
//                   online submissions
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double pour;
        vector<double> glasses;
        
        glasses.push_back(poured);
        
        for(unsigned int i = 0; i < query_row; i++){
            vector<double> temp(glasses.size() + 1, 0.0);
            
            for(unsigned int j = 0; j < glasses.size(); j++){
                pour = (glasses[j] - 1) / 2;
                
                if(pour > 0){
                    temp[j] += pour;
                    temp[j + 1] += pour;
                }
            }
            
            glasses = temp;
        }
        
        if(1.0 <= glasses[query_glass]) return 1.0;
        else return glasses[query_glass];
    }
};
