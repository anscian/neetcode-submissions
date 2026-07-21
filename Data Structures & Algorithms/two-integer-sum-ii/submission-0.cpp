class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i, j, tmp;

        for (i = 0, j = numbers.size() - 1; i < j; ) {
            tmp = numbers[i] + numbers[j];

            if (tmp == target)
                return {i + 1, j + 1};
            else if (tmp < target)
                i++;
            else
                j--;
        }

        return {-1, -1};
    }
};
