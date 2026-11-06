class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> num(digits.rbegin(), digits.rend());
        int c = 1;

        for(auto &n: num){
            c += n;
            n = c % 10;
            c /= 10;
        }
        if(c) num.push_back(c);

        reverse(num.begin(), num.end());

        return num;
    }
};
