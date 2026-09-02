class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0]=1;
        int pre=0, count=0;
        for(int x : nums) {
            pre+=x;
            if(m.count(pre-k)) {
                count+=m[pre-k];
            }
            m[pre]++;
        }
        return count;
    }
};