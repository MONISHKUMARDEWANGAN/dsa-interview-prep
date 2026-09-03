class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        m[0]=-1;
        int longest=0, pre=0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==0) {
                pre+=-1;
            }else {
                pre+=1;
            }
            if(m.count(pre)) {
                longest = max(longest, i-m[pre]);
            }else {
                m[pre]=i;
            }
        }
        return longest;
    }
};

