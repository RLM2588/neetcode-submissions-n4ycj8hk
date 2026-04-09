class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> out_map;
        for (const string& it : strs) {
            int arr[26] = {0};
            for (char c : it) arr[c - 'a']++;
            string k;
            for (int in : arr) k += "#" + to_string(in);
            out_map[k].push_back(it);
        }
        vector<vector<string>> out;
        for (const auto& [key, value] : out_map) {
            out.push_back(value);
        }
        return out;
    }
};
