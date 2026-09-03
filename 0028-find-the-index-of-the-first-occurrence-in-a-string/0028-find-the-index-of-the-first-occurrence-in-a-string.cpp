class Solution {
public:
    vector<int> computeLPS(string pat) {
        vector<int> lps(pat.size(), 0);
        int length=0, i=1;
        while(i<pat.size()) {
            if(pat[i]==pat[length]) {
                length++;
                lps[i]=length;
                i++;
            }else if(length!=0) {
                length = lps[length-1];
            }else {
                lps[i]=0;
                i++;
            }
        }
        return lps;
    }
    int strStr(string text, string pat) {
        int n=text.size(), m=pat.size();
        vector<int> lps = computeLPS(pat);
        int i=0, j=0;
        while(i<n) {
            if(pat[j]==text[i]) {
                i++;
                j++;
                if(j==m) {
                    return i-j;
                }
            } else if(j!=0) {
                j = lps[j-1];
            }else {
                i++;
            }
        }
        return -1;
    }
};