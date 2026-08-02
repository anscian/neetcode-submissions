class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), x = 0;

        while (n)               x ^= n--;
        while (n < nums.size()) x ^= nums[n++];

        return x;
    }
};
