class Solution {
public:
    unordered_map<int, string> integerToEnglish;
    
    string twoDigits(int num){
        int tens, ones;
        
        if(num < 20) return integerToEnglish[num];
        
        tens = num / 10 * 10;
        ones = num % 10;
        
        if(ones == 0) return integerToEnglish[tens];
        else return integerToEnglish[tens] + " " + integerToEnglish[ones];
    }
    
    string threeDigits(int num){
        int hundreds, rest;
        
        hundreds = num / 100;
        rest = num % 100;
        
        if(hundreds == 0) return twoDigits(rest);
        if(rest == 0) return integerToEnglish[hundreds] + " " + integerToEnglish[100];
        else return integerToEnglish[hundreds] + " " + integerToEnglish[100] + " " +
                    twoDigits(rest);
    }
    
    string numberToWords(int num) {
        int billions, millions, thousands;
        string ans = "";
        
        integerToEnglish[0] = "Zero";
        integerToEnglish[1] = "One";
        integerToEnglish[2] = "Two";
        integerToEnglish[3] = "Three";
        integerToEnglish[4] = "Four";
        integerToEnglish[5] = "Five";
        integerToEnglish[6] = "Six";
        integerToEnglish[7] = "Seven";
        integerToEnglish[8] = "Eight";
        integerToEnglish[9] = "Nine";
        integerToEnglish[10] = "Ten";
        integerToEnglish[11] = "Eleven";
        integerToEnglish[12] = "Twelve";
        integerToEnglish[13] = "Thirteen";
        integerToEnglish[14] = "Fourteen";
        integerToEnglish[15] = "Fifteen";
        integerToEnglish[16] = "Sixteen";
        integerToEnglish[17] = "Seventeen";
        integerToEnglish[18] = "Eighteen";
        integerToEnglish[19] = "Nineteen";
        integerToEnglish[20] = "Twenty";
        integerToEnglish[30] = "Thirty";
        integerToEnglish[40] = "Forty";
        integerToEnglish[50] = "Fifty";
        integerToEnglish[60] = "Sixty";
        integerToEnglish[70] = "Seventy";
        integerToEnglish[80] = "Eighty";
        integerToEnglish[90] = "Ninety";
        integerToEnglish[100] = "Hundred";
        integerToEnglish[1000] = "Thousand";
        integerToEnglish[1000000] = "Million";
        integerToEnglish[1000000000] = "Billion";
        
        if(num == 0) return integerToEnglish[0];
        else{
            billions = num / 1000000000;
            num -= billions * 1000000000;

            millions = num / 1000000;
            num -= millions * 1000000;

            thousands = num / 1000;
            num -= thousands * 1000;

            if(billions > 0) ans += threeDigits(billions) + " " + integerToEnglish[1000000000] + " ";

            if(millions > 0) ans += threeDigits(millions) + " " + integerToEnglish[1000000] + " ";

            if(thousands > 0) ans += threeDigits(thousands) + " " + integerToEnglish[1000] + " ";

            if(num > 0) ans += threeDigits(num) + " ";

            ans = ans.substr(0, ans.size() - 1);
            //ans.erase(ans.find_last_not_of(' ') + 1);

            return ans;
        }
    }
};
