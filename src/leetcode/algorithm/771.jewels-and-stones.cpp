class Solution {
public:
	int numJewelsInStones(string J, string S) {
		int o = 0;
		for (char c : S) {
			if (J.find(c) < J.size()) {
				o++;
			}
		}
		return o;
	}
};
