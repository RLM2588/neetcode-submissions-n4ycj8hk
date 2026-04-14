class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 1;
        if(s.size() < 2) return s.size();
        auto l = 0;
        auto r = 1;
        unordered_map<char, int> hash;
        hash[s[l]] = 1;
        while(r < s.size()) {
            if (hash[s[r]] >= l + 1) {
                if(r + 1 >= s.size()) return maxlen;
                l = hash[s[r]];
            }
            hash[s[r]] = r + 1;
            maxlen = max(maxlen, r - l + 1);
            ++r;
        }
        return maxlen;
    }
};
