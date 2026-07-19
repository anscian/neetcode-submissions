class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int mx, tmp;

        for (auto &x : nums) 
            s.insert(x);

        mx = 0;
        for (auto &x : nums) {
            if (s.find(x) == s.end())
                continue;

            tmp = 0;
            for (int i = x; s.find(i) != s.end(); i++)
                tmp++, s.erase(i);
            for (int i = x - 1; s.find(i) != s.end(); i--)
                tmp++, s.erase(i);

            if (mx < tmp)
                mx = tmp;
        }

        return mx;
    }
};
