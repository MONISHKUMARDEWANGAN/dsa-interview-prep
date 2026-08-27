class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;

        int n = s.size(), m = p.size();
        if(m>n) return {};

        vector<int> freq1(26,0), freq2(26,0);
        for(int i=0; i<m; i++) {
            freq1[s[i]-'a']++;
            freq2[p[i]-'a']++;
        }

        if(freq1==freq2) res.push_back(0);

        for(int i=m; i<n; i++) {
            freq1[s[i]-'a']++;
            freq1[s[i-m]-'a']--;
            if(freq1==freq2) res.push_back(i-m+1);
        }

        return res;
    }
};