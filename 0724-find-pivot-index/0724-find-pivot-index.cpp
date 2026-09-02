class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        vector<int> lps(n + 1, 0);
        vector<int> rps(n + 1, 0);

        for (int i = 0; i < n; i++) {
            lps[i + 1] = lps[i] + nums[i];
        }

        for (int i = n; i > 0; i--) {
            rps[i - 1] = rps[i] + nums[i - 1];
        }

        for (int i = 0; i < n; i++) {
            if (lps[i] == rps[i + 1]) {
                return i;
            }
        }

        return -1;
    }
};