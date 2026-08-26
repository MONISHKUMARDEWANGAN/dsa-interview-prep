class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0, l = 0, r = 0;
        unordered_map<char, int> m;

        while (r < s.size()) {
            if (m.find(s[r]) != m.end()) {
                l = max(l, m[s[r]] + 1);
            }
            m[s[r]] = r;
            longest = max(longest, r - l + 1);
            r++;
        }
        return longest;
    }
};