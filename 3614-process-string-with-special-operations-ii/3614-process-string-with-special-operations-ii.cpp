static const auto fast_io = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    char processStr(const string& s, long long k) {
        const char* p = s.data();
        int n = (int)s.size();

        long long cur = 0;
        for (int i = 0; i < n; ++i) {
            char c = p[i];
            if (c >= 'a')        ++cur;
            else if (c == '#')   cur <<= 1;
            else if (c == '*')   { if (cur) --cur; }
        }

        if (k >= cur) return '.';

        for (int i = n - 1; i >= 0; --i) {
            char c = p[i];
            if (c >= 'a') {
                if (k == cur - 1) return c;
                --cur;
            } else if (c == '#') {
                long long half = cur >> 1;
                if (k >= half) k -= half;
                cur = half;
            } else if (c == '%') {
                k = cur - 1 - k;
            } else {           
                ++cur;
            }
        }
        return '.';
    }
};