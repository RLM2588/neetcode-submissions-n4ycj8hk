class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> out_map;
        for (const string& it : strs) {
            string k = it;
            sort(k.begin(), k.end());
            out_map[k].push_back(it);
        }
        vector<vector<string>> out;
        for (const auto& [key, value] : out_map) {
            out.push_back(value);
        }
        return out;
    }
};
