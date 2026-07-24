class Solution {
public:
    int trap(vector<int>& height) {
        int i, j, res, h;

        for (
            i = 0, j = height.size() - 1, h = 0, res = 0;
            i < j;
        ) {
            if (height[i] <= height[j]) {
                if (h <= height[i]) h = height[i++];
                else                res += h - height[i++];
            }
            else {
                if (h <= height[j]) h = height[j--];
                else                res += h - height[j--];
            }
        }

        return res;
    }
};
