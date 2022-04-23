// Space: O(N) - 7.5 MB, less than 12.86% of C++ online submissions
//  Time - 7 ms, faster than 39.83% of C++ online submissions
class Solution {
public:
    // Encodes a URL to a shortened URL - avg. O(1)
    string encode(string longUrl) {
        while(urlToCode.find(longUrl) == urlToCode.end()){
            random_shuffle(alphabet.begin(), alphabet.end());
            string code = alphabet.substr(0, 6);
            
            if(codeToURL.find(code) == codeToURL.end()){
                codeToURL[code] = longUrl;
                urlToCode[longUrl] = code;
            }
        }
        
        return "http://tinyurl.com/" + urlToCode[longUrl];
    }

    // Decodes a shortened URL to its original URL - O(1)
    string decode(string shortUrl) {
        return codeToURL[shortUrl.substr(19)];
    }
    
private:
    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    unordered_map<string, string> codeToURL, urlToCode;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
