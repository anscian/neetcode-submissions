class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        int mp[32], n = 0, lo, hi;

        for (auto &x : mp) x = 0;
        for (auto &x : s1) mp[x - 'a'] += 1;
        for (auto &x : mp)
            if (x) n++;
            else   x = -1001;

        for (lo = hi = 0; hi < s1.size(); hi++) {
            if (mp[s2[hi] - 'a'] == -1001) continue;
            if (!--mp[s2[hi] - 'a'])       n--;
        }

        if (!n) return true;

        while (hi < s2.size()) {
            if (
                mp[s2[hi] - 'a'] != -1001 &&
                !--mp[s2[hi] - 'a']
            ) n--;
            if (
                mp[s2[lo] - 'a'] != -1001 &&
                !mp[s2[lo] - 'a']++
            ) n++;

            lo++, hi++;
            cout << lo << ' ' << hi << ' ' << n << '\n';
            if (!n) return true;
        }

        return false;
    }
};
