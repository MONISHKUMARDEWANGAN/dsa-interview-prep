class Solution {
public:
    int strStr(string s, string t) {
        int m = s.size(), n = t.size();
        for (int i = 0; i <= m - n; i++) {
            bool isIt = true;
            for (int j = i; j < i + n; j++) {
                if (s[j] != t[j - i]) {
                    isIt = false;
                    break;
                }
            }
            if (isIt)
                return i;
        }

        return -1;
    }
};