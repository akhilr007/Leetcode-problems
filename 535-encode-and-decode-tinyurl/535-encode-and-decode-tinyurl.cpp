class Solution {
public:
    map<string, string> m, p;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        m[longUrl] = "http://tinyurl.com/4e9iAk";
        p[m[longUrl]] = longUrl;
        return m[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        
        return p[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));