class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0, j = s.size() - 1; i < j;) {
            if(!isupper(s[i]) && !islower(s[i]) && !isdigit(s[i])) {++i; continue;}
            if(!isupper(s[j]) && !islower(s[j]) && !isdigit(s[j])) {--j; continue;}
            if(tolower(s[i]) != tolower(s[j])) return false;
            ++i;
            --j;
        }
        return true;
    }
};
