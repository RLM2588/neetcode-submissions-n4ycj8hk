class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> arr;
        int max_len = 0;

        for (int it: nums) {
            if(arr[it]) continue;
            arr[it] = arr[it - 1] + arr[it + 1] + 1;
            arr[it - arr[it - 1]] = arr[it];
            arr[it + arr[it + 1]] = arr[it];

            max_len = max(arr[it], max_len);
        }

        return max_len;
    }
};
