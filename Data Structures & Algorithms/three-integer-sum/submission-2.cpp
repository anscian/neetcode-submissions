class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i, j, k, tmp;
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for (i = 0; i < nums.size(); i++) {
            if (i && nums[i] == nums[i - 1])
                continue;

            for (j = i + 1, k = nums.size() - 1; j < k; ) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    j++;
                    continue;
                }

                tmp = nums[i] + nums[j] + nums[k];

                if (!tmp)
                    res.push_back({nums[i], nums[j], nums[k]}),
                    j++;
                else if (tmp < 0) j++;
                else              k--;
            }
        }

        return res;
    }
};
