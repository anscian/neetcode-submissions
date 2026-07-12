class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        vector<vector<string>> res;

        for (string &s : strs) {
            vector<int> v(26, 0);
            for (char &c : s)
                v[c - 'a']++;

            mp[v].push_back(s);
        }

        for (auto &it : mp)
            res.push_back(it.second);

        return res;
    }
};
