class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> fq;
        unordered_map<int, vector<int>> mp;
        pair<int, int> mn_max = {-1, -1};
        vector<int> res;
        int n;
        
        for (int &x : nums) 
            fq[x]++;

        for (auto &it : fq) {
            mp[it.second].push_back(it.first);

            if (mn_max.first < 0 || mn_max.first > it.second)
                mn_max.first  = it.second;
            if (mn_max.second < it.second)
                mn_max.second = it.second;
        }

        while (k) {
            n = min((int) mp[mn_max.second].size(), k);
            res.reserve(res.size() + n);
            res.insert(res.end(), mp[mn_max.second].begin(), mp[mn_max.second].begin() + n);

            mn_max.second--;
            k -= n;
        }

        return res;
    }
};
