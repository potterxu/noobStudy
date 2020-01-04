class Solution {
public:
	int numFactoredBinaryTrees(vector<int>& A) {
		if (A.empty()) {
			return 0;
		}
		sort(A.begin(), A.end());
		int rv = 1;
		map<int, int> m; //key is the root value, value is the number of trees
		m[A[0]] = 1;
		for (int i = 1; i < A.size(); ++i) {
			m[A[i]] = 1;
			for (int j = 0; j < i; ++j) {
				if (A[i]%A[j] != 0) {
					continue;
				}
				int rightV = A[i] / A[j];
				int count = 0;
				if  (m.find(rightV) != m.end()){
					count = (long)m[A[j]] * m[rightV] % 1000000007;
				}

				m[A[i]] += count;
				m[A[i]] %= 1000000007;
			}
			rv += m[A[i]];
			rv %= 1000000007;
		}
		return rv;
	}
};
