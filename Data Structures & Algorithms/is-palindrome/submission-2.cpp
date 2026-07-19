class Solution {
public:
    bool isPalindrome(string s) {
        int i, j, n = s.size();

        for (i = 0, j = n - 1; i < j; ) {
            if (!isalnum(s[i])) {
                i++;
                continue;
            }
            if (!isalnum(s[j])) {
                j--;
                continue;
            }

            if (s[i] >= 'A' && s[i] <= 'Z') s[i] = 'a' + (s[i] - 'A');
            if (s[j] >= 'A' && s[j] <= 'Z') s[j] = 'a' + (s[j] - 'A');

            if (s[i] != s[j]) return false;
            i++, j--;
        }

        return true;
    }
};
