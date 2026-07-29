class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        if(n<4) return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int a=0; a<n-3; a++) {
            if(a>0 && nums[a]==nums[a-1]) continue;

            long long min1 = 1LL*nums[a]+nums[a+1]+nums[a+2]+nums[a+3];
            if(min1>target) break;
            long long max1 = 1LL*nums[a]+nums[n-1]+nums[n-2]+nums[n-3];
            if(max1<target) continue;

            for(int b=a+1; b<n-2; b++) {
                if(b>a+1 && nums[b]==nums[b-1]) continue;

                long long min2 = 1LL*nums[a]+nums[b]+nums[b+1]+nums[b+2];
                if(min2>target) break;
                long long max2 = 1LL*nums[a]+nums[b]+nums[n-1]+nums[n-2];
                if(max2<target) continue;

                int c=b+1, d=n-1;
                while(c<d) {
                    long long sum= 1LL*nums[a]+nums[b]+nums[c]+nums[d];
                    if(sum==target) {
                        res.push_back({nums[a], nums[b], nums[c], nums[d]});
                        c++;
                        d--;
                        while(c<d && nums[c]==nums[c-1]) c++;
                        while(c<d && nums[d]==nums[d+1]) d--;
                    }else if(sum>target) {
                        d--;
                    }else {
                        c++;
                    }
                }
            }
        }
        return res;
    }
};