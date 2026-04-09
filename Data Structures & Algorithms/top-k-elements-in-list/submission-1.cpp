class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int& it : nums){
            freq[it]++;
        }
        vector<pair<int,int>> vec(freq.begin(), freq.end());
        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b){ return a.second > b.second; });
        
        vector<int> answ(k);
        for (int it = 0; it < k; ++it) answ[it] = vec[it].first;
        return answ;
    }
};
