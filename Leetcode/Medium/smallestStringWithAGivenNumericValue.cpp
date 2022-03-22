// Space complexity: O(N), being N = n - 27.2 MB, less than 35.89% of C++ online submissions
//  Time complexity: O(N) - 58 ms, faster than 55.14% of C++ online submissions
// class Solution {
// public:
//     string getSmallestString(int n, int k) {
//         string ans = "";
//         vector<char> intToChar(27);
        
//         for(char c = 'a'; c <= 'z'; c++){
//             intToChar[c - 'a' + 1] = c; 
//         }
        
//         for(; n > 0; n--){
//             if(k - n >= 26){
//                 ans += intToChar[26];
//                 k -= 26;
//             }
//             else if(k > n){
//                 ans += intToChar[k - n + 1];
//                 k -= k - n + 1;
//             }
//             else{
//                 ans += intToChar[1];
//                 k--;
//             }
//         }
        
//         reverse(ans.begin(), ans.end());
        
//         return ans;
//     }
// };



// Space complexity: O(N) - 21.2 MB, less than 80.96% of C++ online submissions
//  Time complexity: O(N) - 53 ms, faster than 63.02% of C++ online submissions
class Solution {
public:
    string getSmallestString(int n, int k) {
        int missing;
        string ans(n, 'a');
        
        k -= n;
        n--;
        
        while(k > 0){
            missing = min(k, 25);
            ans[n] += missing; 
            
            k -= missing;
            n--;
        }
        
        return ans;
    }
};
