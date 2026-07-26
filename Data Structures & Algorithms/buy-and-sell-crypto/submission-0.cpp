class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b = 101, p = 0;

        for (int &s : prices) {
            if (b > s) b = s;
            p = max(p, s - b);
        }

        return p;
    }
};
