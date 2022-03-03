// Space complexity: O(N) - less than 34.56% of C++ online submissions
//  Time complexity: O(N log N) - faster than 24.24% of C++ online submissions
// class Solution {
// public:
//     vector<int> countBits(int n) {
//         int curNum, value;
//         vector<int> ans;
        
//         for(int i = 0; i <= n; i++){
//             value = 0;
//             curNum = i;
            
//             while(curNum > 0){
//                 if(curNum % 2 == 1) value++;
                
//                 curNum /= 2;
//             }
            
//             ans.push_back(value);
//         }
        
//         return ans;
//     }
// };



// Space complexity: O(N) - less than 21.65% of C++ online submissions
//  Time complexity: O(N) - faster than 65.96% of C++ online submissions
class Solution {
public:
    vector<int> countBits(int n) {
        int index = 0, offset = 1;
        vector<int> ans;
        
        /*
           0000 - 0
           0001 - 1
           0010 - 1
           0011 - 2
           0100 - 1 + 0
           0101 - 1 + 1
           0110 - 1 + 1
           0111 - 1 + 2
        */
        
        if(index <= n) ans.push_back(0), index++;
        
        for(; index <= n; index++){
            if(index == offset * 2) offset *= 2;
            
            ans.push_back(1 + ans[index - offset]);
        }
        
        return ans;
    }
};
