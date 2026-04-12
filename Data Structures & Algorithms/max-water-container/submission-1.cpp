class Solution {
public:
    int maxArea(vector<int>& arr) {
        int l = 0;
        int r = arr.size() - 1;
        int maxcon = 0;
        while(l < r) {
            if (arr[l] < arr[r]) {
                maxcon = max(maxcon, arr[l] * (r - l));
                ++l;
            } else {
                maxcon = max(maxcon, arr[r] * (r - l));
                --r;
            }
        }

        return maxcon;
    }
};
