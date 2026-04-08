class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0, size = (int)nums.size(); i < size - 1; ++i) {
            for(int j = i + 1; j < size; ++j) {
                if (nums[i] + nums[j] == target) return {i, j};
            }
        }
    }
};
