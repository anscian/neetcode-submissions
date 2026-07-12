class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for (int &x : nums) 
            mp[x]++;

        struct Compare {
            bool operator()(const pair<int, int> &x,
                            const pair<int, int> &y) {
                return x.second < y.second;
            }
        };

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            Compare
        > pq(mp.begin(), mp.end());

        vector<int> res(k);
        for (int &x : res)
            x = pq.top().first, pq.pop();

        return res;
    }
};
