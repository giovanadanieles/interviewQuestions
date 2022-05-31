// Ref: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/solution/
// Space complexity: O(2^K) - 63.1 MB, less than 55.97% of C++ online submissions
//  Time complexity: O(N) -  67 ms, faster than 91.51% of C++ online submissions
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int neededCodes = 1 << k, mask = neededCodes - 1, hashVal = 0;
        vector<int> foundCodes(neededCodes, false);
        
        for(int i = 0; i < (int)s.size(); i++){
            /*
                    For example, say s  ="11010110", and k=3, and we just finish calculating 
                the hash of the first substring: "110" (hash is 4+2=6, or 110). Now we want to 
                know the next hash, which is the hash of "101".

                    We can start from the binary form of our hash, which is 110. First, we shift left, 
                resulting 1100. We do not need the first digit, so it is a good idea to do 1100 & 111 = 100. 
                The all-one 111 helps us to align the digits. Now we need to apply the lowest digit 
                of "101", which is 1, to our hash, and by using |, we get 100 | last_digit = 100 | 1 = 101.
            */
            hashVal = ((hashVal << 1) & mask) | (s[i] - '0');
            
            if(i >= k - 1 && foundCodes[hashVal] == false){
                foundCodes[hashVal] = true;
                neededCodes--;
                
                if(neededCodes == 0) return true;
            }
        }
        
        return false;
    }
};
