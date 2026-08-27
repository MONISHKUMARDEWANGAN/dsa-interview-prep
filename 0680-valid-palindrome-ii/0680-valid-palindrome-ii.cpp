class Solution {
public:
    bool validPalindrome(string s) {
        int l=0, r=s.size()-1;
        int lS=true, rS=true;
        while(l<r) {
            if(s[l]!=s[r]) {
                break;
            }
            l++;
            r--;
        }

        int l1 = l+1, r1 = r;
        while(l1<r1) {
            if(s[l1]!=s[r1]) {
                lS=false;
                break;
            }
            l1++;
            r1--;
        }

        int l2 = l, r2 = r-1;
        while(l2<r2) {
            if(s[l2]!=s[r2]) {
                rS=false;
            }
            l2++;
            r2--;
        }
        return lS || rS;
    }
};