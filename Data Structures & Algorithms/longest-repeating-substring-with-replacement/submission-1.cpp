class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> lkp(26, 0);
        int res = 1, lo, hi, i;
        char c;

        for (
            lo = 0, hi = 1, lkp[s[0] - 'A'] = 1;
            hi < s.size();
        ) {
            lkp[s[hi] - 'A']++;

            for (i = 1, c = 'A'; i < 26; i++)
                if (lkp[i] > lkp[c - 'A'])
                    c = 'A' + i;

            if (hi - lo + 1 - lkp[c - 'A'] > k)
                lkp[s[hi] - 'A']--, lkp[s[lo++] - 'A']--;
            else
                hi++, res = max(res, hi - lo);
        }

        return res;
    }
};
