// Space complexity: O(1) - 8 MB, less than 36.48% of C++ online submissions
//  Time complexity: O(N) - 10 ms, faster than 9.66% of C++ online submissions
// class Solution {
// public:
//     vector<string> fizzBuzz(int n) {
//         vector<string> ans;
        
//         for(int num = 1; num <= n; num++){
//             if(num % 3 == 0){
//                 if(num % 5 == 0) ans.push_back("FizzBuzz");
//                 else ans.push_back("Fizz");
//             }
//             else if(num % 5 == 0) ans.push_back("Buzz");
//             else ans.push_back(to_string(num));
//         }
        
//         return ans;
//     }
// };



// Space complexity: O(1) - 8 MB, less than 36.48% of C++ online submissions
//  Time complexity: O(N) - 3 ms, faster than 85.32% of C++ online submissions
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        
        for(int num = 1; num <= n; num++){
            if(num % 3 == 0 && num % 5 == 0) ans.push_back("FizzBuzz");
            else if(num % 3 == 0) ans.push_back("Fizz");
            else if(num % 5 == 0) ans.push_back("Buzz");
            else ans.push_back(to_string(num));
        }
        
        return ans;
    }
};
