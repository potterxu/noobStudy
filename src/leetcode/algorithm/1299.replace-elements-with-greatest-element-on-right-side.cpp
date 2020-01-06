class Solution {
public:
	vector<int> replaceElements(vector<int>& arr) {
		vector<int> rv(arr.size());
		int max = arr[arr.size()-1];
		rv[arr.size()-1] = -1;
		for (int i = arr.size()-2; i>=0; --i) {
			rv[i] = max;
			if (arr[i] > max) {
				max = arr[i];
			}
		}
		return rv;
	}
};
