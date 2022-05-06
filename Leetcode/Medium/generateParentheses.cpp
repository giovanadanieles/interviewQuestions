/*      PERMUTATION WITH REPETITION
*   Example: how many anagrams are there of the word ASA?
*            -> P^(n)_(alfa, beta, gama) = P_n / (P_alfa * P_beta * P_gama)
*            -> P^(2)_(3) = P_3 / P_2 = 3! / 2! = 3
*
*   Used when you just want to change the order of elements and between them there are repetitions.
*/

// Space complexity: O((2N)! / (N! * N!)) - 27.2 MB, less than 5.62% of C++ online submissions
//  Time complexity: O((2N)! / (N! * N!)) - 19 ms, faster than 9.75% of C++ online submissions
// class Solution {
// public:
//     bool isValid(string combination){
//         stack<char> stck;
        
//         for(unsigned int i = 0; i < combination.size(); i++){
//             if(combination[i] == '(') stck.push(combination[i]);
//             else if(stck.empty()) return false;
//             else stck.pop();   
//         }
        
//         return stck.empty();
//     }

//     void backtracking(vector<string> &allCombinations, unordered_map<char, int> &parenthesesQtt, string curComb, int size){
//         if(curComb.size() == (size * 2)){
//             allCombinations.push_back(curComb);
//             return;
//         }
        
//         for(auto it = parenthesesQtt.begin(); it != parenthesesQtt.end(); it++){
//             if(it->second > 0){
//                 curComb += it->first, it->second--;
//                 backtracking(allCombinations, parenthesesQtt, curComb, size);
                
//                 curComb.pop_back(), it->second++;
//             }
//         }
//     }
    
//     vector<string> generateParenthesis(int n) {
//         vector<string> allCombinations, validCombinations;
//         unordered_map<char, int> parenthesesQtt;
        
//         parenthesesQtt['('] = n;
//         parenthesesQtt[')'] = n;
        
//         backtracking(allCombinations, parenthesesQtt, "", n);
        
//         for(string combination : allCombinations){
//             if(isValid(combination) == true) validCombinations.push_back(combination);
//         }
        
//         return validCombinations;
//     }
// };



// Ref: https://leetcode.com/problems/generate-parentheses/solution/

// Space complexity: O(4^N / (N*sqrt(N))), the Catalan number - 15.7 MB, less than 19.04% of C++ online submissions
//  Time complexity: O(4^N / (N*sqrt(N))) or O(N) (ref. to the seq) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    void backtracking(vector<string> &combinations, string curComb, int openPar, int closePar, int max){
        if(curComb.size() == max * 2){
            combinations.push_back(curComb);
            return;
        }
        
        if(openPar < max){
            curComb += '(';
            backtracking(combinations, curComb, openPar + 1, closePar, max);
            curComb.pop_back();
        }
        
        if(closePar < openPar){
            curComb += ')';
            backtracking(combinations, curComb, openPar, closePar + 1, max);
            curComb.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> combinations;
        
        backtracking(combinations, "", 0, 0, n);
        
        return combinations;
    }
};
