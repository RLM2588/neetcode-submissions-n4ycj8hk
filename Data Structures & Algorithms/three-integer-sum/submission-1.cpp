class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() == 0) return {};

        sort(nums.begin(), nums.end());
        vector<vector<int>> answ;
        unordered_map<string, bool> test;
        int last = nums[0] - 1;
        for (int i = 0; i < nums.size() - 2; ++i) {
            if(last == nums[i]) continue;
            last = nums[i];
            int target = - nums[i];
            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r) {
                if (nums[l] + nums[r] == target) {
                    string tmp = to_string(nums[i]) + to_string(nums[l]) + to_string(nums[r]);
                    if (!test.count(tmp)) {
                        answ.push_back({nums[i], nums[l], nums[r]});
                        test[tmp] = true;   
                    }
                }
                if (nums[l] + nums[r] > target) --r;
                else ++l;
            }
        }
        return answ;
    }
};
