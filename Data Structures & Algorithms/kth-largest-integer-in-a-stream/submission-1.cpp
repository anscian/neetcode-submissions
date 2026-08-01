class KthLargest {
public:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> big;

    KthLargest(int k, vector<int>& nums) {
        small = {}, big = {};

        for (int x : nums) small.push(x);
        while (!small.empty() && --k)
            big.push(small.top()), small.pop();
    }
 
    int add(int val) {
        if (big.empty() || val > big.top()) {
            big.push(val);
            small.push(big.top()), big.pop();
        }
        else
            small.push(val);

        return small.top();
    }
};
