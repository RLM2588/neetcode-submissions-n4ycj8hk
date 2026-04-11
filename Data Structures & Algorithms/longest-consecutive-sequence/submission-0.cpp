class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        vector<pair<int, int>> head;
        head.push_back(make_pair(0,0));
        unordered_map<int, int> arr;
        int max_len = 0;

        for (const auto& it: nums) {
            if(arr.find(it) != arr.end()) continue;

            bool k = false;
            if(arr.find(it - 1) != arr.end()) {
                arr[it] = arr[it - 1];
                ++head[arr[it - 1]].second;
                k = true;
            }
            if(arr.find(it + 1) != arr.end()) {
                if(k) {
                    int right = head[arr[it + 1]].second;
                    arr[right] = arr[it];
                    head[arr[it]].second = right;
                } else {
                    arr[it] = arr[it + 1];
                    --head[arr[it + 1]].first;
                }
                k = true;
            }
            if(!k) {
                head.push_back(make_pair(it, it));
                arr[it] = head.size() - 1;
            }
            max_len = max(head[arr[it]].second - head[arr[it]].first + 1, max_len);
        }

        return max_len;
    }
};
