class Solution {
public:
	bool isPredecessor(string &a, string&b) {
		// a is b's predecessor
		if (b.size() != a.size() + 1) {
			return false;
		}
		bool hasDiff = false;
		int aI = 0;
		int bI = 0;
		while (aI != a.size() && bI != b.size()) {
			if (a[aI] != b[bI]) {
				if (hasDiff) {
					return false;
				}
				hasDiff = true;
				++bI;
				continue;
			}
			++aI;
			++bI;
		}
		return true;
	}

	int longestStrChain(vector<string>& words) {
		int rv = 0;
		vector<int> chainLength(words.size(), 1);
		int maxSize = 0;
		for (auto &s : words) {
			if (s.size() > maxSize) {
				maxSize = s.size();
			}
		}
		for (int size = 2; size <= maxSize; ++size) {
			for (int i = 0; i < words.size(); ++i) {
				int length = 0;
				if (size == words[i].size()) {
					for (int j = 0; j < words.size(); ++j) {
						if (size - 1 == words[j].size()) {
							if (isPredecessor(words[j], words[i])) {
								length = max(chainLength[j], length);
							}
						}
					}
					chainLength[i] += length;
					rv = max(chainLength[i], rv);
				}
			}
		}
		return rv;
	}
};
