class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int x, y;

        for (int x : stones) pq.push(x);

        while (!pq.empty()) {
            y = pq.top(), pq.pop();

            if (pq.empty()) return y;

            x = pq.top(), pq.pop();
            if (x != y) pq.push(y - x);
        }

        return 0;
    }
};
