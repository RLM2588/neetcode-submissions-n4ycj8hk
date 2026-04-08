class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> set_arr(nums.begin(), nums.end());
        return set_arr.size() != nums.size();
    }
};