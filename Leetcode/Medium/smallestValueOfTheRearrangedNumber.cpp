// Space complexity: O(N), being N num of digits - 6.1 MB, less than 30.82% of C++ online submissions
//  Time complexity: O(NlogN) - 4 ms, faster than 31.60% of C++ online submissions
// class Solution {
// public:
//     static bool customCmpPositive(int a, int b){
//         string strA, strB, temp;
        
//         strA = to_string(a), strB = to_string(b);
        
//         temp = strA;
//         strA += strB;
//         strB += temp;
        
//         return strA < strB;
//     }
    
//     static bool customCmpNegative(int a, int b){
//         string strA, strB, temp;
        
//         strA = to_string(a), strB = to_string(b);
        
//         temp = strA;
//         strA += strB;
//         strB += temp;
        
//         return strA > strB;
//     }
    
//     long long smallestNumber(long long num) {
//         bool isNegative = false;
//         long long ans = 0ll, cpNum = num;
//         string originalVal, smallVal;
//         vector<int> nums;
        
//         if(num < 0ll) isNegative = true, num *= -1, cpNum *= -1;
        
//         while(cpNum > 0ll) nums.push_back(cpNum % 10), cpNum /= 10;
        
//         if(isNegative) sort(nums.begin(), nums.end(), customCmpNegative);
//         else sort(nums.begin(), nums.end(), customCmpPositive);
        
//         for(int i : nums) ans = ans * 10ll + i;
        
//         if(isNegative) ans *= -1;
//         else{
//             originalVal = to_string(num);
//             smallVal = to_string(ans);
                        
//             if(smallVal.size() < originalVal.size()){
//                 int diff = (int)(originalVal.size() - smallVal.size());
                
//                 originalVal = "";
//                 for(int i = 0; i < diff; i++) originalVal += "0";

//                 smallVal = smallVal.substr(0, 1) + originalVal + smallVal.substr(1);
                
//                 ans = stoll(smallVal);
//             }
//         }
        
//         return ans;
//     }
// };



// Ref: https://leetcode.com/problems/smallest-value-of-the-rearranged-number/discuss/1748511/Sort-and-Swap
// Space complexity: O(N), being N num of digits - 6 MB, less than 67.30% of C++ online submissions
//  Time complexity: O(NlogN) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    long long smallestNumber(long long num) {
        string strNum = to_string(abs(num));
        sort(strNum.begin(), strNum.end(), [&](int a, int b){ return num < 0 ? a > b : a < b; });
        
        if(num > 0) swap(strNum[0], strNum[strNum.find_first_not_of('0')]);
        
        return num < 0 ? stoll(strNum) * -1ll : stoll(strNum);
    }
};
