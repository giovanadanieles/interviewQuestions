// Space complexity: O(1) - less than 11.29% of C++ online submissions
//  Time complexity: O(2 log N) = O(log N) - faster than 5.22% of C++ online submissions
// class Solution {
// public:
//     bool isPalindrome(int x) {
//         int aux, numDigits = 0;
        
//         if(x < 0) return false;
//         else if(x < 10) return true;
        
//         aux = x;
        
//         while(aux > 0){
//             numDigits++;
//             aux /= 10;
//         }
        
//         aux = x;
        
//         while(x > 0){
//             cout << x % 10 << " " << aux / (int)pow(10, numDigits - 1) << endl;
            
//             if(x % 10 != aux / (int)pow(10, numDigits - 1)) return false;
                        
//             x /= 10;
            
//             aux -= aux / (int)pow(10, numDigits - 1) * (int)pow(10, numDigits - 1);
//             numDigits--;
//         }
        
//         return true;
//     }
// };



// Space complexity: O(1) - less than 33.06% of C++ online submissions
//  Time complexity: O(log10 N) - faster than 90.50% of C++ online submissions
class Solution {
public:
    bool isPalindrome(int x) {  
        long long divValue = 1, leftDigit, rightDigit;
        
        if(x < 0) return false;
        
        while(x >= 10 * divValue) divValue *= 10;
        
        while(x > 0){
            leftDigit = x / divValue;
            rightDigit = x % 10;
            
            if(leftDigit != rightDigit) return false;
            
            //chopping off left and right digits
            x = (x % divValue) / 10;
            divValue /= 100;
        }
        
        return true;
    }
};
