class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i, j, mx = 0, ar;

        for (i = 0, j = heights.size() - 1; i < j;) {
            ar = heights[i] - heights[j];

            if (ar <= 0) ar = heights[i++];
            else         ar = heights[j--];

            ar *= (j - i + 1);
            if (ar > mx) mx = ar;
        }

        return mx;
    }
};
