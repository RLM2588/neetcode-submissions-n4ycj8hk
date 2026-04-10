class Solution {
public:

    string encode(vector<string>& strs) {
        size_t total = 1;
        for(const auto& it: strs) {
            total += 1 + it.length();
        }

        string answ;
        answ.reserve(total);

        uint8_t count = static_cast<uint8_t>(strs.size());
        answ.push_back(static_cast<char>(count));

        for(string& it: strs) {
            uint8_t len = static_cast<uint8_t>(it.length());
            answ.push_back(static_cast<char>(len));
            answ.append(it.data(), it.length());
        }
        return answ;
    }

    vector<string> decode(string s) {
        vector<string> answ;
        const char* ptr = s.data();
        const char* end = ptr + s.size();
        uint8_t count = static_cast<uint8_t>(*ptr);
        answ.reserve(count);
        ++ptr;

        for(int i = 0; i < count; ++i) {
            uint8_t len = static_cast<uint8_t>(*ptr);
            ++ptr;
            if (ptr + len > end) break;
            answ.emplace_back(ptr, len);
            ptr += len;
        }
        return answ;
    }
};
