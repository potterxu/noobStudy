class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        for (int i = 1; i < arr.size(); ++i) {
            arr[i] ^= arr[i-1];
        }
        vector<int> rv(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            auto &q = queries[i];
            rv[i] = arr[q[1]];
            if (q[0] > 0) {
                rv[i] ^= arr[q[0]-1];
            }
        }
        return rv;
    }
};
