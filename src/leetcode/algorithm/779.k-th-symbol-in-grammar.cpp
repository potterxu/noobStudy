class Solution {
public:
	int kthGrammar(int N, int K) {
		if (N == 1) {
			return 0;
		}
		int length = 1 << (N-2); // mid index
		if (K > length) {
			return 1 - kthGrammar(N-1, K-length);
		} else {
			return kthGrammar(N-1, K);
		}
	}
};
