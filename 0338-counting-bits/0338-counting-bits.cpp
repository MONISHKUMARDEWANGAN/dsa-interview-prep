class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        for(int x=0; x<=n; x++) {
            int num=0, i=x;
            while(i>0) {
                num+=(i%2);
                i/=2;
            }
            res[x] = num;
        }
        return res;
    }
};