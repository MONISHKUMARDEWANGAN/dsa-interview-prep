class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count=0, longest=0;
        int l=0, r=0;
        while(r<nums.size()) {
            if(nums[r]==1) {
                count++;
            }
            while(r-l+1-count > k) {
                if(nums[l]==1) count--;
                l++;
            }
            longest = max(longest, r-l+1);
            r++;
        }
        return longest;
    }
};