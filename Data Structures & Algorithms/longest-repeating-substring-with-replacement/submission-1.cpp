class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.length() <= 1) return s.length();

        int h['Z' - 'A' + 1] = {0};
        int m = 0;
        int l = 0, r = 0;
        ++h[s[0] - 'A'];
        
        while (r < s.length()) {
            if((r - l + 1 - maof(h)) <= k) {
                m = max(m, r - l + 1);
                ++r;
                if (r < s.length()) ++h[s[r] - 'A'];
            } else {
                --h[s[l] - 'A'];
                ++l;
            }
        }
        return m;
    }

    int maof(int* mas) {
        int m = 0;
        for (int i = 0; i <= 'Z' - 'A'; ++i) {
            m = max(m, mas[i]);
        }

        return m;
    }
};