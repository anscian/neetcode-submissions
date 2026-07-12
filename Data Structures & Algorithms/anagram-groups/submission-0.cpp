class Trie {
private:
    static const int  N  = 26;
    static const char ST = 'a';
public:
    vector<Trie *> vec;

    Trie() {
        vec.resize(N);
    }

    Trie *addString(const string &s) {
        Trie *t = this;
        int idx;

        for (const char &c : s) {
            idx = c - ST;
            if (!t->vec[idx])
                t->vec[idx] = new Trie();
            t = t->vec[idx];
        }

        return t;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        string tmp;
        Trie db;
        map<Trie *, vector<string>> mp;
        vector<vector<string>> res;

        for (string &s : strs) {
            tmp = s;
            sort(tmp.begin(), tmp.end());
            mp[db.addString(tmp)].push_back(s);
        }

        for (auto &it : mp)
            res.push_back(it.second);

        return res;
    }
};
