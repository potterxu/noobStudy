class Solution {
public:
	int minCostToMoveChips(vector<int>& chips) {
		// only move from odd/even to even/odd position will have cost, then the min cost is the min value between chips in odd/even position;
		int oddNum = 0;
		for (int i : chips) {
			if (i&1) {
				++oddNum;
			}
		}
		if (oddNum + oddNum > chips.size()) {
			return chips.size() - oddNum;
		} else {
			return oddNum;
		}
	}
};
