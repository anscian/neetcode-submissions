class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i, n = nums.size();
        vector<int> pfx(n), sfx(n);

        pfx[0] = 1;
        for (i = 1; i < n; i++)
            pfx[i] = pfx[i - 1] * nums[i - 1];

        sfx[n - 1] = 1;
        for (i = n - 2; i >= 0; i--)
            sfx[i] = sfx[i + 1] * nums[i + 1];

        for (i = 0; i < n; i++)
            pfx[i] = pfx[i] * sfx[i];

        return pfx;
    }
};
