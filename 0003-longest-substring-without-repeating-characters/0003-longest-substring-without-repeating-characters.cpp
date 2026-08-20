class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, n = s.size();
        unordered_map<char, int> m;
        int longest = 0;

        while (r < n) {
            if (m.count(s[r]) && m[s[r]] >= l) {
                l = m[s[r]] + 1;
            }
            m[s[r]] = r;
            longest = max(longest, r - l + 1);
            r++;
        }
        return longest;
    }
};