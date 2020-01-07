class Solution {
public:
	bool isEvenDigits(int num) {
		if (num == 100000) {
			return true;
		} else if (num > 10000) {
			return false;
		} else if (num > 1000) {
			return true;
		} else if (num > 100) {
			return false;
		} else if (num > 10) {
			return true;
		} else {
			return false;
		}
	}

	int findNumbers(vector<int>& nums) {
		int rv = 0;
		for (int n : nums) {
			if (isEvenDigits(n)) {
				++rv;
			}
		}
		return rv;
	}
};
