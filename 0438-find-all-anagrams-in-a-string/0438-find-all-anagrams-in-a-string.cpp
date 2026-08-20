class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int n1=s.size(), n2=p.size();
        if(n2>n1) return {};
        vector<int> freq1(26,0), freq2(26,0);
        for(int i=0; i<n2; i++) {
            freq1[s[i]-'a']++;
            freq2[p[i]-'a']++;
        }
        if(freq1==freq2) res.push_back(0);

        int l=0, r=n2;
        while(r<s.size()) {
            freq1[s[r]-'a']++;
            freq1[s[l]-'a']--;
            l++;
            r++;
            if(freq1==freq2) res.push_back(l);
        }
        return res;
    }
};