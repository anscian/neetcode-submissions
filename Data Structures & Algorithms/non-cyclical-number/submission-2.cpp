class Solution {
public:
    bool isHappy(int n) {
        int f;

        for(f = sum_of_sq(n); f != n; n = sum_of_sq(n)){
            f = sum_of_sq(f);
            f = sum_of_sq(f);
        }

        return f == 1;
    }

    int sum_of_sq(int n) {
        int t;

        for(t = 0; n; n /= 10)
            t += (n % 10) * (n % 10);

        return t;
    }
};
