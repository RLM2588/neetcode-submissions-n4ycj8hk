class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> arr;
        int max_len = 0;

        for (int it: nums) {
            if(arr.count(it)) continue;

            int left = arr.count(it - 1) ? arr[it - 1] : 0;
            int right = arr.count(it + 1) ? arr[it + 1] : 0;
            int total = left + right + 1;

            arr[it] = total;
            arr[it - left] = total;
            arr[it + right] = total;

            max_len = max(total, max_len);
        }

        return max_len;
    }
};
