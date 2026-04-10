class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int nsize = static_cast<int>(nums.size());
        vector<int> larr(nsize + 1);
        larr[0] = 1;
        vector<int> rarr(nsize + 1);
        rarr[nsize] = 1;

        for(int i = 0; i < nsize; ++i) {
            larr[i+1] = larr[i] * nums[i];
            rarr[nsize - i - 1] = rarr[nsize - i] * nums[nsize - i - 1];
        }
        
        vector<int> answ;
        answ.reserve(nsize);
        for(int i = 0; i < nsize; ++i) {
            answ.push_back(larr[i] * rarr[i+1]);
        }

        return answ;
    }
};
