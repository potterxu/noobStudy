class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        vector<int> rv;
        if (nums.empty()) {
            return rv;
        }
        sort(nums.begin(), nums.end());
        //map<int, vector<int>> m;
        vector<int> count(nums.size(), 0);
        count[0] = 1;
        vector<int> parent(nums.size(), -1);
        int maxIndex = 0;
        for (int i = 1; i< nums.size(); ++i) {
            int n = nums[i];
            int c = 0;
            int index = -1;
            for (int p = i - 1; p > -1; --p)
            {
                if (count[p] == 0) {
                    continue;
                }
                if (n % nums[p] == 0) {
                    if (count[p] > c) {
                        c = count[p];
                        index = p;
                    }
                }
            }
            count[i] = c+1;
            parent[i] = index;
            if (count[i] > count[maxIndex]) {
                maxIndex = i;
            }
        }
        while (maxIndex != -1) {
            rv.push_back(nums[maxIndex]);
            maxIndex = parent[maxIndex];
        }
        return rv;
    }
};
