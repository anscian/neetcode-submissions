class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        
        res += to_string(strs.size()) + ",";
        for (auto &s : strs) {
            for (char &c : s) {
                if (c == ',')       res += "\\,";
                else if (c == '\\') res += "\\\\";
                else                res += c;       
            }
            res += ',';
        }

        return res;
    }

    vector<string> decode(string s) {
        int n, i;
        vector<string> res;
        string tmp = "";
        bool flag;

        for (i = 0; s[i] != ','; i++)
            tmp += s[i];
        n = stoi(tmp);
        i++;

        res.resize(n);
        n = 0;
        for (flag = false; i < s.size(); i++) {
            if (flag)
                res[n] += s[i], flag = false;
            else if (s[i] == '\\')
                flag = true;
            else if (s[i] == ',')
                n++;
            else
                res[n] += s[i];
        }

        return res;
    }
};
