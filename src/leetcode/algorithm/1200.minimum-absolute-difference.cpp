class Solution {
public:
	vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
		sort(arr.begin(), arr.end());
		int minDiff = 0x7fffffff;
		vector<vector<int>> rv;
		for (int i = 1; i < arr.size(); ++i) {
			int diff = arr[i] - arr[i-1];
			if (diff < minDiff) {
				minDiff = diff;
				rv.clear();
				rv.push_back({arr[i-1], arr[i]});
			} else if (diff == minDiff) {
				rv.push_back({arr[i-1], arr[i]});
			}
		}
		return rv;
	}
};
