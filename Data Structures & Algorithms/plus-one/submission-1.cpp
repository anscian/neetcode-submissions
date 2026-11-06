class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c;

        reverse(digits.begin(), digits.end());
        c = 1;
        for(auto &n: digits){
            c += n;
            n = c % 10;
            c /= 10;
        }
        if(c) digits.push_back(c);
        reverse(digits.begin(), digits.end());

        return digits;
    }
};
