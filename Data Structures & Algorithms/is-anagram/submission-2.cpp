class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = 26, mp[n];
        for (int &i : mp) i = 0;

        for (char &c : s)
            mp[c - 'a']++;
        
        for (char &c : t)
            mp[c - 'a']--;

        for (int &i : mp)
            if (i) return false;
        return true;
    }
};
