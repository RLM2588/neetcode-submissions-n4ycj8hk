class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int maxprof = 0;
        if (arr.size() < 2) return 0;
        auto l = arr.begin();
        auto r = l + 1;
        while (r < arr.end()) {
            maxprof = max(maxprof, *r - *l);
            if (*r < *l) {
                if (r + 1 >= arr.end()) break;
                l = r;
                ++r;
            }
            else ++r;
        }

        return maxprof;
    }
};
