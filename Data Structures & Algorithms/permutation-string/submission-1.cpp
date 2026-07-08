class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()) return false;
        if (s2 == s1) return true;
        int sh['z' - 'a' + 1] = {0};
        hashCreate(sh, s1);

        int buff['z' - 'a' + 1] = {0};
        ++buff[s2[0] - 'a'];
        int l = 0, r = 0;

        while (r < s2.length()) {
            if ((r - l + 1) < s1.length()) {
                ++r;
                ++buff[s2[r] - 'a'];
            } else {
                if (ifr(sh, buff)) return true;
                --buff[s2[l] - 'a'];
                ++l;
                ++r;
                if (r < s2.length()) ++buff[s2[r] - 'a'];
            }
        }
        return false;
    }

    void hashCreate(int *m, string &s) {
        for (auto i : s) {
            ++m[i - 'a'];
        }
    }

    bool ifr(int *m1, int *m2) {
        for (int i = 0; i <= 'z' - 'a'; ++i) {
            if (m1[i] != m2[i]) return false;
        }

        return true;
    }
};
