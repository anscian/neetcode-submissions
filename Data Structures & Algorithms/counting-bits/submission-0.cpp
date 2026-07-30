class Solution {
protected:
    static vector<int> nbits;
public:
    vector<int> countBits(int n) {
        vector<int> res;
        int i;

        n++;
        for (i = nbits.size(); i < n; i++)
            nbits.push_back(numBits(i));

        for (i = 0; i < n; i++)
            res.push_back(nbits[i]);

        return res;
    }

    int numBits(int n) {
        int res;

        for (res = 0; n; n >>= 1)
            res += n & 1;

        return res;
    }
};

vector<int> Solution::nbits;