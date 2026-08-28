class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> m;
        int l=0, longest=0;
        for(int r=0; r<n; r++) {
            m[fruits[r]]++;
            while(m.size()>2) {
                m[fruits[l]]--;
                if(m[fruits[l]]==0) {
                    m.erase(fruits[l]);
                }
                l++;
            }
            longest = max(longest, r-l+1);
        }
        return longest;
    }
};