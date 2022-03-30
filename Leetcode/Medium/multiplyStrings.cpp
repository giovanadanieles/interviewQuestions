// Space complexity: O(N) - 6.7 MB, less than 66.77% of C++ online submissions
//  Time complexity: O(N * M) - 7 ms, faster than 72.42% of C++ online submissions
class Solution {
public:
    string multiply(string num1, string num2) {
        int carry = 0, cur;
        string mult = "";
        vector<int> ans;
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        for(int i = 0; i < num2.size(); i++){
            for(int j = 0; j < num1.size(); j++){
                if(ans.size() <= i + j) ans.push_back((num1[j] - '0') * (num2[i] - '0'));
                else ans[i + j] += (num1[j] - '0') * (num2[i] - '0');
            }
        }
                
        for(int i = 0; i < ans.size(); i++){
            cur = (ans[i] + carry) % 10;
            carry = (ans[i] + carry) / 10;
            
            mult += to_string(cur);        
        }
        
        if(carry != 0) mult += to_string(carry);
        
        reverse(mult.begin(), mult.end());
        mult.erase(0, min(mult.find_first_not_of('0'), mult.size() - 1));
        
        return mult;
    }
};
