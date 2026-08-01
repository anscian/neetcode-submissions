class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> topK;
    int cap;

    KthLargest(int k, vector<int>& nums) {
        topK = {}, cap = k;

        for (int x : nums)
            topK.push(x);
        while (topK.size() > k)
            topK.pop();
    }
    
    int add(int val) {
        topK.push(val);
        if (topK.size() > cap)
            topK.pop();

        return topK.top();
    }
};
