class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> history;
        int t;

        while(n != 1){
            if(history.find(n) != history.end())
                return false;
            history.insert(n);

            for(t = 0; n; n /= 10)
                t += (n % 10) * (n % 10);
            n = t;
        }

        return true;
    }
};
