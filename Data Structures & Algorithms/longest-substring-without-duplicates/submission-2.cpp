class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;

        int lo, hi, len, maxlen;
        int idx_lookup[128];
        for (auto &x : idx_lookup) x = -1;

        for (
            lo = 0, hi = 1, idx_lookup[s[lo]] = lo, maxlen = len = 1;
            hi < s.size(); 
            hi++, maxlen = max(maxlen, ++len) 
        ) {
            if (idx_lookup[s[hi]] >= 0) {
                for ( ; s[lo] != s[hi]; lo++, len--)
                    idx_lookup[s[lo]] = -1;
                lo++, len--;
            }

            idx_lookup[s[hi]] = hi;
        }
        
        return maxlen;
    }
};
