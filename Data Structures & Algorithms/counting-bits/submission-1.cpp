class Solution {
public:
    vector<int> countBits(int n) {
        if (!n) return {0};

        vector<int> res = {0, 1};
        int i = 0, x = 2;

        while (--n)
            if (i < x)
                res.push_back(res[i++] + 1);
            else {
                x *= 2;
                i = 1;
                res.push_back(1);
            }

        return res;
    }
};
